#include <iostream>

struct Node
{
    int data;
    Node *pNext;

    Node()
    {
        // std::cout << "Node constructor\n";
        this->data = 0;
        this->pNext = nullptr;
    }
};

Node *createNode(int data)
{
    Node *rNode = new Node();
    rNode->data = data;
    rNode->pNext = nullptr;

    return rNode;
}

struct SinglyList
{
    Node *pHead;

    SinglyList()
    {
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

void SinglyList::addHead(int data)
{
    Node *pNode = createNode(data);
    // list is empty
    if (pHead == nullptr)
    {
        this->pHead = pNode;

        return;
    }

    pNode->pNext = this->pHead;
    this->pHead = pNode;
}

void SinglyList::showList()
{
    Node *pNode = this->pHead;

    while (pNode != nullptr)
    {
        std::cout << pNode->data << " ";
        pNode = pNode->pNext;
    }
}

void SinglyList::addTail(int data)
{
    Node *pNode = createNode(data);
    if (pHead == nullptr)
    {
        pHead = pNode;
        return;
    }

    Node *pTemp = pHead;
    while (pTemp->pNext != nullptr)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNode;
}

int SinglyList::size()
{
    Node *pTemp = pHead;
    int count = 0;
    while (pTemp != nullptr)
    {
        count++;
        pTemp = pTemp->pNext;
    }
    return count;
}

void SinglyList::insert(int data, int pos)
{
    Node *pNode = createNode(data);
    if (pos == 0)
    {
        addHead(data);
        return;
    }
    if (pos >= size())
    {
        addTail(data);
        return;
    }
    Node *pTemp = pHead;
    for (int i = 1; i <= pos - 1; ++i)
    {
        pTemp = pTemp->pNext;
    }
    pNode->pNext = pTemp->pNext;
    pTemp->pNext = pNode;
}

int SinglyList::search(int data)
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

int SinglyList::removeHead()
{
    // empty list
    if (pHead == nullptr)
    {
        return -1;
    }
    // only one element
    if (pHead->pNext == nullptr)
    {
        int rVal = pHead->data; // luu lai gia tri tra ve truoc khi xoa
        delete pHead;           // tra quyen cho hdh
        pHead = nullptr;        // xoa gia tri luu tru tai vung nho
        return rVal;
    }
    Node *pTemp = pHead;
    int rVal = pTemp->data;
    pHead = pHead->pNext;
    delete pTemp;
    pTemp = nullptr;
    return rVal;
}

int SinglyList::removeTail()
{
    // empty list
    if (pHead == nullptr)
    {
        return -1;
    }
    // only one element
    if (pHead->pNext == nullptr)
    {
        int rVal = pHead->data; // luu lai gia tri tra ve truoc khi xoa
        delete pHead;           // tra quyen cho hdh
        pHead = nullptr;        // xoa gia tri luu tru tai vung nho
        return rVal;
    }

    Node *prevEnd = pHead; // truoc cuoi
    while (prevEnd->pNext->pNext != nullptr)
    {
        prevEnd = prevEnd->pNext;
    }
    Node *pEnd = prevEnd->pNext;
    int rVal = pEnd->data;
    prevEnd->pNext = nullptr;
    delete pEnd;
    pEnd = nullptr;
    return rVal;
}

int SinglyList::removePos(int pos)
{
    // empty list
    if (pHead == nullptr)
    {
        return -1;
    }
    // only one element
    if (pHead->pNext == nullptr)
    {
        int rVal = pHead->data; // luu lai gia tri tra ve truoc khi xoa
        delete pHead;           // tra quyen cho hdh
        pHead = nullptr;        // xoa gia tri luu tru tai vung nho
        return rVal;
    }
    if (pos == 0)
    {
        return removeHead();
    }
    if (pos >= size())
    {
        return removeTail();
    }

    Node *prevRemove = pHead;
    for (int i = 1; i <= pos - 1; ++i)
    {
        prevRemove = prevRemove->pNext;
    }

    Node *pRemove = prevRemove->pNext;
    prevRemove->pNext = prevRemove->pNext->pNext;
    int rVal = pRemove->data;
    delete pRemove;
    pRemove = nullptr;
    return rVal;
}

void removeAllX(SinglyList &pList, int x)
{
    if (pList.pHead == nullptr)
    {
        return;
    }
    Node *pTemp = pList.pHead;
    int pos = 0;
    while (pTemp != nullptr)
    {
        if (pTemp->data == x)
        {
            pTemp = pTemp->pNext;
            pList.removePos(pos);
        }
        else
        {
            pos++;
            pTemp = pTemp->pNext;
        }
    }
}
bool SinglyList::checkDuplicate(int data)
{
    int count = 0;
    Node *pTemp = pHead;
    while (pTemp != nullptr)
    {
        if (pTemp->data == data)
        {
            count++;
        }
        pTemp = pTemp->pNext;
    }
    return (count >= 2);
}

void removeDuplicate(SinglyList &pList)
{
    if (pList.pHead == nullptr)
    {
        return;
    }
    int pos = 0;
    Node *pTemp = pList.pHead;
    while (pTemp != nullptr)
    {
        if (pList.checkDuplicate(pTemp->data))
        {
            pTemp = pTemp->pNext;
            pList.removePos(pos);
        }
        else
        {
            pos++;
            pTemp = pTemp->pNext;
        }
    }
}

SinglyList join2Linklist(SinglyList &pList1, SinglyList &pList2)
{
    SinglyList result;
    if (pList1.pHead == nullptr && pList2.pHead == nullptr)
    {
        return result;
    }
    Node *pTemp1 = pList1.pHead;
    while (pTemp1->pNext != nullptr)
    {
        pTemp1 = pTemp1->pNext;
    }
    pTemp1->pNext = pList2.pHead;
    return pList1;
}

int main()
{
    // int *num;
    // std::cin >> *num;
    SinglyList pList1;
    pList1.addTail(10);
    pList1.addTail(30);
    pList1.addTail(50);
    pList1.addTail(70);
    pList1.addTail(90);
    pList1.addTail(110);
    SinglyList pList2;
    pList2.addTail(20);
    pList2.addTail(40);
    pList2.addTail(60);

    // removeAllX(pList,2);
    pList1.showList();
    std::cout << "\n";
    pList2.showList();
    std::cout << "\n";
    // removeDuplicate(pList);
    // pList.removeHead();
    // pList.removeTail();
    // pList.removeTail();
    // pList.removeTail();
    // pList.removeTail();
    // pList.removeTail();
    // pList.removePos(0);
    // pList.removePos(2);
    join2Linklist(pList1, pList2);
    pList1.showList();
    std::cout << "\n";
    // std::cout << pList.search(10) << "\n";
    // std::cout << pList.search(15) << "\n";
    // std::cout << pList.search(100);
}