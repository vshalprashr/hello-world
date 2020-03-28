#include <iostream>
#include <map>
using namespace std;

long long C3(int n, int r=3) {
	if(n==0)
		return 0;
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
	int t, n;
	cin >> t;
	string required = "aeiou";
	string list_has[] = {
		"",
		"a",
		"e",
		"i",
		"o",
		"u",
		"ae",
		"ai",
		"ao",
		"au",
		"ei",
		"eo",
		"eu",
		"io",
		"iu",
		"ou",
		"aei",
		"aeo",
		"aeu",
		"aio",
		"aiu",
		"aou",
		"eio",
		"eiu",
		"eou",
		"iou",
		"aeio",
		"aeiu",
		"aeou",
		"aiou",
		"eiou",
		"aeiou"
	};
	while(t--){
		cin >> n;
		
		map<char, bool> req;
		

		int map[32];
		for(int i=0 ; i<32 ; i++)
			map[i] = 0;
		string arr[n];
		for(int si=0 ; si<n ; si++){
			cin >> arr[si];

			req['a'] = false;
			req['e'] = false;
			req['i'] = false;
			req['o'] = false;
			req['u'] = false;
			for(int i=0 ; i<arr[si].length() ; i++){
				if(arr[si][i] == 'a')
					req['a'] = true;
				else if(arr[si][i] == 'e')
					req['e'] = true;
				else if(arr[si][i] == 'i')
					req['i'] = true;
				else if(arr[si][i] == 'o')
					req['o'] = true;
				else if(arr[si][i] == 'u')
					req['u'] = true;
			}
			for(int i=1 ; i<32 ; i++){
				int ctr=0;
				for(int j=0 ; j<list_has[i].length() ; j++){
					if(req[list_has[i][j]])
						ctr++;
					else
						break;
				}
				if(ctr==list_has[i].length()){
					map[i]++;
					//cout << list_has[i] << " : " << map[i] << endl;
				}
			}
		}
		int res=0;
		for(int i=1 ; i<32 ; i++){
			if(list_has[i].length()%2==0)
				res -= map[i];
			else
				res += map[i];
			//cout << list_has[i] << " " << map[i] << endl;
		}
		cout << "Result: " << C3(res) << endl;

	}	
	return 0;
}