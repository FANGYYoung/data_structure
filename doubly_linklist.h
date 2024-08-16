#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

// 定义双向链表的节点结构
typedef struct DoubleLinkList {
    data_t data;             // 数据域
    struct DoubleLinkList* prev;    // 指向前驱节点的指针
    struct DoubleLinkList* next;    // 指向后继节点的指针
} DoubleLinkList;

// 创建新节点
DoubleLinkList* CreateNode(data_t value);

// 在链表头部插入新节点
void InsertAtHead(DoubleLinkList** head, data_t value);

// 在链表尾部插入新节点
void InsertAtTail(DoubleLinkList** head, data_t value);

// 在链表中间指定节点后插入新节点
void InsertAfter(DoubleLinkList* prevNode, data_t value);

// 删除指定值的节点
void DeleteNode(DoubleLinkList** head, data_t value);

// 正向遍历并打印链表
void PrintForward(DoubleLinkList* head);

// 反向遍历并打印链表
void PrintBackward(DoubleLinkList* head);

// 释放整个链表
void FreeList(DoubleLinkList* head);


#endif /* __DOUBLE_LIST_H__*/