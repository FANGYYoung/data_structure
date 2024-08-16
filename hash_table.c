#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

// 简单的哈希函数
int HashFunction(key_t key, int tableSize)
{
    return key % tableSize; // 使用键对哈希表大小取模作为哈希值
}

// 初始化哈希表
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
        hashTable->table[i] = NULL; // 初始化每个表项为空
    }
}

// 插入键值对到哈希表
bool HashTable_Insert(HashTable *hashTable, key_t key, value_t value)
{
    int index = HashFunction(key, hashTable->size); // 计算哈希索引
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return false;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable->table[index]; // 头插法，新的节点指向原链表第一个节点
    hashTable->table[index] = newNode;       // 更新哈希表该位置的头指针
    return true;
}

// 查找键对应的值
bool HashTable_Search(HashTable *hashTable, key_t key, value_t *value)
{
    int index = HashFunction(key, hashTable->size); // 计算哈希索引
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
    return false; // 如果没有找到返回 false
}

// 删除哈希表中的键值对
bool HashTable_Delete(HashTable *hashTable, key_t key)
{
    int index = HashFunction(key, hashTable->size); // 计算哈希索引
    HashNode *current = hashTable->table[index];
    HashNode *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL)
            {
                hashTable->table[index] = current->next; // 删除头节点
            }
            else
            {
                prev->next = current->next; // 跳过当前节点
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false; // 如果没有找到返回 false
}

// 打印哈希表内容
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

// 释放哈希表内存
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
    free(hashTable->table); // 释放哈希表指针数组
}
