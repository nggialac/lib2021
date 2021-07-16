#include "prototype.h"


#ifndef DMS
#define DMS
void insertFirst_DMS(ptrNode_DanhMucSach &First, DanhMucSach x)
{
    ptrNode_DanhMucSach p;
    p = new NodeDanhMucSach();
    p->danhMucSach = x;
    p->next = First;
    First = p;
}

int insertAfter_DMS(ptrNode_DanhMucSach p, DanhMucSach x)
{
    ptrNode_DanhMucSach q;
    if (p == NULL)
        return 0;
    else
    {
        q = new NodeDanhMucSach();
        q->danhMucSach = x;
        q->next = p->next;
        p->next = q;
    }
    return 1;
}

ptrNode_DanhMucSach search_DMS(ptrNode_DanhMucSach First, char *ms)
{
    ptrNode_DanhMucSach p;
    for (p = First; p != NULL; p = p->next)
    {
        if (strcmp(p->danhMucSach.maSach, ms) == 0)
        {
            return p;
        }
    }
    return NULL;
}

int deleteFirst_DMS(ptrNode_DanhMucSach &First)
{
    ptrNode_DanhMucSach p;
    if (First == NULL)
        return 0;
    p = First;
    First = p->next;
    delete p;
    return 1;
}

int deleteAfter_DMS(ptrNode_DanhMucSach p)
{
    ptrNode_DanhMucSach q; //nut can xoa sau p
    if (p == NULL || p->next == NULL)
        return 0;
    q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}

int deleteOneByInfo_DMS(ptrNode_DanhMucSach &First, char *ms)
{
    ptrNode_DanhMucSach p = First;
    if (First == NULL)
        return 0;
    if (strcmp(p->danhMucSach.maSach, ms))
    {
        deleteFirst_DMS(First);
        return 1;
    }
    for (p = First; p->next != NULL && strcmp(p->next->danhMucSach.maSach, ms) != 0; p = p->next)
        ;
    if (p->next != NULL)
    {
        deleteAfter_DMS(p);
        return 1;
    }
    return 0;
}

int traverse_DMS(ptrNode_DanhMucSach First)
{
    ptrNode_DanhMucSach p;
    int count = 0;
    if (First == NULL)
        return 0;
    for (p = First; p != NULL; p = p->next)
    {
        count++;
    }
    return count;
}

#endif
