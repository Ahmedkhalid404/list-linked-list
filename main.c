#include <stdio.h>
#include <stdlib.h>
#include "data structure.h"
void print(type *el);
int main()
{
    List l;
    create(&l);
    for(int i=0;i<10;i++)
    {
        insertList(&l,i,0);
    }
    insertList(&l,55,5);
    insertList(&l,66,5);
    printf("size = %d\n",listSize(l));
    printf("------------------------------------\n");
    traverse(&l,&print);
    printf("------------------------------------\n");
    int el;
    deleteEl_List(&l,&el,5);
    deleteEl_List(&l,&el,0);
    deleteEl_List(&l,&el,0);
    traverse(&l,&print);
    printf("----------------\n");
    printf("size = %d\n",listSize(l));
    printf("-------------------\n");
    retrieve(&l,&el,6);
    printf("%d\n",el);
    replace(&l,88,0);
    retrieve(&l,&el,0);
    printf("%d\n",el);
    return 0;
}
void print(type *el)
{
    printf("%d\n",(*el));
}
