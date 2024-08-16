#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// ��ʼ������
void Queue_Init(Queue *queue)
{
    queue->front = NULL; // ��ʼʱ��ͷ�Ͷ�β��ָ�� NULL
    queue->rear = NULL;
}

// �ж϶����Ƿ�Ϊ��
bool Queue_IsEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// ���е���Ӳ���
bool Queue_Enqueue(Queue *queue, data_t value)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return false;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (Queue_IsEmpty(queue))
    {
        // �������Ϊ�գ�front �� rear ��ָ���½ڵ�
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // ���򣬽��½ڵ���뵽��β�������¶�βָ��
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return true;
}

// ���еĳ��Ӳ���
bool Queue_Dequeue(Queue *queue, data_t *value)
{
    if (Queue_IsEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return false;
    }
    QueueNode *temp = queue->front;
    *value = temp->data;
    queue->front = temp->next;

    // �������Ϊ�գ����� rear Ϊ NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return true;
}

// ��ȡ���еĶ�ͷԪ�أ������ӣ�
bool Queue_Peek(Queue *queue, data_t *value)
{
    if (Queue_IsEmpty(queue))
    {
        printf("Queue is empty. Cannot peek.\n");
        return false;
    }
    *value = queue->front->data;
    return true;
}

// ��ӡ�����е�����Ԫ��
void Queue_Print(Queue *queue)
{
    if (Queue_IsEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    QueueNode *current = queue->front;
    printf("Queue elements (front to rear): ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// �ͷŶ��е����нڵ�
void Queue_Free(Queue *queue)
{
    while (!Queue_IsEmpty(queue))
    {
        data_t value;
        Queue_Dequeue(queue, &value); // ���ϳ��Ӳ��ͷŽڵ�
    }
}
