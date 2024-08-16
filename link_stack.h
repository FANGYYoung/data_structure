#ifndef LINK_STACK_H
#define LINK_STACK_H

#include <stdbool.h> // Ϊ������������ true/false ����

// ������������
typedef int data_t;

// ��ջ�ڵ�ṹ����
typedef struct LinkStackNode
{
    data_t data;                // ������
    struct LinkStackNode *next; // ָ����һ���ڵ��ָ��
} LinkStackNode;

// ��ջ�ṹ����
typedef struct
{
    LinkStackNode *top; // ָ��ջ����ָ��
} LinkStack;

// ��������

// ��ʼ����ջ
void LinkStack_Init(LinkStack *stack);

// �ж���ջ�Ƿ�Ϊ��
bool LinkStack_IsEmpty(LinkStack *stack);

// ��ջ����ջ����
bool LinkStack_Push(LinkStack *stack, data_t value);

// ��ջ�ĳ�ջ����
bool LinkStack_Pop(LinkStack *stack, data_t *value);

// ��ȡ��ջ��ջ��Ԫ�أ�����ջ��
bool LinkStack_Peek(LinkStack *stack, data_t *value);

// ��ӡ��ջ������Ԫ��
void LinkStack_Print(LinkStack *stack);

// �ͷ���ջ�����нڵ�
void LinkStack_Free(LinkStack *stack);

#endif // LINK_STACK_H
