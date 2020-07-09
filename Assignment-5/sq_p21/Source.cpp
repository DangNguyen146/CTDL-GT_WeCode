#include <string>
#include <iostream>
using namespace std;
struct node {
    char info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l);
node* CreateNode(char x);
void AddTail(List& l, node* p);
void Xuat(List l);
void enqueue(List& l, char x);
int dequeue(List& l);
bool isEmpty(List l);
int main()
{
    char c;
    cin >> c;
    string s = "";
    cin >> s;
    List queue;
    CreateList(queue);

    if (s == "")
    {
        cout << "Chuoi rong.";
        return 0;
    }

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        node* p = CreateNode(s[i]);
        AddTail(queue, p);
    }
    enqueue(queue, c);
    return 0;
}
void CreateList(List& l)
{
    l.pHead = l.pTail = NULL;
}
node* CreateNode(char x)
{
    node* p = new node;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddTail(List& l, node* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void Xuat(List l)
{
    node* p = l.pHead;
    while (p != NULL)
    {
        cout << p->info;
        p = p->pNext;
    }
}
bool isEmpty(List l)
{
    if (l.pHead == NULL)
        return true;
    else
        return false;
}
void enqueue(List& l, char x)
{
    List q;
    CreateList(q);
    List de_q;
    CreateList(de_q);
    for (node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->info != x)
        {
            node* e = CreateNode(p->info);
            AddTail(q, e);
        }
        else
        {
            if (q.pHead != NULL)
            {
                node* e = CreateNode(q.pHead->info);
                AddTail(de_q, e);
            }
            dequeue(q);
        }
    }
    Xuat(de_q);
    cout << endl;
    if (isEmpty(q) == true)
        cout << "Hang doi rong.";
    else
    {
        cout << "Cac gia tri co trong hang doi la: ";
        Xuat(q);
    }
}
int dequeue(List& l)
{
    if (l.pHead == NULL)
        l.pTail = NULL;
    else
        l.pHead = l.pHead->pNext;
    return 1;
}