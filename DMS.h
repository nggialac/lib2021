#include "prototype.h"

#ifndef DMS
#define DMS

void initializeListNode_DMS(listNodeDMS &ln_dms)
{
    ln_dms.n = 0;
    ln_dms.FirstNode_DanhMucSach = ln_dms.LastNode_DanhMucSach = NULL;
    // ln_dms.LastNode_DanhMucSach = NULL;
}

ptrNode_DanhMucSach getNode_DMS(DanhMucSach data)
{
    ptrNode_DanhMucSach p = new NodeDanhMucSach;
    if (p == NULL)
        return NULL;
    p->danhMucSach = data;
    p->next = NULL;
    return (p);
}

void themCuoiList_DMS(listNodeDMS &ln_dms, DanhMucSach data)
{
    ptrNode_DanhMucSach p = new NodeDanhMucSach;
    p->danhMucSach = data;
    p->next = NULL;
    if (ln_dms.FirstNode_DanhMucSach == NULL)
    {
        ln_dms.FirstNode_DanhMucSach = ln_dms.LastNode_DanhMucSach = p;
    }
    else
    {
        // ptrNode_DanhMucSach temp = ln_dms.FirstNode_DanhMucSach;
        // while (temp->next != NULL)
        //     temp = temp->next;

        // //6. Change the next of last node to new node
        // temp->next = p;

        ln_dms.LastNode_DanhMucSach->next = p;
        ln_dms.LastNode_DanhMucSach = p;
        // cout<<"them cuoi!!!";
        // cout<<ln_dms.LastNode_DanhMucSach->danhMucSach.maSach;
    }
    ln_dms.n++;
}

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

int isFull_DS(ListDauSach listDS)
{
    return listDS.n == MAX_LIST;
}

int add_DS(ListDauSach &listDS, pDauSach &pDS)
{
    if (isFull_DS(listDS))
    {
        return 0;
    }
    listDS.nodes[listDS.n++] = pDS;
    // cout << listDS.nodes[listDS.n]->tenSach;
    return 1;
}

ptrNode_DanhMucSach Search_DMS_ViTri(ptrNode_DanhMucSach dms, int pos) {
	int count = -1;
	for (ptrNode_DanhMucSach temp = dms; temp != NULL; temp = temp->next) {
		count++;
		if (pos == count) {
			return temp;
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

int traverse_DMS(listNodeDMS ln_dms)
{
    ptrNode_DanhMucSach p;
    int count = 0;
    if (ln_dms.FirstNode_DanhMucSach == NULL)
        return 0;
    for (p = ln_dms.FirstNode_DanhMucSach; p != NULL; p = p->next)
    {
        cout << p->danhMucSach.maSach;
        cout << " " + p->danhMucSach.trangThai;
        cout << " " + p->danhMucSach.viTri;
        count++;
    }
    return count;
}

int readFile_DS(ListDauSach &listDS)
{
    fstream fileIn;
    DauSach info;
    fileIn.open("DS.txt", ios::in);
    pDauSach pDS;
    DanhMucSach dms;
    int soDauSach, soSach;
    if (fileIn.is_open())
    {
        string temp;
        fileIn >> soDauSach;
        cout << "So dau Sach: ";
        cout << soDauSach << endl;
        getline(fileIn, temp);
        for (int i = 0; i < soDauSach; i++)
        {
            pDS = new DauSach;
            if (pDS == NULL)
                continue;
            // load thong tin vao bien tam.
            getline(fileIn, info.tenSach);
            getline(fileIn, info.isbn);

            getline(fileIn, info.tacGia);
            getline(fileIn, info.theLoai);

            fileIn >> info.soTrang;
            fileIn >> info.namXuatBan;
            fileIn >> info.soLanMuon;
            // load thong tin vao dau sach
            *(pDS) = info; //cout<<*(pDS)->isbn;
            fileIn >> soSach;
            getline(fileIn, temp);
            initializeListNode_DMS(pDS->ptrListNode_DMS);
            for (int j = 0; j < soSach; j++)
            {
                getline(fileIn, dms.maSach);
                fileIn >> dms.trangThai;
                getline(fileIn, temp);
                getline(fileIn, dms.viTri);
                themCuoiList_DMS(pDS->ptrListNode_DMS, dms);
            }
            add_DS(listDS, pDS);
        }
    }
    else
    {
        cout << "file DS.txt khong tim thay! ";
        return 0;
    }

    for (int j = 0; j < listDS.n; j++)
    {
        cout << listDS.nodes[j]->tenSach;
    }
    fileIn.close();
    return 1;
}

#endif
