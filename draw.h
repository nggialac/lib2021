#include "mylib.h"
#include "DG.h"
#include "DMS.h"
#include "DateTime.h"
#include "DS.h"
#include "preInput.h"

string masach = "";
// string vitrisach = "";
string isbnTemp = "";

string keyDisplayDG[5] = {"Ma DG", "     Ho DG", "Ten DG", "Phai  ", "TTr The"};
string keyDisplayDS[6] = {"        Dau Sach", "ISBN", "    Tac Gia", "  The Loai ", " So Trg ", " NXB"};
string keyDisplayDMS[3] = {"Ma Sach", "Trang Thai", "            Vi Tri"};
string keyDisplayMT[7] = {"          Ten Sach", "Ma Sach", "   Ngay Muon", "   Ngay Tra", "So Ngay Da Muon", "      Vi Tri", "  Trang Thai"};
string keyBangNhapDG[13] = {
    "                Cap Nhat The Doc Gia                      ",
    "                                                            ",
    " Ma Doc Gia   :",
    "                                                            ",
    " Ho Doc Gia   :",
    "                                                            ",
    " Ten Doc Gia  :",
    "                                                            ",
    " Phai [0, 1]  :",
    "                                                            ",
    " TT the [0, 1]:",
    "                                                            ",
    "                                                            ",
};

int x_DG[6] = {3, 13, 32, 43, 53, 65};
int x_DS[7] = {1, 29, 36, 55, 67, 74, 80};
int x_DMS[4] = {2, 14, 29, 64};
int x_MT[8] = {2, 30, 39, 55, 70, 88, 115, 132};

const int so_item = 10;
const int dong = 1;
const int cot = 0;
const int Up = 72;
const int Down = 80;

char mainMenu[so_item][50] = {"1. Nhap Doc Gia    ",
                              //   "2. Ghi file Doc Gia         ",
                              "2. Muon Sach            ",
                              "3. Tra Sach    ",
                              "4. Empty     ",
                              "5. Show records Doc Gia  ",
                              "6. Xoa Doc Gia  ",
                              "7. In Doc Gia theo ten ",
                              "8. In Doc Gia theo ma the ",
                              "9. Muon sach ",

                              "10. Exit"};

void Normal()
{
    SetColor(15);
    SetBGColor(0);
}
void HighLight()
{
    SetColor(15);
    SetBGColor(2);
}

int MenuDong(char td[so_item][50])
{
    Normal();
    system("cls");
    int chon = 0;
    int i;
    for (i = 0; i < so_item; i++) //show 4 chuc nang
    {
        gotoxy(cot, dong + i);
        cout << td[i];
    }

    //them mau dong dau tien khi show
    HighLight();
    gotoxy(cot, dong + chon);
    cout << td[chon];

    char kytu;
    do
    {
        kytu = getch();
        if (kytu == -32)
            kytu = getch();
        switch (kytu)
        {
        case Up:
            if (chon > 0)
            {
                Normal();
                gotoxy(cot, dong + chon);
                cout << td[chon];
                chon--;
                HighLight();
                gotoxy(cot, dong + chon);
                cout << td[chon];
            }
            break;
        case Down:
            if (chon + 1 < so_item)
            {
                Normal();
                gotoxy(cot, dong + chon);
                cout << td[chon];
                chon++;
                HighLight();
                gotoxy(cot, dong + chon);
                cout << td[chon];
            }
            break;
        case 13:
            return chon + 1;
        } // end switch
    } while (1);
}

int Menu(char td[so_item][50])
{
    system("cls");
    int chon = 0;
    int i;
    for (i = 0; i < so_item; i++)
    {
        gotoxy(cot, dong + i);
        cout << td[i];
    }
Nhaplai:
    gotoxy(cot, dong + so_item);
    cout << "Ban chon 1 so (1..10) :    ";
    gotoxy(wherex() - 4, wherey());
    cin >> chon;
    if (chon < 1 || chon > so_item)
        goto Nhaplai;
    return chon;
}

void xuatNgayThang(DateTime dt, int x, int y)
{
    gotoxy(x, y);
    cout << dt.ngay << " /";
    gotoxy(x + 4, y);
    cout << dt.thang << " /";
    gotoxy(x + 8, y);
    cout << dt.nam;
}

int NhapMaDocGia(int &msdg)
{
    ShowCur(true);
    int temp = msdg;
    int count = 0;
    while (temp != 0)
    {
        count++;
        temp /= 10;
    }
    if (count)
    {
        cout << msdg;
    }
    while (true)
    {
        while (_kbhit())
        {
            int kb_hit = _getch();
            if ((kb_hit >= 48 && kb_hit <= 57) && (count <= 9 && count >= 0))
            {
                int f = kb_hit - 48;
                cout << f;
                msdg = msdg * 10 + (f);
                count++;
            }
            else if (kb_hit == ENTER)
            {
                return 1;
            }
            else if (kb_hit == BACKSPACE && count > 0)
            {
                cout << "\b"
                     << " "
                     << "\b";
                count--;
                msdg /= 10;
            }
            else if (kb_hit == ESC)
            {
                return -1;
            }
        }
    }
}

