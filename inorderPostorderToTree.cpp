#include <iostream>
#include <unordered_map>
using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node *left, *right;

	Node(T data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node<int>* construct(int *post, int n, unordered_map<int,int>* mp,int err){
	if(n<1)
		return NULL;
	Node<int>* root = new Node<int>(post[n-1]);
	cout << "Exec " << root->data << " " << n << " " << err << endl;
		root->left = construct(post,mp->at(root->data)-err,mp,err);
		root->right = construct(post+mp->at(root->data)-err,n-mp->at(root->data)-1+err,mp, mp->at(root->data)+1);
	return root;
}
void print(Node<int>* root){
	if(root==NULL)
		return;
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}

int main()
{
	//int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
	//4 8 2 5 1 6 3 7 
    //int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    //8 4 5 2 6 7 3 1 
    //int n = sizeof(in) / sizeof(in[0]);
	int n; cin >> n;
	int *in = new int[n],*post = new int[n];
	cout << "Enter Inorder: ";
	unordered_map<int,int> *mp = new unordered_map<int,int>;
	for(int i=0 ; i<n ; i++){
		cin >> in[i];
		mp->emplace(in[i],i);
	}
	cout << "Enter Postorder: ";
	for(int i=0 ; i<n ; i++)
		cin >> post[i];
	cout << "Enter DONE\n";
	Node<int> *root = construct(post,n,mp,0);
	cout << "Construct DONE\n";
	print(root);

	return 0;
}