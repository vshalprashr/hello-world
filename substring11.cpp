#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int ctr=0;
	for(int i=0 ; i<s.length() ; i++)
		if(s[i]=='1')	ctr++;
	int res=--ctr;
	while(ctr>1){
		res += --ctr;
	}
	cout << res << endl;
	return 0;
}