void ve_DG(string key[], int nKey, int xDisplay[])
{
    ShowCur(true);
    SetColor(WHITE);
    SetBGColor(BLACK);
    // hien thi cac danh muc trong bang hien thi
    for (int i = 0; i < nKey; i++)
    {
        gotoxy(xDisplay[i] + 3, 2 + 1);
        cout << key[i];
    }
    //hien thi cot hai ben
    SetColor(WHITE);
    for (int j = 2; j <= 2 + 32; j++)
    {
        for (int i = 0; i < nKey + 1; i++)
        {
            gotoxy(xDisplay[i], j);

            cout << char(179);
        }
    }
    //hien thi dong hai ben
    for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
    {
        gotoxy(i, 2);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
            cout << char(194); //nga 3
        else if (i == xDisplay[0])
        {
            cout << char(218); //moc phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(191); //moc trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 2 + 2);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
            cout << char(197); //nga 4
        else if (i == xDisplay[0])
        {
            cout << char(195); //nga 3 sang phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(180); //nga 3 sang trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 2 + 32);
        if (i == xDisplay[nKey])
        {
            cout << char(217); //nga 3 sang trai
        }
        else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
            cout << char(193);
        else if (i == xDisplay[0])
            cout << char(192); //nga 3 sang phai
        else
        {
            cout << char(196); //duong thang ngang
        }
    }
}

void Xoa_DG_line(int locate)
{
    gotoxy(x_DG[0] + 1, 2 + 3 + locate);
    cout << setw(x_DG[1] - x_DG[0] - 1) << setfill(' ') << ' ';
    gotoxy(x_DG[1] + 1, 2 + 3 + locate);
    cout << setw(x_DG[2] - x_DG[1] - 1) << setfill(' ') << ' ';
    gotoxy(x_DG[2] + 4, 2 + 3 + locate);
    cout << setw(x_DG[3] - x_DG[2] - 5) << setfill(' ') << ' ';
    gotoxy(x_DG[3] + 3, 2 + 3 + locate);
    cout << setw(x_DG[4] - x_DG[3] - 3) << setfill(' ') << ' ';
    gotoxy(x_DG[4] + 3, 2 + 3 + locate);
    cout << setw(x_DG[5] - x_DG[4] - 3) << setfill(' ') << ' ';
}

void xuat_DG(ptrNode_DocGia dg)
{
    Xoa_DG_line(toaDo);
    SetBGColor(BLACK);
    gotoxy(x_DG[0] + 3, 2 + 3 + toaDo);
    cout << dg->info.maThe;
    gotoxy(x_DG[1] + 1, 2 + 3 + toaDo);
    cout << dg->info.ho;
    gotoxy(x_DG[2] + 4, 2 + 3 + toaDo);
    cout << dg->info.ten;
    gotoxy(x_DG[3] + 3, 2 + 3 + toaDo);
    (dg->info.phai == 0) ? cout << "Nam" : cout << "Nu";
    gotoxy(x_DG[4] + 3, 2 + 3 + toaDo);
    (dg->info.trangThai == 0) ? cout << "Khoa" : cout << "Hoat dong";
    toaDo++;
}

void xuat_DG_Page1(ptrNode_DocGia t, DocGia *arr, int index)
{
    for (int i = 0; i < NUMBER_LINES; i++)
    {
        Xoa_DG_line(i);
    }
    toaDo = 0;
    index--;
    ptrNode_DocGia temp = NULL;
    if (t == NULL)
        return;
    else
    {
        for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (1 + index) && i < nNodeDocGia; i++)
        {
            temp = layDG_NTDG(t, arr[i].maThe);
            xuat_DG(temp);
        }
    }
}

void xuat_ListDG_MT(ptrNode_DocGia t, DocGia *arr)
{
    ShowCur(false);
    SetBGColor(BLACK);
    // nNodeDocGia = demDG(t);
    // thu tu trang
    int thuTuTrang, tongtrang;
    thuTuTrang = 1;
    tongtrang = (nNodeDocGia / NUMBER_LINES) + 1;
    xuat_DG_Page1(t, arr, thuTuTrang);
    int kb_hit;
    do
    {
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)
                kb_hit = _getch();
            switch (kb_hit)
            {
            case PAGE_UP:
                (thuTuTrang > 1) ? thuTuTrang-- : thuTuTrang = tongtrang;
                xuat_DG_Page1(t, arr, thuTuTrang);
                break;
            case PAGE_DOWN:
                (thuTuTrang < tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
                xuat_DG_Page1(t, arr, thuTuTrang);
                break;
            case ENTER:
                return;
            }
        }
        SetColor(WHITE);
        gotoxy(3, 35);
        cout << " PageUp, PageDn, ENTER (tiep tuc) ";
        gotoxy(62, 1);
        cout << "Page: " << thuTuTrang << "/" << tongtrang;
    } while (true);
}

