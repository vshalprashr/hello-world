#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>
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


//BinaryTree() __constructor__
//fill() to input data into the tree
//insert(int/char) to insert elements in BST
//printPre() to print in PREORDER
//print() to print in INORDER
//printPost() to print in POSTORDER
//deleteTree() to delete the tree
//preorderToString() returns preorder traversal in string format
//toFile("__nameoffile__") writes preorder into file(overwrites, if already present)
//diameter() returns int diameter of the tree
//pairSum(int/char) prints the pair summing up to given target
//topView() prints top view of tree
//leftView() prints left view of tree
//rightView() prints right view of tree
//bottomView() prints bottom view of tree
//bottomLeftView() prints bottom left view of tree
//bottomRightView() prints bottom right view of tree
//isBalanced() returns boolean as tree balanced or not
//diagonalTraversal() prints diagonal traversal of tree
//leafCount() returns int, count of leaf nodes
//isMirror() returns boolean, true if tree is symmetrical
//levelTraversal() prints level order traversal
//zigzagTraversal() prints zigzag traversal
//spiralTraversal() prints spiral traversal
//inorderSuccessor(int/char) prints inorder successor of given number
//searchBST(int/char) returns reference, to the node being searched
template <typename T>
class BinaryTree{
	Node<T> *root;
	int height;
public:
	BinaryTree(){
		root = NULL;
	}

	//INSERTION AND FILLING METHODS
	void fill(){
		fill(root);
	}
	void fill(Node<T> *node){
		T x;
		if(node == NULL){
			cout << "Enter root value: ";
			cin >> x;
			if(x==-1 || x=='~'){
				return;
			}
			node = new Node<T>(x);
			root = node;
		}
		cout << "Enter " << node->data << "'s left child: ";
		cin >> x;
		if(x!=-1 && x!='~'){
			node->left = new Node<T>(x);
			fill(node->left);

		}
		cout << "Enter " << node->data << "'s right child: ";
		cin >> x;
		if(x!=-1 && x!='~'){
			node->right = new Node<T>(x);
			fill(node->right);
		}
	}
	void insert(T x){
		root = insert(root, x);
	}
	Node<T>* insert(Node<T> *node, T x){
		if(node == NULL){
			return new Node<T>(x);			
		}
		if(x<node->data)
			node->left = insert(node->left,x);
		else
			node->right = insert(node->right, x);
		return node;
	}

	//PRINTING METHODS
	void printPre(){
		printPre(root);
	}
	void printPre(Node<T> *node){
		if(node != NULL){
			cout << node->data << " ";
			printPre(node->left);
			printPre(node->right);
		}
	}
	void print(){
		print(root);
	}
	void print(Node<T> *node){
		if(node != NULL){
			print(node->left);
			cout << node->data << " ";
			print(node->right);
		}
	}
	void printPost(){
		printPost(root);
	}
	void printPost(Node<T> *node){
		if(node != NULL){
			printPost(node->left);
			printPost(node->right);
			cout << node->data << " ";
		}
	}

