#include "doubly_linklist.h"

// 创建新节点
DoubleLinkList *CreateNode(data_t value)
{
    DoubleLinkList *newNode = (DoubleLinkList *)malloc(sizeof(DoubleLinkList));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入新节点
void InsertAtHead(DoubleLinkList **head, data_t value)
{
    DoubleLinkList *newNode = CreateNode(value);
    if (*head == NULL)
    { // 链表为空时
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// 在链表中间指定位置后面插入新节点
void InsertAfter(DoubleLinkList* prevNode, data_t value) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    DoubleLinkList* newNode = CreateNode(value);

    newNode->next = prevNode->next;  // 新节点的下一个节点指向前驱节点的下一个节点
    newNode->prev = prevNode;        // 新节点的前驱指向前驱节点

    if (prevNode->next != NULL) {    // 如果前驱节点的下一个节点不为空，更新前驱节点的下一个节点的前驱指针
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;        // 更新前驱节点的 next 指针
}


// 在链表尾部插入新节点
void InsertAtTail(DoubleLinkList **head, data_t value)
{
    DoubleLinkList *newNode = CreateNode(value);
    if (*head == NULL)
    { // 如果链表为空
        *head = newNode;
    }
    else
    {
        DoubleLinkList *temp = *head;
        while (temp->next != NULL)
        { // 找到尾部节点
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// 删除指定值的节点
void DeleteNode(DoubleLinkList **head, data_t value)
{
    DoubleLinkList *temp = *head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    { // 节点不存在
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (temp == *head)
    { // 要删除的是头节点
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else if (temp->next == NULL)
    { // 要删除的是尾节点
        temp->prev->next = NULL;
    }
    else
    { // 删除中间节点
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Value %d deleted from the list.\n", value);
}

// 正向遍历并打印链表
void PrintForward(DoubleLinkList *head)
{
    DoubleLinkList *temp = head;
    printf("List (forward): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 反向遍历并打印链表
void PrintBackward(DoubleLinkList *head)
{
    DoubleLinkList *temp = head;

    if (temp == NULL)
        return;

    // 移动到链表的尾节点
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("List (backward): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// 释放整个链表
void FreeList(DoubleLinkList *head)
{
    DoubleLinkList *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
