
#include "initial.h"

#ifndef prototype
#define prototype

//DateTime
bool isNamNhuan(int year);
int isNgayDung(DateTime d);
int tinhNgay(DateTime dt);
void layNgayGioHT(DateTime &d);
int khoangCachNgay(DateTime nt1);
int soSanhNgay(DateTime nt1, DateTime nt2);
int quaHan(listMuonTra lMT);
int soNgayQuaHan(listMuonTra lMT);

//DS
pDauSach findDSByISBN(ListDauSach listDS, string isbn);
bool isDauSach_ISBN(ListDauSach listDS, string ISBN);
int isFull_DS(ListDauSach listDS);
int Empty(ListDauSach &ds);
void DS_TheoTen(ListDauSach &listDS, string mten);
pDauSach layDauSach_Ten(ListDauSach listDS, string tenSach);
int Insert_DS(ListDauSach &listDS, pDauSach &pDS);
int Delete_DS(ListDauSach &plist, int i);
int Search_isbn(ListDauSach &plist, string isbn);
int DocFile_DS(ListDauSach &listDS);
int GhiFile_DS(ListDauSach &listDS);

int soNgayQuaHan(listMuonTra lMT);
void add_DS(ListDauSach listDS, pDauSach pDS);

//DMS
void initializeListNode_DMS(listNodeDMS &ln_dms);
ptrNode_DanhMucSach getNode_DMS(DanhMucSach data);
void themCuoiList_DMS(listNodeDMS &ln_dms, DanhMucSach data);
int insertAfter_DMS(ptrNode_DanhMucSach p, DanhMucSach x);
void insertFirst_DMS(ptrNode_DanhMucSach &First, DanhMucSach x);
ptrNode_DanhMucSach search_DMS_ViTri(listNodeDMS dms, int pos);
ptrNode_DanhMucSach search_DMS_MaSach(pDauSach pDS, string masach);
int deleteFirst_DMS(ptrNode_DanhMucSach &First);
int deleteAfter_DMS(ptrNode_DanhMucSach p);
int deleteOneByInfo_DMS(ptrNode_DanhMucSach &First, string ms);
int traverse_DMS(listNodeDMS ln_dms);
bool CheckMuon_DMS(ptrNode_DanhMucSach nDMS);


// DOC GIA
void initialize_NodeDG(ptrNode_DocGia &root);
ptrNode_DocGia getNode_DG(DocGia dg);
void insert_NodeDG_Load(ptrNode_DocGia &p, DocGia dg);
int preorder_NodeDG_NLR(ptrNode_DocGia p); //
void remove2Child_NodeDG(ptrNode_DocGia &rp, ptrNode_DocGia &p);
int remove_NodeDG(ptrNode_DocGia &p, DocGia dg);
void saveDG(ptrNode_DocGia &root, fstream &fout);
void writeFile_NodeDG(ptrNode_DocGia &root, fstream &fout);
int writeFile_DG(ptrNode_DocGia &root);
int readDG(ptrNode_DocGia &root);
ptrNode_DocGia layDG_NTDG(ptrNode_DocGia root, int MADG);
int checkSortHoTen(DocGia dg1, DocGia dg2);
void sort_DG(DocGia *arr, int low, int high);//!Quick sort
void sort_QH(DocGia *arr, int low, int high);
ptrNode_DocGia sortedArrayToBST(DocGia arr[], int start, int end);
int treeToArr(ptrNode_DocGia p, DocGia *arr, int indexDG);
int taoRandom();
int randomMaThe(ptrNode_DocGia t);
int height(ptrNode_DocGia p);//Lay chieu cao cay con
int getBalance(ptrNode_DocGia p);//Left - Right (Height)
int max(int a, int b);
ptrNode_DocGia rightRotate(ptrNode_DocGia y);
ptrNode_DocGia leftRotate(ptrNode_DocGia x);
ptrNode_DocGia newNode(DocGia dg); //New node AVL, set height = 1
ptrNode_DocGia insert(ptrNode_DocGia node, DocGia dg);
ptrNode_DocGia minValueNode(ptrNode_DocGia node);//Lay nut nho nhat ben trai
ptrNode_DocGia deleteNode(ptrNode_DocGia root, DocGia dg);

