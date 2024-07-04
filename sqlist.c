/*----------------------------------------------------------------
C文件功能：线性表的基本功能
线性表优点：存储密度高，能够随机存取
      缺点：1）要求系统提供一片较大的连续存储空间
            2）插入删除等运算耗时，且存在元素在存储器中成片移动的现象
------------------------------------------------------------------*/



#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*----------------------------------------------------------------
函数功能：创建线性表
入口参数:
        void
返回参数：
        sqlink--结构体变量
------------------------------------------------------------------*/
sqlink list_create()
{
    sqlink L;
    L = malloc(sizeof(sqlist));
    if (L == NULL)
    {
        printf("list malloc failure\n");
        return L;
    }
    //initialize to 0
    memset(L, 0, sizeof(sqlist));
    L->last = -1;
    
    return L;
}

/*----------------------------------------------------------------
函数功能：删除线性表
入口参数:
        sqlink L
返回参数：
        0：删除成功
        -1：线性表为空
------------------------------------------------------------------*/
int list_free(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    free(L);
    L = NULL;
    return 0;
}


/*----------------------------------------------------------------
函数功能：将线性表清零
入口参数:
        sqlink L：线性表变量
返回参数：
        -1：线性表为空
         0：线性表已清零
------------------------------------------------------------------*/
int list_clear(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    memset(L, 0, sizeof(sqlist));
    return 0;
}

/*----------------------------------------------------------------
函数功能：判断线性表是否为空
入口参数:
        sqlink L：线性表变量
返回参数：
        1：空
        0：非空
------------------------------------------------------------------*/
int list_empty(sqlink L)
{
    if (L->last == -1)
        return 1;
    else
        return 0;
}

/*----------------------------------------------------------------
函数功能：计算线性表的长度
入口参数:
        sqlink L：线性表变量
返回参数：
        线性表长度
------------------------------------------------------------------*/
int list_length(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    
    return (L->last+1);
}

/*----------------------------------------------------------------
函数功能：查找线性表中是否存在value值
入口参数:
        sqlink L：线性表变量
        data_t value：要查找的值
返回参数：
        -1：没有
        i：线性表中value的位置
------------------------------------------------------------------*/
int list_locate(sqlink L, data_t value)
{
    for (int i = 0; i < L->last; i++)
    {
        if (value == L->data[i])
        {
            return i;
        }
    }
    return -1;
}

/*----------------------------------------------------------------
函数功能：在线性表中插入一个值
入口参数:
        sqlink L：线性表变量
        data_t value：插入的值
        int pos：插入的位置
返回参数：
        -1：插入失败
        0：插入成功
------------------------------------------------------------------*/
int list_insert(sqlink L, data_t value, int pos)
{
    if (L->last > N-1)
    {    
        printf("list full\n");
        return -1;
    }
    if (pos <0 || pos > L->last+1)
    {
        printf("list pos error\n");
        return -1;
    }
    
    for (int i = L->last; i >= pos; i--)
    {
        L->data[i+1] = L->data[i];
    }
    L->data[pos] = value;
    L->last++;
    return 0;
}

/*----------------------------------------------------------------
函数功能：打印线性表
入口参数:
        sqlink L：线性表变量
返回参数：
        -1：线性表为空
        0：打印完成
------------------------------------------------------------------*/
int list_show(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    if (L->last == -1)
    {
        printf("list is empty\n");
    }
    for (int i = 0; i <= L->last; i++)
    {
        printf("%d\n", L->data[i]);
    }
    puts("\n");
    return 0;
}

/*----------------------------------------------------------------
函数功能：线性表元素的删除
入口参数:
        sqlink L：线性表变量
        pos：要删除的位置
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int list_delete(sqlink L, int pos)
{
    if (L->last == -1)
    {
        printf("list is empty\n");
        return -1;
    }
    if (L->last > N-1)
    {    
        printf("list full\n");
        return -1;
    }
    if (pos <0 || pos > L->last+1)
    {
        printf("list pos error\n");
        return -1;
    }


    for (int i = pos; i <= L->last; i++)
    {
        L->data[i] = L->data[i+1];
    }


    L->last--;
    return 0;
}

/*----------------------------------------------------------------
函数功能：两个线性表的合并
入口参数:
        sqlink L1：线性表1变量
        sqlink L2：线性表2变量
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int list_merge(sqlink L1, sqlink L2)
{
    if (L1 == NULL || L2 == NULL)
    {
        printf("list empty\n");
        return -1;
    }
    int ret = 0;
    for (int i = 0; i <= L2->last; i++)
    {
        ret = list_locate(L1, L2->data[i]);
        if (ret == -1)
        {
            if (list_insert(L1, L2->data[i], L1->last+1) == -1)
            {
                return -1;
            }
        }
    }
    return 0;
}

/*----------------------------------------------------------------
函数功能：删除线性表中的重复元素
入口参数:
        sqlink L：线性表变量
返回参数：
        -1：出错
        0：成功
------------------------------------------------------------------*/
int list_purge(sqlink L)
{
    if (L == NULL || L->last == -1)
    {
        printf("list empty\n");
        return -1;
    }
    int i = 1,j = 0;
    while (i <= L->last)
    {
        j = i-1;
        while (j >= 0)
        {
            if (L->data[i] == L->data[j])
            {
                list_delete(L,i);
                break;
            }
            else
            j--;
            if (j<0)
            {
                i++;
            }
        }
        
    }
    
}