#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h> // Ϊ������������ true/false ����

// ������������
typedef int data_t;

// �������ڵ�ṹ����
typedef struct BinaryTreeNode
{
    data_t data;                  // ������
    struct BinaryTreeNode *left;  // ���ӽڵ�ָ��
    struct BinaryTreeNode *right; // ���ӽڵ�ָ��
} BinaryTreeNode;

// �������ṹ����
typedef struct
{
    BinaryTreeNode *root; // ���ڵ�ָ��
} BinaryTree;

// ��������

// ��ʼ��������
void BinaryTree_Init(BinaryTree *tree);

// �����½ڵ�
BinaryTreeNode *BinaryTree_CreateNode(data_t value);

// ����ڵ㵽��������
void BinaryTree_Insert(BinaryTree *tree, data_t value);

// ǰ�����������
void BinaryTree_PreOrder(BinaryTreeNode *node);

// �������������
void BinaryTree_InOrder(BinaryTreeNode *node);

// �������������
void BinaryTree_PostOrder(BinaryTreeNode *node);

// �����ڵ�
BinaryTreeNode *BinaryTree_Search(BinaryTreeNode *node, data_t value);

// �ͷŶ�����
void BinaryTree_Free(BinaryTreeNode *node);

#endif // BINARY_TREE_H
