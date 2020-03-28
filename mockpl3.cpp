#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
	int n;
	long long temp;
	cin >> n;
	long long arr[n];
	for(int i=0 ; i<n ; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	long long sum=0;
	//long long x=1;
	for(int i=n-1 ; i>=0 ; i--){
		sum = (sum*2) + arr[i];
	}
	cout << sum << endl;

	return 0;
}