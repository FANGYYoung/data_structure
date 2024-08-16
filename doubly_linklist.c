#include "doubly_linklist.h"

// �����½ڵ�
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

// ������ͷ�������½ڵ�
void InsertAtHead(DoubleLinkList **head, data_t value)
{
    DoubleLinkList *newNode = CreateNode(value);
    if (*head == NULL)
    { // ����Ϊ��ʱ
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// �������м�ָ��λ�ú�������½ڵ�
void InsertAfter(DoubleLinkList* prevNode, data_t value) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    DoubleLinkList* newNode = CreateNode(value);

    newNode->next = prevNode->next;  // �½ڵ����һ���ڵ�ָ��ǰ���ڵ����һ���ڵ�
    newNode->prev = prevNode;        // �½ڵ��ǰ��ָ��ǰ���ڵ�

    if (prevNode->next != NULL) {    // ���ǰ���ڵ����һ���ڵ㲻Ϊ�գ�����ǰ���ڵ����һ���ڵ��ǰ��ָ��
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;        // ����ǰ���ڵ�� next ָ��
}


// ������β�������½ڵ�
void InsertAtTail(DoubleLinkList **head, data_t value)
{
    DoubleLinkList *newNode = CreateNode(value);
    if (*head == NULL)
    { // �������Ϊ��
        *head = newNode;
    }
    else
    {
        DoubleLinkList *temp = *head;
        while (temp->next != NULL)
        { // �ҵ�β���ڵ�
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// ɾ��ָ��ֵ�Ľڵ�
void DeleteNode(DoubleLinkList **head, data_t value)
{
    DoubleLinkList *temp = *head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    { // �ڵ㲻����
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (temp == *head)
    { // Ҫɾ������ͷ�ڵ�
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else if (temp->next == NULL)
    { // Ҫɾ������β�ڵ�
        temp->prev->next = NULL;
    }
    else
    { // ɾ���м�ڵ�
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Value %d deleted from the list.\n", value);
}

// �����������ӡ����
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

// �����������ӡ����
void PrintBackward(DoubleLinkList *head)
{
    DoubleLinkList *temp = head;

    if (temp == NULL)
        return;

    // �ƶ��������β�ڵ�
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

// �ͷ���������
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
