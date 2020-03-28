// find number of pairs in all subarrays that are maximum and second maximum.
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int n=8;
	//cin >> n;
	int arr[n]={4,2,3,8,6,7,9,15};
	//for(int i=0 ; i<n ; i++){
	//	cin >> arr[i];
	//}

	stack<int> s;
	int res[n] = {0};
	for(int i=0 ; i<n ; i++){
		while(!s.empty() && arr[i]>arr[s.top()]){
			res[s.top()] = 1;
			s.pop();
		}
		s.push(i);
	}
	stack<int> st;
	int rest[n] = {0};
	for(int i=n-1 ; i>=0 ; i--){
		while(!st.empty() && arr[i]>arr[st.top()]){
			rest[st.top()] = 1;
			st.pop();
		}
		st.push(i);
	}

	cout << "Result: \n";
	int totalPairs=0;
	for(int i=0 ; i<n ; i++){
		cout << arr[i] << " " << res[i] << " " << rest[i] << endl;
		totalPairs += res[i]+rest[i];
	}

	cout << endl;

	return 0;
}