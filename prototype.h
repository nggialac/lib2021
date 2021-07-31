
#include "initial.h"

#ifndef prototype
#define prototype

//DateTime
int khoangCachNgay(DateTime nt1);

//DS
int soNgayQuaHan(listMuonTra lMT);

//DMS
void insertFirst_DMS(ptrNode_DanhMucSach &First, DanhMucSach x);
int insertAfter_DMS(ptrNode_DanhMucSach p, DanhMucSach x);
int insertLinkedList_DMS(ptrNode_DanhMucSach &First, ptrNode_DanhMucSach &Second, DanhMucSach x);
int deleteFirst_DMS(ptrNode_DanhMucSach &First);
int deleteAfter_DMS(ptrNode_DanhMucSach p);
int deleteOneByInfo_DMS(ptrNode_DanhMucSach &First, DanhMucSach x);
int traverse_DMS(ptrNode_DanhMucSach First);

// TODO: DG - BST
void initialize_NodeDG(ptrNode_DocGia &root);
//cay nhi phan tim kiem, lam sao de tu sinh ma cay van can bang?
void insert_NodeDG(ptrNode_DocGia &p, DocGia dg, int x); //!cay nhi phan tim kiem

void create_Tree(ptrNode_DocGia &root);

int preorder_NodeDG_NLR(ptrNode_DocGia p); //Co the dung giai thuat ko de quy

ptrNode_DocGia search_NodeDG(ptrNode_DocGia root, int x);


// void remove2Child_NodeDG(ptrNode_DocGia &p);
// int remove_NodeDG(ptrNode_DocGia &p, DocGia dg);

void saveDG(ptrNode_DocGia &root, fstream &fout);
void writeFile_NodeDG(ptrNode_DocGia &root, FILE &fout);
int writeFile_DG(ptrNode_DocGia &root, char *filePath);

void readFile_NodeDG(ptrNode_DocGia &root, FILE *fin);
int readFile_DG(ptrNode_DocGia &root, char *filePath);
int randomMaThe(ptrNode_DocGia root);
// TODO: DG - AVL To chuc can bang cho cay tim kiem


int NhapMaDocGia(int &msdg);
void do_MuonSach(ptrNode_DocGia &root, ListDauSach &listDauSach);
pDauSach findDSByISBN(ListDauSach listDS, string isbn);
//
int chonItems1(pDauSach &pDS, int &thuTuTrang, int tongtrang);
void ve_DMS(string key[], int nKey, int xDisplay[]);
void xuat_DS(string tenSach, string ISBN, string tacGia, string theLoai, int soTrang, int namXB);
int Menu_MS(ListDauSach &lDS, ptrNode_DocGia nDG);
int ChonItems(ListDauSach &lDS, int &thuTuTrang, int tongtrang);
//
void xoaManHinh_MT(int i);
void Xoa_DS_lineS();
void Xoa_DS_line(int locate);
void ve_DS(string key[], int nKey, int xDisplay[]);
void xuat_DStheoTrang(ListDauSach &lDS, int index);
void xuat_MT(ptrNode_MuonTra p, int i);
void xuatNgayThang(DateTime dt, int x, int y);
void xuat_DG_Page(ptrNode_DocGia t, DocGia *arr, int index);

#endif
