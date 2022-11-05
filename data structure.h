#ifndef QUEUE
#define QUEUE

#define MAX 500
typedef int type;
typedef struct NodeList
{
    type el;
    struct NodeList *pNext;
}Node;
typedef struct list
{
    Node *head;
    int size;
}List;
//******************************************************
//******************************************************
//create
void create(List *l);
//******************************************************
//is empty
int isEmpty(List l);
//******************************************************
//is full
int isFull(List l);
//******************************************************
//size
int listSize(List l);
//******************************************************
//destroy
void destroyList(List *l);
//******************************************************
//traverse
void traverse(List *l, void (*operation)(type *el) );
//******************************************************
//insert
int insertList(List *l,type el,int p);
//******************************************************
//delete from list
int deleteEl_List(List *l,type *el,int p);
//******************************************************
//retrieve elment
int retrieve(List *l,int *el,int p);
//******************************************************
//replace elment
int replace(List *l,int el,int p);
//******************************************************
#endif // QUEUE







