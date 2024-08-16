#include "link_stack.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化链栈
void LinkStack_Init(LinkStack *stack)
{
    stack->top = NULL; // 栈顶指针初始化为 NULL，表示栈为空
}

// 判断链栈是否为空
bool LinkStack_IsEmpty(LinkStack *stack)
{
    return stack->top == NULL;
}

// 链栈的入栈操作
bool LinkStack_Push(LinkStack *stack, data_t value)
{
    LinkStackNode *newNode = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return false;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return true;
}

// 链栈的出栈操作
bool LinkStack_Pop(LinkStack *stack, data_t *value)
{
    if (LinkStack_IsEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return false;
    }
    LinkStackNode *temp = stack->top;
    *value = temp->data;
    stack->top = temp->next;
    free(temp);
    return true;
}

// 获取链栈的栈顶元素（不出栈）
bool LinkStack_Peek(LinkStack *stack, data_t *value)
{
    if (LinkStack_IsEmpty(stack))
    {
        printf("Stack is empty. Cannot peek.\n");
        return false;
    }
    *value = stack->top->data;
    return true;
}

// 打印链栈中的所有元素
void LinkStack_Print(LinkStack *stack)
{
    if (LinkStack_IsEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    LinkStackNode *current = stack->top;
    printf("Stack elements (top to bottom): ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放链栈的所有节点
void LinkStack_Free(LinkStack *stack)
{
    while (!LinkStack_IsEmpty(stack))
    {
        data_t value;
        LinkStack_Pop(stack, &value); // 不断弹出并释放节点
    }
}
