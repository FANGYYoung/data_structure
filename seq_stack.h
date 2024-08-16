#ifndef SEQ_STACK_H
#define SEQ_STACK_H

#include <stdbool.h> // Ϊ������������ true/false ����

// ������������
typedef int data_t;

// ����ջ������С
#define MAX_SIZE 100

// ˳��ջ�Ľṹ����
typedef struct
{
    data_t data[MAX_SIZE]; // ���ڴ洢ջԪ�ص�����
    int top;               // ջ��ָ��
} SeqStack;

// ��������

// ��ʼ��˳��ջ
void SeqStack_Init(SeqStack *stack);

// �ж�˳��ջ�Ƿ�Ϊ��
bool SeqStack_IsEmpty(SeqStack *stack);

// �ж�˳��ջ�Ƿ�����
bool SeqStack_IsFull(SeqStack *stack);

// ˳��ջ����ջ����
bool SeqStack_Push(SeqStack *stack, data_t value);

// ˳��ջ�ĳ�ջ����
bool SeqStack_Pop(SeqStack *stack, data_t *value);

// ��ȡ˳��ջ��ջ��Ԫ�أ�����ջ��
bool SeqStack_Peek(SeqStack *stack, data_t *value);

// ��ӡ˳��ջ������Ԫ��
void SeqStack_Print(SeqStack *stack);

#endif // SEQ_STACK_H
