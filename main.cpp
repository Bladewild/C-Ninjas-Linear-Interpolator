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


tuple<int, int> numData;
int main()
{
    /*
    string test = "This is a test";
    cout << test<<endl;
    vector<string> newTokens = split(test, ' ');
    for (auto x : newTokens)
    {
        cout << x;
    }*/
    
    string wholeLine, word;
    ifstream fin;
    vector < tuple<float, float, float>> setofPoints_1;
    vector < tuple<float, float, float>> setofPoints_2;
    fin.open("sample.input");
    cout.precision(8); // as requested

    if(fin.fail())
    {
        cerr<<"Error Opening File"<<endl;
        exit(1);
    }
    
    fin>>get<0>(numData)>>get<1>(numData);
    cout<<endl<<get<0>(numData)<<endl<<get<1>(numData)<<endl;

    try
    {
        linearInterpolator<float> H1(get<0>(numData));
        linearInterpolator<float> H2(get<1>(numData));
        fin >> H1 >> H2;
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


