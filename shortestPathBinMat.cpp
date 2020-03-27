#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define n 5
using namespace std;

bool isValid(int x, int y){
	if((x<n && x>=0) && (y<n && y>=0))
		return true;
	return false;
}

int main()
{
	int arr[][n]={
		{1,0,0,0,0},
		{0,1,1,0,0},
		{0,1,0,1,0},
		{1,0,0,1,0},
		{0,1,1,1,1}
	};


	bool visited[n][n];
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			visited[i][j] = false;
	int x=4,y=4;
	queue<pair<pair<int,int>,int>> q;
	q.push({{0,0},0});
	visited[0][0] = true;

	int rownum[] = {0,0,1,-1,1,1,-1,-1};
	int colnum[] = {1,-1,0,0,1,-1,-1,1};
	int a,b,dist;
	bool done = false;
	while(!q.empty() && !done){
		a = q.front().first.first;
		b = q.front().first.second;
		dist = q.front().second;
		q.pop();
		for(int i=0 ; i<8 ; i++){
			if(isValid(a+rownum[i], b+colnum[i]) && arr[a+rownum[i]][b+colnum[i]] && !visited[a+rownum[i]][b+colnum[i]]){
				if(a+rownum[i]==x && b+colnum[i]==y){
					cout << dist+1 << endl;
					done = true;
					break;
				}
				q.push({{a+rownum[i],b+colnum[i]},dist+1});
				visited[a+rownum[i]][b+colnum[i]] = true;
			}
		}
	}

	return 0;
}