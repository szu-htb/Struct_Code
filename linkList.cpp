#include <iostream>
using namespace std;
//宏定义 错误信息
#define ERROR -1
#define CORRECT 1
typedef struct Node
{
    int data;   // 数据域
    Node *next; // 指针域
} link_node, *link_list;

// 单链表的查找
link_list Find_Elem(link_list head, int position)
{
    link_list p = head;
    int pos = position;
    // 判断是否为空链表
    if (p == NULL)
    {
        return NULL;
    }
    // 遍历链表
    while (pos > 1)
    {
        p = p->next;
        // 越界判断
        if (p == NULL)
        {   
            cout << "越界！" << endl;
            return NULL;
        }
        pos--;
    }
    // 找到元素并返回 该节点指针
    return p;
}

// 指定插入
int Insert_Elem(link_list head, int position, int elem)
{
    int pos = position;
    link_list p = head;
    // 创建新的节点，并插入到链表中
    link_list s = new link_node;

    //position is Correct?
    if (pos <= 0)
    {
        cout << "越界！" << endl;
        return ERROR;
    }

    // 判断是否创建成功
    if (s == NULL)
    {
        cout << "内存分配失败！" << endl;
        return ERROR;
    }
    else
    {
        s->data = elem;
        s->next = NULL;
    }
    // 判断是否为空链表
    if (p == NULL)
    {
        head = s;
    }
    else
    {
        // 找到插入位置
        p = Find_Elem(head, pos - 1);
        // 插入节点
        s->next = p->next;
        p->next = s;
    }
    return CORRECT;
}

// 链表的创建
link_list Create_List(int* r, int n)
{
    int i = 0;
    //判断数据是否为空
    if (r == NULL || n <= 0)
    {
        cout << "数据为空！" << endl;
        return NULL;
    }

    // 创建头节点
    link_list head = new link_node;
    link_list p = head;
    // 判断是否创建成功
    if(head == NULL)
    {
        cout << "内存分配失败！" << endl;
        return NULL;
    }

    // 成功创建头节点
    while(i < n)
    {
        p -> next = new link_node;
        p = p -> next;
        // 判断是否创建成功
        if(p == NULL)
        {
            cout << "内存分配失败！" << endl;
            return NULL;
        }
        p -> data = r[i];
        i++;
    }
    // 尾节点指向NULL
    p -> next = NULL;
    //头节点为空
    return head->next;
}
    
// 链表的删除
int Delete_Elem(link_list head, int position)
{
    int pos = position;
    link_list p = head;
    link_list s = NULL;
    // 判断越界情况
    if(position <= 0)
    {
        cout << "越界！" << endl;
        return ERROR;
    }

    //判断链表是否为空
    if(p == NULL)
    {
        cout << "链表为空！" << endl;
        return ERROR;
    }
    // 找到删除位置
    p = Find_Elem(head, position - 1);
    if(p->next == NULL)
    {
        // 返回报错
        cout << "无元素可以删除" << endl;
        return ERROR;
    }
    //删除
    s = p->next;
    p->next = s->next;
    delete s;
    //！！
    s = NULL;

    return CORRECT;
}
// 打印链表
int Show_List(link_list head)
{
    link_list p = head;
    if(p == NULL)
    {
        //打印错误信息
        cout << "该链表为空" << endl;
        return ERROR;
    }
    else
    {
        while(p->next != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        // 显示最后一个元素 ，下个指向的是NULL,但是本身还是有的
        cout << p->data << endl;
    }
    return CORRECT;
}
// 主函数
int main()
{
    // 创建链表
    int r[100], i, SampleNum, SearchPos, NewPos, NewItem, DelPos;
    link_list p = NULL;

    // 输入样本数量
    cin >> SampleNum;
    for (i = 0; i < SampleNum; i++) {
        cin >> r[i];  // 输入样本数据
    }

    // 生成单链表
    p = Create_List(r, SampleNum);
    
    // 显示单链表
    Show_List(p);

    // 输入查找位置
    cin >> SearchPos;
    link_list q = Find_Elem(p, SearchPos);
    if (q != NULL) {
        cout << q->data << endl;  // 输出查找的数据元素值
    } else {
        cout << "位置无效" << endl;
    }

    // 输入插入位置和数据
    cin >> NewPos >> NewItem;
    if (Insert_Elem(p, NewItem, NewPos) == 1) {
        // 显示单链表
        Show_List(p);
    } else {
        cout << "插入位置无效" << endl;
    }

    // 输入删除元素位置
    cin >> DelPos;
    if (Delete_Elem(p, DelPos) == 1) {
        // 显示单链表
        Show_List(p);
    } else {
        cout << "删除位置无效" << endl;
    }

    return 0;
}