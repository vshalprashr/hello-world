#include <iostream>
using namespace std;

int main()
{
	int sum; cin >> sum;
	int ans[sum+1];
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 3;
	ans[4] = 1;

	for(int i=5 ; i<=sum ; i++){
		ans[i] = i;
		for(int j=1 ; j*j<=i ; j++)
			if(ans[i] > ans[i-(j*j)]+1)
				ans[i] = 1+ans[i-(j*j)];
	}
	cout << ans[sum] << endl;
	return 0;
}