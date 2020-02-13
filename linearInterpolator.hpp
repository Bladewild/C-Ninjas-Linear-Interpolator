

template<typename t>
linearInterpolator< t >::linearInterpolator()
{
    cout << endl << "Creating linearInterpolator" << endl;
    setSize(20);
    cout << endl << "Default Size: "<< sizeOfPointVector;
}

template<typename t>
linearInterpolator< t >::linearInterpolator(int sizeGiven)
{
    cout << endl << "Creating linearInterpolator" << endl;
    setSize(sizeGiven);
    cout << endl << "Given Size: " << sizeOfPointVector<<endl;
}

template<typename t>
linearInterpolator< t >::linearInterpolator(const vector<tuple<t, t, t>>
    inputPoints)
{

    cout << endl << "Creating linearInterpolator" << endl;

    setSize(inputPoints.size());
    cout <<"Size: " << sizeOfPointVector<<endl;

    //creating vector of points
    for (int i = 0; i < sizeOfPointVector; i++)
    {
        t independent1, dependent1, dependent2;
        tie(independent1, dependent1, dependent2) = inputPoints[i];
        points.push_back(make_tuple(independent1, dependent1,
            dependent2));
        indonly_points.push_back(independent1);
        //check if increasing
        if(i>0 && (indonly_points[i-1] >= indonly_points[i]))
        {
            throw invalid_argument("Independent Variable must be increasing.");
        }
    }

}

//Copy Constructor
template<typename t>
linearInterpolator<t>::linearInterpolator(const linearInterpolator<t> & source)
{
    setSize(source.sizeOfPointVector);
    points = source.points;
    upper_bound = source.upper_bound;
    lower_bound = source.lower_bound;
}

template<typename t>
linearInterpolator<t>& linearInterpolator<t>::operator = (const linearInterpolator<t>& source)
{
    if (this == &source)
    {
        //this works
        cout << "Prevent self assignment (=)" << endl;
    }
    else
    {
        setSize(source.sizeOfPointVector);
        points = source.points;
        upper_bound = source.upper_bound;
        lower_bound = source.lower_bound;
    }
    return *this;

}

template<typename t>
void linearInterpolator< t >::setSize(const int inputSize)
{
    //might refactor later if no additional data
    if (sizeOfPointVector != inputSize)
    {
        sizeOfPointVector = inputSize;
    }
    return;
}
/*
Pre: 
    << must be define for  template t
*/
template<typename t>
ostream& operator << (ostream& os, const linearInterpolator<t> & liObj)
{
    if (liObj.points.empty())
    {
        throw std::out_of_range("Empty Vector");
    }
    for (int i = 0; i < liObj.sizeOfPointVector; i++)
    {
        t independent1, dependent1, dependent2;
        tie(independent1, dependent1, dependent2) = liObj.points[i];
        os << independent1 << ": " << dependent1 << " " << dependent2 << "\n";
    }
    return os;
}

template<typename t>
istream& operator >> (istream& finput, linearInterpolator<t>& liObj)
{
    //clears out entire vector
    //check for invalid range
    vector<tuple<t, t, t>> new_points;
    vector<t> new_indonlypoints;
    for (int i = 0; i < liObj.sizeOfPointVector; i++)
    {
        //change this to getline then check if extra points
        vector<t> temp_points;
        for (int j = 0; j < 3; j++)
        {
            string temp_input;
            finput >> temp_input;
            temp_points.push_back(stof(temp_input));
        }
        //if (temp_points.size() != 3)
        //{
            //throw error
        //}
        tuple<t, t, t> temp_tuple = make_tuple(temp_points[0],
            temp_points[1], temp_points[2]);
        new_points.push_back(temp_tuple);
        new_indonlypoints.push_back(temp_points[0]);
        //check if increasing
        if (i > 0 && (new_indonlypoints[i - 1] >= new_indonlypoints[i]))
        {
            //cout << "\nOne: " << new_indonlypoints[i - 1] << endl;
            //cout << "\nTwo: " << new_indonlypoints[i] << endl;
            throw invalid_argument("Independent Variable must be increasing.");
        }
        
    }
    liObj.points = new_points;
    liObj.indonly_points = new_indonlypoints;
    //establish bounds
    tuple<t,t,t> firstTuple = liObj.points[0]; 
    liObj.lower_bound = get<0>(firstTuple);
    tuple<t, t, t> lastTuple = liObj.points[liObj.sizeOfPointVector - 1];
    liObj.upper_bound = get<0>(lastTuple);
    //cout << "\nUpper Bound: " << upper_bound << endl;
    //cout << "\nLower Bound: " << lower_bound << endl;

    return finput;
}
/*
Pre: upper_bound and lower_bound variables have to be defined
    < and > must be define for  template t
Post:
    returns null if not found;
*/

