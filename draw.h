#include "mylib.h"
#include "DG.h"
#include "DateTime.h"
#include "DS.h"
#include "preInput.h"

string masach = "";
// string vitrisach = "";
string isbnTemp = "";

string keyDisplayDG[5] = {"Ma DG", "     Ho DG", "Ten DG", "Phai  ", "TTr The"};
string keyDisplayDS[6] = {"        Ten Sach", "ISBN", "    Tac Gia", "  The Loai ", " So Trg ", " NXB"};
string keyDisplayDMS[3] = {"Ma Sach", "Trang Thai", "            Vi Tri"};
string keyDisplayMT[7] = {"          Ten Sach", "Ma Sach      ", "   Ngay Muon", "   Ngay Tra", "So Ngay Da Muon", "      Vi Tri", "  Trang Thai"};
string keyDisplayTop10[3] = { "   So Thu Tu", "          Ten Sach", " So Luot Muon Sach Thuoc Dau Sach" };
string keyBangNhapDG[13] = {
    "                Cap Nhat The Doc Gia                      ",
    "                                                            ",
    " Ma Doc Gia   :",
    "                                                            ",
    " Ho Doc Gia   :",
    "                                                            ",
    " Ten Doc Gia  :",
    "                                                            ",
    " Phai  :",
    "                                                            ",
    " TT the :",
    "                                                            ",
    "                                                            ",
};

string keyBangNhapDanhMucSach[8] = {"                    Cap Nhat Danh Muc Sach                   ",
                                    "                                                                   ",
                                    " Ma Sach           :",
                                    "                                                                   ",
                                    " Trang Thai(0,1,2) :",
                                    "                                                                   ",
                                    " Vi tri cua sach   :",
                                    "                                                                   "};

int x_DG[6] = {3, 13, 32, 43, 53, 65};
int x_DS[7] = {1, 29, 36, 55, 67, 74, 80};
int x_DMS[4] = {2, 14, 29, 64};
int x_MT[8] = {2, 30, 39, 55, 70, 88, 115, 132};

const int so_item = 3;
// const int so_item_sub_dg = 5;
const int so_item_sub_dg = 4;
const int so_item_sub_mt = 4;
const int dong = 50;
const int cot = 0;
// const int subDong = 1;
const int Up = 72;
const int Down = 80;

// char mainMenu[so_item][50] = {"1. Doc Gia                    ",
//                               "2. Muon tra sach              ",
//                               "3. Dau Sach & Danh muc        ",
//                               "4. Exit                       "};

// char subMenuDG[so_item_sub_dg][50] = {"1. Chinh Sua Doc Gia             ",
//                                       "2. In Doc Gia theo Ten Ho        ",
//                                       "3. In Doc Gia theo Ma The        ",
//                                       "4. In Doc Gia qua han            ",
//                                       "5. Back                          "};

// char subMenuMT[so_item_sub_mt][50] = {"1. Muon sach                            ",
//                                       "2. Tra Sach                             ",
//                                       "3. Top 10 sach co luot muon nhieu nhat  ",
//                                       "4. Back                                 "};
string keyMainMenu[4] = {"QUAN LY DOC GIA", "QUAN LY DAU SACH ", "QUAN LY MUON TRA SACH", "THOAT"};

string keySubMainMenuDS[5] = {"   CAP NHAT DAU SACH     ",
                              "  CAP NHAT DANH MUC SACH ",
                              "       THE LOAI SACH     ",
                              "     TIM KIEM TEN SACH   ",
                              "           BACK          "};

string keySubMainMenuDG[5] = {"    CAP NHAT DOC GIA     ",
                              "    DS DOC GIA THEO HO   ",
                              " DS DOC GIA THEO MA THE  ",
                              " DS DG MUON SACH QUA HAN ",
                              "          BACK           "};

string keySubMainMenuMT[4] = {"      MUON SACH       ",
                              "       TRA SACH       ",
                              " SACH MUON NHIEU NHAT ",
                              "         BACK         "};

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

void taoBox(int x, int y, string text, int length)
{
    gotoxy(x - 2, y - 1);
    cout << char(218) << setw(length) << setfill(char(196)) << char(196) << char(191);
    gotoxy(x - 2, y);
    cout << char(179) << text << setw(length - text.length() + 1) << setfill(' ') << char(179);
    gotoxy(x - 2, y + 1);
    cout << char(192) << setw(length) << setfill(char(196)) << char(196) << char(217);
}

