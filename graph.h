#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

// ������������
typedef int vertex_t; // �������������
typedef int weight_t; // ��Ȩ�ص���������

#define MAX_VERTICES 100 // ��󶥵���
#define INF 9999         // ��ʾ�����ĳ��������������ӵı�

// ͼ�Ľṹ����
typedef struct
{
    weight_t adjMatrix[MAX_VERTICES][MAX_VERTICES]; // �ڽӾ���
    int numVertices;                                // ���������
    int numEdges;                                   // �ߵ�����
} Graph;

// ��������

// ��ʼ��ͼ
void Graph_Init(Graph *graph, int numVertices);

// ��ӱ�
bool Graph_AddEdge(Graph *graph, vertex_t start, vertex_t end, weight_t weight);

// ɾ����
bool Graph_RemoveEdge(Graph *graph, vertex_t start, vertex_t end);

// ���ұߵ�Ȩ��
weight_t Graph_GetEdgeWeight(Graph *graph, vertex_t start, vertex_t end);

// ��ӡͼ���ڽӾ���
void Graph_Print(Graph *graph);

// �ͷ�ͼ�ڴ棨�����Ҫ��̬�����ڴ�ʱʹ�ã�
void Graph_Free(Graph *graph);

#endif // GRAPH_H
