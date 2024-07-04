#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    linklist H,p,H1;
    int value,sum;

    H = linklist_create();
    H1 = linklist_create();
    if (H == NULL)
    {
        return -1;
    }
    printf("input:");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        linklist_tail_insert(H, value);
        printf("input:");
    }
    while (1)
    {
        printf("input2:");
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        linklist_tail_insert(H1, value);
        
    }
    linklist_show(H);
    linklist_merge(H, H1);
    linklist_show(H);
    return 0;
}
