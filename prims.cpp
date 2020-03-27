#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

//prims not done


bool isValid(int x, int y, int n){
	if((x<n && x>=0) && (y<n && y>=0))
		return true;
	return false;
}

bool comp(pair<pair<int,int>,int> x, pair<pair<int,int>,int> y){
	return (x.second<=y.second);
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

	vector<int> dist(n);
	for(int i=0 ; i<n ; i++)
		dist.at(i) = INT_MAX;
	dist.at(0) = 0;
	make_heap(dist.begin(), dist.end());
	int x;
	for(int i=0 ; i<n-1 ;){
		x = dist.front();
		pop_heap(dist.begin(), dist.end());
		dist.pop_back();
	}

	return 0;
}