void VeHinhBangNhap(int x, int y, int dorong, string str)
{
    // SetBGColor(WHITE);
    // SetColor(BLACK);
    HighLight();
    gotoxy(x, y);
    cout << str;
    SetColor(WHITE);
    SetBGColor(BLACK);
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

int InputNgayThang(DateTime &date, int x, int y)
{
    ShowCur(true);
    int flag = 2;
    layNgayGioHT(date);
    DateTime tempDate;
    tempDate.ngay = date.ngay;
    tempDate.thang = date.thang;
    tempDate.nam = date.nam;

    gotoxy(123, 37);
    gotoxy(x, y);
    cout << date.ngay << " /" << date.thang << " /" << date.nam;
    while (true)
    {
        while (_kbhit())
        {
            int kb_hit = _getch();
            if (kb_hit >= 48 && kb_hit <= 57)
            {
                if (flag == 0)
                {
                    int f = kb_hit - 48;
                    tempDate.ngay = tempDate.ngay * 10 + (f);
                    if (tempDate.ngay > 31)
                    {
                        tempDate.ngay /= 10;
                        continue;
                    }
                    gotoxy(x, y);
                    cout << tempDate.ngay;
                }
                else if (flag == 1)
                {
                    int f = kb_hit - 48;
                    tempDate.thang = tempDate.thang * 10 + (f);
                    if (tempDate.thang > 12)
                    {
                        tempDate.thang /= 10;
                        continue;
                    }
                    gotoxy(x + 4, y);
                    cout << tempDate.thang;
                }
                else if (flag == 2)
                {
                    int f = kb_hit - 48;
                    tempDate.nam = tempDate.nam * 10 + (f);
                    if (tempDate.nam > 9999)
                    {
                        tempDate.nam /= 10;
                        continue;
                    }
                    gotoxy(x + 7, y);
                    cout << tempDate.nam;
                }
            }
            else if (kb_hit == ENTER)
            {
                if (flag == 0)
                {
                    gotoxy(x + 4, y);
                    cout << tempDate.thang;
                    flag = 1;
                }
                else if (flag == 1)
                {
                    gotoxy(x + 7, y);
                    cout << tempDate.nam;
                    flag = 2;
                }
                else if (flag == 2)
                {
                    gotoxy(x, y);
                    cout << tempDate.ngay;
                    flag = 0;
                }
            }
            else if (kb_hit == BACKSPACE && tempDate.ngay > 0 && tempDate.thang > 0 && tempDate.nam > 0)
            {
                cout << "\b"
                     << " "
                     << "\b";
                if (flag == 0)
                {
                    tempDate.ngay /= 10;
                }
                else if (flag == 1)
                {
                    tempDate.thang /= 10;
                }
                else if (flag == 2)
                {
                    tempDate.nam /= 10;
                }
            }
            else if (kb_hit == 0)
            {
                kb_hit = _getch();
                if (kb_hit == F5)
                {
                    flag = isNgayDung(tempDate);
                    if (flag == 3)
                    {
                        // xoa du
                        gotoxy(x - 19, y - 2);
                        cout << "                                                  ";
                        gotoxy(x, y);
                        cout << "                     ";
                        gotoxy(x - 3, y + 2);
                        cout << "                     ";
                        // kiem tra ngay nhap lon hon ngay hien tai
                        if (khoangCachNgay(tempDate) < 0)
                        {
                            return 1;
                        }
                        else
                        {
                            date = tempDate;
                            return 2;
                        }
                    }
                    else if (flag == 0)
                    {
                        gotoxy(x - 3, y + 2);
                        cout << "Sai ngay. Nhap lai!";
                        gotoxy(x, y);
                        cout << tempDate.ngay;
                        continue;
                    }
                    else if (flag == 1)
                    {
                        gotoxy(x - 3, y + 2);
                        cout << "Sai thang. Nhap lai!";
                        gotoxy(x + 4, y);
                        cout << tempDate.thang;
                        continue;
                    }
                    else if (flag == 2)
                    {
                        gotoxy(x - 3, y + 2);
                        cout << "Sai nam. Nhap lai!";
                        gotoxy(x + 7, y);
                        cout << tempDate.nam;
                        continue;
                    }
                }
            }
            else if (kb_hit == ESC)
            {
                // xoa du
                gotoxy(x - 19, y - 2);
                cout << "                                                  ";
                gotoxy(x, y);
                cout << "                     ";
                gotoxy(x - 3, y + 2);
                cout << "                     ";
                return -1;
            }
        }
    }
}

void Xoa_OutDMS_1line(int locate)
{
    gotoxy(x_DMS[0] + 1, 2 + 3 + locate);
    cout << setw(11) << setfill(' ') << ' ';
    gotoxy(x_DMS[1] + 1, 2 + 3 + locate);
    cout << setw(13) << setfill(' ') << ' ';
    gotoxy(x_DMS[2] + 1, 2 + 3 + locate);
    cout << setw(34) << setfill(' ') << ' ';
}

void xuat_DMS(DanhMucSach dms)
{
    Xoa_OutDMS_1line(toaDo);
    gotoxy(x_DMS[0] + 3, 2 + 3 + toaDo);
    cout << dms.maSach;
    gotoxy(x_DMS[1] + 1, 2 + 3 + toaDo);
    if (dms.trangThai == 0)
    {
        cout << "Cho Muon Duoc";
    }
    else if (dms.trangThai == 1)
    {
        cout << "Da Cho Muon";
    }
    else if (dms.trangThai == 2)
    {
        cout << "Da Thanh Ly";
    }
    gotoxy(x_DMS[2] + 10, 2 + 3 + toaDo);
    cout << dms.viTri;
    toaDo++;
}

void Xoa_OutDMS_29lines()
{
    for (int i = 0; i < NUMBER_LINES; i++)
    {
        Xoa_OutDMS_1line(i);
    }
}

void xuat_DMS_trang(pDauSach pDS, int index)
{
    Xoa_OutDMS_29lines();
    toaDo = 0;
    if (pDS->ptrDMS.FirstNode_DanhMucSach == NULL && pDS->ptrDMS.LastNode_DanhMucSach == NULL)
        return;
    index--;
    index *= NUMBER_LINES;
    int count = 0;
    ptrNode_DanhMucSach temp = NULL;
    for (temp = pDS->ptrDMS.FirstNode_DanhMucSach; temp != NULL && count < index; temp = temp->next)
    {
        count++;
    }
    for (int i = 0; i < NUMBER_LINES && temp != NULL; i++)
    {
        xuat_DMS(temp->danhMucSach);
        temp = temp->next;
    }
    return;
}

int chonItems1(pDauSach &pDS, int &thuTuTrang, int tongtrang)
{
    int pos = 0;
    int kb_hit;
    pos = 0;
    SetColor(LIGHT_RED);
    gotoxy(x_DMS[0] + 1, 2 + 3 + pos);
    cout << "->";
    gotoxy(x_DMS[0] + 10, 2 + 3 + pos);
    cout << "";

    while (true)
    {
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)
                kb_hit = _getch();
            switch (kb_hit)
            {
            case KEY_UP:
                // xoa muc truoc
                gotoxy(x_DMS[0] + 1, 2 + 3 + pos);
                cout << "  ";
                gotoxy(x_DMS[0] + 10, 2 + 3 + pos);
                cout << "  ";
                (pos > 0) ? pos-- : pos = 28;
                // to mau muc moi
                SetColor(LIGHT_RED);
                gotoxy(x_DMS[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DMS[0] + 10, 2 + 3 + pos);
                cout << "";
                break;

            case KEY_DOWN:
                // xoa muc truoc
                gotoxy(x_DMS[0] + 1, 2 + 3 + pos);
                cout << "  ";
                gotoxy(x_DMS[0] + 10, 2 + 3 + pos);
                cout << "  ";
                (pos < 28) ? pos++ : pos = 0;

                // to mau muc moi
                SetColor(LIGHT_RED);
                gotoxy(x_DMS[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DMS[0] + 10, 2 + 3 + pos);
                cout << "";
                break;

            case PAGE_UP:
                if (thuTuTrang > 1)
                {
                    thuTuTrang--;
                }
                else
                {
                    thuTuTrang = tongtrang;
                }
                Xoa_OutDMS_29lines();
                xuat_DMS_trang(pDS, thuTuTrang);
                pos = 0;
                SetColor(LIGHT_RED);
                gotoxy(x_DMS[0] + 1, 2 + 3 + pos);
                cout << "";
                gotoxy(x_DMS[0] + 10, 2 + 3 + pos);
                cout << "->";
                break;

            case PAGE_DOWN:
                if (thuTuTrang < tongtrang)
                {
                    thuTuTrang++;
                }
                else
                {
                    thuTuTrang = 1;
                }
                Xoa_OutDMS_29lines();
                xuat_DMS_trang(pDS, thuTuTrang);
                pos = 0;
                SetColor(LIGHT_RED);
                gotoxy(x_DMS[0] + 1, 2 + 3 + pos);
                cout << "";
                gotoxy(x_DMS[0] + 10, 2 + 3 + pos);
                cout << "->";
                break;

            case ENTER:
                return (pos == 0 && thuTuTrang == 1) ? pos : pos + (thuTuTrang - 1) * NUMBER_LINES;

            case ESC:
                return -1;
            }
        }
        ShowCur(false);
        gotoxy(62, 1);
        SetColor(WHITE);
        cout << "Page: " << thuTuTrang << "/" << tongtrang;
    }
}

int Menu_MS(ListDauSach &lDS, ptrNode_DocGia nDG)
{
    int choose1, choose2;
    bool check;
    char thongbao1[] = "  Sach da co doc gia muon !";
    char thongbao2[] = "  Sach da duoc thanh ly !";
    char thongbao3[] = "  Doc gia da muon sach thuoc Dau Sach nay!";
    SetColor(WHITE);
    SetBGColor(BLACK);

    // nDs : so luong dau sach.
    int nDS = lDS.n + 1;
    int thuTuTrang, tongtrang;
    pDauSach pDS = NULL;
    thuTuTrang = 1;
    tongtrang = (nDS / NUMBER_LINES) + 1;
    int temp = 1;

label:
    do
    {
        // hien thi bang chua thong tin dau sach
        XoaMotVung(1, 1, 65, 80);
        cout << "Da xoa 1 vung";
        ve_DS(keyDisplayDS, 6, x_DS);
        cout << " Da ve dau sach";
        xuat_DStheoTrang(lDS, thuTuTrang);
        cout << " Da xuat theo trang";
        gotoxy(23, 1);
        cout << "Chon dau sach de muon ! ";
        SetColor(WHITE);
        SetBGColor(BLACK);
        // chon dau sach muon nhap sach vao
        choose1 = ChonItems(lDS, thuTuTrang, tongtrang);
        // check cac truong hop ...
        if (choose1 == -1)
        {
            return -1;
        }
        else if (choose1 > lDS.n)
        {
            gotoxy(2, 2 + 3 + choose1 % NUMBER_LINES);
            cout << setw(27) << setfill(' ') << ' ';
            continue;
        }
        pDS = lDS.nodes[choose1];
        // lay ten sach.
        string tensach;
        tensach = pDS->tenSach;
        check = timTenSach_MT(nDG->info.ptrMuonTra, tensach, lDS);
        // check cac truong hop
        if (check == true)
        {
            gotoxy(90, 24);
            cout << thongbao3;
            _getch();
            gotoxy(90, 24);
            cout << "                                                       ";
        }
        else
        {
            XoaMotVung(1, 1, 35, 79);
            temp = 2;
        }
    } while (temp == 1);

label1:
    temp = 1;
    thuTuTrang = 1;
    tongtrang = (pDS->ptrDMS.n / NUMBER_LINES) + 1;
    gotoxy(15, 1);
    cout << "Chon Sach De Muon !";
    SetColor(WHITE);
    SetBGColor(BLACK);
    do
    {
        // hien thi bang chua thong tin danh muc sach
        ve_DMS(keyDisplayDMS, 3, x_DMS);
        xuat_DMS_trang(pDS, thuTuTrang);
        choose2 = chonItems1(pDS, thuTuTrang, tongtrang);
        if (choose2 == -1)
        {
            temp = 1;
            thuTuTrang = 1;
            gotoxy(15, 1);
            cout << "                                       ";
            goto label;
        }
        else if (choose2 + 1 > pDS->ptrDMS.n)
        {
            gotoxy(2, 2 + 3 + choose2 % NUMBER_LINES);
            cout << setw(12) << setfill(' ') << ' ';
            continue;
        }
        else
        {
            ptrNode_DanhMucSach dms = search_DMS_ViTri(pDS->ptrDMS, choose2);
            // trang thai sach = 1 se khong muon sach nay.
            if (dms->danhMucSach.trangThai == 1)
            {
                gotoxy(88, 24);
                cout << thongbao1;
                _getch();
                gotoxy(88, 24);
                cout << "                                                                     ";
                goto label1;
            }
            else if (dms->danhMucSach.trangThai == 2)
            {
                gotoxy(88, 24);
                cout << thongbao1;
                _getch();
                gotoxy(88, 24);
                cout << "                                                                      ";
                goto label1;
            }
            else if (dms->danhMucSach.trangThai == 0)
            {
                masach = dms->danhMucSach.maSach;
                // vitrisach = dms->danhMucSach.viTri;
                isbnTemp = pDS->isbn;
                dms->danhMucSach.trangThai = 1;
                pDS->soLanMuon += 1;
            }
            gotoxy(15, 1);
            cout << "                                       ";
            temp = 0;
        }
    } while (temp);
    return 1;
}

void ve_DS(string key[], int nKey, int xDisplay[])
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    // hien thi cac danh muc trong bang hien thi
    for (int i = 0; i < nKey; i++)
    {
        gotoxy(xDisplay[i] + 1, 2 + 1);
        cout << key[i];
    }
    //hien thi cot hai ben
    SetColor(WHITE);
    for (int j = 2; j <= 2 + 32; j++)
    {
        for (int i = 0; i < nKey + 1; i++)
        {
            gotoxy(xDisplay[i], j);
            cout << char(179);
        }
    }
    //hien thi dong hai ben
    for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
    {
        gotoxy(i, 2);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
            cout << char(194); //nga 3
        else if (i == xDisplay[0])
        {
            cout << char(218); //moc phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(191); //moc trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 2 + 2);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
            cout << char(197); //nga 4
        else if (i == xDisplay[0])
        {
            cout << char(195); //nga 3 sang phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(180); //nga 3 sang trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 2 + 32);
        if (i == xDisplay[0])
        {
            cout << char(192); //qeo sang phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(217); //qeo sang trai
        }
        else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
            cout << char(193);
        else
        {
            cout << char(196); //duong thang ngang
        }
    }
}

void xuat_DStheoTrang(ListDauSach &lDS, int index)
{
    Xoa_DS_lineS();
    SetColor(WHITE);
    toaDo = 0;
    index--;
    if (lDS.n == 0)
        return;
    for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (1 + index) && i < lDS.n; i++)
    {
        xuat_DS(lDS.nodes[i]->tenSach, lDS.nodes[i]->isbn, lDS.nodes[i]->tacGia, lDS.nodes[i]->theLoai, lDS.nodes[i]->soTrang, lDS.nodes[i]->namXuatBan);
    }
}

void Xoa_DS_lineS()
{
    for (int i = 0; i < NUMBER_LINES; i++)
    {
        Xoa_DS_line(i);
    }
}

void Xoa_DS_line(int locate)
{
    gotoxy(x_DS[0] + 1, 2 + 3 + locate);
    cout << setw(27) << setfill(' ') << ' ';
    gotoxy(x_DS[1] + 1, 2 + 3 + locate);
    cout << setw(6) << setfill(' ') << ' ';
    gotoxy(x_DS[2] + 1, 2 + 3 + locate);
    cout << setw(18) << setfill(' ') << ' ';
    gotoxy(x_DS[3] + 1, 2 + 3 + locate);
    cout << setw(11) << setfill(' ') << ' ';
    gotoxy(x_DS[4] + 1, 2 + 3 + locate);
    cout << setw(6) << setfill(' ') << ' ';
    gotoxy(x_DS[5] + 1, 2 + 3 + locate);
    cout << setw(4) << setfill(' ') << ' ';
}

void xuat_DS(string tenSach, string ISBN, string tacGia, string theLoai, int soTrang, int namXB)
{
    ShowCur(false);
    Xoa_DS_line(toaDo);
    gotoxy(x_DS[0] + 3, 2 + 3 + toaDo);
    cout << tenSach;
    gotoxy(x_DS[1] + 1, 2 + 3 + toaDo);
    cout << ISBN;
    gotoxy(x_DS[2] + 1, 2 + 3 + toaDo);
    cout << tacGia;
    gotoxy(x_DS[3] + 1, 2 + 3 + toaDo);
    cout << theLoai;
    gotoxy(x_DS[4] + 1, 2 + 3 + toaDo);
    cout << soTrang;
    gotoxy(x_DS[5] + 1, 2 + 3 + toaDo);
    cout << namXB;
    toaDo++;
}

int ChonItems(ListDauSach &lDS, int &thuTuTrang, int tongtrang)
{
    int pos = 0;
    int kb_hit;
    pos = 0;
    SetColor(LIGHT_RED);
    gotoxy(x_DS[0] + 1, 2 + 3 + pos);
    cout << "->";
    gotoxy(x_DS[0] + 26, 2 + 3 + pos);
    cout << "";
    while (true)
    {
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)
                kb_hit = _getch();
            switch (kb_hit)
            {
            case KEY_UP:
                // xoa muc truoc
                gotoxy(x_DS[0] + 1, 2 + 3 + pos);
                cout << "  ";
                gotoxy(x_DS[0] + 26, 2 + 3 + pos);
                cout << "  ";
                (pos > 0) ? pos-- : pos = 28;
                // to mau muc moi
                SetColor(LIGHT_RED);
                gotoxy(x_DS[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DS[0] + 26, 2 + 3 + pos);
                cout << "";
                break;
            case KEY_DOWN:
                // xoa muc truoc
                gotoxy(x_DS[0] + 1, 2 + 3 + pos);
                cout << "  ";
                gotoxy(x_DS[0] + 26, 2 + 3 + pos);
                cout << "  ";
                (pos < 28) ? pos++ : pos = 0;
                // to mau muc moi
                SetColor(LIGHT_RED);
                gotoxy(x_DS[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DS[0] + 26, 2 + 3 + pos);
                cout << "";
                break;
            case PAGE_UP:
                if (thuTuTrang > 1)
                {
                    thuTuTrang--;
                }
                else
                {
                    thuTuTrang = tongtrang;
                }
                xuat_DStheoTrang(lDS, thuTuTrang);
                // hight light dong dau.
                pos = 0;
                SetColor(LIGHT_RED);
                gotoxy(x_DS[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DS[0] + 26, 2 + 3 + pos);
                cout << "";
                break;
            case PAGE_DOWN:
                if (thuTuTrang < tongtrang)
                {
                    thuTuTrang++;
                }
                else
                {
                    thuTuTrang = 1;
                }
                xuat_DStheoTrang(lDS, thuTuTrang);
                // high light dong dau.
                pos = 0;
                SetColor(LIGHT_RED);
                gotoxy(x_DS[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DS[0] + 26, 2 + 3 + pos);
                cout << "";
                break;
            case ENTER:
                return (pos == 0 && thuTuTrang == 1) ? pos : pos + (thuTuTrang - 1) * NUMBER_LINES;

            case ESC:
                return -1;
            }
        }
        ShowCur(false);
        gotoxy(62, 1);
        SetColor(WHITE);
        cout << "Page: " << thuTuTrang << "/" << tongtrang;
    }
}

void ve_DMS(string key[], int nKey, int xDisplay[])
{
    ShowCur(true);
    SetColor(WHITE);
    SetBGColor(BLACK);
    // hien thi cac danh muc trong bang hien thi
    for (int i = 0; i < nKey; i++)
    {
        gotoxy(xDisplay[i] + 3, 2 + 1);
        cout << key[i];
    }
    //hien thi cot hai ben
    SetColor(WHITE);
    for (int j = 2; j <= 2 + 32; j++)
    {
        for (int i = 0; i < nKey + 1; i++)
        {
            gotoxy(xDisplay[i], j);
            cout << char(179);
        }
    }
    //hien thi dong hai ben
    for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
    {
        gotoxy(i, 2);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3])
            cout << char(194); //nga 3
        else if (i == xDisplay[0])
        {
            cout << char(218); //moc phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(191); //moc trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 2 + 2);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3])
            cout << char(197); //nga 4
        else if (i == xDisplay[0])
        {
            cout << char(195); //nga 3 sang phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(180); //nga 3 sang trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 2 + 32);
        if (i == xDisplay[nKey])
        {
            cout << char(217); //nga 3 sang trai
        }
        else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3])
            cout << char(193);
        else if (i == xDisplay[0])
            cout << char(192); //nga 3 sang phai
        else
        {
            cout << char(196); //duong thang ngang
        }
    }
}

void do_MuonSach(ptrNode_DocGia &root, ListDauSach &listDauSach)
{
    clrscr();
    system("color 0");
    SetBGColor(BLACK);
    MuonTra muontra;
    int check2, check3 = 0;

    char thongbao1[] = "           Doc Gia chi duoc muon toi da 3 cuon !";
    char thongbao2[] = "           Doc Gia da bi khoa the!";
    char thongbao3[] = "           Doc Gia da giu sach qua han 7 ngay!";
    char thongbao4[] = "           Doc Gia da lam mat sach! ";
    int mt;
    int checkMt;
    // int index;
    ptrNode_DocGia nodeTemp;

label:
    indexDG = 0;
    cout << nNodeDocGia;
    DocGia *ArrTenHo = new DocGia[nNodeDocGia];
    cout << root->info.maThe;
    tao_Arr(root, ArrTenHo);
    ve_DG(keyDisplayDG, 5, x_DG);
    // sort_DG(ArrTenHo, 0, nNodeDocGia - 1);
    xuat_ListDG_MT(root, ArrTenHo);
    delete[] ArrTenHo;

    VeHinhBangNhap(95, 3, 50, "Nhap ma doc gia de muon !");
    gotoxy(103, 5);

    checkMt = NhapMaDocGia(mt);
    cout << "Ma doc gia: ";
    cout << mt;
    if (checkMt == -1)
    {
        gotoxy(91, 10);
        cout << "Huy muon sach !";
        _getch();
    }
    else if (checkMt == 1)
    {
        nodeTemp = layDG_NTDG(tree, mt);
        if (nodeTemp == NULL)
        {
            gotoxy(82, 10);
            cout << "Khong tim thay ma the doc gia !";
            _getch();
            gotoxy(82, 10);
            cout << "                                                   ";
            goto label;
        }
        else
        {
        label1:
            gotoxy(95, 9);
            cout << "-Thong tin Doc Gia";
            gotoxy(93, 11);
            cout << "-Ho va ten: " << nodeTemp->info.ho << " " << nodeTemp->info.ten;
            gotoxy(93, 12);
            cout << "-Trang thai the : ";
            (nodeTemp->info.trangThai == 0) ? cout << "Khoa" : cout << "Hoat dong";
            gotoxy(93, 13);
            cout << "-Phai: ";
            (nodeTemp->info.phai == 0) ? cout << "Nam" : cout << "Nu";
            gotoxy(93, 14);
            // cout << "-So sach chua tra : " << nodeTemp->info.ptrMuonTra->muonTra.isbn;
            cout << "-So sach chua tra : " << soSachDangMuon(nodeTemp->info.ptrMuonTra);
            gotoxy(95, 17);
            cout << "     =Sach Dang Muon=      ";
            gotoxy(85, 18);
            cout << "     Ten Sach                           ";
            gotoxy(118, 18);
            cout << " Ngay Muon  ";
            // gotoxy(85, 20);
            // cout<<"ISBN: "<<endl;
            int pos;
            for (ptrNode_MuonTra p = nodeTemp->info.ptrMuonTra.head; p != NULL; p = p->next)
            {
                if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2)
                {
                    gotoxy(87, 20 + pos);
                    cout << "                                           ";
                    gotoxy(87, 20 + pos);
                    // cout << p->muonTra.isbn;
                    cout << findDSByISBN(listDauSach, p->muonTra.isbn)->tenSach;
                    xuatNgayThang(p->muonTra.ngayMuon, 118, 20 + pos);
                    pos++;
                    if (pos == 3)
                    {
                        gotoxy(70, 28);
                        cout << thongbao1;
                        _getch();
                        return;
                    }
                }
            }

            if (nodeTemp->info.trangThai == 0)
            {
                gotoxy(70, 28);
                cout << thongbao2;
                _getch();
                return;
            }
            if (MatSach(nodeTemp->info.ptrMuonTra))
            {
                gotoxy(70, 28);
                cout << thongbao4;
                _getch();
                return;
            }
            if (soNgayMuonMax(nodeTemp->info.ptrMuonTra) > 7)
            {
                gotoxy(70, 28);
                cout << thongbao3;
                _getch();
                return;
            }
            gotoxy(70, 35);
            cout << "                                                  ";
            _getch();
            gotoxy(88, 35);
            cout << "                                                  ";

            //MT
            cout << "truoc menu ms";
            check2 = Menu_MS(listDauSach, nodeTemp);
            cout << " menu ms";
            if (check2 == -1)
            {
                return;
            }
            else if (check2 == 1)
            {
                muontra.isbn = isbnTemp;
                muontra.ngayTra.nam = 0;
                muontra.ngayTra.thang = 0;
                muontra.ngayTra.ngay = 0;
                muontra.maSach = masach;
                // muontra. = vitrisach;
                muontra.trangThai = 0;
                do
                {
                    gotoxy(83, 28);
                    cout << "Nhap vao ngay muon (F5 luu, ESC huy) !";
                    check3 = InputNgayThang(muontra.ngayMuon, 100, 30);
                    // check cac truong hop
                    if (check3 == -1)
                    {
                        return;
                    }
                    else if (check3 == 2)
                    {
                        themDauList_MT(nodeTemp->info.ptrMuonTra, muontra);
                        goto label1;
                    }
                } while (check3);
            }
        }
    }
}

