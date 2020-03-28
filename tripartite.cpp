#include <iostream>
#include <queue>
#include <cstring>
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

	int color[V];
	for(int i=0 ; i<V ; i++)
		color[i] = -1;

	queue<int> q;
	q.push(0);
	color[0] = 0;
	while(!q.empty()){
		x = q.front();
		q.pop();
		for (int j = 0; j < adj[x].size(); j++){
				if(color[adj[x][j]] == -1){
					q.push(adj[x][j]);
					color[adj[x][j]] = (color[x]+1)%3;
				}
				else if(color[adj[x][j]] == color[x]){
					cout << "Not Tripartite!" << endl;
					return 0;
				}
			}
	}
	for(int i=0 ; i<V ; i++)
		cout << color[i] << " ";
	cout << "Tripartite!" << endl;
	return 0;
}