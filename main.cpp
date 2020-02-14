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
  fin >>get<0>(numData)>>get<1>(numData);
  //cin >> get<0>(numData) >> get<1>(numData);
  cout<<endl<<get<0>(numData)<<endl<<get<1>(numData)<<endl;

  //test constant
   

  try
  {

    //test 1 tests constructor with size given. empty <<
    /*
    readInput(fin, get<0>(numData), setofPoints_1);
    readInput(fin, get<1>(numData), setofPoints_2);
    const linearInterpolator<double> H1(setofPoints_1);
    linearInterpolator<double> H2(setofPoints_2);
    */
    /*
    cout << H1 << "--\n" << H2;
    */
    //test2
    linearInterpolator<double> H1(get<0>(numData));
    linearInterpolator<double> H2(get<1>(numData));
        
    fin >> H1 >> H2;
        
    cout << ~H1<<endl;
    cout << "H1<H2:" << (H1 < H2)<<endl;
    cout << "H1>H2:" << (H1 > H2) << endl;
    cout << "H1==H2:" << (H1 == H2) << endl;
    cout << "H1!=H2:" << (H1 != H2) << endl;

    tuple<double, double> dependInterpolated1;
    dependInterpolated1 = H1(1.707f);
    cout << "1.707:" << get<0>(dependInterpolated1) <<" "<< get<1>(dependInterpolated1) << endl;

    tuple<double, double> dependInterpolated2;
    dependInterpolated2 = H2(1.707f);
    cout << "1.707:" << get<0>(dependInterpolated2) << " " << get<1>(dependInterpolated2) << endl;
    //tuple tests;
    tuple <double, double, double > h1Tuple = H1[1.609f]; //check for const and non const versions
    tuple <double, double, double> h2Tuple = H2[1.609f]; //check for const and non const versions
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
    cout << H1 << "--\n" << H2;
        
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
}


