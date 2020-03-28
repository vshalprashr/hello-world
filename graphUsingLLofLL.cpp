#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
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
	return 0;
}