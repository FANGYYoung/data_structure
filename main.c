#include "graph.h"
#include <stdio.h>

int main()
{
    Graph graph;
    int numVertices = 5;

    // 初始化图
    Graph_Init(&graph, numVertices);

    // 添加边
    Graph_AddEdge(&graph, 0, 1, 10);
    Graph_AddEdge(&graph, 0, 4, 5);
    Graph_AddEdge(&graph, 1, 2, 3);
    Graph_AddEdge(&graph, 1, 4, 2);
    Graph_AddEdge(&graph, 2, 3, 7);
    Graph_AddEdge(&graph, 3, 0, 9);
    Graph_AddEdge(&graph, 4, 2, 1);

    // 打印图的邻接矩阵
    Graph_Print(&graph);

    // 获取边的权重
    weight_t weight = Graph_GetEdgeWeight(&graph, 0, 4);
    if (weight != INF)
    {
        printf("Edge weight from 0 to 4: %d\n", weight);
    }
    else
    {
        printf("No edge from 0 to 4\n");
    }

    // 删除边
    Graph_RemoveEdge(&graph, 0, 4);
    printf("After removing edge from 0 to 4:\n");
    Graph_Print(&graph);

    // 释放图内存（如果需要动态分配时使用）
    Graph_Free(&graph);

    return 0;
}
