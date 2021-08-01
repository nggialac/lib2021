#include "draw.h"

#define x_SMainMenusDS 3
#define x_SMainMenusDG 3
#define x_SMainMenusMT 3
#define xMainMenu 3
// #define yMainMenu 12

// int x_MainMenus[5] = { 8,26,52, 81,105 };
int y_MainMenus[4] = {16, 19, 22, 25};
int y_SMainMenusDS[3] = { 16, 19, 22};
int y_SMainMenusDG[3] = { 16, 19, 22 };
int y_SMainMenusMT[3] = { 16, 19, 22 };

void taoBox(int x, int y, string text, int length) {
	gotoxy(x - 2, y - 1);
	cout << char(218) << setw(length) << setfill(char(196)) << char(196) << char(191);
	gotoxy(x - 2, y);
	cout << char(179) << text << setw(length - text.length() + 1) << setfill(' ') << char(179);
	gotoxy(x - 2, y + 1);
	cout << char(192) << setw(length) << setfill(char(196)) << char(196) << char(217);
}

void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor) {
	// den dia chi can highlight
	gotoxy(x - 1, y[index]);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}

void SMainMenuDG(string key[], int nKey) {
	SetColor(WHITE);
    SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++) {
		taoBox(x_SMainMenusDG, y_SMainMenusDG[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenuDG[0], 0, x_SMainMenusDG, y_SMainMenusDG, GREEN, BLACK);
	ShowCur(false);
}

void SMainMenuDS(string key[], int nKey) {
	SetColor(WHITE);
    SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++) {
		taoBox(x_SMainMenusDS, y_SMainMenusDS[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenuDS[0], 0, x_SMainMenusDS, y_SMainMenusDS, GREEN, BLACK);
	ShowCur(false);
}

void SMainMenuMT(string key[], int nKey) {
	SetColor(WHITE);
    SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++) {
		taoBox(x_SMainMenusMT, y_SMainMenusMT[i], key[i],(int)key[i].length());
	}
	HighLight1(keySubMainMenuMT[0], 0, x_SMainMenusMT, y_SMainMenusMT, GREEN, BLACK);
	ShowCur(false);
}

void hieuUngSMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag) {
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1) {
		ShowCur(false);
		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << key[pos];
		gotoxy(xSubMenu - 1, ykey[(pos + nkey - 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(WHITE);
		cout << key[(pos + nkey - 1) % nkey];
	} else if (flag == 2) {
		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);
		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << key[pos];
		gotoxy(xSubMenu - 1, ykey[(pos + 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(WHITE);
		cout << key[(pos + 1) % nkey];
	}
}

int ChonSMenu(string key[], int xSubMenu, int ykey[], int nkey) {
	int currposSubMainMenu = 0;
	ShowCur(false);
	int kb_hit;
	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case KEY_UP:
					if (currposSubMainMenu > 0) {
						currposSubMainMenu = currposSubMainMenu - 1;
					} else {
						currposSubMainMenu = nkey - 1;
					}
					hieuUngSMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 2);
					break;
				case KEY_DOWN:
					if (currposSubMainMenu < nkey - 1) {
						currposSubMainMenu = currposSubMainMenu + 1;
					} else {
						currposSubMainMenu = 0;
					}
					hieuUngSMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 1);
					break;
				case ESC:
					return -1;
				case ENTER:
					return currposSubMainMenu;
			}
		}
	}
}

void MainMenu(string key[], int nKey) {
	SetColor(WHITE);
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++) {
		taoBox(xMainMenu, y_MainMenus[i], key[i],(int)key[i].length());
	}
}

void ManHinhChinh() {
	system("color 0");
	clrscr();
	SetColor(WHITE);
	ShowCur(false);
	SetBGColor(BLACK);
	setFontSize(16);
	MainMenu(keyMainMenu, 4);
	SetColor(WHITE);
	SetBGColor(BLACK);
	string text;
	int y = 0;
	fstream inFile("TV.txt", ios:: in );
	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, text);
			SetColor(11);
			Sleep(15);
			gotoxy(50, y++);
			cout << text << endl;
		}
	}
	else {
		cout << "ERROR! File QLTV not found!" << "\n";
	}
	SetColor(WHITE);
	SetBGColor(BLACK);
	return;
}

