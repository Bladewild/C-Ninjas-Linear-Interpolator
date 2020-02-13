#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <sstream> 
#include "linearInterpolator.h"
using namespace std;

// for test
template <typename t>
void readInput(istream& finput, int sizeofData, vector < tuple<t, t, t>>& source_emptypoints)
{
    for (int i = 0; i < sizeofData; i++)
    {
        vector<float> temp_points;
        for (int j = 0; j < 3; j++)
        {
            string temp_input;
            finput >> temp_input;
            temp_points.push_back(stof(temp_input));
        }
        tuple<float, float, float> temp_tuple = make_tuple(temp_points[0],
            temp_points[1], temp_points[2]);
        source_emptypoints.push_back(temp_tuple);
    }
}

tuple<int, int> numData;
int main()
{
    
    vector < tuple<float, float, float>> setofPoints_1;
    vector < tuple<float, float, float>> setofPoints_2;
    
    ifstream fin;
    fin.open("sample.input");
    if(fin.fail())
    {
        cerr<<"Error Opening File"<<endl;
        exit(1);
    }
    
    cout.precision(8); // as requested
    fin >>get<0>(numData)>>get<1>(numData);
    cout<<endl<<get<0>(numData)<<endl<<get<1>(numData)<<endl;
    //cin >> get<0>(numData) >> get<1>(numData);

    readInput(fin, get<0>(numData), setofPoints_1);
    readInput(fin, get<1>(numData), setofPoints_2);
    const linearInterpolator<float> H1(setofPoints_1);
    linearInterpolator<float> H2(setofPoints_2);
   

    try
    {
        //linearInterpolator<float> H1(get<0>(numData));
        //linearInterpolator<float> H2(get<1>(numData));
        //cin >> H1 >> H2;
        //float test = 0.201;
        cout << ~H1<<endl;
        cout << "H1<H2:" << (H1 < H2)<<endl;
        cout << "H1>H2:" << (H1 > H2) << endl;
        cout << "H1==H2:" << (H1 == H2) << endl;
        cout << "H1!=H2:" << (H1 != H2) << endl;

        tuple<float, float> dependInterpolated1;
        dependInterpolated1 = H1(1.707f);
        cout << "1.707:" << get<0>(dependInterpolated1) <<" "<< get<1>(dependInterpolated1) << endl;

        tuple<float, float> dependInterpolated2;
        dependInterpolated2 = H2(1.707f);
        cout << "1.707:" << get<0>(dependInterpolated2) << " " << get<1>(dependInterpolated2) << endl;
        //tuple tests;
        tuple <float , float, float > h1Tuple = H1[1.609f]; //check for const and non const versions
        tuple <float, float, float> h2Tuple = H2[1.609f]; //check for const and non const versions
        cout << "\nh1Tuple" << endl;
        cout << "\n" << get<0>(h1Tuple) << " " << get<1>(h1Tuple) << " " << get<2>(h1Tuple) << endl;
        cout << "\nh2Tuple" << endl;
        cout << "\n" << get<0>(h2Tuple) << " " << get<1>(h2Tuple) << " " << get<2>(h2Tuple) << endl;


        //H1[1.609f] = make_tuple(0.000f, 0.000f, 0.000f);
        H2[1.609f] = make_tuple(0.000f, 0.000f, 0.000f);
        h1Tuple = H1[1.609f]; //check for const and non const versions
        h2Tuple = H2[1.609f]; //check for const and non const versions
        cout << "\n\nNEW\nh1Tuple" << endl;
        cout << "\n" << get<0>(h1Tuple) << " " << get<1>(h1Tuple) << " " << get<2>(h1Tuple) << endl;
        cout << "\nh2Tuple" << endl;
        cout << "\n" << get<0>(h2Tuple) << " " << get<1>(h2Tuple) << " " << get<2>(h2Tuple) << endl;

        //H1 = H1;
        //H1 = H2;
        //cout << H1 << "--\n" << H2;

    }
   catch (const std::out_of_range & oor) {
    std::cerr << "\nOut of Range error: " << oor.what() << '\n';
   }
   catch (const std::invalid_argument & ia) {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
   }
   catch (const std::length_error & le) {
       std::cerr << "Length error: " << le.what() << '\n';
   }
   catch (...)
   {
       std::cerr << "An uknown error has occured." << '\n';
   }
   /*
    try
    {
        //linearInterpolator<float> H1(get<0>(numData));
        //linearInterpolator<float> H2(get<1>(numData));
        //cin >> H1 >> H2;
        //float test = 0.201;
        cout << ~H1<<endl;
        cout << "H1<H2:" << (H1 < H2)<<endl;
        cout << "H1>H2:" << (H1 > H2) << endl;
        cout << "H1==H2:" << (H1 == H2) << endl;
        cout << "H1!=H2:" << (H1 != H2) << endl;

        tuple<float, float> dependInterpolated1;
        dependInterpolated1 = H1(1.707f);
        cout << "1.707:" << get<0>(dependInterpolated1) <<" "<< get<1>(dependInterpolated1) << endl;

        tuple<float, float> dependInterpolated2;
        dependInterpolated2 = H2(1.707f);
        cout << "1.707:" << get<0>(dependInterpolated2) << " " << get<1>(dependInterpolated2) << endl;
        //H1[1.609f]; //check for const and non const versions
        //H1 = H1;
        //H1 = H2;
        //cout << H1 << "--\n" << H2;

    }
   catch (const std::out_of_range & oor) {
    std::cerr << "\nOut of Range error: " << oor.what() << '\n';
   }
   catch (const std::invalid_argument & ia) {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
   }
   catch (const std::length_error & le) {
       std::cerr << "Length error: " << le.what() << '\n';
   }
   catch (...)
   {
       std::cerr << "An uknown error has occured." << '\n';
   }
   */
   
    return 0;
    //Your program must first read two integers from stdin,
    //denoting the number of data points in the two following data files

    //You will then read in (again from stdin) two three-column data sets 
    //(all columns will be floating-point) like those described above
    //into two instances of your templated interpolator class

    //Print out the interpolated values of both functions for the 
    //independent variable value of 1.707

    /*Print ‘0’ if the first interpolator compares greater than
     the second, ‘1’ otherwise*/
     /*
    Modify the data point of the first interpolator at the independent
     variable value of zero to the pair of dependent variables (1.47, -0.0234)
     */
    /*
    Print out the interpolated values of the first interpolator object
     for the independent variable value of 0.03 Your output should be 
     formatted as follows:*/
}


