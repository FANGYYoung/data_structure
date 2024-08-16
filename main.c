#include "graph.h"
#include <stdio.h>

int main()
{
    Graph graph;
    int numVertices = 5;

    // ��ʼ��ͼ
    Graph_Init(&graph, numVertices);

    // ��ӱ�
    Graph_AddEdge(&graph, 0, 1, 10);
    Graph_AddEdge(&graph, 0, 4, 5);
    Graph_AddEdge(&graph, 1, 2, 3);
    Graph_AddEdge(&graph, 1, 4, 2);
    Graph_AddEdge(&graph, 2, 3, 7);
    Graph_AddEdge(&graph, 3, 0, 9);
    Graph_AddEdge(&graph, 4, 2, 1);

    // ��ӡͼ���ڽӾ���
    Graph_Print(&graph);

    // ��ȡ�ߵ�Ȩ��
    weight_t weight = Graph_GetEdgeWeight(&graph, 0, 4);
    if (weight != INF)
    {
        printf("Edge weight from 0 to 4: %d\n", weight);
    }
    else
    {
        printf("No edge from 0 to 4\n");
    }

    // ɾ����
    Graph_RemoveEdge(&graph, 0, 4);
    printf("After removing edge from 0 to 4:\n");
    Graph_Print(&graph);

    // �ͷ�ͼ�ڴ棨�����Ҫ��̬����ʱʹ�ã�
    Graph_Free(&graph);

    return 0;
}
