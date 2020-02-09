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
vector<string> split(const std::string& s, char delimiter)
{
    vector<std::string> tokens;
    string token;
    istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
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

    if(fin.fail())
    {
        cerr<<"Error Opening File"<<endl;
        exit(1);
    }
    
    fin>>get<0>(numData)>>get<1>(numData);
    cout<<endl<<get<0>(numData)<<endl<<get<1>(numData)<<endl;
    
    for (int i = 0; i < get<0>(numData); i++)
    {

        vector<float> temp_points;
        for (int j = 0; j < 3; j++)
        {
            string temp_input;
            fin >> temp_input;
            temp_points.push_back(stof(temp_input));

        }
        //if (temp_points.size() != 3)
        //{
            //throw error
        //}
        tuple<float, float, float> temp_tuple = make_tuple(temp_points[0],
            temp_points[1],temp_points[2]);
        setofPoints_1.push_back(temp_tuple);
    }
    //check if datapoints are correct



    linearInterpolator<float> h(setofPoints_1);
    cout << h;

    /* test tuples
    cout << endl << "-------------" << endl;
    for (int i = 0; i < setofPoints_1.size(); i++)
    {
        float one, two, three;
        tie(one,two,three) = setofPoints_1[i];
        cout << one << " " << two << " " << three << endl;
    }
    cout << endl << "-------------" << endl;
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


