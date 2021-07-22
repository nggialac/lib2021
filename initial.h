#pragma once
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <time.h>
#include <cstdio>
#include <conio.h>
#include <dos.h>
#include <iostream>
#include <ios>
#include <iomanip>
#include <math.h>
using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::max;
using std::string;
using std::stringstream;
using std::setfill;
using std::setw;

extern int nNodeDocGia = 0;
extern int indexDG = 0;
extern int MAX_RAND = 500;
extern int toaDo = 0;

#define MAX_LIST 1000
#define BACKSPACE 8
#define ENTER 13
#define ESC 27

#define Enter 13
#define PASSWORD "abcdef"
#define BLACK 0
#define WHITE 7
#define LIGHT_RED 12

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define F1 59
#define F2 60
#define F3 61
#define KEY_F9 67
#define F5 63
#define PAGE_DOWN 81
#define PAGE_UP 73

#define NUMBER_LINES 29

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
struct ListNodeDMS
{
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
    listNodeDMS ptrListNode_DMS;
    //
    int soLanMuon = 0;
};
typedef struct DauSach *pDauSach;

struct ListDauSach
{
    int n = 0;
    DauSach *nodes[MAX_LIST];
};
typedef struct ListDauSach;
ListDauSach listDS;

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
    //
    string isbn;
};

struct NodeMuonTra
{
    MuonTra muonTra;
    NodeMuonTra *next;
};
typedef NodeMuonTra *ptrNode_MuonTra;
struct ListMuonTra{
    int n = 0;
    ptrNode_MuonTra head;
    ptrNode_MuonTra tail;
};
typedef ListMuonTra listMuonTra;

//---DOC GIA---

typedef struct DocGia
{
    int maThe; //! MATHE (số nguyên ngẫu nhiên tự động)
    string ho;
    string ten;
    int phai;
    int trangThai;
    listMuonTra ptrMuonTra;
};

struct NodeDocGia
{
    int key;
    DocGia info;
    // int nNodeDocGia = 0;
    // int bf;
    struct NodeDocGia *left;
    struct NodeDocGia *right;
};
typedef struct NodeDocGia *ptrNode_DocGia;
// typedef struct NodeDocGia *ptrNode_DocGia_Name;
ptrNode_DocGia tree = NULL;

// struct TenHo {
// 	string ho;
//     string ten;
// 	int MADG;
// };
// typedef struct TenHo hoTen;

// struct TempList {
// 	int index;
// 	int MADG;
// };
// typedef struct TempList TempL;