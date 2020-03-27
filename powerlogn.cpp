#include<iostream>
using namespace std;

double getpow(double x, long long int p) {
	if(p==1)
		return x;
	double res = getpow(x,p/2);
	if(p%2==0) {
		return res*res;
	}
	return x*res*res;
}

int main() {
	double x;
	long long int p;
	cin >> x >> p;
	cout << "\nResult: " << getpow(x,p) << endl;
	return 0;
}