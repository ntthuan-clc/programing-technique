#include <iostream>

using namespace std;
struct Queue {
	int* arrData;
  int _front;
  int _rear;
  int capacity;
  
  Queue(){
  arrData = (int*)malloc(sizeof(int));
  _front = -1;
  _rear = -1;
  capacity = 0;
  }
  
  Queue(int _capacity){
  	arrData = (int*)malloc(sizeof(int)*_capacity);
    _front = -1;
    _rear = -1;
    capacity = _capacity;
  }
  void enQueue(int data);
  void deQueue();
  int front();
  int size();
  bool isEmpty();
};

void Queue::enQueue(int data){
	if(_rear >= capacity - 1){
  	cout << "Queue overflow !!!";
    return;
  }
	if (_front == -1){
  	_front++; 
    _rear++;
  	arrData[_front] = data;
    return;
  }
  _rear++;
  arrData[_rear] = data;
}

bool Queue::isEmpty(){
  if(_rear < _front){
  	return true;
  }
  return false;
}

void Queue::deQueue(){
    if(_front >= capacity - 1){
  	cout << "Queue underflow!!!";
    return;
  }
  if(this->isEmpty()){
  	cout << "Empty";
  	return;
  }
  _front++;
}

int Queue::size(){
	return (_rear - _front) + 1;
}

int Queue::front(){
	if(_front != -1){
  	return arrData[_front];
  }
  return -100000;
}

int main() {
	Queue que(5);
  que.enQueue(1);
  que.enQueue(2);
  que.enQueue(3);
  que.enQueue(4);

  while (!que.isEmpty()) {
        cout << que.front() << ' ';
        que.deQueue();
  }
  return 0;
}
