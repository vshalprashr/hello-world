#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *left,*right;
	Node(int x){
		this->data = x;
		this->left = NULL;
		this->right = NULL;
	}
};

class binaryTree{
	Node *root;
public:
	binaryTree(){
		this->root = NULL;
	}
	void fill(){
		fill(root);
	}
	void fill(Node* node){
		int x;
		if(node == NULL){
			cout << "Enter root value: ";
			cin >> x;
			root = new Node(x);
			node = root;
		}

		cout << node->data << "'s left child: ";
		cin >> x;
		if(x!=-1){
			node->left = new Node(x);
			fill(node->left);
		}

		cout << node->data << "'s right child: ";
		cin >> x;
		if(x!=-1){
			node->right = new Node(x);
			fill(node->right);
		}
	}

	void getPointers(Node *node, Node **first, Node **middle, Node **last, Node **prev){
		if(node == NULL)
			return;
		getPointers(node->left,first,middle,last,prev);
		if((*prev) && (*prev)->data > node->data){
			if(!(*first)){
				*first = *prev;
				*middle = node;
			}
			else{
				*last = node;
			}
		}
		*prev = node;
		getPointers(node->right,first,middle,last,prev);
	}

	void correctBST(){
		if(root == NULL)
			return;
		Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;
		getPointers(root,&first,&middle,&last,&prev);
		if(first && last){
			int x = first->data;
			first->data = last->data;
			last->data = x;
		}
		else if(middle){
			int x = first->data;
			first->data = middle->data;
			middle->data = x;
		}
		inorder(root);
	}
	void inorder(Node* node){
		if(node){
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}
};

int main(){
	binaryTree bt;
	bt.fill();
	bt.correctBST();
	return 0;
}