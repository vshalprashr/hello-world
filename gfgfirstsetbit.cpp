#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		unsigned long long n;
		int x=1;
		cin >> n;
		while((n&(1<<(x-1))) != 1){
			x++;
		}
		cout << x << endl;
	}
	return 0;
}