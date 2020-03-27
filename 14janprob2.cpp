#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	cin >> arr[0] >> arr[1];
	int ctr = 0, req = 0, x, y;

	int i;
	for(i=0 ; req < 2 && i<n ; i++){
		cin >> arr[i];
		if(arr[i] == req){
			req++;
		}
		else{
			ctr++;
		}
		cout << ctr << " ";
	}

	x = 0;
	y = 1;
	req = x+y;

	for(; i<n ; i++){
		cin >> arr[i];
		if(arr[i] == req){
			x = y;
			y = req;
			req = x+y;
		}
		else{
			ctr++;
		}
		cout << ctr << " ";
	}
	cout << "Result: " << ctr << endl;

	return 0;
}