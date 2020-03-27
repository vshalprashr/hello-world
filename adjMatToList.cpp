#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	bool arr[][6] = {
		{0,1,1,0,0,0},
		{1,0,0,1,1,0},
		{1,0,0,0,1,0},
		{0,1,0,0,1,1},
		{0,1,1,1,0,1},
		{0,0,0,1,1,0}
	};

	Node<Node<int>*>* ll = NULL;
	Node<Node<int>*>* temp = NULL;

	for(int i=0 ; i<6 ; i++){
		if(i==0)
			temp = new Node<Node<int>*>(new Node<int>(-1));
		else{
			temp->next = new Node<Node<int>*>(new Node<int>(-1));
			temp = temp->next;
		}
		Node<int>* list = temp->data;
		for(int j=0 ; j<6 ; j++){
			if(arr[i][j]){
				list->next = new Node<int>(j);
				list = list->next;
			}
		}
		if(ll == NULL)
			ll = temp;
		list = temp->data;
		while(list!=NULL){
			cout << list->data << " ";
			list = list->next;
		}
		cout << endl;
	}

	//cout << "Pair summing to 15: ";
	//bt.pairSum(15);
	//cout << "Pair summing to 20: ";
	//bt.pairSum(20);
	return 0;
}