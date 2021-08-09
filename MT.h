#include "prototype.h"

int soSachDangMuon(ptrNode_MuonTra lMT)
{
	int i = 0;
	ptrNode_MuonTra p = lMT;

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
	ptrNode_MuonTra p = new NodeMuonTra();
	if (p == NULL)
	{
		return NULL;
	}
	p->muonTra = data;
	p->next = NULL;
	return p;
}


void themDauList_MT(ptrNode_MuonTra &First, MuonTra x)
{
    ptrNode_MuonTra p;
    p = new NodeMuonTra();
    // p=GetNode_MT(x);
    p->muonTra = x;
    p->next = First;
    First = p;
}

bool timTenSach_MT(ptrNode_MuonTra lMT, string tensach, ListDauSach lDS)
{
	for (ptrNode_MuonTra p = lMT; p != NULL; p = p->next)
	{
		string temp = findDSByISBN(lDS, p->muonTra.maSach.substr(0,6))->tenSach;
		if ((temp.compare(tensach) == 0 && p->muonTra.trangThai == 0) || (temp.compare(tensach) == 0 && p->muonTra.trangThai == 2))
		{
			return true;
		}
	}
	return false;
}

int MatSach(ptrNode_MuonTra lMT)
{
    for (ptrNode_MuonTra p = lMT; p != NULL; p = p->next)
    {
        if (p->muonTra.trangThai == 2)
        {
            return 1;
        }
    }
    return 0;
}

int soNgayMuonMax(ptrNode_MuonTra lMT)
{
    int max = 0;
    int nngay;
    for (ptrNode_MuonTra p = lMT; p != NULL; p = p->next)
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