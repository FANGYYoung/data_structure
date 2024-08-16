#ifndef SEQ_STACK_H
#define SEQ_STACK_H

#include <stdbool.h> // 为布尔类型引入 true/false 定义

// 定义数据类型
typedef int data_t;

// 定义栈的最大大小
#define MAX_SIZE 100

// 顺序栈的结构定义
typedef struct
{
    data_t data[MAX_SIZE]; // 用于存储栈元素的数组
    int top;               // 栈顶指针
} SeqStack;

// 函数声明

// 初始化顺序栈
void SeqStack_Init(SeqStack *stack);

// 判断顺序栈是否为空
bool SeqStack_IsEmpty(SeqStack *stack);

// 判断顺序栈是否已满
bool SeqStack_IsFull(SeqStack *stack);

// 顺序栈的入栈操作
bool SeqStack_Push(SeqStack *stack, data_t value);

// 顺序栈的出栈操作
bool SeqStack_Pop(SeqStack *stack, data_t *value);

// 获取顺序栈的栈顶元素（不出栈）
bool SeqStack_Peek(SeqStack *stack, data_t *value);

// 打印顺序栈中所有元素
void SeqStack_Print(SeqStack *stack);

#endif // SEQ_STACK_H
