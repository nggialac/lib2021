#include "prototype.h"

int soSachDangMuon(ptrNode_MuonTra nMT) {
	int i = 0;
	for (ptrNode_MuonTra p = NULL; p != NULL; p = p->next) {
		if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2) {
			i++;
		}
	}
	return i;
}

ptrNode_MuonTra GetNode_MT(MuonTra data) {
	ptrNode_MuonTra p = new NodeMuonTra;
	if (p == NULL) {
		return NULL;
	}
	p->muonTra = data;
	p->next = NULL;
	return (p);
}

void themDauList_MT(ptrNode_MuonTra &First, MuonTra data) {
	// tao Node
	ptrNode_MuonTra p = GetNode_MT(data);
	if (First == NULL) {
		First = p;
	} else {
		p->next = First;
		First = p;
	}
	cout<<"THEM DAU LIST: ";
	cout<<First->muonTra.maSach<<endl;
	cout<<First->muonTra.isbn<<endl;
	++First->n;
}
