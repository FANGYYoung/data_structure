#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h> // 为布尔类型引入 true/false 定义

// 定义数据类型
typedef int data_t;

// 二叉树节点结构定义
typedef struct BinaryTreeNode
{
    data_t data;                  // 数据域
    struct BinaryTreeNode *left;  // 左子节点指针
    struct BinaryTreeNode *right; // 右子节点指针
} BinaryTreeNode;

// 二叉树结构定义
typedef struct
{
    BinaryTreeNode *root; // 根节点指针
} BinaryTree;

// 函数声明

// 初始化二叉树
void BinaryTree_Init(BinaryTree *tree);

// 创建新节点
BinaryTreeNode *BinaryTree_CreateNode(data_t value);

// 插入节点到二叉树中
void BinaryTree_Insert(BinaryTree *tree, data_t value);

// 前序遍历二叉树
void BinaryTree_PreOrder(BinaryTreeNode *node);

// 中序遍历二叉树
void BinaryTree_InOrder(BinaryTreeNode *node);

// 后序遍历二叉树
void BinaryTree_PostOrder(BinaryTreeNode *node);

// 搜索节点
BinaryTreeNode *BinaryTree_Search(BinaryTreeNode *node, data_t value);

// 释放二叉树
void BinaryTree_Free(BinaryTreeNode *node);

#endif // BINARY_TREE_H
