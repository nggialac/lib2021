#pragma once
#ifndef initial
#define initial

#define MAX_LIST 1000

//---DANH MUC SACH (DSLK)---
typedef struct DanhMucSach
{
    string maSach;
    int trangThai;
    string viTri;
};

struct NodeDanhMucSach
{
    DanhMucSach danhMucSach;
    NodeDanhMucSach *next;
};
// typedef NodeDanhMucSach node_DanhMucSach;
typedef NodeDanhMucSach *ptrNode_DanhMucSach;
struct ListNodeDMS {
	int n;
	ptrNode_DanhMucSach FirstNode_DanhMucSach;
    ptrNode_DanhMucSach LastNode_DanhMucSach;
};
typedef ListNodeDMS listNodeDMS;

// ptrNode_DanhMucSach First_DanhMucSach = NULL;
// ptrNode_DanhMucSach Last_DanhMucSach = NULL;

//----DAU SACH---
struct DauSach
{
    string isbn;
    string tenSach;
    int soTrang;
    string tacGia;
    int namXuatBan;
    string theLoai;
    listNodeDMS *ptrListNode_DMS;
    int soLanMuon = 0;
};
typedef struct DauSach *pDauSach;

struct ListDauSach
{
    int n = 0;
    DauSach *nodes[MAX_LIST];
};
typedef struct ListDauSach listDauSach;
listDauSach linkedList;

//---MUON TRA---
typedef struct DateTime
{
    int ngay;
    int thang;
    int nam;
};

typedef struct MuonTra
{
    string maSach;
    DateTime ngayMuon;
    DateTime ngayTra;
    int trangThai;
};

struct NodeMuonTra
{
    MuonTra muonTra;
    NodeMuonTra *next;
};
typedef NodeMuonTra *ptrNode_MuonTra;
ptrNode_MuonTra First_MuonTra = NULL;

//---DOC GIA---

typedef struct DocGia
{
    int maThe; //! MATHE (số nguyên ngẫu nhiên tự động)
    string ho;
    string ten;
    int phai;
    int trangThai;
    MuonTra *ptrMuonTra;
};

struct NodeDocGia
{
    int key;
    DocGia info;
    int nNodeDocGia = 0;
    struct NodeDocGia *left;
    struct NodeDocGia *right;
};
typedef struct NodeDocGia *ptrNode_DocGia;
ptrNode_DocGia tree = NULL;

#endif
