#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
	cout << "Enter Num Of Vertices and Snake and Ladder: ";
	int V;	cin >> V;
	int S;	cin >> S;
	int L;	cin >> L;
	
	unordered_map<int,int> snake;
	unordered_map<int,int> ladder;
	
	int x,y;
	cout << "Enter Snakes:\n";
	for(int i=0 ; i<S ; i++){
		cin >> x >> y;
		snake[x]=y;
	}
	cout << "Enter Ladders:\n";
	for(int i=0 ; i<L ; i++){
		cin >> x >> y;
		ladder[x]=y;
	}
	
	string moves;
	queue<pair<int,string>> q;
	q.push({1,""});
	while(!q.empty()){
		x = q.front().first;
		moves = q.front().second;
		q.pop();
		if(x==V){
			cout << "Reached through " << moves << endl;
			break;
		}
		for(int i=1 ; i<7 ; i++){
			if(snake.find(x+i) != snake.end()){
				q.push({snake[x+i],moves+to_string(x+i)+"-"});
			}
			else if(ladder.find(x+i) != ladder.end()){
				q.push({ladder[x+i],moves+to_string(x+i)+"-"});
			}
			else
				q.push({x+i,moves+to_string(x+i)+"-"});
		}
	}

	return 0;
}