void hieuUngMenu_MT(listMuonTra lMT, int pos, int flag)
{
    int i = 0;
    ShowCur(false);
    // get so sach dang muon trong danh sach.
    int n = soSachDangMuon(lMT);
    // 0 --> 2;  2---> 1;  1---> 0
    if (flag == 1)
    {
        for (ptrNode_MuonTra p = lMT.head; p != NULL; p = p->next)
        {
            if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2)
            {
                if (i == pos)
                {
                    HighLight();
                    xuat_MT(p, i);
                    SetBGColor(BLACK);
                    SetColor(WHITE);
                }
                if (i == (pos + n - 1) % n)
                {
                    SetColor(WHITE);
                    xuat_MT(p, i);
                }
                i++;
            }
        }
    }
    else if (flag == 2)
    {
        // 0 ---> 1; 1 ---> 2; 2 ---> 0
        for (ptrNode_MuonTra p = lMT.head; p != NULL; p = p->next)
        {
            if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2)
            {
                if (i == pos)
                {
                    HighLight();
                    xuat_MT(p, i);
                    SetBGColor(BLACK);
                    SetColor(WHITE);
                }
                if (i == (pos + 1) % n)
                {
                    SetColor(WHITE);
                    xuat_MT(p, i);
                }
                i++;
            }
        }
    }
}

