#include "prototype.h"

void initializeListMuonTra(listMuonTra &lMT)
{
	lMT.head = lMT.tail = NULL;
	lMT.n = 0;
}

int soSachDangMuon(listMuonTra lMT)
{
	int i = 0;
	ptrNode_MuonTra p = lMT.head;

	while (p != NULL)
	{
		if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2)
		{
			i++;
		}
		p = p->next;
	}
	return i;
}

ptrNode_MuonTra GetNode_MT(MuonTra data)
{
	ptrNode_MuonTra p = new NodeMuonTra;
	if (p == NULL)
	{
		return NULL;
	}
	p->muonTra = data;
	p->next = NULL;
	return p;
}

void themDauList_MT(listMuonTra &listMT, MuonTra data)
{
	// tao Node
	ptrNode_MuonTra p = GetNode_MT(data);

	if (listMT.head == NULL)
	{
		listMT.head = listMT.tail = p;
	}
	else
	{
		p->next = listMT.head;
		listMT.head = p;
	}
	// cout << "THEM DAU LIST: ";
	// cout << listMT.head->muonTra.maSach << endl;
	// cout << listMT.head->muonTra.isbn << endl;
	++listMT.n;
}

void themCuoiList_MT(listMuonTra &lMT, MuonTra data)
{
	// tao Node
	ptrNode_MuonTra p = GetNode_MT(data);
	if (lMT.head == NULL)
	{
		lMT.head = lMT.tail = p;
	}
	else
	{
		lMT.tail->next = p;
		lMT.tail = p;
	}
	// cout << "THEM CUOI LIST: ";
	++lMT.n;
}

bool timTenSach_MT(listMuonTra lMT, string tensach, ListDauSach lDS)
{
	for (ptrNode_MuonTra p = lMT.head; p != NULL; p = p->next)
	{
		string temp = findDSByISBN(lDS, p->muonTra.isbn)->tenSach;
		if ((temp.compare(tensach) == 0 && p->muonTra.trangThai == 0) || (temp.compare(tensach) == 0 && p->muonTra.trangThai == 2))
		{
			return true;
		}
	}
	return false;
}

int MatSach(listMuonTra lMT)
{
    for (ptrNode_MuonTra p = lMT.head; p != NULL; p = p->next)
    {
        if (p->muonTra.trangThai == 2)
        {
            return 1;
        }
    }
    return 0;
}

int soNgayMuonMax(listMuonTra lMT)
{
    int max = 0;
    int nngay;
    for (ptrNode_MuonTra p = lMT.head; p != NULL; p = p->next)
    {
        if ((p->muonTra.trangThai == 0) || (p->muonTra.trangThai == 2))
        {
            nngay = khoangCachNgay(p->muonTra.ngayMuon);
            if (max < nngay)
            {
                max = nngay;
            }
        }
    }
    return max;
}