#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

//Returns all the bridge edges from given graph DONE

bool **adj;
int *res;

int dfs(int curr, int parent, int V, bool *visited, int *disc){
	visited[curr] = true;
	static int time = 0, cycle=1;
	disc[curr] = ++time;
	int result = -1, cres;
	for(int i=0 ; i<V ; i++){
		if(adj[curr][i]){
			if(!visited[i]){
				cres = dfs(i,curr,V,visited,disc);
				if(cres!=-1){
					res[curr] = cycle;
					if(curr != cres){
						if(result == -1 || result>cres)
							result = cres;
					}
					else{
						cycle++;
					}
				}
			}
			else if(i!=parent && disc[i]<disc[curr]){
				res[curr] = cycle;
				result = i;
			}
		}	
	}
	return result;
}

int main()
{
	static int V,E; cin >> V >> E;
	adj = new bool*[V];
	res = new int[V];
	memset(res,-1,V);
	for(int i=0 ; i<V ; i++){
		adj[i] = new bool[V];
		memset(adj[i],false,V);
	}

	int x,y;
	for(int i=0 ; i<E ; i++){
		cin >> x >> y;
		adj[x][y] = true;
		adj[y][x] = true;
	}

	bool *visited = new bool[V];
	memset(visited,false,V);
	int *disc = new int[V];
	memset(disc,5555,V);
	x = dfs(0,0,V,visited,disc);
	cout << x << endl;

	for(int i=0 ; i<V ; i++){
		for(int j=0 ; j<V ; j++)
			if(adj[i][j] && (res[i]!=res[j] || !res[i] || !res[j]))
				cout << i << " " << j << endl;
	}
	for(int i=0 ; i<V ; i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}