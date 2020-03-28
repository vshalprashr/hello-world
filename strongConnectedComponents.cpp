#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

void dfsI(int x, vector<int> *adj, stack<int> *timeOrder, bool* visited){
	visited[x] = true;
	for(auto i:adj[x]){
		if(!visited[i]){
			dfsI(i, adj, timeOrder, visited);
		}
	}
	timeOrder->push(x);
}

void dfsII(int x, vector<int> *adj, bool* visited){
	visited[x] = true;
	for(auto i:adj[x]){
		if(!visited[i]){
			dfsII(i, adj, visited);
			cout << i << " ";
		}
	}
}

int main(){
    int V,E,x,y; cin >> V >> E;
    vector<int> *adj = new vector<int>[V];
    vector<int> *revadj = new vector<int>[V];
    
    for(int i=0 ; i<E ; i++){
    	cin >> x >> y;
    	adj[x].push_back(y);
    	revadj[y].push_back(x);
    }
    bool *visited = new bool[V];
    stack<int> *timeOrder = new stack<int>;
    for(int i=0 ; i<V ; i++){
    	if(!visited[i]){
    		dfsI(i,adj,timeOrder,visited);
    	}
    }



    memset(visited,false,V);
    int ans=0;
    while(!timeOrder->empty()){
    	x = timeOrder->top();
    	timeOrder->pop();
    	if(!visited[x]){
	    	dfsII(x, revadj, visited);
    		ans++;
	    	cout << x << endl;
    	}
    }
    cout << "Result: " << ans << endl;
}