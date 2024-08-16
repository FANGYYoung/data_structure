#include "graph.h"
#include <stdio.h>

// 初始化图
void Graph_Init(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    // 初始化邻接矩阵，所有边权重为 INF（表示无连接）
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0;  // 自己到自己的边权重为 0
            } else {
                graph->adjMatrix[i][j] = INF;  // 其他边初始化为无穷大
            }
        }
    }
}

// 添加边
bool Graph_AddEdge(Graph* graph, vertex_t start, vertex_t end, weight_t weight) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        return false;  // 无效的顶点
    }

    graph->adjMatrix[start][end] = weight;
    graph->numEdges++;
    return true;
}

// 删除边
bool Graph_RemoveEdge(Graph* graph, vertex_t start, vertex_t end) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        return false;  // 无效的顶点
    }

    graph->adjMatrix[start][end] = INF;  // 恢复为无连接状态
    graph->numEdges--;
    return true;
}

// 查找边的权重
weight_t Graph_GetEdgeWeight(Graph* graph, vertex_t start, vertex_t end) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        return INF;  // 无效的顶点
    }
    return graph->adjMatrix[start][end];
}

// 打印图的邻接矩阵
void Graph_Print(Graph* graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", graph->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

// 释放图内存（如果有动态分配内存可以在这里释放）
void Graph_Free(Graph* graph) {
    // 当前未使用动态分配，所以不需要操作
}
