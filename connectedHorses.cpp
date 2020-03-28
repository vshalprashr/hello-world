#include <iostream>
#include <stack>
#include <cstring>
#define ll long long int
using namespace std;

bool isValid(const int &x, const int &y, const int& n, const int &m){
	return (x>=0 && x<n && y>=0 && y<m);
}

int main()
{
    int t; cin >> t;
    while(t--){
    	int N,M,Q,x,y; cin >> N >> M >> Q;
    	bool adj[N][M];
    	memset(adj,false,N*M);
    	for(int i=0 ; i<Q ; i++){
    		cin >> x >> y;
    		adj[--x][--y] = true;
    	}
    	ll ans=1;
    	int move[][8] = {{2,2,-2,-2,1,-1,1,-1},//x
    				{1,-1,1,-1,2,2,-2,-2}};//y
    
    	bool visited[N][M];
    	memset(visited,false,N*M);
    	stack<pair<int,int>> st;
    	for(int i=0 ; i<N ; i++){
    		for(int j=0 ; j<M ; j++){
    			if(adj[i][j] && !visited[i][j]){
    				//cout << "DFS " << i << " " << j << endl;
    				st.push({i,j});
    				visited[i][j] = true;
    				ll ctr=0;
    				while(!st.empty()){
    					x = st.top().first;
    					y = st.top().second;
    					//cout << "\t" << x << " " << y << endl;
    					st.pop();
    					for(int k=0 ; k<8 ; k++){
    						if(isValid(x+move[0][k],y+move[1][k],N,M) && adj[x+move[0][k]][y+move[1][k]] && !visited[x+move[0][k]][y+move[1][k]]){
    							st.push({x+move[0][k], y+move[1][k]});
    							visited[x+move[0][k]][y+move[1][k]] = true;
    						}
    					}
    					ctr++;
    				}
    				while(ctr>1){
    					ans *= ctr;
    					ans = ans%1000000007;
    					ctr--;
    				}
    			}
    		}
    	}
    	cout << ans << endl;
    }
	return 0;
}