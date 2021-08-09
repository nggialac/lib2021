#include "prototype.h"

//void initializeListNode_DMS(listNodeDMS &ln_dms)
//{
//    ln_dms.n = 0;
//    ln_dms.FirstNode_DanhMucSach = ln_dms.LastNode_DanhMucSach = NULL;
//    // ln_dms.LastNode_DanhMucSach = NULL;
//}

ptrNode_DanhMucSach getNode_DMS(DanhMucSach data)
{
    ptrNode_DanhMucSach p = new NodeDanhMucSach;
    if (p == NULL)
        return NULL;
    p->danhMucSach = data;
    p->next = NULL;
    return (p);
}

//void themCuoiList_DMS(listNodeDMS &ln_dms, DanhMucSach data)
//{
//    ptrNode_DanhMucSach p = new NodeDanhMucSach;
//    p->danhMucSach = data;
//    p->next = NULL;
//    if (ln_dms.FirstNode_DanhMucSach == NULL)
//    {
//        ln_dms.FirstNode_DanhMucSach = ln_dms.LastNode_DanhMucSach = p;
//    }
//    else
//    {
//        ln_dms.LastNode_DanhMucSach->next = p;
//        ln_dms.LastNode_DanhMucSach = p;
//    }
//    ln_dms.n++;
//}

//int insertAfter_DMS(ptrNode_DanhMucSach p, DanhMucSach x)
//{
//    ptrNode_DanhMucSach q;
//    if (p == NULL)
//        return 0;
//    else
//    {
//        q = new NodeDanhMucSach();
//        q->danhMucSach = x;
//        q->next = p->next;
//        p->next = q;
//    }
//    return 1;
//}

void insertFirst_DMS(ptrNode_DanhMucSach &First, DanhMucSach x)
{
    ptrNode_DanhMucSach p;
    // p = new NodeDanhMucSach();
    p=getNode_DMS(x);
    p->danhMucSach = x;
    p->next = First;
    First = p;
}

ptrNode_DanhMucSach search_DMS_ViTri(ptrNode_DanhMucSach First, int pos)
{
    int count = -1;
    for (ptrNode_DanhMucSach temp = First; temp != NULL; temp = temp->next)
    {
        count++;
        if (pos == count)
        {
            return temp;
        }
    }
    return NULL;
}

ptrNode_DanhMucSach search_DMS_MaSach(pDauSach pDS, string masach)
{
    ptrNode_DanhMucSach p;
    p = pDS->First_DMS;
    while (p != NULL && p->danhMucSach.maSach.compare(masach) == 0)
        p = p->next;
    return (p);
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

int deleteOneByInfo_DMS(ptrNode_DanhMucSach &First, string ms)
{
    ptrNode_DanhMucSach p = First;
    if (First == NULL)
        return 0;
    if (ms.compare(p->danhMucSach.maSach))
    {
        deleteFirst_DMS(First);
        return 1;
    }
    for (p = First; p->next != NULL && ms.compare(p->next->danhMucSach.maSach) != 0; p = p->next)
        ;
    if (p->next != NULL)
    {
        deleteAfter_DMS(p);
        return 1;
    }
    return 0;
}

int traverse_DMS(ptrNode_DanhMucSach &First)
{
    ptrNode_DanhMucSach p;
    int count = 0;
    if (First == NULL)
        return 0;
    for (p = First; p != NULL; p = p->next)
    {
        cout << p->danhMucSach.maSach;
        cout << " " + p->danhMucSach.trangThai;
        cout << " " + p->danhMucSach.viTri;
        count++;
    }
    return count;
}

bool CheckMuon_DMS(ptrNode_DanhMucSach nDMS)
{
    for (ptrNode_DanhMucSach p = nDMS; p != NULL; p = p->next)
    {
        if (p->danhMucSach.trangThai == 1)
        {
            return true;
        }
    }
    return false;
}
