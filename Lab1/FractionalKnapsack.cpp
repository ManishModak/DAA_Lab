#include <bits/stdc++.h>
using namespace std ;

struct Item 
{
	double value ;
	double weight ;
};

bool comparator(Item A, Item B)
{
	double ratio1 = (double)A.value/(double)A.weight ;
	double ratio2 = (double)B.value/(double)B.weight ;
	return ratio1 > ratio2 ;
};

int knapSack(Item data[], int size, int maxWeight)
{
	sort(data,data+size,comparator);

	double maxValue = 0.0 ;

	for(int i = 0 ; i < size ; i++)
	{
		if(data[i].weight < maxWeight)
		{
			maxWeight -=  data[i].weight ;
			maxValue += data[i].value ;
		}
		else
		{
			maxValue += data[i].value*(maxWeight/data[i].weight) ;
		}
	}

	return maxValue ;
}

int main()
{
	Item data[] = {{100, 20}, {60, 10}, {120, 30}} ;

	int n = sizeof(data)/sizeof(data[0]) ;

	int maxWeight = 50 ;
	
	int maxValue = knapSack(data,n,maxWeight) ;
	
	cout << "maxValue: " << maxValue ;
	
	return 0 ;
}
