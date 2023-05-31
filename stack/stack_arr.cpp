// build stack as a array
#include <iostream>
using namespace std;

struct Stack {
	int* arrData; // dynamic array
	int _top; // index of top element  in arrData
  int capacity; // threshold of stack
  
  Stack() {
  	arrData = (int*)malloc(sizeof(int));
    _top = -1;
    capacity = 0;
  }
  
  Stack(int _capacity) {
    arrData = (int*)malloc(sizeof(int) * _capacity);
    _top = -1;
    capacity = _capacity;
  }
  
  void push(int data);
  int top();  // get top but dont remove top
  void pop(); // remove top
	
  int size();     // get size of stack
  bool isEmpty(); // return true if stack is empty
};

int Stack::top(){
	if(_top != -1){
  	return arrData[_top];
  }
  return -100000;
}

void Stack::pop(){
	if(_top == -1){
  	cout << "stack underflow !!!\n";
  	return;
  }
  _top--;
}

int Stack::size(){
	return _top + 1;
}

bool Stack::isEmpty(){
	if(_top == -1){
  	return true;
  }
  return false;
}

void Stack::push(int data){
	if(_top >= capacity - 1){
  	cout << "stack overflow !!!\n";
    return;
  }
  _top++;
  arrData[_top] = data;
}

int main() {
	Stack st;
	st.push(10);
  st.push(20);
  st.push(30);
  
  while (!st.isEmpty()) {
  	cout << st.top() << ' ';
    st.pop();
  }
  
	return 0;
}