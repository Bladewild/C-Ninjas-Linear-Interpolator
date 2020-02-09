

template<typename t>
linearInterpolator< t >::linearInterpolator()
{
	cout << endl << "Creating linearInterpolator" << endl;
	sizeOfPointVector = 20;
	cout << endl << "Default Size: "<< sizeOfPointVector;
}

template<typename t>
linearInterpolator< t >::linearInterpolator(const vector<tuple<t, t, t>>
	inputPoints)
{

	cout << endl << "Creating linearInterpolator" << endl;

	sizeOfPointVector = inputPoints.size();
	cout << endl << "Size: " << sizeOfPointVector;

	//creating vector of points
	for (int i = 0; i < sizeOfPointVector; i++)
	{
		float independent1, dependent1, dependent2;
		tie(independent1, dependent1, dependent2) = inputPoints[i];
		points.push_back(make_tuple(independent1, dependent1,
			dependent2));
	}

}

/*
Pre: 
*/
template<class t>
ostream& operator << (ostream& os, const linearInterpolator<t> & liObj)
{
	for (int i = 0; i < liObj.sizeOfPointVector; i++)
	{
		float independent1, dependent1, dependent2;
		tie(independent1, dependent1, dependent2) = liObj.points[i];
		os << independent1 << " " << dependent1 << " " << dependent2 << endl;
	}
	return os;
}
