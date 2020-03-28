#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValid(int x, int y){
	if(x>=0 && x<5 && y>=0 && y<4)
		return true;
	return false;
}

int main()
{
	int jug1=0, jug2=0, target=2, size1=4, size2=3;
	int x,y,mxsize = max(size1,size2);
	bool done=false;

	vector<pair<int,int>> path;

	bool visited[size1+1][size2+1];
	for(int i=0 ; i<=size1 ; i++)
		for(int j=0 ; j<=size2 ; j++)
			visited[i][j] = false;
	queue<pair<int,int>> q;
	
	q.push({jug1,jug2});
	visited[jug1][jug2] = true;

	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();

		path.push_back({x,y});

		if(x==target){
			cout << "Reached (" << target << ",0)!" << endl;
			path.push_back({target,0});
			done = true;
			break;
		}
		else if(y==target){
			cout << "Reached (0," << target << ")!" << endl;
			path.push_back({0,target});
			done = true;
			break;
		}

		if(!visited[x][0]){
			q.push({x,0});
			visited[x][0] = true;
		}
		if(!visited[0][y]){
			q.push({0,y});
			visited[0][y] = true;
		}

		if(isValid(x+y,0) && !visited[x+y][0]){
			q.push({x+y,0});
			visited[x+y][0] = true;
		}
		if(isValid(0,x+y) && !visited[0][x+y]){
			q.push({0,x+y});
			visited[0][x+y] = true;
		}

		if(isValid(x-(size2-y),size2) && !visited[x-(size2-y)][size2]){
			q.push({x-(size2-y),size2});
			visited[x-(size2-y)][size2] = true;
		}
		if(isValid(size1,y-(size1-x)) && !visited[size1][y-(size1-x)]){
			q.push({size1,y-(size1-x)});
			visited[size1][y-(size1-x)] = true;
		}

		if(!visited[x][size2]){
			q.push({x,size2});
			visited[x][size2] = true;
		}
		if(!visited[size1][y]){
			q.push({size1,y});
			visited[size1][y] = true;
		}
	}
	if(done){
		cout << "Path:\n";
		for(int i=0 ; i<path.size() ; i++)
			cout << "(" << path.at(i).first << "," << path.at(i).second << ")" << endl;
	}
	return 0;
}