void ve_MT(string key[], int nKey, int xDisplay[])
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    // HighLight();
    ShowCur(false);
    // hien thi cac danh muc trong bang hien thi
    for (int i = 0; i < nKey; i++)
    {
        gotoxy(xDisplay[i] + 1, 18 + 1);
        cout << key[i];
    }
    //hien thi cot hai ben
    SetColor(WHITE);
    for (int j = 18; j <= 18 + 6; j++)
    {
        for (int i = 0; i < nKey + 1; i++)
        {
            gotoxy(xDisplay[i], j);
            cout << char(179);
        }
    }
    //hien thi dong hai ben
    for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
    {

        gotoxy(i, 18);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
            cout << char(194); //nga 3
        else if (i == xDisplay[0])
        {
            cout << char(218); //moc phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(191); //moc trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 18 + 2);
        if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
            cout << char(197); //nga 4
        else if (i == xDisplay[0])
        {
            cout << char(195); //nga 3 sang phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(180); //nga 3 sang trai
        }
        else
        {
            cout << char(196); //duong thang ngang
        }

        gotoxy(i, 18 + 6);
        if (i == xDisplay[0])
        {
            cout << char(192); //qeo sang phai
        }
        else if (i == xDisplay[nKey])
        {
            cout << char(217); //qeo sang trai
        }
        else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
            cout << char(193);
        else
        {
            cout << char(196); //duong thang ngang
        }
    }
}

