#include <iostream>
#include <string>
using namespace std;

//Write a program that takes an input string that represents a base X number and
//convert it into a base Y number where X and Y range from 2 to 36. 

long long getNum(string s, int x, long long num){
	if(s.length()){
		long long val;
		if(s[0]<='9')
			val = s[0]-'0';
		else
			val = s[0]-'A'+10;
		//cout << val << endl;
		return getNum(s.substr(1),x,((num*x)+val));
	}
	else{
		return num;
	}
}

string getResult(long long num, int y){
	if(num>0){
		string res = getResult(num/y,y);
		string val;
		if(num%y <10){
			val = '0'+(num%y);
		}
		else{
			val = 'A'+((num%y)-10);
		}
		return res+val;
	}
	else{
		return "";
	}
}

int main()
{
	int x,y;	cin >> x >> y;
	string s;	cin >> s;
	long long num = getNum(s,x,0);
	cout << num << endl;
	cout << "Base " << y << ": " << getResult(num,y) << endl;
	return 0;
}