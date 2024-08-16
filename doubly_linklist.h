#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

// ����˫������Ľڵ�ṹ
typedef struct DoubleLinkList {
    data_t data;             // ������
    struct DoubleLinkList* prev;    // ָ��ǰ���ڵ��ָ��
    struct DoubleLinkList* next;    // ָ���̽ڵ��ָ��
} DoubleLinkList;

// �����½ڵ�
DoubleLinkList* CreateNode(data_t value);

// ������ͷ�������½ڵ�
void InsertAtHead(DoubleLinkList** head, data_t value);

// ������β�������½ڵ�
void InsertAtTail(DoubleLinkList** head, data_t value);

// �������м�ָ���ڵ������½ڵ�
void InsertAfter(DoubleLinkList* prevNode, data_t value);

// ɾ��ָ��ֵ�Ľڵ�
void DeleteNode(DoubleLinkList** head, data_t value);

// �����������ӡ����
void PrintForward(DoubleLinkList* head);

// �����������ӡ����
void PrintBackward(DoubleLinkList* head);

// �ͷ���������
void FreeList(DoubleLinkList* head);


#endif /* __DOUBLE_LIST_H__*/