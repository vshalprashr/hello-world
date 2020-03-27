#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool isValid(int x, int y, int n){
	if((x<n && x>=0) && (y<n && y>=0))
		return true;
	return false;
}

bool comp(pair<pair<int,int>,int> x, pair<pair<int,int>,int> y){
	return (x.second<=y.second);
}

int find(int *parent, int x){
	while(parent[x]!=-1)
		x = parent[x];
	return x;
}

bool unionx(int* parent, int x, int y){
	int parx = find(parent, x), pary = find(parent, y);
	if(parx == pary)
		return false;
	parent[parx] = pary;
	return true;
}

int main()
{
	int n,e;
	cin >> n >> e;
	if(e<n){
		cout << "Not Possible!";
		return 0;
	}
	pair<pair<int,int>,int> edge[e];
	for(int i=0 ; i<e ; i++)
		cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second;
	sort(edge,edge+e,comp);

	int *parent = new int[n];
	for(int i=0 ; i<n ; i++)
		parent[i] = -1;

	cout << "SRC\tDEST\tweight" << endl;
	for(int i=0 ; i<e ; i++){
		if(unionx(parent, edge[i].first.first, edge[i].first.second)){
			cout << edge[i].first.first << "\t" << edge[i].first.second << "\t" << edge[i].second << endl;
		}
	}

	return 0;
}