int chonItem_MT(listMuonTra lMT)
{
    int currpos = 0;
    ShowCur(false);
    // get so sach dang muon trong danh sach.
    int n = soSachDangMuon(lMT);

    if (n == 0)
        return -1;
    // high light muc dau.
    int i = 0;
    for (ptrNode_MuonTra p = lMT.head; p != NULL && i != 1; p = p->next)
    {
        if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2)
        {
            if (i == 0)
            {
                HighLight();
                xuat_MT(p, i);
                SetBGColor(BLACK);
                SetColor(WHITE);
                i++;
            }
        }
    }
    // xu ly.

    int kb_hit;
    while (true)
    {
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)
            {
                kb_hit = _getch();
            }
            switch (kb_hit)
            {
            case KEY_UP:
                if (currpos > 0)
                {
                    currpos = currpos - 1;
                }
                else
                {
                    currpos = n - 1; // vi tri hien tai bang so so sach muon.
                }
                hieuUngMenu_MT(lMT, currpos, 2);
                break;
            case KEY_DOWN:
                if (currpos < n - 1)
                {
                    currpos = currpos + 1;
                }
                else
                {
                    currpos = 0;
                }
                hieuUngMenu_MT(lMT, currpos, 1);
                break;
            case ENTER:
                return currpos;
            }
        }
    }
}

void xoaManHinh_MT(int i)
{
    gotoxy(x_MT[0] + 1, 21 + i);
    cout << setw(x_MT[1] - x_MT[0] - 1) << setfill(' ') << " ";
    gotoxy(x_MT[1] + 1, 21 + i);
    cout << setw(x_MT[2] - x_MT[1] - 1) << setfill(' ') << " ";
    gotoxy(x_MT[2] + 1, 21 + i);
    cout << setw(x_MT[3] - x_MT[2] - 1) << setfill(' ') << " ";
    gotoxy(x_MT[3] + 1, 21 + i);
    cout << setw(x_MT[4] - x_MT[3] - 1) << setfill(' ') << " ";
    gotoxy(x_MT[4] + 1, 21 + i);
    cout << setw(x_MT[5] - x_MT[4] - 1) << setfill(' ') << " ";
    gotoxy(x_MT[5] + 1, 21 + i);
    cout << setw(x_MT[6] - x_MT[5] - 1) << setfill(' ') << " ";
    gotoxy(x_MT[6] + 1, 21 + i);
    cout << setw(x_MT[7] - x_MT[6] - 1) << setfill(' ') << " ";
}

void xuat_MT(ptrNode_MuonTra p, int i)
{
    pDauSach q = findDSByISBN(listDS, p->muonTra.isbn);
    gotoxy(x_MT[0] + 2, 21 + i);
    // cout << p->muonTra.tenSach;

    cout << q->tenSach;
    gotoxy(x_MT[1] + 2, 21 + i);
    cout << p->muonTra.maSach;
    xuatNgayThang(p->muonTra.ngayMuon, x_MT[2] + 2, 21 + i);
    xuatNgayThang(p->muonTra.ngayTra, x_MT[3] + 3, 21 + i);

    gotoxy(x_MT[4] + 9, 21 + i);
    cout << khoangCachNgay(p->muonTra.ngayMuon);
    gotoxy(x_MT[5] + 6, 21 + i);
    cout << search_DMS_MaSach(q, p->muonTra.maSach)->danhMucSach.viTri;
    gotoxy(x_MT[6] + 2, 21 + i);
    if (p->muonTra.trangThai == 2)
        cout << " Lam Mat Sach";
    else if (khoangCachNgay(p->muonTra.ngayMuon) > 7)
        cout << " M. Qua 7 ngay";
    else if (p->muonTra.trangThai == 0)
        cout << " Dang Muon";
    else if (p->muonTra.trangThai == 1)
        cout << " Da Tra";
}

