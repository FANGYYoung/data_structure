#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

// �򵥵Ĺ�ϣ����
int HashFunction(key_t key, int tableSize)
{
    return key % tableSize; // ʹ�ü��Թ�ϣ���Сȡģ��Ϊ��ϣֵ
}

// ��ʼ����ϣ��
void HashTable_Init(HashTable *hashTable, int size)
{
    hashTable->size = size;
    hashTable->table = (HashNode **)malloc(sizeof(HashNode *) * size);
    if (hashTable->table == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        hashTable->table[i] = NULL; // ��ʼ��ÿ������Ϊ��
    }
}

// �����ֵ�Ե���ϣ��
bool HashTable_Insert(HashTable *hashTable, key_t key, value_t value)
{
    int index = HashFunction(key, hashTable->size); // �����ϣ����
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return false;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable->table[index]; // ͷ�巨���µĽڵ�ָ��ԭ�����һ���ڵ�
    hashTable->table[index] = newNode;       // ���¹�ϣ���λ�õ�ͷָ��
    return true;
}

// ���Ҽ���Ӧ��ֵ
bool HashTable_Search(HashTable *hashTable, key_t key, value_t *value)
{
    int index = HashFunction(key, hashTable->size); // �����ϣ����
    HashNode *current = hashTable->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            *value = current->value;
            return true;
        }
        current = current->next;
    }
    return false; // ���û���ҵ����� false
}

// ɾ����ϣ���еļ�ֵ��
bool HashTable_Delete(HashTable *hashTable, key_t key)
{
    int index = HashFunction(key, hashTable->size); // �����ϣ����
    HashNode *current = hashTable->table[index];
    HashNode *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL)
            {
                hashTable->table[index] = current->next; // ɾ��ͷ�ڵ�
            }
            else
            {
                prev->next = current->next; // ������ǰ�ڵ�
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false; // ���û���ҵ����� false
}

// ��ӡ��ϣ������
void HashTable_Print(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        printf("Index %d: ", i);
        HashNode *current = hashTable->table[i];
        while (current != NULL)
        {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// �ͷŹ�ϣ���ڴ�
void HashTable_Free(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        HashNode *current = hashTable->table[i];
        while (current != NULL)
        {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table); // �ͷŹ�ϣ��ָ������
}
