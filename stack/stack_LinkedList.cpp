// Build stack as a LinkedList
#include <iostream>
using namespace std;

struct Node {
	int data;
  Node* pNext;
  
  Node() {
  	this->data = INT_MAX;
    this->pNext = nullptr;
  }
  
  Node(int data) {
  	this->data = data;
    this->pNext = nullptr;
  }
};

struct Stack {
	Node* top; // head;
	
  void push(int data);
  int top(); // get top but dont remove top
  void pop(); // remove top
  
  int size(); // get size of stack
  bool isEmpty(); // return true if stack is empty
};

int Stack::top(){
	if(top == nullptr){
  	return INT_MAX;
  }
	return top->data;
}

void Stack::pop(){
	if(top == nullptr){
  	return;
  }
  Node* pTemp = top;
  top = top->pNext;
  delete pTemp;
  pTemp = nullptr;
}

int Stack::size(){
	if(_top == nullptr){
  	return 0;
  }
  Node* pTemp = _top;
  int count = 0;
  while(pTemp){
  	pTemp = pTemp->pNext;
    count++;
  }
  return count;
}

int main() {
	Stack st;

	return 0;
}