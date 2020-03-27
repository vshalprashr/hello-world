#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

bool isValid(int x, int y, int n){
	if((x<n && x>=0) && (y<n && y>=0))
		return true;
	return false;
}

bool isTree(int adj[][7], int n){
	bool visited[n];
	for(auto i:visited)
		i = false;
	stack<pair<int,int>> st;
	st.push({0,-1});
	visited[0] = true;
	int x,parent;
	while(!st.empty()){
		x = st.top().first;
		parent = st.top().second;
		st.pop();
		for(int i=0 ; i<n ; i++){
			if(adj[x][i]){
				if(!visited[i]){
					st.push({i,x});
					visited[i] = true;
				}
				else if(i!=parent)
					return false;
			}
		}
	}
	for(int i=0 ; i<n ; i++)
		if(!visited[i])
			return false;
	return true;
}

int main()
{
	int n=7;
	int arr[][7]={
		{0,1,1,0,0,0,0},
		{1,0,0,1,1,0,0},
		{1,0,0,0,0,1,1},
		{0,1,0,0,1,0,0},
		{0,1,0,0,0,0,0},
		{0,0,1,0,0,0,0},
		{0,0,1,0,0,0,0}
	};

	cout << isTree(arr,n) << endl;
	return 0;
}