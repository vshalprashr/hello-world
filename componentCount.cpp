#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isValid(int x, int y, int n){
	if((x<n && x>=0) && (y<n && y>=0))
		return true;
	return false;
}

int componentCount(int adj[][7], int n){
	int res=0, x;
	stack<int> st;
	bool visited[n];
	memset(visited, false, n);
	for(int i=0 ; i<n ; i++){
		if(!visited[i]){
			res++;
			st.push(i);
			visited[i] = true;
			while(!st.empty()){
				x = st.top();
				st.pop();
				for(int j=0 ; j<n ; j++){
					if(adj[x][j] && !visited[j]){
						st.push(j);
						visited[j] = true;
					}
				}
			}
		}
	}
	return res;
}

int main()
{
	int n=7;
	int arr[][7]={
		{0,1,1,0,0,0,0},
		{1,0,0,1,1,0,0},
		{1,0,0,0,0,1,1},
		{0,1,0,0,0,0,0},
		{0,1,0,0,0,0,0},
		{0,0,1,0,0,0,0},
		{0,0,1,0,0,0,0}
	};

	cout << componentCount(arr,n) << endl;
	arr[3][1] = arr[1][3] = 0;
	cout << componentCount(arr,n) << endl;
	return 0;
}