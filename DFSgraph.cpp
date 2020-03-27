#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include "LinkedList.h"
using namespace std;

int main()
{
	cout << "Enter Num Of Vertices and Edges: ";
	int V;	cin >> V;
	int E;	cin >> E;

	vector<int> *adj = new vector<int>[V];
	cout << "Enter Edges:\n";
	int x,y;
	for(int i=0 ; i<E ; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << "Enter source and destination: ";
	cin >> x >> y;
	stack<int> q;
	bool visited[V];
	int parent[V];
	vector<int> path;
	memset(parent,-1,V);
	memset(visited,false, V);

	q.push(x);
	visited[x] = true;
	bool done=false;
	while(!q.empty() && !done){
		x = q.top();
		cout << x << endl;
		q.pop();
		for(int i=0 ; i<adj[x].size() ; i++){
			if(!visited[adj[x].at(i)]){
				visited[adj[x].at(i)] = true;
				q.push(adj[x].at(i));
				parent[adj[x].at(i)] = x;
				if(adj[x].at(i)==y){
					path.push_back(y);
					done = true;
				}
			}
		}
	}
	if(done){
		x = y;
		while(parent[x]!=-1){
			x = parent[x];
			path.push_back(x);
		}
		cout << "Path: ";
		for(auto i:path)
			cout << i << " ";
		cout << endl;
	}
	else{
		cout << "No path exists!" << endl;
	}

	return 0;
}