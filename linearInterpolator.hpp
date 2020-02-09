

template<typename t>
linearInterpolator< t >::linearInterpolator()
{
	cout << endl << "Creating linearInterpolator" << endl;
	setSize(20);
	cout << endl << "Default Size: "<< sizeOfPointVector;
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

template<typename U>
linearInterpolator<U>& linearInterpolator<U>::operator = (const linearInterpolator<U> & source)
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
*/
template<typename t>
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
