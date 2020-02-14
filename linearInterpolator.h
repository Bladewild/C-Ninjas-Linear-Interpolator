/*
* Author: Your name and your class and section number
* File: filename.cpp Date: tomorrow
* Class: CS 9001 section A
* Instructor : Homer Simpson
* A brief description of the file ’s contents
*/

/*! \file
 *
 * A Linear Interpolator library.
 */
#ifndef LINEARINTERPOLATOR_H
#define LINEARINTERPOLATOR_H
#include <vector>
#include <iostream>
#include <tuple>
//Interpolator Class
/*
* Class: Class_name
* A brief description of what the class does
*/
using namespace std;
template <typename t>
class linearInterpolator
{
  private:
    int sizeOfPointVector; //size of points
    vector <tuple<t, t, t>> points; //contains dataset given

    // below uses to find span
    t upper_bound; //last of independent variable
    t lower_bound; //first independent variable


public:


  /*!
  *
  * @brief Constructs an emptry vector that defaults to size 20
  * @post sizeOfPointVector set to 20. 
  * @post The rest of the variables are default setup. 
  */
  linearInterpolator(); 

  /*! 
  *
  * @brief Constructs an emptry vector that defaults to size 20
  * @param[in] sizeGiven used for setting size
  * @post sizeOfPointVector set to given sizeGiven paramater. 
  * @post The rest of the variables are default setup. 
  */

  linearInterpolator(int sizeGiven);

  /*!
  *
  * @brief Constructs a vector from inputPoints. Checks if increasing
  * @param[in] inputPoints dataset for interpolation
  * @pre t >= t (relational) defined.
  * @post sizeOfPointVector set to inputPoints.size().
  * @post inputPoints vector transfered to points vector.
  * @post sets bounds for other functions to use.
  * @throw invalid_argument if non-increasing independent variables.
  */
  linearInterpolator(const vector<tuple<t, t, t>>
      inputPoints);

  /*!
  *
  * @brief Constructs a linearInterpolator from source.
  * @param[in] source can have valid or invalid data.
  * (this is checked whenever data is being used/outputted)
  * @pre t = t (assingment) defined.
  * @post source variables are assigned to *this variables
  * @post returns *this is same assignment
  */

  linearInterpolator(const linearInterpolator<t>& source);

  /*!
  *
  * @brief Constructs a linearInterpolator by assigning from source.
  * @param[in] source can have valid or invalid data.
  * (this is checked whenever data is being used/outputted)
  * @pre t = t (assingment) defined.
  * @post source variables are assigned to *this variables
  * @post returns *this is same assignment
  * @note almost same implementation as 
  * @note linearInterpolator(const vector<tuple<t, t, t>> inputPoints);
  */

  linearInterpolator<t>& operator = (const linearInterpolator<t>& source);
 
  /*!
  *
  * @brief  Pretty prints dataset seperated by newline
  * @param[in] os ostream&
  * @param[in] liObj linearInterpolator<t>
  * @pre << t (insertion) defined.
  * @pre liobj must have non-empty vector points 
  * @pre and increasing independent variables.
  * @post Pretty Prints in form of
  * @post <independent>: <dependent> <denpendent>
  * @post in increasing order seperated by  '\\n'.
  * @post with 8 sig figs.
  * @throw out_of_range if empty vector.
  * @throw invalid_argument if non-increasing independent variables.
  */

  template<typename U>
  friend ostream& operator << (ostream& os, const 
  linearInterpolator<U>& liObj);

  /*!
  *
  * @brief Dataset is taken from istream with getline.
  * @brief Cycles until size limit and constructs and replace
  * @brief new set.
  * @param[in] finput ostream& passed by ref
  * @param[in] liObj linearInterpolator<t> passed by ref
  * @pre data set is seperated by '\\n' anymore will not be read
  * @pre data set fits to size of libObj.size()
  * @post Transfer finput data by cycling istream to liObj.points.
  * @post Sets upper_bound and lower_bound for ~ operator use.
  * @throw length_error if variables do not equal to size 3.
  * @throw invalid_argument if non-increasing independent variables.
  */

  template<typename U>
  friend istream& operator >> (istream& finput, linearInterpolator<U>& liObj);

  /*! 
  *
  * @brief Const Version []
  * @brief returns a reference vector tuple nearest below specified input.
  * @param[in] index_var const t. As the name implies, an index.
  * @pre upper_bound and lower_bound variables have to be set
  * @pre points vector is non-empty.
  * @pre < and > must be define for  template t
  * @pre t != t (equality) defined
  * @pre index_var is within range of liObj's span (inclusion)
  * @post Finds tuple at the index given.
  * @post (closest and below or at index_var)
  * @return reference to vector[itr], itr being the index found.
  * @throw out_of_range if out of bounds. Cannot extrapolate.
  * @throw out_of_range no points to access, empty vector.
  */

  const tuple<t, t, t>  operator [] (const t index_var) const;