int MenuDong(char td[so_item][50])
{
    Normal();
    // system("cls");
    int chon = 0;
    int i;
    for (i = 0; i < so_item; i++)
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

int SubMenuDong(char td[10][50], int item)
{
    Normal();
    // system("cls");
    int chon = 0;
    int i;
    for (i = 0; i < item; i++)
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
            if (chon + 1 < item)
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
        case ENTER:
            return chon + 1;
        }
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
        int nNodeDocGia = demDocGia(t);
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

    int nNodeDocGia = demDocGia(t);
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

int InputNgayThang(DateTime &date, int x, int y) {
	ShowCur(true);
	int flag = 2;
	layNgayGioHT(date);
	DateTime tempDate;
	tempDate.ngay = date.ngay;
	tempDate.thang = date.thang;
	tempDate.nam = date.nam;

	gotoxy(123, 37);
	gotoxy(x, y);
	cout << date.ngay << "  /" << date.thang << " /" << date.nam;
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57) {
				if (flag == 0) {
					int f = kb_hit - 48;
					tempDate.ngay = tempDate.ngay * 10 + (f);
					if (tempDate.ngay > 31) {
						tempDate.ngay /= 10;
						continue;
					}
					gotoxy(x, y);
					cout << tempDate.ngay;
				} else if (flag == 1) {
					int f = kb_hit - 48;
					tempDate.thang = tempDate.thang * 10 + (f);
					if (tempDate.thang > 12) {
						tempDate.thang /= 10;
						continue;
					}
					gotoxy(x + 4, y);
					cout << tempDate.thang;
				} else if (flag == 2) {
					int f = kb_hit - 48;
					tempDate.nam = tempDate.nam * 10 + (f);
					if (tempDate.nam > 9999) {
						tempDate.nam /= 10;
						continue;
					}
					gotoxy(x + 7, y);
					cout << tempDate.nam;
				}
			} else if (kb_hit == ENTER) {
				if (flag == 0) {
					gotoxy(x + 4, y);
					cout << tempDate.thang;
					flag = 1;
				} else if (flag == 1) {
					gotoxy(x + 7, y);
					cout << tempDate.nam;
					flag = 2;
				} else if (flag == 2) {
					gotoxy(x, y);
					cout << tempDate.ngay;
					flag = 0;
				}
			} else if (kb_hit == BACKSPACE && tempDate.ngay > 0 && tempDate.thang > 0 && tempDate.nam > 0) {
				cout << "\b" << " " << "\b";
				if (flag == 0) {
					tempDate.ngay /= 10;
				} else if (flag == 1) {
					tempDate.thang /= 10;
				} else if (flag == 2) {
					tempDate.nam /= 10;
				}
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == F5) {
					flag = isNgayDung(tempDate);
					if (flag == 3) {
						// xoa du
						gotoxy(x - 19, y - 2);
						cout << "                                                  ";
						gotoxy(x, y);
						cout << "                     ";
						gotoxy(x - 3, y + 2);
						cout << "                     ";
						// kiem tra ngay nhap lon hon ngay hien tai
						if (khoangCachNgay(tempDate) < 0) {
							return 1;
						} else {
							date = tempDate;
							return 2;
						}
					} else if (flag == 0) {
						gotoxy(x - 3, y + 2);
						cout << "Sai ngay. Nhap lai!";
						gotoxy(x, y);
						cout << tempDate.ngay;
						continue;
					} else if (flag == 1) {
						gotoxy(x - 3, y + 2);
						cout << "Sai thang. Nhap lai!";
						gotoxy(x + 4, y);
						cout << tempDate.thang;
						continue;
					} else if (flag == 2) {
						gotoxy(x - 3, y + 2);
						cout << "Sai nam. Nhap lai!";
						gotoxy(x + 7, y);
						cout << tempDate.nam;
						continue;
					}
				}
			} else if (kb_hit == ESC) {
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
    gotoxy(x_DMS[0] + 1, 2 + 3 + toaDo);
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
    if (pDS->First_DMS == NULL)
        return;
    index--;
    index *= NUMBER_LINES;
    int count = 0;
    ptrNode_DanhMucSach temp = NULL;
    for (temp = pDS->First_DMS; temp != NULL && count < index; temp = temp->next)
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

int chonItems_DMS(pDauSach &pDS, int &thuTuTrang, int tongtrang)
{
    int pos = 0;
    int kb_hit;
    pos = 0;
    SetColor(WHITE);
    gotoxy(x_DMS[0] + -2, 2 + 3 + pos);
    cout << "->";
    gotoxy(x_DMS[0] + 7, 2 + 3 + pos);
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
                gotoxy(x_DMS[0] + -2, 2 + 3 + pos);
                cout << "  ";
                // gotoxy(x_DMS[0] + 7, 2 + 3 + pos);
                // cout << "  ";
                (pos > 0) ? pos-- : pos = 28;
                // to mau muc moi
                SetColor(WHITE);
                gotoxy(x_DMS[0] + -2, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DMS[0] + 7, 2 + 3 + pos);
                cout << "";
                break;

            case KEY_DOWN:
                // xoa muc truoc
                gotoxy(x_DMS[0] + -2, 2 + 3 + pos);
                cout << "  ";
                // gotoxy(x_DMS[0] + 7, 2 + 3 + pos);
                // cout << "  ";
                (pos < 28) ? pos++ : pos = 0;

                // to mau muc moi
                SetColor(WHITE);
                gotoxy(x_DMS[0] + -2, 2 + 3 + pos);
                cout << "->";
                gotoxy(x_DMS[0] + 7, 2 + 3 + pos);
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
                SetColor(WHITE);
                gotoxy(x_DMS[0] + -2, 2 + 3 + pos);
                cout << "";
                gotoxy(x_DMS[0] + 7, 2 + 3 + pos);
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
                SetColor(WHITE);
                gotoxy(x_DMS[0] + -2, 2 + 3 + pos);
                cout << "";
                gotoxy(x_DMS[0] + 7, 2 + 3 + pos);
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
        ve_DS(keyDisplayDS, 6, x_DS);
        xuat_DStheoTrang(lDS, thuTuTrang);
        gotoxy(23, 1);
        SetColor(WHITE);
        SetBGColor(BLACK);
        // chon dau sach muon nhap sach vao
        choose1 = chonItems_DS(lDS, thuTuTrang, tongtrang);
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
    int soSach=0;
	ptrNode_DanhMucSach p=pDS->First_DMS;
    for(p;p!=NULL;p=p->next)
    	soSach++;
    tongtrang = (soSach / NUMBER_LINES) + 1;
    gotoxy(15, 1);
    cout << "Chon Sach De Muon !";
    SetColor(WHITE);
    SetBGColor(BLACK);
    do
    {
        // hien thi bang chua thong tin danh muc sach
        ve_DMS(keyDisplayDMS, 3, x_DMS);
        xuat_DMS_trang(pDS, thuTuTrang);
        choose2 = chonItems_DMS(pDS, thuTuTrang, tongtrang);
        if (choose2 == -1)
        {
            temp = 1;
            thuTuTrang = 1;
            gotoxy(15, 1);
            cout << "                                       ";
            goto label;
        }
        else if (choose2 + 1 > soSach)
        {
            gotoxy(2, 2 + 3 + choose2 % NUMBER_LINES);
            cout << setw(12) << setfill(' ') << ' ';
            continue;
        }
        else
        {
            ptrNode_DanhMucSach dms = search_DMS_ViTri(pDS->First_DMS, choose2);
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
    clrscr();
    checkMt = 0;
    int index = 0;
    // cout << nNodeDocGia;
    int nNodeDocGia = demDocGia(root);
    DocGia *arr;
    arr = new DocGia[nNodeDocGia];
    // cout << root->info.maThe;
    treeToArr(root, arr, index);
    ve_DG(keyDisplayDG, 5, x_DG);
    // sort_DG(ArrTenHo, 0, nNodeDocGia - 1);
    xuat_ListDG_MT(root, arr);
    delete[] arr;

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
            // cout << "truoc menu ms";
            check2 = Menu_MS(listDauSach, nodeTemp);
            // cout << " menu ms";
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
                    check3 = InputNgayThang(muontra.ngayMuon, 99, 30);
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

void xuatListMT(listMuonTra lMT)
{
	int i = 0;
	// xoa display dau sach
	for (int j = 0; j < 3; j++)
	{
		xoaManHinh_MT(j);
	}
	// thuc hien ouput
	for (ptrNode_MuonTra p = lMT.head; p != NULL; p = p->next)
	{
		if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2)
		{
			xuat_MT(p, i);
			i++;
		}
	}
}

void xuat_MT(ptrNode_MuonTra p, int i)
{
    pDauSach q = findDSByISBN(listDS, p->muonTra.isbn);
    gotoxy(x_MT[0] + 2, 21 + i);
    // cout << p->muonTra.tenSach;

    cout << q->tenSach;
    gotoxy(x_MT[1] , 21 + i);
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
    int index = 0;
    int nNodeDocGia = demDocGia(t);
    DocGia *ArrTenHo = new DocGia[nNodeDocGia];
    treeToArr(t, ArrTenHo, index);
    ve_DG(keyDisplayDG, 5, x_DG);
    // sort_DG(ArrTenHo, 0, nNodeDocGia - 1);
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
            cout << "   F2:   Tra Sach,  F3:   Lam mat sach,  ESC:   thoat";
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

void ve_BangNhap_DS(int x, int y, int nngang, string key[], int nkey)
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
            cout << key[i - 1];
            gotoxy(x + nngang, y + i);
        }
    }
    SetBGColor(BLACK);
    SetColor(WHITE);
}

int chonItems_DG(ptrNode_DocGia &t, DocGia *&arr, int tttrang, int tongtrang)
{
    int pos = 0;
    int kb_hit;
    pos = 0;
    SetColor(WHITE);
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

                (pos < 28) ? pos++ : pos = 0;

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
                SetColor(WHITE);
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
                SetColor(WHITE);
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
            Nhap(phai, 0, trinhTu, isSave, isEscape);
            break;
        case 3:
            gotoxy((x_DG[5] + 7 + nngang / 2), positionY + 11);
            Nhap(ttthe, 1, trinhTu, isSave, isEscape);
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
                // dg.ptrMuonTra.head = dg.ptrMuonTra.tail = NULL;
                // dg.ptrMuonTra.n = 0;
                // insert_NodeDG_Load(t, dg);
                // insertAVL(t, dg);
                t = insert(t, dg);
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
        int nNodeDocGia = demDocGia(t);
        for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (1 + index) && i < nNodeDocGia; i++)
        {
            temp = layDG_NTDG(t, arr[i].maThe);
            if (temp == NULL)
                return;
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
    int nNodeDocGia = demDocGia(t);
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
                delete[] arr;
                return 1;
                // hieu chinh
            case F2:
                choose = chonItems_DG(t, arr, thuTuTrang, tongtrang);
                capNhat_DG(t, arr[choose], true);
                delete[] arr;
                return 1;
                // xoa
            case F3:
                choose = chonItems_DG(t, arr, thuTuTrang, tongtrang);
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

                    // check = remove_NodeDG(t, arr[choose]);
                    t = deleteNode(t, arr[choose]);
                    delete[] arr;
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

void xuat_ListDG_1(ptrNode_DocGia t, DocGia *arr)
{
    ShowCur(false);
    // nDG = demDocGia(t);
    // thu tu trang
    int nNodeDocGia = demDocGia(t);
    int tttrang, tongtrang;
    tttrang = 1;
    tongtrang = (nNodeDocGia / NUMBER_LINES) + 1;
    xuat_DG_Page1(t, arr, tttrang);

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
                (tttrang > 1) ? tttrang-- : tttrang = tongtrang;
                xuat_DG_Page1(t, arr, tttrang);
                break;
            case PAGE_DOWN:
                (tttrang < tongtrang) ? tttrang++ : tttrang = 1;
                xuat_DG_Page1(t, arr, tttrang);
                break;
            case ESC:
                return;
            }
        }
        gotoxy(3, 35);
        cout << "HotKey: PgUp, PgDn, ESC";
        gotoxy(55, 1);
        cout << "Page: " << tttrang << "/" << tongtrang;
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
        int index = 0;
        // cout << "So node: " << nNodeDocGia;
        DocGia *arr = new DocGia[demDocGia(t)];
        treeToArr(t, arr, index);

        // sort_DG(arr, 0, nNodeDocGia - 1);
        // t = sortedArrayToBST(arr, 0, nNodeDocGia - 1);
        // cout << "preorder: ";
        // cout << preorder_NodeDG_NLR(t);

        ve_DG(keyDisplayDG, 5, x_DG);
        esc = xuat_ListDG(t, arr, dg, tttrang);
    } while (esc);
}

