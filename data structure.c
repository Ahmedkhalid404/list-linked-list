#include <stdio.h>
#include <stdlib.h>
#include "data structure.h"
//******************************************************
//create
void create(List *l)
{
    l->head = NULL;
    l->size = 0;
}
//******************************************************
//is empty
int isEmpty(List l)
{
    return !l.size;
    //or  return l.head == NULL;
}
//******************************************************
//is full
int isFull(List l)
{
    return 0;
}
//******************************************************
//size
int listSize(List l)
{
    return l.size;
}
//******************************************************
//destroy
void destroyList(List *l)
{
    Node *q;
    while( l->head )
    {
        q = l->head->pNext;
        free(l->head);
        l->head = q;
    }
    l->size = 0;
}
//******************************************************
//traverse
void traverse(List *l, void (*operation)(type *el) )
{
    Node *q;
    q = l->head;
    while(q)
    {
        (*operation)(&q->el);
        q = q->pNext;
    }
}
//******************************************************
//insert
int insertList(List *l,type el,int p)
{
    if( p >= 0 && p <= l->size )
    {
        Node *pNewNode = (Node*) malloc( sizeof(Node) );
        if(pNewNode)//if malloc success to book memory
        {
            pNewNode->el = el;
            Node *q ;
            q = l->head;
            for(int i=0;i<p-1;i++)
            {
                q = q->pNext;
            }
            if(p==0)
            {
                pNewNode->pNext = q;//here q can be l->head
                l->head = pNewNode;//here l->head can't be q
                /*
                    because if you make q refer to pNewNode
                    you don't change l->head
                */
            }
            else
            {
                pNewNode->pNext = q->pNext;
                q->pNext = pNewNode;
            }

            l->size++;
            return 1;//success insert
        }
        else
            return 0;//fail to book size in memory
    }
    else
        return 0;//fail to insert
}
//******************************************************
//delete from list
int deleteEl_List(List *l,type *el,int p)
{
    if(  (p>=0) && (p < l->size) && ( !isEmpty(*l) )  )
    {
        if(p==0)
        {
            Node *q = l->head;
            *el = q->el;
            l->head = q->pNext;
            free(q);
        }
        else
        {
            Node *q = l->head;
            Node *d;
            for(int i=0;i<p-1;i++)
                q = q->pNext;
            d = q->pNext;
            q->pNext = d->pNext;
            *el = d->el;
            free(d);
        }
        l->size--;
        return 1;
    }
    else
        *el = -404;
        return 0;
}
//******************************************************
//retrieve elment
int retrieve(List *l,int *el,int p)
{
    if(p >= 0 && p <= l->size && !isEmpty(*l))
    {
        Node *q = l->head;
        for(int i=0;i<p;i++)
            q = q->pNext;
        *el = q->el;

        return 1;
    }
    else
        return 0;
}
//******************************************************
//replace elment
int replace(List *l,int el,int p)
{
    Node *q = l->head;
    for(int i=0;i<p;i++)
        q = q->pNext;
    q->el = el;
    return 1;
}
//******************************************************

