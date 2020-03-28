#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];

	int pathx[n];
	int x,y;
	cin >> x >> y;
	int a=x,b=y;
	bool visited[n];
	for(int i=0 ; i<n ; i++){
		visited[i] = false;
		pathx[i] = -1;
	}
	int i=1;
	while(x!=-1 && !visited[x]){
		visited[x] = true;
		pathx[x] = i;
		x = arr[x];
		i++;
	}
	//for(int i=0 ; i<n ; i++)
	//	cout << pathx[i] << " ";
	//cout << endl;

	for(int i=0 ; i<n ; i++)
		visited[i] = false;
	i=1;
	int min = -1, mindist=0;
	while(y!=-1 && !visited[y]){
		visited[y] = true;
		if(pathx[y]!=-1 && (min==-1 || pathx[y]+i<pathx[min]+mindist)){
			min = y;
			mindist = i;
		}
		y = arr[y];
		i++;
	}
	cout << "Result: " << min << endl;

	return 0;
}