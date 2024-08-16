#include "graph.h"
#include <stdio.h>

// ��ʼ��ͼ
void Graph_Init(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    // ��ʼ���ڽӾ������б�Ȩ��Ϊ INF����ʾ�����ӣ�
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0;  // �Լ����Լ��ı�Ȩ��Ϊ 0
            } else {
                graph->adjMatrix[i][j] = INF;  // �����߳�ʼ��Ϊ�����
            }
        }
    }
}

// ��ӱ�
bool Graph_AddEdge(Graph* graph, vertex_t start, vertex_t end, weight_t weight) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        return false;  // ��Ч�Ķ���
    }

    graph->adjMatrix[start][end] = weight;
    graph->numEdges++;
    return true;
}

// ɾ����
bool Graph_RemoveEdge(Graph* graph, vertex_t start, vertex_t end) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        return false;  // ��Ч�Ķ���
    }

    graph->adjMatrix[start][end] = INF;  // �ָ�Ϊ������״̬
    graph->numEdges--;
    return true;
}

// ���ұߵ�Ȩ��
weight_t Graph_GetEdgeWeight(Graph* graph, vertex_t start, vertex_t end) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        return INF;  // ��Ч�Ķ���
    }
    return graph->adjMatrix[start][end];
}

// ��ӡͼ���ڽӾ���
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

// �ͷ�ͼ�ڴ棨����ж�̬�����ڴ�����������ͷţ�
void Graph_Free(Graph* graph) {
    // ��ǰδʹ�ö�̬���䣬���Բ���Ҫ����
}
