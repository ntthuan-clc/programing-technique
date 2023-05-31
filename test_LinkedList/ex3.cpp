#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node* pNext;
    Node(){
        this->data = 0;
        this->pNext = nullptr;
    } 
    Node(char data){
        this->data = data;
        this->pNext = nullptr;
    }
};

struct Stack {
    Node* pHead; // head;
    Stack(){
        this->pHead = nullptr;
    }
    void push(char data);
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

void Stack::push(char data){
    Node* pNode = new Node(data);
    if(pHead == nullptr){
        pHead = pNode;
        return;
    }
    pNode->pNext = pHead;
    pHead = pNode;
}

void isValidBracket(string seq){
    Stack bracket;
    for(int i = 0; i < seq.size(); ++i){
        if(seq[i] == '(' || seq[i] == '{' || seq[i] == '[' || bracket.isEmpty()){
            bracket.push(seq[i]);
        }
        else{
            char top = bracket.top();
            bracket.pop();
            if(top == '{' && seq[i] != '}'){
                cout << "False";
                return;
            }
            if(top == '[' && seq[i] != ']'){
                cout << "False";
                return;
            }
            if(top == '(' && seq[i] != ')'){
                cout << "False";
                return;
            }
        }
    }
    if(!bracket.isEmpty()){
        cout << "False";
        return;
    }
    cout << "True";
    
}

int main(){
    string seq = "[{}[]])";
    isValidBracket(seq);
    return 0;
}