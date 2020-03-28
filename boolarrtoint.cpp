#include<iostream>
#include<bitset>
using namespace std;

int main(int argc, char const *argv[])
{
	bool arr[9] = {0,1,1,0,1,1,0,1,1,};
	int x = 0;
	for(int i=0 ; i<sizeof(arr)/sizeof(bool) ; i++)
		x |= (arr[i] << i);
	cout << ((bitset<9>)x<<1) << endl;
	return 0;
}