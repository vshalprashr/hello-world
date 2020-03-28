//find random triplet from array whose sum is equal to given k

#include <iostream>
using namespace std;

int binary(int *arr, int n, int sum){
	if(n<1)
		return -1;
	int i=0,j=n-1;
	while(i<=j){
		if(arr[(i+j)/2] == sum)
			return (i+j)/2;
		else if(arr[(i+j)/2] < sum)
			i = (i+j)/2 + 1;
		else
			j = (i+j)/2 - 1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n, sum, x;
	cin >> n >> sum;
	int *arr = new int[n];
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];
	sort(arr,arr+n);
	for(int i=0,j=n-1 ; i<j ; i++,j--){
		x = binary(arr, n, sum-(arr[i]+arr[j]));
		if(x!=-1){
			cout << "Result: " << arr[i] << " " << arr[j] << " " << x << endl;
			break;
		}
	}
	cout << "No Result Found!" << endl;
	return 0;
}