void do_QuaHan(ptrNode_DocGia t, ListDauSach lDS)
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    clrscr();

    // int soDG = demDocGia(t);
    int index = 0;
    int nNodeDocGia = demDocGia(t);
    DocGia *arr = new DocGia[nNodeDocGia];
    treeToArr(t, arr, index);
    // sort_DG(arr, 0, nNodeDocGia - 1);
    //
    string text = "Danh Sach Doc Gia Muon Qua Han ";
    //taoBox(48, 2, text, (int)text.length());

    gotoxy(47, 2);
    cout << "Danh Sach DG Muon Qua Han ";
    gotoxy(3, 5);
    cout << "Stt";
    gotoxy(10, 5);
    cout << "Ma doc gia";
    gotoxy(25, 5);
    cout << "Ho DG";
    gotoxy(40, 5);
    cout << "Ten DG";
    gotoxy(55, 5);
    cout << "Ma sach";
    gotoxy(70, 5);
    cout << "Ten sach";
    gotoxy(97, 5);
    cout << "Ngay muon";
    gotoxy(110, 5);
    cout << "Tong so ngay qua han";
    SetColor(WHITE);
    SetBGColor(BLACK);

    int j = 0;
    for (int i = 0; i < nNodeDocGia; i++)
    {
        if (soNgayQuaHan(arr[i].ptrMuonTra) > 0)
        {
            // ptrNode_DocGia p = layDG_NTDG(t, arr[i].maThe);
            gotoxy(12, 6 + j);
            cout << arr[i].maThe;
            gotoxy(23, 6 + j);
            cout << arr[i].ho;
            gotoxy(40, 6 + j);
            cout << arr[i].ten;
            gotoxy(55, 6 + j);
            cout << arr[i].ptrMuonTra.head->muonTra.maSach;
            gotoxy(68, 6 + j);
            cout << findDSByISBN(lDS, arr[i].ptrMuonTra.head->muonTra.maSach)->tenSach;
            gotoxy(96, 6 + j);
            cout << arr[i].ptrMuonTra.head->muonTra.ngayMuon.ngay;
            gotoxy(98, 6 + j);
            cout << "/";
            gotoxy(99, 6 + j);
            cout << arr[i].ptrMuonTra.head->muonTra.ngayMuon.thang;
            gotoxy(101, 6 + j);
            cout << "/";
            gotoxy(102, 6 + j);
            cout << arr[i].ptrMuonTra.head->muonTra.ngayMuon.nam;
            gotoxy(120, 6 + j);
            cout << soNgayQuaHan(arr[i].ptrMuonTra);
            gotoxy(4, 6 + j);
            j++;
            cout << j;
        }
        // else
        // {
        //     cout << "Khong co ai qua han!" << endl;
        // }
    }
    _getch();
    delete[] arr;
}

//ListDauSach Top10_DS(ListDauSach listDS)
//{
//	ListDauSach A=listDS;
//	DauSach t;
//	int B[10];
//	int dem=0,max,i,j;	
//	for(i=0;i<A.n-1;i++){
//		max=i;
//		for (j = i+1; j < A.n; j++)
//        	if (A.nodes[j]->soLanMuon > A.nodes[max]->soLanMuon) max = j;        				      
//        DauSach *t=A.nodes[i];
//        A.nodes[i]=A.nodes[max];
//        A.nodes[max]=t; 
//		dem++;
//		if(dem>10) break;		              
//    }
//    return A; 	
//}

//DAUSACH

