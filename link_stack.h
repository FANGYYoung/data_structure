#ifndef LINK_STACK_H
#define LINK_STACK_H

#include <stdbool.h> // 为布尔类型引入 true/false 定义

// 定义数据类型
typedef int data_t;

// 链栈节点结构定义
typedef struct LinkStackNode
{
    data_t data;                // 数据域
    struct LinkStackNode *next; // 指向下一个节点的指针
} LinkStackNode;

// 链栈结构定义
typedef struct
{
    LinkStackNode *top; // 指向栈顶的指针
} LinkStack;

// 函数声明

// 初始化链栈
void LinkStack_Init(LinkStack *stack);

// 判断链栈是否为空
bool LinkStack_IsEmpty(LinkStack *stack);

// 链栈的入栈操作
bool LinkStack_Push(LinkStack *stack, data_t value);

// 链栈的出栈操作
bool LinkStack_Pop(LinkStack *stack, data_t *value);

// 获取链栈的栈顶元素（不出栈）
bool LinkStack_Peek(LinkStack *stack, data_t *value);

// 打印链栈中所有元素
void LinkStack_Print(LinkStack *stack);

// 释放链栈的所有节点
void LinkStack_Free(LinkStack *stack);

#endif // LINK_STACK_H
