#include <iostream>
#include <climits>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int x){
		this->data = x;
		this->left = NULL;
		this->right = NULL;
	}
};

struct info{
	int min, max, nodes;
	bool isBST;
};

int max(const int &x, const int &y){
	return x>y ? x:y;
}

info largestBST(Node* root){
	if(root == NULL){
		info res;
		res.isBST = true;
		res.min = -1;
		res.max = -1;
		res.nodes = -1;
		return res;
	}
	info res;
	info linfo = largestBST(root->left);
	info rinfo = largestBST(root->right);
	res.nodes = 1;
	res.min = root->data;
	res.max = root->data;

	bool lok=false, rok=false;
	if(linfo.nodes == -1 || linfo.max <= root->data){
		lok = true;
	}
	if(rinfo.nodes == -1 || rinfo.min >= root->data){
		rok = true;
	}
	res.isBST = false;
	if(linfo.isBST && rinfo.isBST){
		if(lok && rok){
			res.isBST = true;
		}
	}
	if(res.isBST){
		if(linfo.nodes != -1)
			res.nodes += linfo.nodes;
		if(rinfo.nodes != -1)
			res.nodes += rinfo.nodes;
	}
	else{
		res.nodes = max(linfo.nodes,rinfo.nodes);
	}

	if(linfo.nodes!=-1)
		res.min = linfo.min;
	if(rinfo.nodes!=-1)
		res.max = rinfo.max;
	cout << root->data << "\t" << res.isBST << " " << res.min << " " << res.max << " " << res.nodes << endl;
	return res;
}

int main()
{
	Node *root = new Node(50);
	root->left = new Node(30);
	root->right = new Node(60);
	root->left->left = new Node(5);
	root->left->right = new Node(20);
	root->right->left = new Node(45);
	root->right->right = new Node(70);
	root->right->right->left = new Node(65);
	root->right->right->right = new Node(80);
	
	info res = largestBST(root);
	cout << endl << res.isBST << " " << res.nodes << endl;

	return 0;
}