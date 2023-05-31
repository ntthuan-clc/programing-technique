#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* pNext;
    Node* pPrev;
    Node(){
        this->data = 0;
        this->pNext = nullptr;
        this->pPrev = nullptr;
    }
    Node(int data){
        this->data = data;
        this->pNext = nullptr;
        this->pPrev = nullptr;
    }
};

struct CList
{
    Node* pHead;
    CList(){
        this->pHead = nullptr;
    }
    void addTail(int data);
    void showList();
    void josephus(int n, int k);
};

//Ds lien ket vong
void CList::addTail(int data){
    Node* pNode = new Node(data); 
    if(pHead == nullptr){
        pHead = pNode;
        pHead->pNext = pHead;
        pHead->pPrev = pHead;
        return;
    }
    Node* pTemp = pHead;
    while (pTemp->pNext != pHead)
    {
        pTemp = pTemp->pNext;
    }
    pNode->pNext = pHead;
    pHead->pPrev = pNode;
    pTemp->pNext = pNode;
    pNode->pPrev = pTemp;
}

void CList::showList(){
    Node* pTemp = pHead;
    do
    {
        cout << pTemp->data << ' ';
        pTemp = pTemp->pNext;
    }
    while(pTemp != pHead);
}

void CList::josephus(int n, int k){
    for (int i = 1; i <= n; ++i){
        this->addTail(i);
    }
    Node* current = pHead;
    while (current->pNext != current)
    {
        for(int i = 1; i <= k - 1; ++i){
            current = current->pNext;
        }
        Node* pRemove = current;
        current = current->pNext;
        Node* pPrevRemove = pRemove->pPrev;
        Node* pNextRemove = pRemove->pNext;
        pPrevRemove->pNext = pNextRemove;
        pNextRemove->pPrev = pPrevRemove;
        delete pRemove;
        pRemove = nullptr;
    }
    cout << "Current data: " << current->data;
    
}

int main(){
    CList pList;
    //int n = 7, k = 3;
    //int n = 5, k = 3;
    int n = 5, k = 2;
    pList.josephus(n,k);
    return 0;
}