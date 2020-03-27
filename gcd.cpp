#include<iostream>
using namespace std;

int main() {
	long long int x, y;
	cin >> x >> y;
	while(x!=0 && y!=0 && x!=y) {
		x<y ? y-=x : x-=y;
	}
	if(x==0)
		cout << "GCD: " << y << endl;
	else
		cout << "GCD: " << x << endl;
}