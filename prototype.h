#include <iostream>
using namespace std;
#include <string.h>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <time.h>

#include "initial.h"

#ifndef prototype
#define prototype

extern char *FILE_PATH = "D:\\Lib\\DG.txt";
extern int nNodeDocGia = 0;

//DMS
void insertFirst_DMS(ptrNode_DanhMucSach &First, DanhMucSach x);
int insertAfter_DMS(ptrNode_DanhMucSach p, DanhMucSach x);
int insertLinkedList_DMS(ptrNode_DanhMucSach &First, ptrNode_DanhMucSach &Second, DanhMucSach x);
ptrNode_DanhMucSach search_DMS(ptrNode_DanhMucSach First, char *x);
int deleteFirst_DMS(ptrNode_DanhMucSach &First);
int deleteAfter_DMS(ptrNode_DanhMucSach p);
int deleteOneByInfo_DMS(ptrNode_DanhMucSach &First, DanhMucSach x);
int traverse_DMS(ptrNode_DanhMucSach First);

// TODO: DG - BST
void initialize_NodeDG(ptrNode_DocGia &root);
//cay nhi phan tim kiem, lam sao de tu sinh ma cay van can bang?
void insert_NodeDG(ptrNode_DocGia &p, DocGia dg); //!cay nhi phan tim kiem

void create_Tree(ptrNode_DocGia &root);

int preorder_NodeDG(ptrNode_DocGia p); //Co the dung giai thuat ko de quy

ptrNode_DocGia search_NodeDG(ptrNode_DocGia root, int x);

ptrNode_DocGia rp;
void remove2Child_NodeDG(ptrNode_DocGia &p);
int remove_NodeDG(ptrNode_DocGia &p, int xKey);

void saveDG(ptrNode_DocGia &root, fstream &fout);
void writeFile_NodeDG(ptrNode_DocGia &root, FILE &fout);
int writeFile_DG(ptrNode_DocGia &root, char *filePath);

void readFile_NodeDG(ptrNode_DocGia &root, FILE *fin);
int readFile_DG(ptrNode_DocGia &root, char *filePath);

// TODO: DG - AVL To chuc can bang cho cay tim kiem

#endif
