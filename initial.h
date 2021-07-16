
#ifndef initial
#define initial

#define MAX_LIST 1000

//---DANH MUC SACH (DSLK)---
typedef struct DanhMucSach
{
    char *maSach;
    int trangThai;
    char *viTri;
};

struct NodeDanhMucSach
{
    DanhMucSach danhMucSach;
    NodeDanhMucSach *next;
};
typedef NodeDanhMucSach *ptrNode_DanhMucSach;
ptrNode_DanhMucSach First_DanhMucSach = NULL;
// ptrNode_DanhMucSach Last_DanhMucSach = NULL;

//----DAU SACH---
typedef struct DauSach
{
    int isbn;
    char *tenSach;
    int namXuatBan;
    char *theLoai;
    DanhMucSach *ptrDanhMucSach;
};

typedef struct ListDauSach
{
    int n = 0;
    DauSach nodes[MAX_LIST];
};
ListDauSach listDauSach;

//---MUON TRA---
typedef struct DateTime
{
    int ngay;
    int thang;
    int nam;
};

typedef struct MuonTra
{
    char *maSach;
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
    char ho[50];
    char ten[25];
    int phai;
    int trangThai;
    MuonTra *ptrMuonTra;
};

struct NodeDocGia
{
    int key;
    DocGia info;
    struct NodeDocGia *left;
    struct NodeDocGia *right;
};
typedef struct NodeDocGia *ptrNode_DocGia;
ptrNode_DocGia tree = NULL;



#endif
