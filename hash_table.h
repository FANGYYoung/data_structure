#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h> // Ϊ������������ true/false ����

// ������������
typedef int key_t;   // ������������
typedef int value_t; // ֵ����������

// �����ϣ����ÿ����Ŀ�Ľṹ
typedef struct HashNode
{
    key_t key;             // ��
    value_t value;         // ֵ
    struct HashNode *next; // ָ��������һ���ڵ�
} HashNode;

// �����ϣ��Ľṹ
typedef struct
{
    HashNode **table; // ָ���ϣ�������ָ��
    int size;         // ��ϣ��Ĵ�С
} HashTable;

// ��������

// ��ʼ����ϣ��
void HashTable_Init(HashTable *hashTable, int size);

// �����ֵ�Ե���ϣ��
bool HashTable_Insert(HashTable *hashTable, key_t key, value_t value);

// ���Ҽ���Ӧ��ֵ
bool HashTable_Search(HashTable *hashTable, key_t key, value_t *value);

// ɾ����ϣ���еļ�ֵ��
bool HashTable_Delete(HashTable *hashTable, key_t key);

// ��ӡ��ϣ������
void HashTable_Print(HashTable *hashTable);

// �ͷŹ�ϣ���ڴ�
void HashTable_Free(HashTable *hashTable);

#endif // HASH_TABLE_H
