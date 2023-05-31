#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* pNext;
    Node* pPrev;
    Node() {
        this->data = 0;
        this->pNext = nullptr;
        this->pPrev = nullptr;
    }
};

Node *createNode(int data)
{
    Node *rNode = new Node();
    rNode->data = data;
    rNode->pNext = nullptr;
    rNode->pPrev = nullptr;
    return rNode;
}

struct Doublylist
{
    Node* pHead;
    Doublylist(){
        this->pHead = nullptr;
    }
    void addHead(int data);
    void addTail(int data);
    int size();
    void insert(int data, int pos);
    int search(int data);
    void showList();
    int removeHead();
    int removeTail();
    int removePos(int pos);
    bool checkDuplicate(int data);
};

void Doublylist::addHead(int data){
    Node* pNode = createNode(data);
    if (this->pHead == nullptr){
        this->pHead = pNode;
        return;
    }
    pNode->pNext = pHead;
    this->pHead->pPrev = pNode;
    this->pHead = pNode;
}

void Doublylist::addTail(int data){
    Node* pNode = createNode(data);
    if (this->pHead == nullptr){
        this->pHead = pNode;
        return;
    }
    Node* pTemp = pHead;
    while (pTemp->pNext != nullptr)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNode;
    pNode->pPrev = pTemp;
    
}

void Doublylist::showList(){
    Node* pTemp = pHead;
    while (pTemp != nullptr)
    {
        cout << pTemp->data << " ";
        pTemp = pTemp->pNext;
    }
}

int Doublylist::size(){
    int count = 0;
    Node* pTemp = pHead;
    while (pTemp != nullptr)
    {
        pTemp = pTemp->pNext;
        count++;
    }
    return count;
}

void Doublylist::insert(int pos, int data){
    Node* pNode = createNode(data);
    if(pos == 0){
        this->addHead(data);
        return;
    }
    if(pos >= this->size()){
        this->addTail(data);
        return;
    }
    Node* pTemp = pHead;
    for(int i = 1; i < pos; ++i){
        pTemp = pTemp->pNext;
    }
    pNode->pNext = pTemp->pNext;
    pNode->pPrev = pTemp;
    pTemp->pNext = pNode;
    pNode->pNext->pPrev = pNode;
}

int Doublylist::search(int data)
{
    Node *pTemp = pHead;
    int pos = 0;
    while (pTemp != nullptr)
    {
        if (pTemp->data == data)
        {
            return pos;
        }
        pos++;
        pTemp = pTemp->pNext;
    }
    return -1;
}

int Doublylist::removeHead(){
    if(pHead == nullptr){
        return -1;
    }
    int rVal;
    Node* pTemp = pHead;
    rVal = pHead->data;
    pHead = pHead->pNext;
    pHead->pPrev->pNext = nullptr;
    pHead->pPrev = nullptr;
    delete pTemp;
    pTemp = nullptr;
    return rVal;
}
int Doublylist::removeTail(){
    if(pHead == nullptr){
        return -1;
    }
    int rVal;
    Node* pTemp = pHead;
    while (pTemp->pNext)
    {
        pTemp = pTemp->pNext;
    }
    Node* pPreRemove = pTemp->pPrev;
    pPreRemove->pNext = nullptr;
    rVal = pTemp->data;
    pTemp->pPrev = nullptr;
    delete pTemp;
    pTemp = nullptr;
    return rVal;
    
}

int Doublylist::removePos(int pos){
    if(pos == 0){
        return this->removeHead();
    }
    if(pos >= this->size() - 1){
       return this->removeTail();
    }
    
    Node* pRemove = pHead;
    
    for(int i = 1; i <= pos; ++i){
        pRemove = pRemove->pNext;
    }

    Node *pPrevRemove = pRemove->pPrev;
    Node *pNextRemove = pRemove->pNext;
    pPrevRemove->pNext = pNextRemove;
    pNextRemove->pPrev = pPrevRemove;
    int rVal = pRemove->data;
    pRemove->pPrev = nullptr;
    pRemove->pNext = nullptr;
    delete pRemove;
    pRemove = nullptr;
    cout << "test "
         << "\n";
    return rVal;
}

int main (){
    // Doublylist pList1;
    // pList1.addHead(10);
    // pList1.addHead(30);
    // pList1.addHead(50);
    // pList1.addHead(70);
    // pList1.addHead(90);
    // pList1.addHead(110);
    // pList1.showList(); 
    Doublylist pList2;
    pList2.addTail(20);
    pList2.addTail(40);
    pList2.addTail(60);
    pList2.insert(2,10);
    pList2.insert(2,70);
    cout << pList2.removeHead() << "\n";
    cout << pList2.removeTail() << "\n";
    cout << pList2.removePos(2) << "\n";
    pList2.showList(); 
    return 0;
}