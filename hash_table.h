#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h> // 为布尔类型引入 true/false 定义

// 定义数据类型
typedef int key_t;   // 键的数据类型
typedef int value_t; // 值的数据类型

// 定义哈希表中每个条目的结构
typedef struct HashNode
{
    key_t key;             // 键
    value_t value;         // 值
    struct HashNode *next; // 指向链表下一个节点
} HashNode;

// 定义哈希表的结构
typedef struct
{
    HashNode **table; // 指向哈希表数组的指针
    int size;         // 哈希表的大小
} HashTable;

// 函数声明

// 初始化哈希表
void HashTable_Init(HashTable *hashTable, int size);

// 插入键值对到哈希表
bool HashTable_Insert(HashTable *hashTable, key_t key, value_t value);

// 查找键对应的值
bool HashTable_Search(HashTable *hashTable, key_t key, value_t *value);

// 删除哈希表中的键值对
bool HashTable_Delete(HashTable *hashTable, key_t key);

// 打印哈希表内容
void HashTable_Print(HashTable *hashTable);

// 释放哈希表内存
void HashTable_Free(HashTable *hashTable);

#endif // HASH_TABLE_H
