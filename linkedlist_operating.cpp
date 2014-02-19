/*这是链表的常用操作*/

/*1. 单链表的结点类型和头指针的定义*/
struct Node
{
    int content;
    Node *next;
}
Node *head = NULL;

/*2. 在链表中插入一个结点*/
/*2.1 插在链表的开头*/
Node *p = new Node;
p -> content = a;
p -> next = head;
head = p;

/*2.2 插在链表的结尾*/
Node *p = new Node;	/*创造一个新结点*/
p -> content = a;
Node *q = head;
while (q -> next != NULL)   /*找到最后一个结点*/
    q = q -> next;
q -> next = p;
p -> next = NULL;

/*2.3 插在链表的第i个结点后*/
Node *p = new Node;
p -> content = a;
Node *q = head;
int count = 1;
while (count < i)	/*循环寻找第i各结点*/
{
    if (q -> next == NULL)
        break;
    q = q -> next;
    count++;
}
if (count == i)
{
    p -> next = q -> next;
    q -> next = p;
}
else
    cout << "没有第" << i << "个结点\n";

/*3 在链表中删除一个结点*/
/*3.1 删除第一个结点*/
Node *p = head;
head = head -> next;
delete p;

/*3.2 删除链表的最后一个结点*/
Node *p = head;
Node *q = NULL;
q = p -> next;
if (p -> next != NULL)
{
    q = p;
    p = p -> next;
}
if (q -> next != NULL)
    q -> next = NULL;
else
    head == NULL;
delete p;

/*3.3 删除链表中第i个结点*/
if (i == 1)
{
    Node *p = head;
    head = head -> next;
    delete p;
}
else
{
    Node *p = head;
    int count = 1;
    while (count < i-1)
    {
        if (p -> next == NULL)
            break;
        p = p -> next;
        count++;
    }
    if (p -> next != NULL)
    {
        Node *q = p -> next;
        p -> next = q -> next;
        delete q;
    }
    else
        cout <<　"无法删除第" << i << "个结点"; 
}

/*4 在链表中检索某个值a*/
int index = 0;
for (Node *p = head; p != NULL; p = p -> next)
{
    index++;
    if (p -> content == a)
        break;
}
if (p != NULL)
    cout << "第" << index << "个结点的值为" << a << endl;
else
    cout << "没有找到值为" << a << "的结点" << endl;

/*5 输出所有结点的值*/
for (Node *p = head; p != NULL; p = p -> next)
    cout << p -> content << ' ';
cout << endl;



