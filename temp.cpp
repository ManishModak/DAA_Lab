#include<iostream>
using namespace std ;

struct Item 
{
	double value ;
	double weight ;
};

bool comparator(Item A, Item B)
{
	
};

int kanpSack(Item data[], int size, int maxWeight) 
{
	sort(data,data+size);
	return 0 ;
}

int main()
{
	Item data[] = {(100,40),(500,30),(50,50)} ;

	int n = sizeof(data)/sizeof(data[0]) ;

	int maxWeight = 50 ;
	
	int maxValue = kanpSack(data,n,maxWeight) ;
	
	cout << "maxValue :" << maxValue ;
	
	return 0 ;
}
