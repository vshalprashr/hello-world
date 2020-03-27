#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	int arr[n];
	int maxfin=0;
	int maxhere=0;
	for(int i=0 ; i<n ; i++){
		cin >> arr[i];
		maxhere = maxhere+arr[i];
		if(maxhere<0)
			maxhere = 0;
		if(maxfin<maxhere)
			maxfin = maxhere;
	}
	cout << maxfin << endl;
	//8
	//-2 -3 4 -1 -2 1 5 -3
	return 0;
}