void dong_DS(ListDauSach listDS, int i)
{
    int y = 6 + i;
    gotoxy(0, y);
    cout << "| " << listDS.nodes[i]->isbn;
    gotoxy(11, y);
    cout << "| " << listDS.nodes[i]->tenSach;
    gotoxy(50, y);
    cout << "| " << listDS.nodes[i]->tacGia;
    gotoxy(68, y);
    cout << "| " << listDS.nodes[i]->theLoai;
    gotoxy(85, y);
    cout << "|  " << listDS.nodes[i]->namXuatBan;
    gotoxy(98, y);
    cout << "|  " << listDS.nodes[i]->soTrang;
    gotoxy(107, y);
    cout << "|  " << listDS.nodes[i]->soLanMuon;
    gotoxy(119, y);
    cout << "|";
}
void do_DMS(DauSach ds)
{
    Normal();
    system("cls");
    gotoxy(50, 0);
    cout << "THONG TIN DAU SACH" << endl;
    cout << "                                ISBN: " << ds.isbn << endl;
    cout << "                                TEN SACH: " << ds.tenSach << endl;
    cout << "                                TAC GIA: " << ds.tacGia << endl;
    cout << "                                THE LOAI: " << ds.theLoai << endl;
    cout << "                                NAM XUAT BAN: " << ds.namXuatBan << endl;
    cout << "                                SO TRANG: " << ds.soTrang << endl;
    cout << "                                SO LAN MOUN: " << ds.soLanMuon;
    if (ds.First_DMS== NULL)
        cout << endl
             << "          DAU SACH NAY CHUA CO SACH" << endl;
    else
    {
        gotoxy(50, 8);
        cout << "DANH MUC SACH";
        gotoxy(11 + 20, 9);
        for (int i = 0; i < 57; i++)
            cout << "-";
        gotoxy(11 + 20, 10);
        cout << "|     MA SACH     |      VI TRI      |    TRANG THAI    |";
        gotoxy(11 + 20, 11);
        for (int i = 0; i < 57; i++)
            cout << "-";
        int y = 12;
        ptrNode_DanhMucSach p = ds.First_DMS;
        for (p; p != NULL; p = p->next)
        {
            gotoxy(0 + 11 + 20, y);
            cout << "| " << p->danhMucSach.maSach;
            gotoxy(18 + 11 + 20, y);
            cout << "| " << p->danhMucSach.viTri;
            gotoxy(37 + 11 + 20, y);
            cout << "| ";
            cout << "        " << p->danhMucSach.trangThai << "        |";
            y++;
        }
        cout << endl
             << "                               ";
        for (int i = 0; i < 57; i++)
            cout << "-";
    }
    cout << endl
         << "          ESC: Tro lai F2: Luu";
    char t;
    do
    {
        t = getch();
    } while (t != 27);
    return;
}
int Them_DS(ListDauSach &listDS)
{
    Normal();
    system("cls");
    DauSach ds;
    cout << "ISBN: ";
    cin >> ds.isbn;
    cout << "TEN SACH: ";
    cin >> ds.tenSach;
    cout << "TAC GIA: ";
    cin >> ds.tacGia;
    cout << "THE LOAI: ";
    cin >> ds.theLoai;
    cout << "NAM XUAT BAN: ";
    cin >> ds.namXuatBan;
    cout << "SO TRANG: ";
    cin >> ds.soTrang;
    cout << "SO LAN MUON: ";
    cin >> ds.soLanMuon;
    pDauSach pDS;
    pDS = new DauSach;
    *(pDS) = ds;
    if (Search_isbn(listDS, ds.isbn) == -1)
    {
        if (Insert_DS(listDS, pDS) == 1)
            cout << "Them thanh cong";
        //initializeListNode_DMS(pDS->ptrDMS);
        Sleep(3000);
        return 1;
    }
    else
    {
        cout << endl
             << "MA ISBN DA TON TAI!";
        Sleep(3000);
        return 0;
    }
}
void DanhSachDS(ListDauSach listDS)
{
    Normal();
    system("cls");
    gotoxy(50, 1);
    cout << "DANH SACH CAC DAU SACH";
    gotoxy(0, 3);
    for (int i = 0; i < 119; i++)
        cout << "-";
    gotoxy(0, 4);
    cout << "|   ISBN   |              TEN SACH                |     TAC GIA     |    THE LOAI    |NAM XUAT BAN|SO TRANG|SO LAN MUON|";
    gotoxy(0, 5);
    for (int i = 0; i < 119; i++)
        cout << "-";
    for (int i = 0; i < listDS.n; i++)
        dong_DS(listDS, i);
    for (int i = 0; i < 119; i++)
        cout << "-";
    cout << endl
         << " ESC: Tro lai     F1: Them     F3: Xoa     Enter: Xem DMS";
    char kytu;
    int chon = 0;
    HighLight();
    gotoxy(1, 6);
    cout << "          ";
    gotoxy(2, 6);
    cout << listDS.nodes[chon]->isbn;
    char t;
    do
    {
        t = getch();
        if (t == 0)
            t = getch();
        switch (t)
        {
        case Up:
            if (chon + 1 > 1)
            {
                Normal();
                gotoxy(1, 6 + chon);
                cout << "          ";
                gotoxy(2, 6 + chon);
                cout << listDS.nodes[chon]->isbn;
                chon--;
                HighLight();
                gotoxy(1, 6 + chon);
                cout << "          ";
                gotoxy(2, 6 + chon);
                cout << listDS.nodes[chon]->isbn;
            }
            break;
        case Down:
            if (chon + 1 < listDS.n)
            {
                Normal();
                gotoxy(1, 6 + chon);
                cout << "          ";
                gotoxy(2, 6 + chon);
                cout << listDS.nodes[chon]->isbn;
                chon++;
                HighLight();
                gotoxy(1, 6 + chon);
                cout << "          ";
                gotoxy(2, 6 + chon);
                cout << listDS.nodes[chon]->isbn;
            }
            break;
        case 61: //delete
        {
            Normal();
            gotoxy(0, listDS.n + 6 + 2);
            cout << endl
                 << "BAN THUC SU MUON XOA DAU SACH NAY?";
            cout << endl
                 << "OK        CANCEL";
            HighLight();
            gotoxy(0, listDS.n + 6 + 4);
            cout << "OK";
            char t2;
            int cot = 1;
            do
            {
                t2 = getch();
                if (t2 == 0)
                    t2 = getch();
                switch (t2)
                {
                case 75: //left
                    if (cot == 2)
                    {
                        Normal();
                        gotoxy(10, listDS.n + 6 + 4);
                        cout << "CANCEL";
                        cot--;
                        HighLight();
                        gotoxy(0, listDS.n + 6 + 4);
                        cout << "OK";
                    }
                    break;
                case 77: //right
                    if (cot == 1)
                    {
                        Normal();
                        gotoxy(0, listDS.n + 6 + 4);
                        cout << "OK";
                        cot++;
                        HighLight();
                        gotoxy(10, listDS.n + 6 + 4);
                        cout << "CANCEL";
                    }
                    break;
                case 13:
                {
                    if (cot == 1)
                        Delete_DS(listDS, chon);
                    // ghi file nua
                    DanhSachDS(listDS);
                }
                break;
                }

            } while (1);
        }
        break;
        case 59:
        {
            if (Them_DS(listDS) == 1)
                GhiFile_DS(listDS);
            DanhSachDS(listDS);
        }
        break;
        case 13: //enter
            do_DMS(*listDS.nodes[chon]);
            break;
        case 27:
            return;
            break;
        }
    } while (1);
}
void ve_TopDS(ListDauSach listDS)
{
    ListDauSach top = Top10_DS(listDS);
    Normal();
    system("cls");
    gotoxy(50, 1);
    cout << "TOP DAU SACH MUON NHIEU NHAT";
    gotoxy(0, 3);
    for (int i = 0; i < 119; i++)
        cout << "-";
    gotoxy(0, 4);
    cout << "|   ISBN   |              TEN SACH                |     TAC GIA     |    THE LOAI    |NAM XUAT BAN|SO TRANG|SO LAN MUON|";
    gotoxy(0, 5);
    for (int i = 0; i < 119; i++)
        cout << "-";
    for (int i = 0; i < 10 && i < top.n; i++)
    {
        if (top.nodes[i]->soLanMuon > 0)
            dong_DS(top, i);
        else
            break;
    }
    cout<<endl;
    for (int i = 0; i < 119; i++)
        cout << "-";
    cout << endl
         << " ESC: Tro lai";
    char t;
    do
    {
        t = getch();
    } while (t != 27);
    return;
}
void TimSach(ListDauSach listDS)
{
    Normal();
    system("cls");
    string tensach;
    cout << "NHAP TEN SACH CAN TIM: ";
    int check = NhapTenSachTimKiem(tensach);
    if (check == -1)
    {
        gotoxy(92, 10);
        cout << "Ban vua huy tra cuu !";
        _getch();
        return;
    }
    ListDauSach A;
    A.n = 0;
    for (int i = 0; i < listDS.n; i++)
        if (strstr(listDS.nodes[i]->tenSach.c_str(), tensach.c_str()) != NULL)
        {
            Insert_DS(A, listDS.nodes[i]);
        }
    if (A.n == 0)
    {
    	Normal();
	    system("cls");
        gotoxy(50, 1);
        cout << "KHONG CO SACH CAN TIM!";
    }
    else
    {
    	Normal();
    	system("cls");
        gotoxy(50, 1);
        cout << "SACH CAN TIM";
        gotoxy(0, 3);
        for (int i = 0; i < 119; i++)
            cout << "-";
        gotoxy(0, 4);
        cout << "|   ISBN   |              TEN SACH                |     TAC GIA     |    THE LOAI    |NAM XUAT BAN|SO TRANG|SO LAN MUON|";
        gotoxy(0, 5);
        for (int i = 0; i < 119; i++)
            cout << "-";
        for (int i = 0; i < A.n; i++)
        {
            dong_DS(A, i);
        }
        cout<<endl;
        for (int i = 0; i < 119; i++)
            cout << "-";
    }
    cout << endl
         << " ESC: Tro lai";
    char t;
    do
    {
        t = getch();
    } while (t != 27);
    return;
}
void ve_DS_TheoTHeLoai(ListDauSach listDS, string theloai)
{
    Normal();
    system("cls");
    gotoxy(50, 1);
    cout << "CAC DAU SACH THUOC THE LOAI " << theloai;
    gotoxy(0, 3);
    for (int i = 0; i < 119; i++)
        cout << "-";
    gotoxy(0, 4);
    cout << "|   ISBN   |              TEN SACH                |     TAC GIA     |    THE LOAI    |NAM XUAT BAN|SO TRANG|SO LAN MUON|";
    gotoxy(0, 5);
    for (int i = 0; i < 119; i++)
        cout << "-";
    int y = 6;
    for (int i = 0; i < listDS.n; i++)
        if (listDS.nodes[i]->theLoai == theloai)
        {
            gotoxy(0, y);
            cout << "| " << listDS.nodes[i]->isbn;
            gotoxy(11, y);
            cout << "| " << listDS.nodes[i]->tenSach;
            gotoxy(50, y);
            cout << "| " << listDS.nodes[i]->tacGia;
            gotoxy(68, y);
            cout << "| " << listDS.nodes[i]->theLoai;
            gotoxy(85, y);
            cout << "|  " << listDS.nodes[i]->namXuatBan;
            gotoxy(98, y);
            cout << "|  " << listDS.nodes[i]->soTrang;
            gotoxy(107, y);
            cout << "|  " << listDS.nodes[i]->soLanMuon;
            gotoxy(119, y);
            cout << "|";
            y++;
        }
    for (int i = 0; i < 119; i++)
        cout << "-";
    cout << endl
         << " ESC: Tro lai";
    char t;
    do
    {
        t = getch();
        if (t == 27)
            return;
    } while (1);
}
void ve_TheLoai(ListDauSach listDS)
{
    Normal();
    system("cls");
    string A[100] = {""};
    int n = 0;
    for (int i = 0; i < listDS.n; i++)
    {
        int check = 0;
        if (n == 0)
            A[n++] = listDS.nodes[i]->theLoai;
        for (int j = 0; j <= n; j++)
            if (A[j] == listDS.nodes[i]->theLoai)
                check = 1;
        if (check == 0)
            A[n++] = listDS.nodes[i]->theLoai;
    }
    cout << "CAC THE LOAI SACH" << endl;
    cout << endl;
    for (int i = 0; i <= n; i++)
        cout << A[i] << endl;
    //	Sleep(3000);
    cout << " ESC: Tro lai";
    HighLight();
    gotoxy(0, 2);
    cout << A[0];
    char t;
    int chon = 0;
    do
    {
        t = getch();
        if (t == 0)
            t = getch();
        switch (t)
        {
        case Up:
            if (chon > 0)
            {
                Normal();
                gotoxy(0, chon + 2);
                cout << A[chon];
                chon--;
                HighLight();
                gotoxy(0, chon + 2);
                cout << A[chon];
            }
            break;
        case Down:
            if (chon < n - 1)
            {
                Normal();
                gotoxy(0, chon + 2);
                cout << A[chon];
                chon++;
                HighLight();
                gotoxy(0, chon + 2);
                cout << A[chon];
            }
            break;
        case 13:
            ve_DS_TheoTHeLoai(listDS, A[chon]);
            ve_TheLoai(listDS);
            break;
        case 27:
            return;
            break;
        }
    } while (1);
}

