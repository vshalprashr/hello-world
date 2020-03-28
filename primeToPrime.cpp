#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

vector<int>* seiveOfEratosthenes(int n){
	vector<int> *res = new vector<int>();
	bool *result = new bool[n+1];
	memset(result, true, n);
	for(int i=2 ; i<=n ; i++){
		if(result[i]){
			for(int j=i ; i*j<=n ; j++)
				result[i*j] = false;
			if(i>999)
			res->push_back(i);
		}
	}
	return res;
}

bool check(int x, int y){
	int ten=10, ctr=0;

	for(int i=0 ; i<4 ; i++){
		if(x%10 != y%10)
			ctr++;
		x /= 10;
		y /= 10;
	}
	return (ctr == 1);
}
int main()
{
	vector<int> *prime = seiveOfEratosthenes(9999);
	
	vector<int> adj[10000];
	for(int i=0 ; i<prime->size() ; i++){
		for(int j=i ; j<prime->size() ; j++){
			if(check(prime->at(i),prime->at(j))){
				adj[prime->at(i)].push_back(prime->at(j));
				adj[prime->at(j)].push_back(prime->at(i));
			}

		}
	}
	int x,y;
	cin >> x >> y;
	string str;
	queue<pair<int,string>> q;
	q.push({x,""});
	while(!q.empty()){
		x = q.front().first;
		str = q.front().second;
		q.pop();
		str += to_string(x)+" ";
		if(x == y){
			cout << str << endl;
			break;
		}
		for(int i=0 ; i<adj[x].size() ; i++){
			q.push({adj[x][i],str});
		}
	}

	return 0;
}