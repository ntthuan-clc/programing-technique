#include <iostream>

using namespace std;

struct Node
{
    string name;
    int priority;
    Node *pNext;
    Node()
    {
        this->name = "";
        this->priority = 0;
        this->pNext = nullptr;
    }
    Node(string name, int priority)
    {
        this->name = name;
        this->priority = priority;
        this->pNext = nullptr;
    }
};

struct List
{
    Node *pHead;
    List()
    {
        this->pHead = nullptr;
    }
    void insert(string name, int priority);
    void addHead(string name, int priority);
    void addTail(string name, int priority);
    void showList();
};

void List::addHead(string name, int priority)
{
    Node *pNode = new Node(name, priority);
    if (pHead == nullptr)
    {
        pHead = pNode;
        return;
    }
    pNode->pNext = pHead;
    pHead = pNode;
}

void List::insert(string name, int priority)
{
    Node *pNode = new Node(name, priority);
    if (pHead == nullptr)
    {
        this->addHead(name, priority);
        return;
    }
    if (pNode->priority < pHead->priority)
    {
        this->addHead(name, priority);
        return;
    }
    Node* pTemp = pHead;
    while (pTemp->pNext != nullptr)
    {
        if (pNode->priority < pTemp->pNext->priority)
        {
            break;
        }

        pTemp = pTemp->pNext;
    }
    if (pTemp->pNext == nullptr) {
    	pTemp->pNext = pNode;
    } else {
      pNode->pNext = pTemp->pNext;
    	pTemp->pNext = pNode;
    }
}

void List::showList()
{
    Node *pTemp = pHead;
    while (pTemp)
    {
        cout << pTemp->priority << " ";
        cout << pTemp->name << '\n';
        pTemp = pTemp->pNext;
    }
}

int main()
{
    List ClinicList;
    ClinicList.insert("An", 1);
    ClinicList.insert("Binh", 3);
    ClinicList.insert("Vu", 2);
    ClinicList.insert("Duc", 0);
    ClinicList.insert("Cuong",6);
    ClinicList.showList();

    return 0;
}