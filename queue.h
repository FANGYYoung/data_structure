#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> // 为布尔类型引入 true/false 定义

// 定义数据类型
typedef int data_t;

// 队列节点结构定义
typedef struct QueueNode
{
    data_t data;            // 数据域
    struct QueueNode *next; // 指向下一个节点的指针
} QueueNode;

// 队列结构定义
typedef struct
{
    QueueNode *front; // 指向队列头部的指针（出队）
    QueueNode *rear;  // 指向队列尾部的指针（入队）
} Queue;

// 函数声明

// 初始化队列
void Queue_Init(Queue *queue);

// 判断队列是否为空
bool Queue_IsEmpty(Queue *queue);

// 队列的入队操作
bool Queue_Enqueue(Queue *queue, data_t value);

// 队列的出队操作
bool Queue_Dequeue(Queue *queue, data_t *value);

// 获取队列的队头元素（不出队）
bool Queue_Peek(Queue *queue, data_t *value);

// 打印队列中所有元素
void Queue_Print(Queue *queue);

// 释放队列的所有节点
void Queue_Free(Queue *queue);

#endif // QUEUE_H
