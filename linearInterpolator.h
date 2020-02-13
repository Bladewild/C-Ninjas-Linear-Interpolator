#ifndef LINEARINTERPOLATOR_H
#define LINEARINTERPOLATOR_H
#include <vector>
#include <iostream>
#include <tuple>
//Interpolator Class
using namespace std;
template <typename t>
class linearInterpolator
{
private:
    int sizeOfPointVector;
    vector <tuple<t, t, t>> points;
    vector <t> indonly_points;
    t upper_bound;
    t lower_bound;


public:
  linearInterpolator(); //defaults to 20
    linearInterpolator(int sizeGiven);
  linearInterpolator(const vector<tuple<t, t, t>>
      inputPoints);
  linearInterpolator(const linearInterpolator<t>& source);
  //pretty print
  template<typename U>
  friend ostream& operator << (ostream& os, const 
      linearInterpolator<U>& liObj);
  template<typename U>
  friend istream& operator >> (istream& in, linearInterpolator<U>& liObj);

  //linearInterpolator(const linearInterpolator& otherlp);
  linearInterpolator<t>& operator = (const linearInterpolator<t> & source);
  //have const, and non-const version
  const tuple<t, t, t>  operator [] (const t index_var) const;
  //tuple<t, t, t> &  operator [] (const t index_var);

  const tuple<t, t> operator () (const t index_var) const;
  t operator ~ () const;
  //relational operators
  template<typename U>
  friend bool operator<(const linearInterpolator<U>& l,
      const linearInterpolator<U>& r);
  template<typename U>
  friend bool operator<(const linearInterpolator<U>& l,
      const linearInterpolator<U>& r);
  template<typename U>
  friend bool operator==(const linearInterpolator<U>& l,
      const linearInterpolator<U>& r);
  template<typename U>
  friend bool operator!=(const linearInterpolator<U>& l,
      const linearInterpolator<U>& r);
  void setSize(const int inputSize);


  /*
  linearInterpolator & operator () ( const linearInterpolator & source);
  

  t& linearInterpolator<t>::operator()(int indVar)
  const t& linearInterpolator<t>::operator()(int indVar) const*/
};

#include "linearInterpolator.hpp"
//questions
/*
  what are vector of points which are of type std::tuple?
*/

/*
parameterized constructor accepting a std::vector of points (which are of type
 std::tuple)
*/

/*

parameterized constructor accepting the number of points in the dataset, which
 should default to 20
copy constructor and copy assignment (=)
subscript operator ([]) for accessing/modifying the 3-tuple with the closest
 independent variable value less than or equal to the index parameter

function evaluation operator () for interpolating given a valid value of the
 independent variable

extraction operator (>>) for reading in a given number of points from a 
std::istream

insertion operator (<<) for pretty-printing every point in the dataset to a 
std::ostream such that 128.1: -55.7, 12.6 indicates that the independent 
variable 128.1 corresponds to dependent variable values -55.7 and 12.6,
 respectively.

an overload of the bitwise complement operator (~) to return the range of the 
independent variable for a given interpolator object

less-than/greater-than/logical equality operators (</>/==/!=), s.t. for
 interpolators a and b, a < b is true if b's range of the independent 
 variable is greater than a's, and a == b if the range of the independent
  variables for a and b are equal
*/

#endif