  /*! 
  *
  * @brief Non-const Version []
  * @brief returns value of vector tuple nearest below specified input.
  * @param[in] index_var const t. As the name implies, an index.
  * @pre upper_bound and lower_bound variables have to be set
  * @pre points vector is non-empty.
  * @pre < and > must be define for  template t
  * @pre t != t (equality) defined
  * @pre index_var is within range of liObj's span (inclusion)
  * @post Finds tuple at the index given.
  * @post (closest and below or at index_var)
  * @return value of vector[itr], itr being the index found.
  * @throw out_of_range if out of bounds. Cannot extrapolate.
  * @throw out_of_range no points to access, empty vector.
  */

  tuple<t, t, t> & operator [] (const t index_var);

  /*!
  *
  * @brief Returns interpolated dependent values at given index_var
  * @param[in] index_var const t. As the name implies, an index.
  * @pre upper_bound and lower_bound variables have to be set
  * @pre < and > must be define for  template t
  * @pre t - t (subtraction) defined
  * @pre t + t (additive) defined
  * @pre t = t (assignment) defined
  * @pre t / t (division) defined
  * @pre index_var is within range of liObj's span (inclusion)
  * @pre points vector is non-empty.
  * @post Uses linear interpolator math to find value between
  * @post the two above and below value and returns it.
  * @return interpolated 2 values of type t b by tuple at index_var.
  * @throw out_of_range if out of bounds. Cannot extrapolate.
  * @throw out_of_range no points to access, empty vector.
  */

  const tuple<t, t> operator () (const t index_var) const;

  /*!
  *
  * @brief Returns interpolated dependent values at given index_var
  * @param[in] index_var const t. As the name implies, an index.
  * @pre upper_bound and lower_bound variables have to be set
  * @pre t - t (subtraction) defined
  * @pre points vector is non-empty.
  * @post calculates span and returns span in scalar.
  * @return returns scalar of span of type t.
  * @throw out_of_range no points to access, empty vector.
  */

  t operator ~ () const;
  //relational operators

  /*!
  *
  * @brief Comparison by < 
  * @param[in] l passed by reference.
  * @param[in] r passed by reference.
  * @pre fullfill ~ operator preconditions
  * @pre t < t (relational) defined
  * @pre points vector is non-empty.
  * @post evaulates ((~l) < (~r)) and returns
  * @return returns result by bool
  * @see operator~()
  */

  template<typename U>
  friend bool operator<(const linearInterpolator<U>& l,
    const linearInterpolator<U>& r);

  /*!
  *
  * @brief Comparison by > 
  * @param[in] l passed by reference.
  * @param[in] r passed by reference.
  * @pre fullfill ~ operator preconditions
  * @pre t > t (relational) defined
  * @pre points vector is non-empty.
  * @post evaulates ((~l) > (~r)) and returns
  * @return returns result by bool
  * @see operator~()
  */

  template<typename U>
  friend bool operator>(const linearInterpolator<U>& l,
      const linearInterpolator<U>& r);

  /*!
  *
  * @brief Comparison by ==
  * @param[in] l passed by reference.
  * @param[in] r passed by reference.
  * @pre fullfill ~ operator preconditions
  * @pre t == t (relational) defined
  * @pre points vector is non-empty.
  * @post evaulates ((~l) == (~r)) and returns
  * @return returns result by bool
  * @see operator~()
  */

  template<typename U>
  friend bool operator==(const linearInterpolator<U>& l,
      const linearInterpolator<U>& r);
  /*!
  *
  * @brief Comparison by !=
  * @param[in] l passed by reference.
  * @param[in] r passed by reference.
  * @pre fullfill ~ operator preconditions
  * @pre t != t (relational) defined
  * @pre points vector is non-empty.
  * @post evaulates ((~l) != (~r)) and returns
  * @return returns result by bool
  * @see operator~()
  */

  template<typename U>
  friend bool operator!=(const linearInterpolator<U>& l,
      const linearInterpolator<U>& r);
  
  /*!
  *
  * @brief sets size to sizeOfPointVector.
  * @param[in] inputSize const int.
  * @pre size is at least 2.
  * @post assigns inputSize to sizeOfPointVector.
  */

  void setSize(const int inputSize);

  /*!
  *
  * @brief splits s into tokens by delimiter.
  * @param[in] s string
  * @param[in] delimiter char
  * @pre delimiter is not an '', preferably ' '
  * @post splits s string to usable vector<string> tokens
  * @return vector<string> of split tokes from data s
  */
  friend vector<string> split(const std::string& s, char delimiter);
  template<typename U>

  /*!
  *
  * @brief converts str to type generated by template of class.
  * @param[in] s string
  * @param[in] delimiter char
  * @pre non-empty
  * @post converts s to type t of class
  * @return converted data s of type t
  */

  friend U convert_to(const std::string& str);

  /*!
  *
  * @brief checks if points is increasing dataset
  * @pre non-empty
  * @pre sizeOfPointVector has been set > 1
  * @post returns if dataset is increasing (tests validity)
  * @throw out_of_range no points to access, empty vector.
  */

  bool checkifIncreasing() const;

};

#include "linearInterpolator.hpp"

#endif