void do_TraSach(ptrNode_DocGia &t, ListDauSach &lDS)
{
    clrscr();
    // system("color 0");
    SetBGColor(BLACK);
    int msdg = 0;
    char thongbao[] = "         Doc Gia chua muon sach !  ";
    char thongbao1[] = "    Thong tin da duoc cap nhat !";
    int check, check1 = 0;
    ptrNode_DocGia nodeTemp;
    DateTime ngaytra;
    int choose1, choose2, i1, i2, condition = 1;

label:
    SetBGColor(BLACK);
    indexDG = 0;
    DocGia *ArrTenHo = new DocGia[nNodeDocGia];
    tao_Arr(t, ArrTenHo);
    ve_DG(keyDisplayDG, 5, x_DG);
    sort_DG(ArrTenHo, 0, nNodeDocGia - 1);
    xuat_ListDG_MT(t, ArrTenHo);
    //// xoa vung nho
    delete[] ArrTenHo;

    VeHinhBangNhap(80, 3, 50, "Hay Nhap Vao Ma Doc Gia !");
    gotoxy(90, 5);
    check = NhapMaDocGia(msdg);
    // kiem tra ca truong hop
    if (check == -1)
    {
        clrscr();
        gotoxy(50, 10);
        cout << "Huy tra sach !";
        _getch();
    }
    else if (check == 1)
    {
        nodeTemp = layDG_NTDG(t, msdg);
        if (nodeTemp == NULL)
        {
            gotoxy(40, 10);
            cout << "Ma doc gia khong dung !";
            _getch();
            gotoxy(40, 10);
            cout << "                                                   ";
            goto label;
        }
        else
        {
            clrscr();
            gotoxy(52, 9);
            cout << "Thong Tin Doc Gia";
            gotoxy(52, 11);
            cout << " Ho va ten: " << nodeTemp->info.ho << " " << nodeTemp->info.ten;

            gotoxy(52, 12);
            cout << " Trang thai the : ";
            (nodeTemp->info.trangThai == 0) ? cout << "Khoa" : cout << "Hoat dong";
            gotoxy(52, 13);
            cout << " Phai: ";
            (nodeTemp->info.phai == 0) ? cout << "Nam" : cout << "Nu";
            gotoxy(52, 14);
            cout << " So sach  da muon : " << nodeTemp->info.ptrMuonTra.n;
            gotoxy(35, 25);
            cout << "   F2:   Tra Sach,  F3:   Bao mat sach,  ESC:   thoat";
        label1:
            gotoxy(52, 15);
            cout << " So sach chua tra : " << soSachDangMuon(nodeTemp->info.ptrMuonTra);
            gotoxy(37, 17);
            cout << "               Cac Sach Dang Muon                     ";
            ve_MT(keyDisplayMT, 7, x_MT);
            xuatListMT(nodeTemp->info.ptrMuonTra);
            do
            {
                while (_kbhit())
                {
                    int kb_hit = _getch();
                    if (kb_hit == 224 || kb_hit == 0)
                        kb_hit = _getch();
                    switch (kb_hit)
                    {
                    case F2:
                        choose1 = chonItem_MT(nodeTemp->info.ptrMuonTra);
                        if (choose1 == -1)
                        {
                            gotoxy(50, 30);
                            cout << thongbao;
                            return;
                        }
                        i1 = -1;
                        for (ptrNode_MuonTra pMT = nodeTemp->info.ptrMuonTra.head; pMT != NULL; pMT = pMT->next)
                        {
                            if (pMT->muonTra.trangThai == 0 || pMT->muonTra.trangThai == 2)
                            {
                                i1++;
                                if (i1 == choose1)
                                {
                                    // chuc nang nhap thong tin ngay tra.
                                    do
                                    {
                                        gotoxy(40, 28);
                                        cout << "Nhap vao ngay tra. Nhan F5 de luu, ESC de huy !";
                                        check1 = InputNgayThang(ngaytra, 55, 30);
                                        // check cac truong hop
                                        if (check1 == 2)
                                        {
                                            if (soSanhNgay(pMT->muonTra.ngayMuon, ngaytra) < 0)
                                            {
                                                check1 = 1;
                                            }
                                            else
                                            {
                                                // thay doi trang thai sach da tra.
                                                pMT->muonTra.trangThai = 1;
                                                pMT->muonTra.ngayTra = ngaytra;
                                                pDauSach pDS = findDSByISBN(lDS, pMT->muonTra.isbn);
                                                ptrNode_DanhMucSach pDMS = search_DMS_MaSach(pDS, pMT->muonTra.maSach);
                                                pDMS->danhMucSach.trangThai = 0;
                                                goto label1;
                                            }
                                        }
                                        else if (check1 == -1)
                                        {
                                            goto label1;
                                        }
                                    } while (check1);
                                }
                            }
                        }
                        goto label1;

                    case F3:
                        choose2 = chonItem_MT(nodeTemp->info.ptrMuonTra);
                        if (choose2 == -1)
                        {
                            gotoxy(50, 30);
                            cout << thongbao;
                            return;
                        }
                        i2 = -1;
                        for (ptrNode_MuonTra pMT = nodeTemp->info.ptrMuonTra.head; pMT != NULL; pMT = pMT->next)
                        {
                            if (pMT->muonTra.trangThai == 0 || pMT->muonTra.trangThai == 2)
                            {
                                i2++;
                                if (i2 == choose2)
                                {
                                    pMT->muonTra.trangThai = 2;
                                    gotoxy(45, 30);
                                    cout << thongbao1;
                                    cout << "                                                ";
                                }
                            }
                        }
                        goto label1;
                    case ESC:
                        condition = 0;
                        break;
                    }
                }
            } while (condition);
        }
    }
}

void ve_BangNhap(int x, int y, int nngang, int nkey)
{
    int i;
    SetBGColor(BLACK);
    SetColor(WHITE);
    for (i = 0; i < nkey + 2; i++)
    {
        gotoxy(x, y + i);
        if (i == 0)
        {
            cout << " ";
        }
        else
        {
            cout << keyBangNhapDG[i - 1];
            gotoxy(x + nngang, y + i);
        }
    }

    SetColor(WHITE);
    SetBGColor(BLACK);
}

int chonItems(ptrNode_DocGia &t, DocGia *&arr, int tttrang, int tongtrang)
{
    int pos = 0;
    int kb_hit;
    pos = 0;
    SetColor(LIGHT_RED);
    gotoxy(x_DG[0] + 1, 2 + 3 + pos);
    cout << "->";
    gotoxy(x_DG[0] + 2 + 6, 2 + 3 + pos);
    cout << "";
    while (true)
    {
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)
                kb_hit = _getch();

            switch (kb_hit)
            {
            case KEY_UP:
                // xoa muc truoc
                gotoxy(x_DG[0] + 1, 2 + 3 + pos);
                cout << "  ";
                gotoxy(x_DG[0] + 2 + 6, 2 + 3 + pos);
                cout << "  ";

                (pos > 0) ? pos-- : pos = 28;

                // to mau muc moi
                gotoxy(x_DG[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DG[0] + 2 + 6, 2 + 3 + pos);
                cout << "";
                break;

            case KEY_DOWN:
                // xoa muc truoc
                gotoxy(x_DG[0] + 1, 2 + 3 + pos);
                cout << "  ";
                gotoxy(x_DG[0] + 2 + 6, 2 + 3 + pos);
                cout << "  ";

                (pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

                // to mau muc moi
                gotoxy(x_DG[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DG[0] + 2 + 6, 2 + 3 + pos);
                cout << "";
                break;

            case PAGE_UP:
                if (tttrang > 1)
                {
                    tttrang--;
                }
                else
                {
                    tttrang = tongtrang;
                }
                xuat_DG_Page(t, arr, tttrang);
                pos = 0;
                SetColor(LIGHT_RED);
                gotoxy(x_DG[0] + 1, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DG[0] + 2 + 6, 2 + 3 + pos);
                cout << "";
                break;

            case PAGE_DOWN:
                if (tttrang < tongtrang)
                {
                    tttrang++;
                }
                else
                {
                    tttrang = 1;
                }
                xuat_DG_Page(t, arr, tttrang);
                pos = 0;
                SetColor(LIGHT_RED);
                gotoxy(x_DG[0] + 1, 2 + 3 + pos);
                cout << "<<";
                gotoxy(x_DG[0] + 2 + 6, 2 + 3 + pos);
                cout << ">>";
                break;

            case ENTER:
                return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1) * NUMBER_LINES;
            }
        }
        ShowCur(false);
        SetColor(WHITE);
        gotoxy(60, 1);
        cout << "Page: " << tttrang << "/" << tongtrang;
        SetColor(WHITE);
        SetBGColor(BLACK);
    }
}

