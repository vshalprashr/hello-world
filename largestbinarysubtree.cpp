//INCOMPLETE
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

class tree{
	Node* root=NULL;
public:
	void add(int parent, int data){
		if(root == NULL){
			root = new Node;
			root->data = data;
			root->left = NULL;
			root->right = NULL;
			return;
		}
		else if(root->data == parent){
			if(root->left == NULL){
				root->left = new Node;
				root->left->data = data;
				root->left->left = NULL;
				root->left->right = NULL;
			}
			else if(root->right == NULL){
				root->right = new Node;
				root->right->data = data;
				root->right->left = NULL;
				root->right->right = NULL;
			}
			return;
		}
		else{
			root->left->add(root->left, parent, data);
			root->right->add(root->right, parent, data);
		}
		return;
	}
	void print(Node* root){
		if(root != NULL){
			print(root->left);
			cout << root->data << endl;
			print(root->right);
		}
	}
};

int main(int argc, char const *argv[])
{
	int t,x,y;
	cin >> t;
	tree *tre = new tree;
	for(int i=0 ; i<t ; i++){
		cin >> x >> y;
		tre->add()
	}
	return 0;
}