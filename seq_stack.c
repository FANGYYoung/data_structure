#include "seq_stack.h"
#include <stdio.h>

// 初始化顺序栈
void SeqStack_Init(SeqStack *stack)
{
    stack->top = -1; // 初始时栈顶指针为 -1，表示栈为空
}

// 判断顺序栈是否为空
bool SeqStack_IsEmpty(SeqStack *stack)
{
    return stack->top == -1;
}

// 判断顺序栈是否已满
bool SeqStack_IsFull(SeqStack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// 顺序栈的入栈操作
bool SeqStack_Push(SeqStack *stack, data_t value)
{
    if (SeqStack_IsFull(stack))
    {
        printf("Stack is full. Cannot push %d\n", value);
        return false;
    }
    stack->top++;
    stack->data[stack->top] = value;
    return true;
}

// 顺序栈的出栈操作
bool SeqStack_Pop(SeqStack *stack, data_t *value)
{
    if (SeqStack_IsEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return false;
    }
    *value = stack->data[stack->top];
    stack->top--;
    return true;
}

// 获取顺序栈的栈顶元素（不出栈）
bool SeqStack_Peek(SeqStack *stack, data_t *value)
{
    if (SeqStack_IsEmpty(stack))
    {
        printf("Stack is empty. Cannot peek.\n");
        return false;
    }
    *value = stack->data[stack->top];
    return true;
}

// 打印顺序栈中的所有元素
void SeqStack_Print(SeqStack *stack)
{
    if (SeqStack_IsEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}
