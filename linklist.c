#include "linklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*----------------------------------------------------------------
函数功能：链表的创建
入口参数:
        void
返回参数：
        创建完成的空间
------------------------------------------------------------------*/
linklist linklist_create(void)
{
    linklist H;
    H = (linklist)malloc(sizeof(listnode));
    if (H == NULL)
    {
        printf("malloc failure\n");
        return H;
    }
    H->data = 0;
    H->next = NULL;
    return H;
}

/*----------------------------------------------------------------
函数功能：链表的遍历并打印
入口参数:
        linklist H：单链表变量
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int linklist_show(linklist H)
{
    linklist p;
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    p = H;
    while (p->next != NULL)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    puts("\n");
    return 0;
}

/*----------------------------------------------------------------
函数功能：链表的尾部插入
入口参数:
        linklist H：单链表变量
        data_t data：要插入的数据
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int linklist_tail_insert(linklist H, data_t data)
{
    // create a new node
    linklist p, q;
    if ((p = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc failure\n");
        return -1;
    }
    p->data = data;
    p->next = NULL;
    // find the tail node
    q = H;
    while (q->next != NULL)
    {
        q = q->next;
    }
    // insert data
    q->next = p;
    return 0;
}

/*----------------------------------------------------------------
函数功能：链表位置检索
入口参数:
        linklist H：单链表变量
        int pos：要插入的数据
返回参数：
        p：节点
------------------------------------------------------------------*/
linklist linklist_locate(linklist H, int pos)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return NULL;
    }
    if (pos == -1)
    {
        return H;
    }

    linklist p;
    p = H;
    for (int i = -1; i < pos; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("pos is invalid\n");
            return NULL;
        }
    }
    return p;
}

/*----------------------------------------------------------------
函数功能：链表的中间插入
入口参数:
        linklist H：单链表变量
        data_t data：要插入的数据
        int pos：插入的位置
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int linklist_insert(linklist H, data_t data, int pos)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    linklist p, q;
    p = linklist_locate(H, pos - 1);
    if (p == NULL)
    {
        printf("pos is invalid\n");
        return -1;
    }

    if ((q = linklist_create()) == NULL)
    {
        printf("malloc error\n");
        return -1;
    }

    q->data = data;
    q->next = p->next;
    p->next = q;

    return 0;
}

/*----------------------------------------------------------------
函数功能：链表的单节点的删除
入口参数:
        linklist H：单链表变量
        int pos：要删除节点的位置
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int linklist_delete(linklist H, int pos)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    if (pos < -1)
    {
        printf("pos is invalid\n");
        return -1;
    }

    linklist p, q;
    p = linklist_locate(H, pos - 1);
    if (p == NULL)
    {
        return -1;
    }
    if (p->next == NULL)
    {
        printf("delete pos error\n");
        return -1;
    }

    q = p->next;
    p->next = q->next;

    free(q);
    q = NULL;
    return 0;
}

/*----------------------------------------------------------------
函数功能：链表的释放
入口参数:
        linklist H：单链表变量
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int linklist_free(linklist H)
{
    if (H == NULL)
    {
        return -1;
    }

    linklist p;
    p = H;

    while (H != NULL)
    {
        p = H;
        printf("free:%d ", p->data);
        free(p);
        H = H->next;
    }
    return 0;
}

/*----------------------------------------------------------------
函数功能：链表的反转
入口参数:
        linklist H：单链表变量
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int linklist_reverse(linklist H)
{
    linklist p, q;

    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    if (H->next == NULL || H->next->next == NULL)
    {
        return -1;
    }

    p = H->next->next;
    H->next->next = NULL;

    while (p != NULL)
    {
        q = p;
        p = p->next;

        q->next = H->next;
        H->next = q;
    }

    return 0;
}

/*----------------------------------------------------------------
函数功能：链表的两相邻节点和的最大值
入口参数:
        linklist H：单链表变量
        data_t *sum：相邻节点和的最大值
返回参数：
        r：最大值的首节点
------------------------------------------------------------------*/
linklist list_adjmax(linklist H, data_t *sum)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return NULL;
    }
    if (H->next == NULL || H->next->next == NULL || H->next->next->next == NULL)
    {
        printf("H is single\n");
        return NULL;
    }

    linklist p, q, r;
    q = H->next;
    p = H->next->next;
    r = q;
    *sum = q->data + p->data;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
        if (*sum < p->data + q->data)
        {
            *sum = p->data + q->data;
            r = q;
        }
    }
    return r;
}

/*----------------------------------------------------------------
函数功能：两个有序链表的合并并存入1中
入口参数:
        linklist H1：单链表变量1
        linklist H2：单链表变量2
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int linklist_merge(linklist H1, linklist H2)
{
    if (H1 == NULL || H2 == NULL)
    {
        printf("H1 or H2 is NULL\n");
        return -1;
    }
    linklist p, q, r;
    p = H1->next;
    q = H2->next;
    r = H1;
    while (p && q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            p = p->next;
            r = r->next;
            r->next = NULL;
        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
            r->next = NULL;
        }
        if (p == NULL)
        {
            r->next = q;
        }
        else
        {
            r->next = p;
        }
    }
    return 0;
}