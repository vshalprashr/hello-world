#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

int V,E;

unordered_set<int> res;

void dfs(bool* visited, vector<int>* adj, int curr, int L, int parent){
	visited[curr] = true;
	for(int i=0 ; i<adj[curr].size() ; i++){
		if(!visited[adj[curr].at(i)]){
			dfs(visited,adj,adj[curr].at(i),L-1, parent);
		}
		if(L==1 && adj[curr].at(i)==parent){
			int num=0;
			for(int j=V-1 ; j>=0 ; j--)
				if(visited[j]){
					num = num*10 + j;
				}
			res.insert(num);
			cout << "\tDone " << parent << endl;
		}
	}
	visited[curr] = false;
}

int main()
{
	cin >> V >> E;
	vector<int> *adj = new vector<int>[V];
	int x,y;
	for(int i=0 ; i<E ; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int L,ctr=0; cin >> L;
	for(int i=0 ; i<V ; i++){
		bool *visited = new bool[V];
		memset(visited,false,V);
		cout << "Iter " << i << endl;
		dfs(visited,adj,i,L,i);
	}
	for(auto i:res)
		cout << i << " ";
	cout << endl;
	return 0;
}