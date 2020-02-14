/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: linearInterpolator.h Date: 2/13/20
* Class: CS 5201
* Instructor : CLATON PRICE
*
* Implementation file of linear interpolator
*/

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
        vector<double> temp_points;
        for (int j = 0; j < 3; j++)
        {
            string temp_input;
            finput >> temp_input;
            temp_points.push_back(stof(temp_input));
        }
        tuple<double, double, double> temp_tuple = make_tuple(temp_points[0],
            temp_points[1], temp_points[2]);
        source_emptypoints.push_back(temp_tuple);
    }
}

int main()
{

  tuple<int, int> numData;
  vector < tuple<double, double, double>> setofPoints_1;
  vector < tuple<double, double, double>> setofPoints_2;
    
  ifstream fin;
  fin.open("sample.input");
  if(fin.fail())
  {
    cerr<<"Error Opening File"<<endl;
    exit(1);
  }
    
  cout.precision(8); // as requested
   

  try
  {
    cin >> get<0>(numData) >> get<1>(numData);
    linearInterpolator<double> H1(get<0>(numData));
    linearInterpolator<double> H2(get<1>(numData));
        
    cin >> H1 >> H2;
        


    tuple<double, double> dependInterpolated1;
    dependInterpolated1 = H1(1.707);
    cout << "1.707: " << get<0>(dependInterpolated1) <<" "<< get<1>(dependInterpolated1) << endl;

    tuple<double, double> dependInterpolated2;
    dependInterpolated2 = H2(1.707);
    cout << "1.707: " << get<0>(dependInterpolated2) << " " << get<1>(dependInterpolated2) << endl;

    cout << (H1 < H2) << endl;

    H1[0.000] = make_tuple(0.000, 1.47, -0.0234);
    tuple<double, double> dependInterpolated3;
    dependInterpolated3 = H1(0.03f);
    cout << "0.03: " << get<0>(dependInterpolated3) << " " << get<1>(dependInterpolated3) << endl;
   
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
}