//access only const version
template<typename t>
const tuple<t,t,t> linearInterpolator<t>::operator [] 
(const t index_var ) const
{
    if (points.empty())
    {
        throw std::out_of_range("No points to access, empty vector");
    }
    if (index_var > upper_bound || index_var < lower_bound)
    {
        throw std::out_of_range("Out of bounds. Cannot extrapolate.");
    }
    
    //has to be increasing check, if haven't. Done before this in construction or >>


    bool found = false;
    int itr = 0;
    tuple<t,t,t> varfound;
    while (!found && itr <sizeOfPointVector)
    {
        t ind_low = indonly_points[itr];
        if (ind_low >= index_var)
        {
            found = true;
            varfound = points[itr];
            cout << "\nFound: " << ind_low << endl;
        }
		else //todo check later
		{
			itr++;
		}
    }
    return varfound;
}

/*
Pre:
    t must have assignment operator(=) defined
    t must have subtraction operator(-) defined
    t must have addition operator(+) defined
    t must have division operator(/) defined
*/
template<typename t>
const tuple<t,t> linearInterpolator<t>::operator () 
(const t index_var ) const
{
    if (points.empty())
    {
        throw std::out_of_range("No points to access, empty vector");
    }
    if (index_var > upper_bound || index_var < lower_bound)
    {
        throw std::out_of_range("Out of bounds. Cannot extrapolate.");
    }
    
    //has to be increasing check, if haven't. Done before this in construction or >>


    bool found = false;
    int itr = 0;
    // -1 because can't exceed last var
    while (!found && itr <sizeOfPointVector-1)
    {
        t ind_low = indonly_points[itr];// this fails
		//cout << "ind_low:" << ind_low << endl;
		//cout << "index_var:" << index_var << endl;
        if (ind_low >= index_var) 
        {
            found = true;
			itr--;
        }
		else
		{
			itr++;
		}
    }

    //check if the same as independent var
    //ifso just just give independent
    // interpolate
    cout << "\nITR:" << itr<<endl;
    t independent1_low, dependent1_low, dependent2_low;
    t independent1_upper, dependent1_upper, dependent2_upper;
    tie(independent1_low, dependent1_low, dependent2_low) = points[itr];
    tie(independent1_upper, dependent1_upper, dependent2_upper) = points[itr+1];
	cout << "Size:" << sizeOfPointVector << endl;
	cout << "Lower:" << independent1_low << "," << dependent1_low << "," << dependent2_low<<endl;
	cout << "Upper:" << independent1_upper << "," << dependent1_upper << "," << dependent2_upper << endl;
    t percent = (index_var - independent1_low) / (independent1_upper - independent1_low);
    t newdepend1 = (dependent1_upper - dependent1_low)* percent + dependent1_low;
    t newdepend2 = (dependent2_upper - dependent2_low)* percent + dependent2_low;

    tuple<t,t> dependInterpolated = make_tuple(newdepend1, newdepend2);
    //cout << newdepend1 << " " << newdepend2<<endl;

    return dependInterpolated;
}
template<typename t>
t linearInterpolator<t>::operator ~ () const
{
	//check if empty, then throw
    t spanScalar = upper_bound - lower_bound;
    return spanScalar;
}

//Pre:
/*
    ~ unary operator has to be defined for both l and r
    result type of unary operator must define < 
*/ 
template<typename t>
bool operator<(const linearInterpolator<t>& l,
    const linearInterpolator<t>& r)
{
    return ((~l) < (~r));
}

//Pre:
/*
    ~ unary operator has to be defined for both l and r
    result type of unary operator must define >
*/
template<typename t>
bool operator>(const linearInterpolator<t>& l,
    const linearInterpolator<t>& r)
{
    return ((~l) > (~r));
}

//Pre:
/*
    ~ unary operator has to be defined for both l and r
    result type of unary operator must define ==
*/
template<typename t>
bool operator==(const linearInterpolator<t>& l,
    const linearInterpolator<t>& r)
{
    return ((~l) == (~r));
}

//Pre:
/*
    ~ unary operator has to be defined for both l and r
    result type of unary operator must define ==
*/
template<typename t>
bool operator!=(const linearInterpolator<t>& l,
    const linearInterpolator<t>& r)
{
    return ((~l) != (~r));
}