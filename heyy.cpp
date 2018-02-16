#include<iostream>
#include<string.h>
using namespace std;
class publication
{
	protected:
	char title[200];
	float price;
};
class book : public publication
{
	int pgcount;
public:
	void getdata(char a[51200], float p, int c)
	{
		for(int i=0 ; i<strlen(a) ; i++)
			title[i]=a[i];
		price=p;
		pgcount=c;
	}
	void putdata()
	{
		cout<<"Title: "<<title<<"\nPrice: "<<price<<"\nNo. of pages: "<<pgcount<<endl;
	}
};
class tape : public publication
{
	float dur;
public:
	void getdata(char a[51200], float p, float c)
	{
		for(int i=0 ; i<strlen(a) ; i++)
			title[i]=a[i];
		price=p;
		dur=c;
	}
	void putdata()
	{
		cout<<"Title: "<<title<<"\nPrice: "<<price<<"\nDuration: "<<dur<<endl;
	}
};
int main()
{
	book b;
	tape t;
	char a[]="The book you don't own", c[]="The tape you can't afford";
	b.getdata(a, 516.5657, 214);
	b.putdata();
	t.getdata(c, 723682.5657, 624);
	t.putdata();
	return 0;
}
