#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> // Ϊ������������ true/false ����

// ������������
typedef int data_t;

// ���нڵ�ṹ����
typedef struct QueueNode
{
    data_t data;            // ������
    struct QueueNode *next; // ָ����һ���ڵ��ָ��
} QueueNode;

// ���нṹ����
typedef struct
{
    QueueNode *front; // ָ�����ͷ����ָ�루���ӣ�
    QueueNode *rear;  // ָ�����β����ָ�루��ӣ�
} Queue;

// ��������

// ��ʼ������
void Queue_Init(Queue *queue);

// �ж϶����Ƿ�Ϊ��
bool Queue_IsEmpty(Queue *queue);

// ���е���Ӳ���
bool Queue_Enqueue(Queue *queue, data_t value);

// ���еĳ��Ӳ���
bool Queue_Dequeue(Queue *queue, data_t *value);

// ��ȡ���еĶ�ͷԪ�أ������ӣ�
bool Queue_Peek(Queue *queue, data_t *value);

// ��ӡ����������Ԫ��
void Queue_Print(Queue *queue);

// �ͷŶ��е����нڵ�
void Queue_Free(Queue *queue);

#endif // QUEUE_H
