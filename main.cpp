#include "draw.h"

#define x_SMainMenusDS 3
#define x_SMainMenusDG 3
#define x_SMainMenusMT 3
#define x_MainMenu 3
// #define yMainMenu 12

// int x_MainMenus[5] = { 8,26,52, 81,105 };
int y_MainMenus[4] = {16, 19, 22, 25};
int y_SMainMenusDS[5] = {16, 19, 22, 25, 28};
int y_SMainMenusDG[5] = {16, 19, 22, 25, 28};
int y_SMainMenusMT[4] = {16, 19, 22, 25};

void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor)
{
    // den dia chi can highlight
    gotoxy(x - 1, y[index]);
    SetBGColor(newColor);
    SetColor(WHITE);
    cout << key;
    SetBGColor(oldColor);
}

void mainMenu(string key[], int nKey)
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    for (int i = 0; i < nKey; i++)
    {
        taoBox(x_MainMenu, y_MainMenus[i], key[i], (int)key[i].length());
    }
    HighLight1(keyMainMenu[0], 0, x_MainMenu, y_MainMenus, GREEN, BLACK);
    ShowCur(false);
}

void SMainMenuDG(string key[], int nKey)
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    for (int i = 0; i < nKey; i++)
    {
        taoBox(x_SMainMenusDG, y_SMainMenusDG[i], key[i], (int)key[i].length());
    }
    HighLight1(keySubMainMenuDG[0], 0, x_SMainMenusDG, y_SMainMenusDG, GREEN, BLACK);
    ShowCur(false);
}

void SMainMenuDS(string key[], int nKey)
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    for (int i = 0; i < nKey; i++)
    {
        taoBox(x_SMainMenusDS, y_SMainMenusDS[i], key[i], (int)key[i].length());
    }
    HighLight1(keySubMainMenuDS[0], 0, x_SMainMenusDS, y_SMainMenusDS, GREEN, BLACK);
    ShowCur(false);
}

void SMainMenuMT(string key[], int nKey)
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    for (int i = 0; i < nKey; i++)
    {
        taoBox(x_SMainMenusMT, y_SMainMenusMT[i], key[i], (int)key[i].length());
    }
    HighLight1(keySubMainMenuMT[0], 0, x_SMainMenusMT, y_SMainMenusMT, GREEN, BLACK);
    ShowCur(false);
}

void hieuUngSMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag)
{
    // 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
    if (flag == 1)
    {
        ShowCur(false);
        gotoxy(xSubMenu - 1, ykey[pos]);
        SetBGColor(GREEN);
        SetColor(WHITE);
        cout << key[pos];
        gotoxy(xSubMenu - 1, ykey[(pos + nkey - 1) % nkey]);
        SetBGColor(BLACK);
        SetColor(WHITE);
        cout << key[(pos + nkey - 1) % nkey];
    }
    else if (flag == 2)
    {
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

int ChonSMenu(string key[], int xSubMenu, int ykey[], int nkey)
{
    int currposSubMainMenu = 0;
    ShowCur(false);
    int kb_hit;
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
                if (currposSubMainMenu > 0)
                {
                    currposSubMainMenu = currposSubMainMenu - 1;
                }
                else
                {
                    currposSubMainMenu = nkey - 1;
                }
                hieuUngSMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 2);
                break;
            case KEY_DOWN:
                if (currposSubMainMenu < nkey - 1)
                {
                    currposSubMainMenu = currposSubMainMenu + 1;
                }
                else
                {
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

void MainMenu(string key[], int nKey)
{
    SetColor(WHITE);
    SetBGColor(BLACK);
    for (int i = 0; i < nKey; i++)
    {
        taoBox(x_MainMenu, y_MainMenus[i], key[i], (int)key[i].length());
    }
}

void ManHinhChinh()
{
    system("color 0");
    clrscr();
    SetColor(WHITE);
    ShowCur(false);
    SetBGColor(BLACK);
    // setFontSize(16);
    MainMenu(keyMainMenu, 4);
    SetColor(WHITE);
    SetBGColor(BLACK);

    gotoxy(10, 12);
    cout << "__MENU__";

    for (int doc = 10; doc < 33; doc++)
    {
        gotoxy(30, doc);
        cout << char(185);
    }
    for (int ngang = 0; ngang < 30; ngang++)
    {
        gotoxy(ngang, 10);
        cout << char(204);
        gotoxy(ngang, 18 + 14);
        cout << char(204);
    }

    string text;
    int y = 0;
    fstream inFile("TV.txt", ios::in);
    if (inFile.good())
    {
        while (!inFile.eof())
        {
            getline(inFile, text);
            SetColor(11);
            Sleep(10);
            gotoxy(50, y++);
            cout << text << endl;
        }
    }
    else
    {
        cout << "ERROR! File TV not found!"
             << "\n";
    }

    SetColor(WHITE);
    SetBGColor(BLACK);
    return;
}

void drawComputer(int x, int y, int color, int delay)
{
    ShowCur(false);
    SetColor(WHITE);
    SetBGColor(BLACK);
    string text;
    fstream inFile("computer.txt", ios::in);
    if (inFile.good())
    {
        while (!inFile.eof())
        {
            getline(inFile, text);
            SetColor(color);
            Sleep(delay);
            gotoxy(x, y++);
            cout << text << endl;
        }
    }
    else
    {
        cout << "ERROR! File computer.txt not found!"
             << "\n";
    }
    SetColor(WHITE);
    SetBGColor(BLACK);
    return;
}

void drawBG()
{
    int x = 55;
    int y = 10;
    int kb_hit;
    // while (1)
    // {
    //     if (!_kbhit())
    //     {
    srand(time(NULL));
    int res = rand() % (15 - 1 + 1) + 1;
    drawComputer(x, y, res, 30);
    Sleep(200);
    // for (int cot = 40; cot < 100; cot++)
    // {
    //     for (int dong = 10; dong < 30; dong++)
    //     {
    //         gotoxy(cot, dong);
    //         // cout << " ";
    //         cout << setw(10) << setfill(' ') << ' ';
    //     }
    // }
    //     }
    //     else
    //         return;
    // }
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

    DocFile_DS(listDS);
    // temp = DocFile_DS(listDS);
    if (temp > 0)
        cout << "Read file DS success!" << endl;
    // system("pause");
    DocGia dg;

    string mten;
    clrscr();

    while (1)
    {
        ManHinhChinh();
        while (1)
        {

            if (!_kbhit())
            {
                drawBG();
            }
            else
            {
                drawComputer(55, 10, WHITE, 0);
                break;
            }
        }
        // kbhit = _getch();

        // chon = MenuDong(mainMenu);
        // mainMenu(keyMainMenu, 4);
        _getch();
        HighLight1(keyMainMenu[0], 0, x_MainMenu, y_MainMenus, GREEN, BLACK);
        chon = ChonSMenu(keyMainMenu, x_MainMenu, y_MainMenus, 4);
        switch (chon)
        {
        case 0:
            // create_Tree(tree);
            SMainMenuDG(keySubMainMenuDG, 5);
            // chonSub = SubMenuDong(subMenuDG, so_item_sub_dg);
            chonSub = ChonSMenu(keySubMainMenuDG, x_SMainMenusDG, y_SMainMenusDG, 5);
            DocGia *arr;
            int indexDG;
            int nNodeDocGia;
            switch (chonSub)
            {
            case 0:
                gotoxy(50, 20);
                Menu_DocGia(tree);
                system("pause");
                break;
            case 1:
                clrscr();
                indexDG = 0;
                nNodeDocGia = demDocGia(tree);
                arr = new DocGia[nNodeDocGia];
                treeToArr(tree, arr, indexDG);
                sort_DG(arr, 0, nNodeDocGia - 1);
                ve_DG(keyDisplayDG, 5, x_DG);
                xuat_ListDG_1(tree, arr);
                system("pause");
                delete[] arr;
                break;

            case 2:
                clrscr();
                indexDG = 0;
                nNodeDocGia = demDocGia(tree);
                arr = new DocGia[nNodeDocGia];
                treeToArr(tree, arr, indexDG);
                // sort_DG(arr, 0, nNodeDocGia - 1);
                ve_DG(keyDisplayDG, 5, x_DG);
                xuat_ListDG_1(tree, arr);
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

            SMainMenuDS(keySubMainMenuDS, 5);
            chonSub = ChonSMenu(keySubMainMenuDS, x_SMainMenusDS, y_SMainMenusDS, 5);
            switch (chonSub)
            {
            case 0:
                // DanhSachDS(listDS);
                Menu_DauSach(listDS);
                SetBGColor(BLACK);
                break;
            case 1:
                Menu_DMS(listDS);
                // 
                SetBGColor(BLACK);
                break;
            case 2:
                xuat_ListDStheoTT(listDS);
                // ve_TheLoai(listDS);
                SetBGColor(BLACK);
                break;

            case 3:
                TimSach(listDS);
                SetBGColor(BLACK);
                break;
            case so_item_sub_mt:
                break;
            }
            break;
        case 2:
            SMainMenuMT(keySubMainMenuMT, 4);
            chonSub = ChonSMenu(keySubMainMenuMT, x_SMainMenusMT, y_SMainMenusMT, 4);
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
                ve_TopDS(listDS);
                system("pause");
                break;
            case so_item_sub_mt:
                break;
            }
            break;

        case so_item:
            boolean isSave = writeFile_DG(tree);
            // gotoxy(10, 20);
            // (isSave ? cout << "Da save DG!" : cout << "That bai");
            //boolean isSave1 = Save_DS(listDS);
            int isSave1 = GhiFile_DS(listDS);
            // gotoxy(15, 20);
            // (isSave1 ? cout << "Da save DG!" : cout << "That bai");
            return;
        }
        Sleep(500);
    }
}

int main()
{
    show(tree, listDS);
    return 0;
}
