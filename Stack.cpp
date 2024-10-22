/*基于链表实现的栈结构*/

#include <iostream>
// 引入命名空间
using namespace std;
// 创建节点结构体
typedef struct Node
{
    Node *next;
    int data;
} Link_Node_t, *Link_Node_p;
// 创建栈结构
typedef struct Stack
{
    Link_Node_p top;
    int size;
} Stack_t, *Stack_p;

// 初始化栈
Stack_p Stack_Create()
{
    Stack_p stack = new Stack_t;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// 压栈
int Stack_Push(Stack_p stack, int data)
{
    Link_Node_p node = new Link_Node_t;
    if (stack == nullptr)
    {
        return -1;
    }
    node->data = data;       // 更新数值域
    node->next = stack->top; // 更新指针域
    stack->top = node;       // 更新栈顶指针
    stack->size++;
    return 0;
}
// 获取栈顶元素
int Stack_Peek(Stack_p stack)
{
    if (stack == nullptr || stack->size == 0)
    {
        return -1;
    }
    return stack->top->data;
}

// 判断栈是否为空
int Stack_IsEmpty(Stack_p stack)
{
    if (stack == nullptr)
    {
        return -1;
    }
    return stack->size == 0;
}

// 出栈
int Stack_Pop(Stack_p stack)
{
    Link_Node_p tmp = stack->top;
    int val = 0;
    if (stack == nullptr || stack->size == 0)
    {
        return -1;
    }
    // 栈空
    if (Stack_IsEmpty(stack))
    {
        cout << "false" << endl;
        return 0;
    }

    // 获取原先栈顶元素
    val = stack->top->data;
    stack->top = stack->top->next;
    stack->size--;
    delete tmp;

    return val;
}
//
bool AreParenthesesBalanced(string str)
{
    Stack_p stack = Stack_Create();
    if (stack == nullptr)
    {
        cout << "栈初始化失败" << endl;
        return false;
    }

    for (char data : str)
    {
        if (data == '(' || data == '[' || data == '{')
        {
            Stack_Push(stack, data);
        }
        else if (data == ')' || data == ']' || data == '}')
        {
            if (Stack_IsEmpty(stack))
            {
                return false;
            }

            char val = Stack_Pop(stack);
            if ((val == '(' && data != ')') ||
                (val == '[' && data != ']') ||
                (val == '{' && data != '}'))
            {
                return false;
            }
        }
    }

    bool balanced = Stack_IsEmpty(stack);
    delete stack; // 释放栈的内存
    return balanced;
}
// 主函数
int main()
{
    Stack_p stack = Stack_Create();
    // Stack_Push(stack, 1);
    // Stack_Push(stack, 2);
    // //Stack_Pop(stack);
    // cout << Stack_Peek(stack) << endl;
    int StingNum = 0;
    cin >> StingNum;
    for (int i = 0; i < StingNum; i++)
    {
        string str;
        cin >> str;
        if (!AreParenthesesBalanced(str))
        {
            cout << "false" << endl;
            return 0;
        }
        // if (Stack_IsEmpty(stack))
        //     return -1;
    }
    printf("true\n");
    return 0;
}