///////////////////////////

string key_NhapDS[14] = {
    "               Cap Nhat Dau Sach               ",
    "                                                   ",
    " Ten Sach     :",
    "                                                   ",
    " ISBN         :",
    "                                                   ",
    " Tac Gia      :",
    "                                                   ",
    " The Loai     :",
    "                                                   ",
    " So Trang     :",
    "                                                   ",
    " Nam Xuat Ban :",
    "                                                   ",
};

void capNhat_DauSach(ListDauSach &lDS, pDauSach &pDS, bool isEdited)
{
    DauSach info;
    ShowCur(true);
    SetBGColor(BLACK);
    SetColor(WHITE);
    int soKyTu = (int)key_NhapDS[0].length();
    // cac flag
    int tienTrinh = 0;
    bool isSave = false;
    bool isEscape = false;
    // temp
    string tensach = "";
    string ISBN = "";
    string tacgia = "";
    string theloai = "";
    int sotrang = 0;
    int namXB = 0;
    gotoxy(x_Note + 7, y_Note);
    cout << "Luu y: ";
    ve_BangNhap_DS(82, 2, soKyTu, key_NhapDS, 13);
    /*gotoxy(x_Note + 5, y_Note - 2);
	XoaMotDong(15);*/
    if (isEdited)
    {
        tensach = pDS->tenSach;
        ISBN = pDS->isbn;
        tacgia = pDS->tacGia;
        theloai = pDS->theLoai;
        sotrang = pDS->soTrang;
        namXB = pDS->namXuatBan;

        gotoxy(83 + (soKyTu / 3), 2 + 3);
        cout << tensach;
        gotoxy(83 + (soKyTu / 3), 2 + 5);
        cout << ISBN;
        gotoxy(83 + (soKyTu / 3), 2 + 7);
        cout << tacgia;
        gotoxy(83 + (soKyTu / 3), 2 + 9);
        cout << theloai;
        gotoxy(83 + (soKyTu / 3), 2 + 11);
        cout << sotrang;
        gotoxy(83 + (soKyTu / 3), 2 + 13);
        cout << namXB;
    }

    while (true)
    {
        switch (tienTrinh)
        {
        case 0:
            gotoxy(83 + (soKyTu / 3), 2 + 3);
            NhapTenSach(tensach, tienTrinh, isSave, isEscape);
            break;
        case 1:
            gotoxy(83 + (soKyTu / 3), 2 + 5);
            NhapISBN(ISBN, tienTrinh, isSave, isEscape);
            break;
        case 2:
            gotoxy(83 + (soKyTu / 3), 2 + 7);
            NhapTenTacGia(tacgia, tienTrinh, isSave, isEscape);
            break;
        case 3:
            gotoxy(83 + (soKyTu / 3), 2 + 9);
            NhapTheLoaiSach(theloai, tienTrinh, isSave, isEscape);
            break;
        case 4:
            gotoxy(83 + (soKyTu / 3), 2 + 11);
            nhapSoTrang(sotrang, tienTrinh, isSave, isEscape);
            break;
        case 5:
            gotoxy(83 + (soKyTu / 3), 2 + 13);
            NhapNamXuatBan(namXB, tienTrinh, isSave, isEscape);
            break;
        }
        if (isSave)
        {
            // cap nhat lai flag
            isSave = false;
            if (tensach.length() == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(WHITE);
                cout << "           Du lieu khong de trong ! ";
                SetBGColor(BLACK);
                SetColor(WHITE);
                tienTrinh = 0;
                continue;
            }
            else if (ISBN.length() == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(WHITE);
                cout << "           Du lieu khong de trong ! ";
                SetBGColor(BLACK);
                SetColor(WHITE);
                tienTrinh = 1;
                continue;
            }
            else if (tacgia.length() == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(WHITE);
                cout << "           Du lieu khong de trong ! ";
                SetBGColor(BLACK);
                SetColor(WHITE);
                tienTrinh = 2;
                continue;
            }
            else if (theloai.length() == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(WHITE);
                cout << "           Du lieu khong de trong ! ";
                SetBGColor(BLACK);
                SetColor(WHITE);
                tienTrinh = 3;
                continue;
            }
            else if (sotrang == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(WHITE);
                cout << "           Du lieu khong de trong ! ";
                SetBGColor(BLACK);
                SetColor(WHITE);
                tienTrinh = 4;
                continue;
            }
            else if (namXB == 0)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(WHITE);
                cout << "          Du lieu khong de trong !";
                SetBGColor(BLACK);
                SetColor(WHITE);
                tienTrinh = 5;
                continue;
            }
            else if (namXB > 2021)
            {
                gotoxy(x_Note + 15, y_Note);
                SetColor(WHITE);
                cout << "Nam xuat ban khong dung !";
                SetBGColor(BLACK);
                SetColor(WHITE);
                tienTrinh = 5;
                continue;
            }
            if (isDauSach_ISBN(lDS, ISBN))
            {
                if (pDS->isbn != ISBN)
                {
                    gotoxy(x_Note + 15, y_Note);
                    SetColor(WHITE);
                    cout << "ISBN bi trung !";
                    SetBGColor(BLACK);
                    SetColor(WHITE);
                    tienTrinh = 1;
                    continue;
                }
            }
            // import data vao info
            info.tenSach = chuanHoaChuoi(tensach);
            info.isbn = chuanHoaChuoi(ISBN);
            info.tacGia = chuanHoaChuoi(tacgia);
            info.theLoai = chuanHoaChuoi(theloai);
            info.soTrang = sotrang;
            info.namXuatBan = namXB;
            if (isEdited)
            {
                pDS->tenSach = info.tenSach;
                pDS->isbn = info.isbn;
                pDS->tacGia = info.tacGia;
                pDS->theLoai = info.theLoai;
                pDS->soTrang = info.soTrang;
                pDS->namXuatBan = info.namXuatBan;
                SetBGColor(BLACK);
                SetColor(WHITE);
                return;
            }
            else
            {
                // khoi tao NULL
                //initializeListNode_DMS(pDS->ptrDMS);
                pDS->tenSach = info.tenSach;
                pDS->isbn = info.isbn;
                pDS->tacGia = info.tacGia;
                pDS->theLoai = info.theLoai;
                pDS->soTrang = info.soTrang;
                pDS->namXuatBan = info.namXuatBan;
                int temp = Insert_DS(lDS, pDS);
                if (temp == 0)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        SetColor(WHITE);
                        gotoxy(x_Note + 15, y_Note);
                        cout << "Bo nho day, khong the them!";
                    }
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        SetColor(WHITE);
                        gotoxy(x_Note + 15, y_Note);
                        cout << "        Hoan tat !";
                    }
                }
                SetBGColor(BLACK);
                SetColor(WHITE);
                return;
            }
        }
        if (isEscape)
        {
            return;
        }
    }
    ShowCur(false);
}

