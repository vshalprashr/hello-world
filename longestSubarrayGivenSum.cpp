#include <iostream>
using namespace std;

int main()
{
	int n, sum; cin >> n >> sum;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];
	int i=0, j=0, currSum=0, x=-1, y=-1;
	while(i<n && j<=n){
		if(currSum == sum){
			if(x==-1 || j-i > y-x){
				x = i;
				y = j;
			}
			currSum += arr[j];
			j++;
		}
		else if(currSum<sum){
			currSum += arr[j];
			j++;
		}
		else{
			currSum -= arr[i];
			i++;
		}
	}
	cout << x << " " << y << endl;
	while(x<y){
		cout << arr[x++] << " ";
	}
	cout << endl;
	return 0;
}