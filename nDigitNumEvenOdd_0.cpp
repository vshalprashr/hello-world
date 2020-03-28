#include <iostream>
using namespace std;

void result(int arr[], int index, int n, int sum){
	if(index>=n){
		if(sum==0){	for(int i=0 ; i<n ; i++) cout << arr[i];	cout << endl;}
		return;
	}
	int fact=1;
	if(index & 1){
		fact = -1;
	}
	for(int i=0 ; i<10 ; i++){
		arr[index] = i;
		result(arr,index+1,n,sum+(fact*i));
	}
}

int main()
{
	int n;	cin >> n;
	int arr[n];
	for(int i=1 ; i<10 ; i++){
		arr[0]=i;
		result(arr,1,n,i);
	}
	return 0;
}