int chonItems_DS(ListDauSach &lDS, int &thuTuTrang, int tongtrang)
{
    int pos = 0;
    int kb_hit;
    pos = 0;
    SetColor(WHITE);
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
                Xoa_DS_lineS();
                xuat_DStheoTrang(lDS, thuTuTrang);
                pos = 0;
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
                Xoa_DS_lineS();
                xuat_DStheoTrang(lDS, thuTuTrang);
                pos = 0;
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
        SetColor(WHITE);
        gotoxy(70, 1);
        cout << "Page: " << thuTuTrang << "/" << tongtrang;
        SetColor(WHITE);
        SetBGColor(BLACK);
    }
}

int layViTri_Key(ptrNode_DanhMucSach first, string key)
{
    int viTri;
    ptrNode_DanhMucSach q;
    q = first;
    viTri = 1;
    if (q == NULL)
        return (-1);
    while (q != NULL && q->danhMucSach.maSach != key)
    {
        q = q->next;
        viTri++;
    }
    return (viTri);
}

ptrNode_DanhMucSach nodePointer(ptrNode_DanhMucSach first, int i)
{
    ptrNode_DanhMucSach p;
    int viTri = 1;
    p = first;
    while (p != NULL && viTri < i)
    {
        p = p->next;
        viTri++;
    }
    return (p);
}

int xoa_Key(pDauSach &pDS, string key)
{
    int viTri;
    viTri = layViTri_Key(pDS->First_DMS, key);
    int soSach=0;
    ptrNode_DanhMucSach p;
    for(p=pDS->First_DMS;p!=NULL;p=p->next)
    	soSach++;
    if (viTri > soSach || viTri == -1)
    {
        return -1;
    }
    // truong hop xoa dau
    else if (viTri == 1)
    {
        deleteFirst_DMS(pDS->First_DMS);
        //pDS->ptrDMS.n--;
        return 1;
    }
    else
    {
        //p chi toi nut truoc nut can xoa
        ptrNode_DanhMucSach p = nodePointer(pDS->First_DMS, viTri - 1);
        deleteAfter_DMS(p);
        // truong hop xoa duoi cap nhat lai pTail*
//        if (viTri == pDS->ptrDMS.n)
//        {
//            pDS->ptrDMS.LastNode_DanhMucSach = p;
//        }
//        pDS->ptrDMS.n--;
        return 1;
    }
}

void xoaDauSach_ViTri(ListDauSach &listDS, int viTri)
{
    if (viTri > listDS.n || Empty(listDS) || isFull_DS(listDS) || viTri < 0)
    {
        return;
    }
    // xoa vi tri cuoi mang
    if (viTri == listDS.n)
    {
        delete listDS.nodes[listDS.n];
        listDS.nodes[listDS.n--] = NULL; //*
        return;
    }
    // *
    delete listDS.nodes[viTri];
    for (int temp = viTri + 1; temp <= listDS.n; temp++)
    {
        listDS.nodes[temp - 1] = listDS.nodes[temp];
    }
    delete listDS.nodes[listDS.n--]; //*
    listDS.nodes[listDS.n--] = NULL;
    return;
}

void Menu_DauSach(ListDauSach &lDS)
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    clrscr();
    gotoxy(32, 1);
    cout << "Cap Nhat Dau Sach ";
    int nDS = lDS.n + 1;
    int choose;
    pDauSach pDS;
    gotoxy(3, 35);
    SetColor(WHITE);
    cout << "     ESC:  Thoat, F1: Them, F2: Sua, F3: Xoa, F5: Luu, PageUp, PageDn";
    SetColor(WHITE);
    SetBGColor(BLACK);
    int thuTuTrang, tongtrang;
    thuTuTrang = 1;
    tongtrang = (nDS / NUMBER_LINES) + 1;
label1:
    XoaMotVung(79, 2, 30, 53);
    ve_DS(keyDisplayDS, 6, x_DS);
    xuat_DStheoTrang(lDS, thuTuTrang);
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
                xuat_DStheoTrang(lDS, thuTuTrang);
                break;
            case PAGE_DOWN:
                (thuTuTrang < tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
                xuat_DStheoTrang(lDS, thuTuTrang);
                break;
            case F1:
                pDS = new DauSach;
                if (pDS == NULL)
                    goto label1;
                capNhat_DauSach(lDS, pDS, false);
                goto label1;
            case F2:
                choose = chonItems_DS(lDS, thuTuTrang, tongtrang);
                if (choose > lDS.n)
                    goto label1;
                capNhat_DauSach(lDS, lDS.nodes[choose], true);
                goto label1;
            case F3:
                choose = chonItems_DS(lDS, thuTuTrang, tongtrang);
                if (choose > lDS.n)
                    goto label1;
                // neu co nguoi muon thi se khong duoc phep xoa .
                if (CheckMuon_DMS(lDS.nodes[choose]->First_DMS))
                {
                    gotoxy(79, 20);
                    cout << " Dau Sach da co Doc Gia muon nen khong duoc phep xoa !";
                    _getch();
                    gotoxy(79, 20);
                    cout << "                                                      ";
                    goto label1;
                }
                xoaDauSach_ViTri(lDS, choose);
                goto label1;
            case ESC:
                return;
            }
        }
        SetColor(WHITE);
        ShowCur(false);
        gotoxy(70, 1);
        cout << "Page: " << thuTuTrang << "/" << tongtrang;
    } while (true);
}

