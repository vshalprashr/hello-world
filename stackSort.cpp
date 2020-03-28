#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>* st, int x){
	if(!st->empty() && st->top()>x){
		int temp = st->top();
		st->pop();
		sortedInsert(st,x);
		st->push(temp);
	}
	else{
		st->push(x);
	}
}

void reverse(stack<int>* st){
	if(!st->empty()){
		int x = st->top();
		st->pop();
		reverse(st);
		sortedInsert(st,x);
	}
}

int main()
{
	stack<int>* st = new stack<int>;
	st->push(7);
	st->push(4);
	st->push(56);
	st->push(13);
	st->push(1);
	st->push(9);
	
	reverse(st);
	while(!st->empty()){
		cout << st->top() << " ";
		st->pop();
	}

	return 0;
}