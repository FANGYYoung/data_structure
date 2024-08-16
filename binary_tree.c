#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化二叉树
void BinaryTree_Init(BinaryTree *tree)
{
    tree->root = NULL; // 树的根节点初始为 NULL
}

// 创建新节点
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

// 插入节点到二叉树中
void BinaryTree_Insert(BinaryTree *tree, data_t value)
{
    BinaryTreeNode *newNode = BinaryTree_CreateNode(value);
    if (newNode == NULL)
    {
        return;
    }

    if (tree->root == NULL)
    {
        tree->root = newNode; // 如果树为空，新节点为根节点
        return;
    }

    BinaryTreeNode *current = tree->root;
    BinaryTreeNode *parent = NULL;

    // 寻找合适的插入位置
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

// 前序遍历二叉树
void BinaryTree_PreOrder(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    BinaryTree_PreOrder(node->left);
    BinaryTree_PreOrder(node->right);
}

// 中序遍历二叉树
void BinaryTree_InOrder(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    BinaryTree_InOrder(node->left);
    printf("%d ", node->data);
    BinaryTree_InOrder(node->right);
}

// 后序遍历二叉树
void BinaryTree_PostOrder(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    BinaryTree_PostOrder(node->left);
    BinaryTree_PostOrder(node->right);
    printf("%d ", node->data);
}

// 搜索节点
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

// 释放二叉树的所有节点
void BinaryTree_Free(BinaryTreeNode *node)
{
    if (node == NULL)
        return;
    BinaryTree_Free(node->left);
    BinaryTree_Free(node->right);
    free(node);
}