int NhapSach(pDauSach &pDS)
{
    DanhMucSach info;
    ShowCur(true);
    SetColor(WHITE);
    SetBGColor(BLACK);
    int dai = (int)keyBangNhapDanhMucSach[0].length();
    gotoxy(38, y_Note + 2);
    // cout << "Luu y: ";
    ve_BangNhap_DS(38, 2 + 2, dai, keyBangNhapDanhMucSach, 8);

    int trinhTu = 1;
    bool isSave = false;
    bool isEscape = false;
    // Temp
    int soSach=0;
    ptrNode_DanhMucSach p=pDS->First_DMS;
    for(p;p!=NULL;p=p->next)
    	soSach++;
    int thuTuDMS = soSach;
//    string maSach = pDS->isbn + char(65 + thuTuDMS); //int->char
//    //kt trung, tang thuTuDMS
//    while (search_DMS_MaSach(pDS, maSach) != NULL)
//    {
//        thuTuDMS++;
//        maSach = pDS->isbn + char(65 + thuTuDMS);
//    }
    /// danh ma sach tu dong
    string maSach=DanhMaSach(pDS);
    int ttSach = 3;
    string viTri = "";
    gotoxy(40 + (dai / 3), 2 + 5);
    cout << maSach;
    while (true)
    {
        switch (trinhTu)
        {
        case 1:
            NhapTrangThaiSach(ttSach, trinhTu, isSave, isEscape, 40 + (dai / 3), 2 + 7);
            break;
        case 2:
            NhapViTri(viTri, trinhTu, isSave, isEscape, 40 + (dai / 3), 2 + 9);
            break;
        }
        if (isSave)
        {
            isSave = false;
            // check rong;
            if (ttSach == 3)
            {
                gotoxy(55, y_Note + 2);
                cout << "Cac truong du lieu khong de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                trinhTu = 1;
                continue;
            }
            if (viTri.length() == 0)
            {
                gotoxy(55, y_Note + 2);
                cout << "Cac truong du lieu khong de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                trinhTu = 2;
                continue;
            }
            info.maSach = maSach;
            info.trangThai = ttSach;
            info.viTri = viTri;
            //themCuoiList_DMS(pDS->ptrDMS, info);
            insertFirst_DMS(pDS->First_DMS, info);
            return 0;
        }
        if (isEscape)
        {
            return -1;
        }
    }
}

int SuaDanhMucSach(pDauSach &pDS, ptrNode_DanhMucSach dms)
{
    DanhMucSach info;
    if (dms->danhMucSach.trangThai == 1)
        return 2;
    // hien con tro nhap
    ShowCur(true);
    SetColor(WHITE);
    SetBGColor(BLACK);
    int dai = (int)keyBangNhapDanhMucSach[0].length();
    taoBox(67, y_Note + 2, "Luu Y:  ", 66);
    ve_BangNhap_DS(65, 2 + 6, dai, keyBangNhapDanhMucSach, 8);
    // cac flag dieu khien qua trinh cap nhat
    int tienTrinh = 1;
    bool isSave = false;
    bool isEscape = false;
    string maSach = dms->danhMucSach.maSach;
    int ttSach = dms->danhMucSach.trangThai;
    string viTri = dms->danhMucSach.viTri;
    gotoxy(67 + (dai / 3), 2 + 9);
    cout << maSach;
    gotoxy(89, 2 + 11);
    if (ttSach == 0)
        cout << ttSach << ":   Co the muon  ";
    else if (ttSach == 1)
        cout << ttSach << ":   Da duoc muon   ";
    else if (ttSach == 2)
        cout << ttSach << ":   Da thanh ly    ";
    gotoxy(89, 2 + 13);
    cout << viTri;
    while (true)
    {
        switch (tienTrinh)
        {
        case 1:
            NhapTrangThaiSach(ttSach, tienTrinh, isSave, isEscape, 89, 2 + 11);
            break;
        case 2:
            NhapViTri(viTri, tienTrinh, isSave, isEscape, 89, 2 + 13);
            break;
        }
        if (isSave)
        {
            isSave = false;
            // check rong;
            if (ttSach == 3)
            {
                gotoxy(67, y_Note + 2);
                cout << "          Du lieu khong duoc de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                // quay lai va dien vao truong du lieu do
                tienTrinh = 1;
                continue;
            }
            if (viTri.length() == 0)
            {
                gotoxy(67, y_Note + 2);
                cout << "          Du lieu khong duoc de trong ! ";
                SetColor(WHITE);
                SetBGColor(BLACK);
                // quay lai va dien vao truong du lieu do
                tienTrinh = 2;
                continue;
            }
            // import data vao info
            info.maSach = maSach;
            info.trangThai = ttSach;
            info.viTri = viTri;
            dms->danhMucSach = info;
            return 1;
        }
        if (isEscape)
        {
            return -1;
        }
    }
}

