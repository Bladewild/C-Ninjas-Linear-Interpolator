

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
    cout << endl << "Given Size: " << sizeOfPointVector;
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
        float independent1, dependent1, dependent2;
        tie(independent1, dependent1, dependent2) = inputPoints[i];
        points.push_back(make_tuple(independent1, dependent1,
            dependent2));
    }

}

template<typename t>
linearInterpolator<t>& linearInterpolator<t>::operator = (const linearInterpolator<t> & source)
{
    
    if (this == &source)
    {
        cout << "Prevent self assignment" << endl;
    }
    else
    {
        setSize(source.sizeOfPointVector);
        points = source.points;
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
        os << independent1 << " " << dependent1 << " " << dependent2 << endl;
    }
    return os;
}

template<typename t>
istream& operator >> (istream& finput, linearInterpolator<t>& liObj)
{
    //clears out entire vector
    //check for invalid range
    vector<tuple<t, t, t>> new_points;
    for (int i = 0; i < liObj.sizeOfPointVector; i++)
    {
        //change this to getline then check if extra points
        vector<float> temp_points;
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
        tuple<float, float, float> temp_tuple = make_tuple(temp_points[0],
            temp_points[1], temp_points[2]);
        new_points.push_back(temp_tuple);
    }
    liObj.points = new_points;
    return finput;
}

/*
template <typename t>
void readInput(ifstream& finput, int sizeofData, vector < tuple<t, t, t>>& source_emptypoints)
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
        //if (temp_points.size() != 3)
        //{
            //throw error
        //}
        tuple<float, float, float> temp_tuple = make_tuple(temp_points[0],
            temp_points[1], temp_points[2]);
        source_emptypoints.push_back(temp_tuple);
    }
}
*/