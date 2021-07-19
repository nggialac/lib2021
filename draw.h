#include "mylib.h"
#include "DG.h"
#include "DMS.h"
#include "DateTime.h"

string keyDisplayDG[5] = {"Ma DG", "     Ho DG", "Ten DG", "Phai  ", "TTr The"};
int x_DG[6] = {3, 13, 32, 43, 53, 65};

const int so_item = 10;
const int dong = 1;
const int cot = 0;
const int Up = 72;
const int Down = 80;

char mainMenu[so_item][50] = {"1. Nhap Doc Gia    ",
                              "2. Ghi file Doc Gia         ",
                              "3. Doc file Doc Gia    ",
                              "4. Doc file Dau Sach     ",
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

void show()
{
    // HWND hWnd = GetConsoleWindow();
    // ShowWindow(hWnd, SW_SHOWMAXIMIZED);
    int chon;
    int temp;
    DocGia dg;
    DocGia *arr;
    while (1)
    {
        chon = MenuDong(mainMenu);
        switch (chon)
        {

        case 1:
            gotoxy(30, 20);
            cout << "Vua chon chuc nang " << chon;
            // int temp = 0;
            create_Tree(tree);
            break;
        case 2:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
            temp = writeFile_DG(tree, FILE_PATH);
            if (temp > 0)
                cout << "Write file success!" << endl;
            system("pause");
            break;
        case 3:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
            temp = readDG(tree, FILE_PATH);
            if (temp > 0)
                cout << "Read file DG success!" << endl;
            system("pause");
            break;

        case 4:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
            temp = readFile_DS(listDS);
            if (temp > 0)
                cout << "Read file success!" << endl;
            system("pause");
            break;
        case 5:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
            temp = preorder_NodeDG_NLR(tree);
            if (temp > 0)
                cout << "Records: " << endl;
            system("pause");
            break;
        case 6:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon << endl;
            cout << "Nhap ma the doc gia: " << endl;
            cin >> dg.maThe;
            cout << dg.maThe;
            temp = remove_NodeDG(tree, dg);
            if (temp > 0)
                cout << "Da xoa thanh cong DG !" << endl;
            system("pause");
            break;

        case 7:
            gotoxy(10, 20);
            indexDG = 0;
            cout << "Vua chon chuc nang " << chon;
            cout << nNodeDocGia << endl;

            arr = new DocGia[nNodeDocGia];
            tao_Arr(tree, arr);
            sort_DG(arr, 0, nNodeDocGia - 1);
            for (int i = 0; i < nNodeDocGia; i++)
            {
                cout << arr[i].maThe << endl;
                cout << arr[i].ho << endl;
                cout << arr[i].ten << endl;
            }
            system("pause");
            delete[] arr;
            break;

        case 8:
            gotoxy(10, 20);
            indexDG = 0;
            cout << "Vua chon chuc nang " << chon;
            cout << nNodeDocGia << endl;

            arr = new DocGia[nNodeDocGia];
            tao_Arr(tree, arr);
            for (int i = 0; i < nNodeDocGia; i++)
            {
                cout << arr[i].maThe << " ";
                cout << arr[i].ho << " ";
                cout << arr[i].ten << " ";
            }
            system("pause");
            delete[] arr;
            break;

        case 9:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon << endl;
            do_MuonSach(tree, listDS);
            system("pause");
            break;

        case so_item:
            return;
        }
        Sleep(500);
    }
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
    SetBGColor(WHITE);
    SetColor(BLACK);
    gotoxy(x, y);
    cout << str;
    SetColor(WHITE);
    SetBGColor(BLACK);
}

int MatSach(ptrNode_MuonTra lMT) {
	for (ptrNode_MuonTra p = First_MuonTra; p != NULL; p = p->next) {
		if ( p->muonTra.trangThai == 2) {
			return 1;
		}
	}
	return 0;
}

int soNgayMuonMax(ptrNode_MuonTra lMT) {
	int max = 0;
	int nngay;
	for (ptrNode_MuonTra p = First_MuonTra; p != NULL; p = p->next) {
		if ((p->muonTra.trangThai == 0) || (p->muonTra.trangThai == 2)) {
			nngay = tinhNgay(p->muonTra.ngayMuon);
			if (max < nngay) {
				max = nngay;
			}
		}
	}
	return max;
}


void do_MuonSach(ptrNode_DocGia &root, ListDauSach &listDauSach)
{

    clrscr();
    system("color 0");
    int msdg = 0;
    int check2, check3 = 0;

    char thongbao1[] = "           Doc Gia chi duoc muon toi da 3 cuon !";
    char thongbao2[] = "           Doc Gia da bi khoa the!";
    char thongbao3[] = "           Doc Gia da giu sach qua han 7 ngay!";
    char thongbao4[] = "           Doc Gia da lam mat sach! ";
    int mt;
    int checkMt;
    ptrNode_DocGia nodeTemp;

label:
    int index = 0;
    DocGia *ArrTenHo = new DocGia[nNodeDocGia];
    tao_Arr(root, ArrTenHo);
    ve_DG(keyDisplayDG, 5, x_DG);
    sort_DG(ArrTenHo, 0, nNodeDocGia - 1);
    xuat_ListDG_MT(root, ArrTenHo);
    //// xoa vung nho
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
        }
        else
        {
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
            cout << "-So sach chua tra : " << soSachDangMuon(nodeTemp->info.ptrMuonTra);
            gotoxy(95, 17);
            cout << "     =Sach Dang Muon=      ";
            gotoxy(85, 18);
            cout << "     Ten Sach                           ";
            gotoxy(118, 18);
            cout << " Ngay Muon  ";
            int pos;
            for (ptrNode_MuonTra p = First_MuonTra; p != NULL; p = p->next)
            {
                cout<<"ISBN: "<<endl;
                cout<< (p->muonTra.isbn);
            
                if (p->muonTra.trangThai == 0 || p->muonTra.trangThai == 2)
                {
                    gotoxy(87, 20 + pos);
                    cout << "                                           ";
                    gotoxy(87, 20 + pos);
                    cout << p->muonTra.isbn;
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

            if (nodeTemp->info.trangThai == 0) {
				gotoxy(70, 28);
				cout << thongbao2;
				_getch();
				return;
			}
			if (MatSach(nodeTemp->info.ptrMuonTra)) {
				gotoxy(70, 28);
				cout << thongbao4;
				_getch();
				return;
			}
			if (soNgayMuonMax(nodeTemp->info.ptrMuonTra) > 7) {
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
			// check2 = Menu_MS(lDS, temp);
			// // check cac truong hop
			// if (check2 == -1) {
			// 	return;
			// } else if (check2 == 1) {
			// 	mt.tenSach = tensach;
			// 	mt.ngayTra.nam = 0;
			// 	mt.ngayTra.thang = 0;
			// 	mt.ngayTra.ngay = 0;
			// 	mt.maSach = masach;
			// 	mt.viTriSach = vitrisach;
			// 	mt.trangThai = 0;
			// 	do {
			// 		gotoxy(83, 28);
			// 		cout << "Nhap vao ngay muon (F5 luu, ESC huy) !";
			// 		check3 = InputNgayThang(mt.ngayMuon, 100, 30);
			// 		// check cac truong hop
			// 		if (check3 == -1) {
			// 			return;
			// 		} else if (check3 == 2) {
			// 			themDauList_MT(temp->listMT, mt);
			// 			goto label1;
			// 		}
			// 	} while (check3 );
			// }


        }
    }
}