void xuat_ListDMS(pDauSach &pDS)
{
    clrscr();
    int check1;
    int check2;
    int check3;
    int thuTuTrang, tongtrang;
    thuTuTrang = 1;
    int soSach=0;
    ptrNode_DanhMucSach p;
    for(p=pDS->First_DMS;p!=NULL;p=p->next)
    	soSach++;
    tongtrang = ((soSach + 1) / NUMBER_LINES) + 1;
    ptrNode_DanhMucSach temp = NULL, temp1 = NULL;
    gotoxy(8, 1);
    cout << " Bang Danh Muc Sach " << pDS->tenSach;
label:
    ve_DMS(keyDisplayDMS, 3, x_DMS);
    xuat_DMS_trang(pDS, thuTuTrang);
    string keySearch = "";
    int kb_hit;
    do
    {
        XoaMotVung(65, 2, 30, 67);
        if (_kbhit())
        {
            kb_hit = _getch();
            if (kb_hit == 224 || kb_hit == 0)
                kb_hit = _getch();
            switch (kb_hit)
            {
            case PAGE_UP:
                (thuTuTrang > 1) ? thuTuTrang-- : thuTuTrang = tongtrang;
                xuat_DMS_trang(pDS, thuTuTrang);
                break;
            case PAGE_DOWN:
                (thuTuTrang < tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
                xuat_DMS_trang(pDS, thuTuTrang);
                break;
            case F2:
                VeHinhBangNhap(82, 3, 38, "       Ma sach can sua !");
                gotoxy(96, 5);
                check1 = NhapMaDauSach(keySearch);
                // kiem tra dieu kien tra ve .....
                if (check1 == -1)
                {
                    gotoxy(84, y_Note + 12);
                    cout << "Da huy tac vu!";
                    _getch();
                }
                else if (check1 == 1)
                {
                    temp = search_DMS_MaSach(pDS, keySearch);
                    if (temp == NULL)
                    {
                        gotoxy(77, y_Note + 12);
                        cout << "Ma sach "
                             << "'" << keySearch << "'"
                             << " khong co trong du lieu";
                        _getch();
                    }
                    else
                    {
                        check3 = SuaDanhMucSach(pDS, temp);
                        // kiem tra cac truong hop.
                        if (check3 == 1)
                        {
                            gotoxy(73, y_Note + 12);
                            cout << "Ban vua sua thong tin sach co ma la: " << keySearch;
                            _getch();
                        }
                        else if (check3 == 2)
                        {
                            gotoxy(73, y_Note + 12);
                            cout << "Sach da co Doc Gia muon nen khong duoc phep hieu chinh !";
                            _getch();
                            gotoxy(73, y_Note + 12);
                            cout << "                                                        ";
                        }
                        else
                        {
                            gotoxy(82, y_Note + 12);
                            cout << "Da huy chinh sua !";
                            _getch();
                        }
                    }
                }
                goto label;
            case F3:
                VeHinhBangNhap(82, 3, 35, "     Nhap Ma De Xoa   ");
                gotoxy(96, 5);
                check1 = NhapMaDauSach(keySearch);
                // kiem tra dieu kien tra ve .....
                if (check1 == -1)
                {
                    gotoxy(88, 10);
                    cout << "Da huy tac vu xoa !";
                    _getch();
                }
                else if (check1 == 1)
                {
                    temp1 = search_DMS_MaSach(pDS, keySearch);
                    // da co doc gia muon.
                    if (temp1->danhMucSach.trangThai == 1)
                    {
                        gotoxy(78, 20);
                        cout << "Sach da co Doc Gia muon nen khong duoc phep xoa !";
                        _getch();
                        gotoxy(78, 20);
                        cout << "                                                      ";
                    }
                    else
                    {
                        check2 = xoa_Key(pDS, keySearch);
                        if (check2 == -1)
                        {
                            gotoxy(75, 10);
                            cout << "Ma sach "
                                 << "'" << keySearch << "'"
                                 << " khong co trong du lieu";
                            _getch();
                        }
                        else if (check2 == 1)
                        {
                            gotoxy(82, 10);
                            cout << "Da xoa sach co ma la: " << keySearch;
                            _getch();
                        }
                    }
                }
                goto label;
            case ESC:
                clrscr();
                return;
            }
        }
        ShowCur(false);
        gotoxy(3, 35);
        cout << " F2:  Hieu chinh , F3:  Xoa , ESC:  Thoat";
        gotoxy(62, 1);
        cout << "Page: " << thuTuTrang << " / " << tongtrang;
    } while (true);
}

void NhapDanhMucSach(pDauSach &pDS, int sosach)
{
    clrscr();
    system("color 0");
    int check1 = 0;
    gotoxy(39, 2);
    cout << "Nhap Thong Tin Dau Sach : " << pDS->tenSach;
    gotoxy(60, 16);
    cout << "So sach chon nhap: " << sosach << endl;
    gotoxy(52, 31);
    cout << "    F5: Luu ,  ESC - Thoat ";
    for (int i = 0; i < sosach && check1 != -1; i++)
    {
        // nhap sach
        check1 = NhapSach(pDS);
        XoaMotVung(38, 2 + 2, 10, (int)keyBangNhapDanhMucSach[0].length());
        gotoxy(60, 18);
        cout << "So sach da nhap : " << i + 1;
    }
    // xuat_ListDMS(pDS);
}

void Menu_DMS(ListDauSach &lDS)
{
    system("color 0");
    int choose;
    int nDS = lDS.n + 1;
    int tttrang, tongtrang;
    tttrang = 1;
    tongtrang = (nDS / NUMBER_LINES) + 1;
    int temp = 1;
    do
    {
        clrscr();
        ve_DS(keyDisplayDS, 6, x_DS);
        xuat_DStheoTrang(lDS, tttrang);
        gotoxy(23, 1);
        cout << "Chon dau sach de cap nhat DMS !";
        SetColor(WHITE);
        SetBGColor(BLACK);
        choose = chonItems_DS(lDS, tttrang, tongtrang);
        if (choose == -1)
        {
            return;
        }
        else if (choose > lDS.n)
        {
            gotoxy(2, 2 + 3 + choose % NUMBER_LINES);
            cout << setw(27) << setfill(' ') << ' ';
            continue;
        }
        //if (lDS.nodes[choose]->ptrDMS.FirstNode_DanhMucSach != NULL && lDS.nodes[choose]->ptrDMS.n == -1)
//        if(lDS.nodes[choose]->First_DMS==NULL)
//        {
//            continue;
//        }
        // chon so sach nhap
        // int sosach = ChonSoSachNhap();
        int sosach = 1;
        gotoxy(88, 3);
        cout << "NHAP SO SACH MUON THEM (0: EDIT DMS): ";
        NhapMaDocGia(sosach);
        if (sosach < 0)
        {
            // XoaMotVung(81, 3, 20, 50);
            // continue;
            return;
        }
        else if (sosach == 0)
        {
            xuat_ListDMS(lDS.nodes[choose]);
            // continue;
        }
        else if (sosach > 0)
        {
            // bat dau nhap thong tin sach
            NhapDanhMucSach(lDS.nodes[choose], sosach);
        }
    } while (true);
}

int xetThuTu(pDauSach left, pDauSach right)
{
    string temp1 = left->theLoai;
    string temp2 = right->theLoai;
    // cout << temp1 << temp2;
    if (temp1.compare(temp2) < 0)
        return true;

    temp1 = left->tenSach;
    temp2 = right->tenSach;
    if (temp1.compare(temp2) < 0)
        return true;
    return false;
}

void swap_DS(pDauSach ds1, pDauSach ds2)
{
    DauSach temp = *ds1;
    *ds1 = *ds2;
    *ds2 = temp;
}

//

void SSort_DauSach(ListDauSach &lDS)
{
    int i, j, min_idx;
    for (i = 0; i <= lDS.n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j <= lDS.n - 1; j++)
        {
            if (xetThuTu(lDS.nodes[j], lDS.nodes[min_idx]))
                min_idx = j;
        }
        swap_DS(lDS.nodes[min_idx], lDS.nodes[i]);
    }
}

int TongSoSachDuocMuon(ptrNode_DanhMucSach &First)
{
    int dem = 0;
    ptrNode_DanhMucSach temp = NULL;
    for (temp = First; temp != NULL; temp = temp->next)
    {
        //  tinh ca sach da muon va da muon nhung lam mat.
        if (temp->danhMucSach.trangThai == 1 || temp->danhMucSach.trangThai == 2)
        {
            dem++;
        }
    }
    return dem;
}

void xuat_ListDStheoTT(ListDauSach lDS)
{
    system("color 0");
    clrscr();
    SetColor(WHITE);
    SetBGColor(BLACK);

    // quickSortMulti_(lDS,0, sl);
    SSort_DauSach(lDS);

    ve_DS(keyDisplayDS, 6, x_DS);
    SetColor(WHITE);
    SetBGColor(BLACK);
    gotoxy(32, 1);
    cout << "Bang Thong Tin Dau Sach ";
    int nDS = lDS.n + 1;
    int thuTuTrang, tongtrang;
    thuTuTrang = 1;
    tongtrang = (nDS / NUMBER_LINES) + 1;
    xuat_DStheoTrang(lDS, thuTuTrang);
    int check;
    pDauSach temp;
    string tensach = "";
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
                xuat_DStheoTrang(lDS, thuTuTrang);
                break;
            case PAGE_DOWN:
                (thuTuTrang < tongtrang) ? thuTuTrang++ : thuTuTrang = 1;
                xuat_DStheoTrang(lDS, thuTuTrang);
                break;

            case ESC:
                return;
            }
        }
        ShowCur(false);
        gotoxy(2, 35);
        SetColor(WHITE);
        cout << "    PageUp, PageDn, ESC: Thoat";
        gotoxy(72, 1);
        cout << "Page: " << thuTuTrang << "/" << tongtrang;
    } while (true);
}
