#include "link_stack.h"
#include <stdio.h>
#include <stdlib.h>

// ��ʼ����ջ
void LinkStack_Init(LinkStack *stack)
{
    stack->top = NULL; // ջ��ָ���ʼ��Ϊ NULL����ʾջΪ��
}

// �ж���ջ�Ƿ�Ϊ��
bool LinkStack_IsEmpty(LinkStack *stack)
{
    return stack->top == NULL;
}

// ��ջ����ջ����
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

// ��ջ�ĳ�ջ����
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

// ��ȡ��ջ��ջ��Ԫ�أ�����ջ��
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

// ��ӡ��ջ�е�����Ԫ��
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

// �ͷ���ջ�����нڵ�
void LinkStack_Free(LinkStack *stack)
{
    while (!LinkStack_IsEmpty(stack))
    {
        data_t value;
        LinkStack_Pop(stack, &value); // ���ϵ������ͷŽڵ�
    }
}
