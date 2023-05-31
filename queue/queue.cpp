#include <iostream>

using namespace std;
struct Node{
	int data;
  Node* pNext;
  Node(){
  	this->data = INT_MAX;
    this->pNext = nullptr;
  }
  //create node have data
  Node(int data){
  	this->data = data;
    this->pNext = nullptr;
  }
};

struct Queue {
	Node* _front;
  void enQueue(int data);
  void deQueue();
  int front();
  int size();
  bool isEmpty();
};

//enQueue = insert
void Queue::enQueue(int data){
    Node* pNode = new Node(data);
    if(_front == nullptr){
  	    _front = pNode;
        return;
     }
    Node* pTemp = _front;
    while(pTemp->pNext){
      	pTemp = pTemp -> pNext;
    }
      pTemp->pNext = pNode;
}

//deQueue = delete
void Queue::deQueue(){
	if(_front == nullptr){
  	return;
  }
	Node* pTemp = _front;
  _front = _front->pNext;
  delete pTemp;
  pTemp = nullptr;
}

int Queue::front(){
	if(_front == nullptr){
  	return INT_MAX;
  }
	return _front->data;
}

int Queue::size(){
	int count = 0;
  if(_front == nullptr){
  	return count;
  }
  Node* pTemp = _front;
  while (pTemp){
  	pTemp = pTemp->pNext;
    count++;
  }
  return count;
}

bool Queue::isEmpty(){
	if(_front == nullptr){
  	return true;
  }
  return false;
}


int main() {
    Queue qe;
  qe.enQueue(10);
  qe.enQueue(20);
  qe.enQueue(30);
    
   while(!qe.isEmpty()) {
       cout << qe.front() << ' ';
       qe.deQueue();
   }
  
	return 0;
}
