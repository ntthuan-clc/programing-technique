#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* pNext;
    Node(){
        this->data = 0;
        this->pNext = nullptr;
    } 
    Node(int data){
        this->data = data;
        this->pNext = nullptr;
    }
};

struct Stack {
    Node* pHead; // head;
    Stack(){
        this->pHead = nullptr;
    }
    void push(int data);
    int top(); // get top but dont remove top
    void pop(); // remove top
    int size(); // get size of stack
    bool isEmpty(); // return true if stack is empty
};

int Stack::top(){
    if(pHead == nullptr){
        return INT_MAX;
    }
    return pHead->data;
}

void Stack::pop(){
    if(pHead == nullptr){
        return;
    }
    Node* pTemp = pHead;
    pHead = pHead->pNext;
    delete pTemp;
    pTemp = nullptr;
}

bool Stack::isEmpty(){
    if(pHead == nullptr){
        return true;
    }
    return false;
}

void Stack::push(int data){
    Node* pNode = new Node(data);
    if(pHead == nullptr){
        pHead = pNode;
        return;
    }
    pNode->pNext = pHead;
    pHead = pNode;
}

void convertDecToBin(int n){
    Stack answer;
    while (n != 0)
    {
        int mod = n%2;
        n = n / 2;
        answer.push(mod);
    }
    while (!answer.isEmpty())
    {
        cout << answer.top();
        answer.pop();
    }
}

int main(){
    int n = 154;
    convertDecToBin(n);
    return 0;
}