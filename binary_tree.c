#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

// ��ʼ��������
void BinaryTree_Init(BinaryTree *tree)
{
    tree->root = NULL; // ���ĸ��ڵ��ʼΪ NULL
}

// �����½ڵ�
BinaryTreeNode *BinaryTree_CreateNode(data_t value)
{
    BinaryTreeNode *newNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ����ڵ㵽��������
void BinaryTree_Insert(BinaryTree *tree, data_t value)
{
    BinaryTreeNode *newNode = BinaryTree_CreateNode(value);
    if (newNode == NULL)
    {
        return;
    }

    if (tree->root == NULL)
    {
        tree->root = newNode; // �����Ϊ�գ��½ڵ�Ϊ���ڵ�
        return;
    }

    BinaryTreeNode *current = tree->root;
    BinaryTreeNode *parent = NULL;

    // Ѱ�Һ��ʵĲ���λ��
    while (current != NULL)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (value < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

// ǰ�����������
void BinaryTree_PreOrder(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    BinaryTree_PreOrder(node->left);
    BinaryTree_PreOrder(node->right);
}

// �������������
void BinaryTree_InOrder(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    BinaryTree_InOrder(node->left);
    printf("%d ", node->data);
    BinaryTree_InOrder(node->right);
}

// �������������
void BinaryTree_PostOrder(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    BinaryTree_PostOrder(node->left);
    BinaryTree_PostOrder(node->right);
    printf("%d ", node->data);
}

// �����ڵ�
BinaryTreeNode *BinaryTree_Search(BinaryTreeNode *node, data_t value)
{
    if (node == NULL || node->data == value)
    {
        return node;
    }

    if (value < node->data)
    {
        return BinaryTree_Search(node->left, value);
    }
    else
    {
        return BinaryTree_Search(node->right, value);
    }
}

// �ͷŶ����������нڵ�
void BinaryTree_Free(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    BinaryTree_Free(node->left);
    BinaryTree_Free(node->right);
    free(node);
}
