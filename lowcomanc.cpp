#include <iostream>
using namespace std;

int lca(int* tree, int i, int n, int x, int y){
	if(i>n)
		return -1;
	int ans1 = lca(tree,i*2,n,x,y);
	int ans2 = lca(tree,(i*2)+1,n,x,y);
	if(tree[i]==x){
		if(ans1==2 || ans2==2){
			cout << "Result: " << tree[i] << endl;
			return 0;
		}
		return 1;
	}
	else if(tree[i]==y){
		if(ans1==1 || ans2==1){
			cout << "Result: " << tree[i] << endl;
			return 0;
		}
		return 2;
	}
	else if((ans1==1 && ans2==2) || (ans2==1 && ans1==2)){
		cout << "Result: " << tree[i] << endl;
		return 0;
	}
	else if(ans1==1)
		return 1;
	return ans2;
}

int main()
{
	int n,x,y;
	cin >> n;
	int* tree = new int[n+1];
	for(int i=0 ; i<n+1 ; i++){
		tree[i] = i;
	}
	cin >> x >> y;
	int res = lca(tree,1,n,x,y);
	return 0;
}