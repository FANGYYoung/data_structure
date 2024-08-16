#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化队列
void Queue_Init(Queue *queue)
{
    queue->front = NULL; // 初始时队头和队尾都指向 NULL
    queue->rear = NULL;
}

// 判断队列是否为空
bool Queue_IsEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// 队列的入队操作
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
        // 如果队列为空，front 和 rear 都指向新节点
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // 否则，将新节点加入到队尾，并更新队尾指针
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return true;
}

// 队列的出队操作
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

    // 如果队列为空，更新 rear 为 NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return true;
}

// 获取队列的队头元素（不出队）
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

// 打印队列中的所有元素
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

// 释放队列的所有节点
void Queue_Free(Queue *queue)
{
    while (!Queue_IsEmpty(queue))
    {
        data_t value;
        Queue_Dequeue(queue, &value); // 不断出队并释放节点
    }
}