	//DELETE WHOLE TREE
	void deleteTree(){
		deleteTree(root);
	}
	void deleteTree(Node<T> *node){
		if(node != NULL){
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
	}

	//EXPORTING TO STRING OR FILE
	string preorderToString(){
		return preorderToString(root, "");
	}
	string preorderToString(Node<T> *node, string res){
		if(node != NULL){
			res.append(to_string(node->data));
			res.append(" ");
			res = preorderToString(node->left, res);
			res = preorderToString(node->right, res);
		}
		return res;
	}
	string postorderToString(){
		return postorderToString(root, "");
	}
	string postorderToString(Node<T> *node, string res){
		if(node != NULL){
			res = postorderToString(node->left, res);
			res = postorderToString(node->right, res);
			res.append(to_string(node->data));
			res.append(" ");
		}
		return res;
	}
	void toFile(const char* name){
		ofstream fout;
		string namewext = name;
		namewext += ".tree";
		fout.open(namewext);
		string line = preorderToString(root, "");
		fout << line << endl;
		cout << "Printed to file(" << name << "): " << line << endl;
	}

	//ALGORITHMS
	int diameter(){
		int *maxdia = new int[1];
		maxdia[0] = 0;
		int height = diameter(root,maxdia);
		return maxdia[0];
	}
	int diameter(Node<T> *node, int* maxdia){
		if(node==NULL)
			return 0;
		int x = diameter(node->left, maxdia);
		int y = diameter(node->right, maxdia);
		if(x+y+1>maxdia[0]){
			maxdia[0] = x+y+1;
		}

		if(x>y)
			return x+1;
		else
			return y+1;
	}
	bool isBalanced(){
		return (isBalanced(root)!=-1);
	}
	int isBalanced(Node<T> *node){
		if(node == NULL)
			return 0;
		int lh = isBalanced(node->left);
		int rh = isBalanced(node->right);
		if(lh==-1 || rh==-1 || abs(lh-rh)>1)
			return -1;
		return lh>rh?lh+1:rh+1;
	}
	void bottomLeftView(){
		unordered_map<int,int> *result = new unordered_map<int,int>;
		bottomLeftView(root,0,result);
		for(int i=0 ; i<result->size() ; i++){
			cout << result->at(i) << "\t";
			cout << endl;
		}
	}
	void bottomLeftView(Node<T> *node, int level, unordered_map<int,int> *result){
		if(node == NULL)
			return;
		//result->at(level).push_back(node->data);
		bottomLeftView(node->left, level, result);
		result->emplace(level,node->data);
		bottomLeftView(node->right, level+1, result);
	}
	void bottomRightView(){
		unordered_map<int,int> *result = new unordered_map<int,int>;
		bottomRightView(root,0,result);
		for(int i=0 ; i<result->size() ; i++){
			cout << result->at(i) << "\t";
			cout << endl;
		}
	}
	void bottomRightView(Node<T> *node, int level, unordered_map<int,int> *result){
		if(node == NULL)
			return;
		//result->at(level).push_back(node->data);
		bottomRightView(node->right, level, result);
		result->emplace(level,node->data);
		bottomRightView(node->left, level+1, result);
	}
	void diagonalTraversal(){
		unordered_map<int,vector<T>> *result = new unordered_map<int,vector<T>>;
		diagonalTraversal(root,0,result);
		for(int i=0 ; i<result->size() ; i++){
			for(int j=0 ; j<result->at(i).size() ; j++)
				cout << result->at(i).at(j) << "\t";
			cout << endl;
		}
	}
	void diagonalTraversal(Node<T> *node, int level, unordered_map<int,vector<T>> *result){
		if(node == NULL)
			return;
		if(result->find(level) == result->end())
			result->emplace(level,vector<T>());
		result->at(level).push_back(node->data);
		diagonalTraversal(node->left, level+1, result);
		diagonalTraversal(node->right, level, result);
	}
	int leafCount(){
		return leafCount(root);
	}
	int leafCount(Node<T> *node){
		if(node == NULL)
			return 0;
		int sum = leafCount(node->left) + leafCount(node->right);
		if(sum == 0)
			return 1;
		return sum;
	}
	bool isMirror(){
		return isMirror(root);
	}
	bool isMirror(Node<T> *node){
		if(node == NULL)
			return true;
		queue<Node<T>*> ql, qr;
		ql.push(node);
		qr.push(node);
		while(!ql.empty() && !qr.empty()){
			Node<T>* templ = ql.front();
			ql.pop();
			Node<T>* tempr = qr.front();
			qr.pop();
			if(templ != NULL && tempr != NULL){
				if(templ->data != tempr->data)
					return false;
				ql.push(templ->left);
				ql.push(templ->right);
				qr.push(tempr->right);
				qr.push(tempr->left);
			}
			else if(!(templ == NULL && tempr == NULL)){
				return false;
			}
		}
		if(ql.empty() && qr.empty())
			return true;
		return false;
	}

	void levelTraversal(){
		vector<vector<T>>* result = new vector<vector<T>>;
		levelTraversal(root, 0, result);
		for(int i=0 ; i<result->size() ; i++){
				for(int j=0 ; j<result->at(i).size() ; j++)
					cout << result->at(i).at(j) << "\t";
				cout << endl;
		}
	}
	void levelTraversal(Node<T> *node, int level, vector<vector<T>>* result){
		if(node == NULL)
			return;
		if(result->size() == level)
			result->push_back(vector<T>());
		result->at(level).push_back(node->data);
		levelTraversal(node->left, level+1, result);
		levelTraversal(node->right, level+1, result);
	}

	void zigzagTraversal(){
		vector<vector<T>>* result = new vector<vector<T>>;
		levelTraversal(root, 0, result);
		for(int i=0 ; i<result->size() ; i++){
			if(i%2==0){
				for(int j=0 ; j<result->at(i).size() ; j++)
					cout << result->at(i).at(j) << "\t";
				cout << endl;
			}
			else{
				for(int j=result->at(i).size()-1 ; j>=0 ; j--)
					cout << result->at(i).at(j) << "\t";
				cout << endl;
			}
		}
	}
	void spiralTraversal(){
		vector<vector<T>>* result = new vector<vector<T>>;
		levelTraversal(root, 0, result);
		for(int i=0,j=result->size()-1 ; i<=j ; i++,j--){
			for(int k=0 ; k<result->at(i).size() ; k++)
				cout << result->at(i).at(k) << "\t";
			cout << endl;
			if(i==j) break;
			for(int k=result->at(j).size()-1 ; k>=0 ; k--)
				cout << result->at(j).at(k) << "\t";
			cout << endl;
		}
	}
	void inorderSuccessor(T target){
		Node<T> *result=NULL;
		if(inorderSuccessor(root, &target, result) && result!=NULL){
			cout << result->data << endl;
		}
		else
			cout << -1 << endl;
	}
	bool inorderSuccessor(Node<T> *node, T* target, Node<T>* &result){
		if(node == NULL)
			return false;
		if(inorderSuccessor(node->right, target, result))
			return true;

		if(node->data == *target){
			return true;
		}
		result = node;

		if(inorderSuccessor(node->left, target, result))
			return true;
		return false;
	}
	void leftView(){
		unordered_map<int, T> *result = new unordered_map<int, T>();
		leftView(root,0,result);
		for(int i=0 ; i<result->size() ; i++){
			cout << result->at(i) << endl;
		}
	}
	void leftView(Node<T> *node, int level, unordered_map<int, T>* result){
		if(node == NULL)
			return;
		if(result->find(level) == result->end())
			result->emplace(level,node->data);
		result->at(level) = node->data;
		leftView(node->right, level+1, result);
		leftView(node->left, level+1, result);
	}
	void rightView(){
		unordered_map<int, T> *result = new unordered_map<int, T>();
		rightView(root,0,result);
		for(int i=0 ; i<result->size() ; i++){
			cout << result->at(i) << endl;
		}
	}
	void rightView(Node<T> *node, int level, unordered_map<int, T>* result){
		if(node == NULL)
			return;
		if(result->find(level) == result->end())
			result->emplace(level,node->data);
		result->at(level) = node->data;
		rightView(node->left, level+1, result);
		rightView(node->right, level+1, result);
	}
	void topView(){
		map<int, T> *result = new map<int, T>();
		topView(root,result);
		for(auto i=result->begin() ; i!=result->end() ; i++){
			cout << i->second << "\t";
		}
	}
	void topView(Node<T> *node, map<int, T>* result){
		if(node == NULL)
			return;

		queue<pair<Node<T>*,int>> q;
		q.push({node,0});
		Node<T> *curr;
		int level;
		while(!q.empty()){
			curr = q.front().first;
			level = q.front().second;
			q.pop();
			if(curr->left)
				q.push({curr->left,level-1});
			if(curr->right)
				q.push({curr->right,level+1});
			if(result->find(level) == result->end()){
				result->emplace(level,curr->data);
			}
		}
	}
	void bottomView(){
		map<int, T> *result = new map<int, T>();
		bottomView(root,0,result);
		for(auto i=result->begin() ; i!=result->end() ; i++){
			cout << i->second << "\t";
		}
	}
	void bottomView(Node<T> *node, map<int, T>* result){
		if(node == NULL)
			return;

		queue<pair<Node<T>*,int>> q;
		q.push({node,0});
		Node<T> *curr;
		int level;
		while(!q.empty()){
			curr = q.front().first;
			level = q.front().second;
			q.pop();
			if(curr->left)
				q.push({curr->left,level-1});
			if(curr->right)
				q.push({curr->right,level+1});
			if(result->find(level) == result->end()){
				result->emplace(level,curr->data);
			}
			result->at(level) = curr->data;
		}
	}

	void boundaryTraversal(){
		if(root == NULL) return;
		vector<T> final;
		Node<T> *temp = root;
		while(temp->left || temp->right){
			final.push_back(temp->data);
			if(temp->left) temp = temp->left;
			else temp = temp->right;
		}

		queue<Node<T>*> q;
		q.push(root);
		while(!q.empty()){
			temp = q.front();
			q.pop();
			if(!(temp->left) && !(temp->right))
				final.push_back(temp->data);
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}

		vector<T> rt;
		temp = root->right;
		while(temp->left || temp->right){
			rt.push_back(temp->data);
			if(temp->right) temp = temp->right;
			else temp = temp->left;
		}
		reverse(rt.begin(), rt.end());
		for(auto i:final)
			cout << i << " ";
		for(auto i:rt)
			cout << i << " ";
		cout << endl;
	}

	Node<T>* searchBST(T x){
		return searchBST(root, x);
	}
	Node<T>* searchBST(Node<T> *node, T x){
		if(node == NULL)
			return new Node<T>(-1);
		if(x == node->data)
			return node;
		if(x < node->data)
			return searchBST(node->left, x);
		else
			return searchBST(node->right, x);
	}
	void pairSum(T sum){
		pairSum(root, sum);
	}
	void pairSum(Node<T> *node, T sum){
		if(node == NULL)
			return;
		Node<T> *temp = NULL;
		queue<Node<T>*> q;
		q.push(node);
		while(!q.empty()){
			temp = q.front();
			q.pop();
			Node<T>* res = searchBST(root, sum-(temp->data));
			if(res != temp && res->data!=-1){
				cout << temp->data << " " << res->data << endl;
				return;
			}
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		cout << "No such pair!" << endl;
	}
};