//MUON TRA
void initializeListMuonTra(listMuonTra &lMT);
int soSachDangMuon(listMuonTra lMT);
ptrNode_MuonTra GetNode_MT(MuonTra data);
void themDauList_MT(listMuonTra &listMT, MuonTra data);
void themCuoiList_MT(listMuonTra &lMT, MuonTra data);
bool timTenSach_MT(listMuonTra lMT, string tensach, ListDauSach lDS);
int MatSach(listMuonTra lMT);
int soNgayMuonMax(listMuonTra lMT);

//DRAW
int NhapMaDocGia(int &msdg);
void ve_DG(string key[], int nKey, int xDisplay[]);
void xuat_DG(ptrNode_DocGia dg);
void xuat_DG_Page1(ptrNode_DocGia t, DocGia *arr, int index);
void xuat_ListDG_MT(ptrNode_DocGia t, DocGia *arr);
int InputNgayThang(DateTime &date, int x, int y);
void do_MuonSach(ptrNode_DocGia &root, ListDauSach &listDauSach);
void hieuUngMenu_MT(listMuonTra lMT, int pos, int flag);
void ve_MT(string key[], int nKey, int xDisplay[]);
int chonItem_MT(listMuonTra lMT);
void xuatListMT(listMuonTra lMT);
void xuat_MT(ptrNode_MuonTra p, int i);
void do_TraSach(ptrNode_DocGia &t, ListDauSach &lDS);
void ve_BangNhap(int x, int y, int nngang, int nkey);
void ve_BangNhap_DS(int x, int y, int nngang, string key[], int nkey);
int chonItems_DG(ptrNode_DocGia &t, DocGia *&arr, int tttrang, int tongtrang);
void capNhat_DG(ptrNode_DocGia &t, DocGia &dg, bool isEdited);//Them Sua Doc Gia
void xuat_DG_Page(ptrNode_DocGia t, DocGia *arr, int index);
int xuat_ListDG(ptrNode_DocGia &t, DocGia *&arr, DocGia &dg, int &thuTuTrang);//Man hinh chinh DG
void xuat_ListDG_1(ptrNode_DocGia t, DocGia *arr);
void Menu_DocGia(ptrNode_DocGia &t);//->xuat_DG_page
void do_QuaHan(ptrNode_DocGia t, ListDauSach lDS);
ListDauSach Top10_DS(ListDauSach listDS);
void ve_TopDS(ListDauSach listDS);
//
void xuat_DMS(DanhMucSach dms);
void xuat_DMS_trang(pDauSach pDS, int index);
void ve_DMS(string key[], int nKey, int xDisplay[]);
void ve_DMS(string key[], int nKey, int xDisplay[]);
int chonItems_DMS(pDauSach &pDS, int &thuTuTrang, int tongtrang);
int Menu_MS(ListDauSach &lDS, ptrNode_DocGia nDG);
void ve_DS(string key[], int nKey, int xDisplay[]);
void xuat_DStheoTrang(ListDauSach &lDS, int index);
void xuat_DS(string tenSach, string ISBN, string tacGia, string theLoai, int soTrang, int namXB);
//
void dong_DS(ListDauSach listDS, int i);
void do_DMS(DauSach ds);
int Them_DS(ListDauSach &listDS);
void DanhSachDS(ListDauSach listDS);
//
void capNhat_DauSach(ListDauSach &lDS, pDauSach &pDS, bool isEdited);
int chonItems_DS(ListDauSach &lDS, int &thuTuTrang, int tongtrang);
int layViTri_Key(ptrNode_DanhMucSach first, string key);
ptrNode_DanhMucSach nodePointer(ptrNode_DanhMucSach first, int i);
int xoa_Key(pDauSach &pDS, string key);
void xoaDauSach_ViTri(ListDauSach &listDS, int viTri);
void Menu_DauSach(ListDauSach &lDS);
int NhapSach(pDauSach &pDS);
int SuaDanhMucSach(pDauSach &pDS, ptrNode_DanhMucSach dms);
void xuat_ListDMS(pDauSach &pDS);
void NhapDanhMucSach(pDauSach &pDS, int sosach);
void Menu_DMS(ListDauSach &lDS);
int xetThuTu(pDauSach left, pDauSach right);
void swap_DS(pDauSach ds1, pDauSach ds2);
void SSort_DauSach(ListDauSach &lDS);
int TongSoSachDuocMuon(ListNodeDMS dms);
void xuat_ListDStheoTT(ListDauSach lDS);

//
void xoaManHinh_MT(int i);
void Xoa_DS_lineS();
void Xoa_DS_line(int locate);
void xuatNgayThang(DateTime dt, int x, int y);

#endif
