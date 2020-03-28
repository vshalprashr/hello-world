#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset<5> b(63);
	bitset<5> b2(2);

	hash<bitset<5>> hashfn;

	cout << b << " " << b2 << endl;
	cout << hashfn(b) << " " << hashfn(b2) << " " << typeof(hashfn(b2)) << endl;
	return 0;
}