void show(ptrNode_DocGia &tree, ListDauSach &listDS)
{
    setWindowSize();
    int chon;
    int chonSub;
    int temp;
    // int indexDG = 0;

    temp = readDG(tree);
    if (temp > 0)
        cout << "Read file DG success!" << endl;

    // temp = readFile_DS(listDS);
    temp = DocFile_DS(listDS);
    if (temp > 0)
        cout << "Read file DS success!" << endl;
    system("pause");
    DocGia dg;
    DocGia *arr;
    clrscr();

    while (1)
    {
        ManHinhChinh();
        // chon = MenuDong(mainMenu);
        chon = ChonSMenu(keyMainMenu, xMainMenu, y_MainMenus, 4);
        switch (chon)
        {
        case 0:

            // create_Tree(tree);
            SMainMenuDG(keySubMainMenuDG, 4);
            // chonSub = SubMenuDong(subMenuDG, so_item_sub_dg);
            chonSub = ChonSMenu(keySubMainMenuDG, x_SMainMenusDG, y_SMainMenusDG, 3);
            switch (chonSub)
            {
            case 0:
                indexDG = 0;
                gotoxy(50, 20);
                Menu_DocGia(tree);
                system("pause");
                break;
            case 1:
                indexDG=0;
                arr = new DocGia[nNodeDocGia];
                treeToArr(tree, arr);
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

            case 2:
                indexDG = 0;
                arr = new DocGia[nNodeDocGia];
                treeToArr(tree, arr);
                for (int i = 0; i < nNodeDocGia; i++)
                {
                    cout << arr[i].maThe << " ";
                    cout << arr[i].ho << " ";
                    cout << arr[i].ten << " ";
                }
                system("pause");
                delete[] arr;
                break;
            case 3:
                do_QuaHan(tree, listDS);
                system("pause");
                break;

            case so_item_sub_dg:
                break;
            }
            break;
        case 1:
            // create_Tree(tree);
            // chonSub = SubMenuDong(subMenuMT, so_item_sub_mt);
            SMainMenuDS(keySubMainMenuDS, 3);
            chonSub = ChonSMenu(keySubMainMenuDS, x_SMainMenusDS, y_SMainMenusDS, 3);
            switch (chonSub)
            {
            case 0:
                system("pause");
                break;
            case 1:
                system("pause");
                break;
            case 2:
                system("pause");
                break;
            case so_item_sub_mt:
                break;
            }
            break;
        case 2:
            SMainMenuMT(keySubMainMenuMT, 3);
            chonSub = ChonSMenu(keySubMainMenuMT, x_SMainMenusMT, y_SMainMenusMT, 3);
            switch (chonSub)
            {
            case 0:
                SetBGColor(BLACK);
                do_MuonSach(tree, listDS);
                system("pause");
                break;
            case 1:
                SetBGColor(BLACK);
                do_TraSach(tree, listDS);
                system("pause");
                break;
            case 2:
                cout << "Top 10 sach !";
                do_Top10(listDS);
                system("pause");
                break;
            case so_item_sub_mt:
                break;
            }
            system("pause");
            break;

        case so_item:


            boolean isSave = writeFile_DG(tree);
            gotoxy(10, 20);
            (isSave ? cout << "Da save DG!" : cout << "That bai");
            //boolean isSave1 = Save_DS(listDS);
            int isSave1 = GhiFile_DS(listDS);
            gotoxy(15, 20);
            (isSave1 ? cout << "Da save DG!" : cout << "That bai");
            break;
        }
        Sleep(500);
    }
}

int main()
{
    show(tree, listDS);
    return 0;
}
