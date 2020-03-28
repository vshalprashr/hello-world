#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	long long num, x, y;
	vector<int> v(10,0);
	while(t--){
		fill(v.begin(), v.end(), 0);
		y=0;
		cin >> num;
		x = num;
		while(x!=0){
			v[(x%10)]++;
			x /= 10;
		}
		for(long long i=9 ; i>=0 ; i--){
			for(int j=0 ; j<v[i] ; j++){
				x = (x*10)+i;
			}
			for(int j=0 ; j<v[9-i] ; j++){
				y = (y*10)+(9-i);
			}
		}
		if(x-num > num-y){
			cout << x-num << endl;
		}
		else
			cout << num-y << endl;

	}
	return 0;
}