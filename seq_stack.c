#include "seq_stack.h"
#include <stdio.h>

// ��ʼ��˳��ջ
void SeqStack_Init(SeqStack *stack)
{
    stack->top = -1; // ��ʼʱջ��ָ��Ϊ -1����ʾջΪ��
}

// �ж�˳��ջ�Ƿ�Ϊ��
bool SeqStack_IsEmpty(SeqStack *stack)
{
    return stack->top == -1;
}

// �ж�˳��ջ�Ƿ�����
bool SeqStack_IsFull(SeqStack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// ˳��ջ����ջ����
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

// ˳��ջ�ĳ�ջ����
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

// ��ȡ˳��ջ��ջ��Ԫ�أ�����ջ��
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

// ��ӡ˳��ջ�е�����Ԫ��
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
