#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

// 定义数据类型
typedef int vertex_t; // 顶点的数据类型
typedef int weight_t; // 边权重的数据类型

#define MAX_VERTICES 100 // 最大顶点数
#define INF 9999         // 表示无穷大的常量，用于无连接的边

// 图的结构定义
typedef struct
{
    weight_t adjMatrix[MAX_VERTICES][MAX_VERTICES]; // 邻接矩阵
    int numVertices;                                // 顶点的数量
    int numEdges;                                   // 边的数量
} Graph;

// 函数声明

// 初始化图
void Graph_Init(Graph *graph, int numVertices);

// 添加边
bool Graph_AddEdge(Graph *graph, vertex_t start, vertex_t end, weight_t weight);

// 删除边
bool Graph_RemoveEdge(Graph *graph, vertex_t start, vertex_t end);

// 查找边的权重
weight_t Graph_GetEdgeWeight(Graph *graph, vertex_t start, vertex_t end);

// 打印图的邻接矩阵
void Graph_Print(Graph *graph);

// 释放图内存（如果需要动态分配内存时使用）
void Graph_Free(Graph *graph);

#endif // GRAPH_H