void capNhat_DG(ptrNode_DocGia &t, DocGia &dg, bool isEdited)
{
    // hien con tro nhap
    ShowCur(true);
    SetColor(WHITE);
    SetBGColor(BLACK);
    // cac flag dieu khien qua trinh cap nhat
    int trinhTu = 0;
    bool isSave = false;
    bool isEscape = false;
    // chieu dai bang nhap
    int nngang = (int)keyBangNhapDG[0].length();
    // cac bien luu tru tam thoi
    string ho = "";
    string ten = "";
    int phai = 3, ttthe = 3;
    int MADG;
    gotoxy(x_Note, y_Note);
    cout << "Luu y:";
    ve_BangNhap(x_DG[5] + 7, 2, nngang, 12);
    int positionY = 2;
    if (isEdited)
    {
        ho = dg.ho;
        ten = dg.ten;
        phai = dg.phai;
        ttthe = dg.trangThai;
        MADG = dg.maThe;
        gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 3);
        cout << MADG;
        gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 5);
        cout << ho;
        gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 7);
        cout << ten;
        gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 9);
        (phai == 0) ? cout << phai << ":  Nam" : cout << phai << ":  Nu";
        gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 11);
        (ttthe == 0) ? cout << ttthe << ":  Khoa" : cout << ttthe << ":  Hoat dong";
    }
    if (!isEdited)
    {
        gotoxy((x_DG[5] + 7 + nngang / 2), 2 + 3);
        MADG = randomMaThe(t);
        cout << MADG;
    }

    while (true)
    {
        switch (trinhTu)
        {
        case 0:
            gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 5);
            NhapHo(ho, trinhTu, isSave, isEscape);
            break;
        case 1:
            gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 7);
            NhapTen(ten, trinhTu, isSave, isEscape);
            break;
        case 2:
            gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 9);
            Nhap(phai, NHAP_PHAI, trinhTu, isSave, isEscape);
            break;
        case 3:
            gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 11);
            Nhap(ttthe, NHAP_TRANG_THAI, trinhTu, isSave, isEscape);
            break;
        }
        if (isSave)
        {
            isSave = false;
            if (ho.length() == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(GREEN);
                cout << "Du lieu khong de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                trinhTu = 0;
                continue;
            }
            else if (ten.length() == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(GREEN);
                cout << "Du lieu khong de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                trinhTu = 1;
                continue;
            }
            else if (phai == 3)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(GREEN);
                cout << "Du lieu khong de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                trinhTu = 2;
                continue;
            }
            else if (ttthe == 3)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(GREEN);
                cout << "Du lieu khong de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                trinhTu = 3;
                continue;
            }
            dg.maThe = MADG;
            dg.ho = chuanHoaChuoi(ho);
            dg.ten = chuanHoaChuoi(ten);
            dg.phai = phai;
            dg.trangThai = ttthe;
            if (isEdited)
            {
                ptrNode_DocGia p;
                p = layDG_NTDG(t, MADG);
                p->info = dg;
            }
            else
            {
                // nNodeDocGia+=1;
                dg.ptrMuonTra.head = dg.ptrMuonTra.tail = NULL;
                dg.ptrMuonTra.n = 0;
                insert_NodeDG_Load(t, dg);
            }
            for (int i = 0; i < 5; i++)
            {
                SetColor(GREEN);
                gotoxy(x_Note + 15, y_Note);
                cout << "           Hoan tat ! ";
            }
            system("pause");
            SetColor(WHITE);
            SetBGColor(BLACK);
            XoaMotVung(x_DG[5] + 7, 2, 30, 60);
            return;
        }
        if (isEscape)
        {
            XoaMotVung(x_DG[5] + 7, 2, 30, 60);
            return;
        }
    }
    ShowCur(false);
}

void xuat_DG_Page(ptrNode_DocGia t, DocGia *arr, int index)
{
    for (int i = 0; i < NUMBER_LINES; i++)
    {
        Xoa_DG_line(i);
    }
    toaDo = 0;
    index--;
    ptrNode_DocGia temp = NULL;
    if (t == NULL)
        return;
    else
    {
        for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (1 + index) && i < nNodeDocGia; i++)
        {
            temp = layDG_NTDG(t, arr[i].maThe);
            xuat_DG(temp);
        }
    }
}

int xuat_ListDG(ptrNode_DocGia &t, DocGia *&arr, DocGia &dg, int &thuTuTrang)
{
    ptrNode_DocGia temp = NULL;
    int choose;
    bool check;
    // thu tu trang
    int tongtrang;
    tongtrang = (nNodeDocGia / NUMBER_LINES) + 1;
    xuat_DG_Page(t, arr, thuTuTrang);
    int kb_hit;
    do
    {
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)
                kb_hit = _getch();
            switch (kb_hit)
            {
            case PAGE_UP:
                (thuTuTrang > 1) ? thuTuTrang-- : thuTuTrang = tongtrang;
                xuat_DG_Page(t, arr, thuTuTrang);
                break;

            case PAGE_DOWN:
                (thuTuTrang < tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
                xuat_DG_Page(t, arr, thuTuTrang);
                break;
                // them
            case F1:
                capNhat_DG(t, dg, false);
                system("pause");
                delete[]arr;
                return 1;
                // hieu chinh
            case F2:
                choose = chonItems(t, arr, thuTuTrang, tongtrang);
                // cout<<arr[choose];
                // temp = layDG_NTDG(t, temp->info.maThe);
                // VeHinhBangNhap(95, 3, 50, "Nhap ma doc gia de muon !");
                // gotoxy(103, 5);
                // int mt;
                // checkMt = NhapMaDocGia(mt);
                // cout << "Ma doc gia: ";
                // cout << mt;
                capNhat_DG(t, arr[choose], true);
                delete[] arr;
                return 1;
                // xoa
            case F3:
                choose = chonItems(t, arr, thuTuTrang, tongtrang);
                // truong hop khong chon doc gia nao.
                // temp = layDG_NTDG(t, temp->info.maThe);
                if (soSachDangMuon(arr[choose].ptrMuonTra) > 0)
                {
                    gotoxy(75, 20);
                    cout << "Doc Gia da muon sach nen khong duoc phep xoa !";
                    _getch();
                    gotoxy(75, 20);
                    cout << "                                                      ";
                    return 1;
                }
                else
                {
                    
                    check = remove_NodeDG(t, arr[choose]);
                    delete[]arr;
                    return 1;
                }

            case ESC:
                return 0;
            }
        }
        ShowCur(false);
        gotoxy(60, 1);
        cout << "Page: " << thuTuTrang << "/" << tongtrang;
    } while (true);
}

void Menu_DocGia(ptrNode_DocGia &t)
{
    clrscr();
    // normalBGColor();
    SetColor(WHITE);
    SetBGColor(BLACK);
    int tttrang = 1;
    int esc = 1;
    do
    {
        clrscr();
        gotoxy(26, 1);
        cout << "Cap Nhat Doc Gia ";
        gotoxy(3, 35);
        SetColor(WHITE);
        cout << "ESC: Thoat, F1: Them, F2: Sua, F3: Xoa, F5: Luu, PageUp, PageDn";
        SetColor(WHITE);
        SetBGColor(BLACK);

        DocGia dg;
        indexDG = 0;
        // nNodeDocGia = demDocGia(t);
        cout<<"So node: "<< nNodeDocGia;
        DocGia *arr;
        arr = new DocGia[nNodeDocGia];

        tao_Arr(t, arr);
        ve_DG(keyDisplayDG, 5, x_DG);
        esc = xuat_ListDG(t, arr, dg, tttrang);
    } while (esc);
}