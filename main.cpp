#include "draw.h"

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

    temp = readFile_DS(listDS);
    if (temp > 0)
        cout << "Read file DS success!" << endl;
    system("pause");
    DocGia dg;
    clrscr();

    while (1)
    {
        chon = MenuDong(mainMenu);
        switch (chon)
        {
        case 1:

            // create_Tree(tree);
            chonSub = SubMenuDong(subMenuDG, so_item_sub_dg);
            switch (chonSub)
            {
            case 1:
                indexDG = 0;
                gotoxy(50, 20);
                Menu_DocGia(tree);
                system("pause");
                break;
            case 2:
                gotoxy(50, 20);
                cout << "Vua chon: " << chonSub;

                cout << "Vua chon chuc nang " << chon;

                DocGia *arr;

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

            case 3:
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
            case 4:
                system("pause");
                break;

            case so_item_sub_dg:
                break;
            }
            break;
        case 2:
            // create_Tree(tree);
            chonSub = SubMenuDong(subMenuMT, so_item_sub_mt);
            switch (chonSub)
            {
            case 1:
                SetBGColor(BLACK);
                do_MuonSach(tree, listDS, indexDG);
                system("pause");
                break;
            case 2:
                SetBGColor(BLACK);
                do_TraSach(tree, listDS, indexDG);
                system("pause");
                break;
            case 3:
                cout << "Danh sach muon qua han !";
                system("pause");
                break;
            case 4:
                cout << "Top 10 sach !";
                system("pause");
                break;
            case so_item_sub_mt:
                break;
            }
            break;
        case 3:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
            system("pause");
            break;

        case so_item:
            boolean isSave = writeFile_DG(tree);
            gotoxy(10, 20);
            (isSave ? cout << "Da save DG!" : cout << "That bai");
            boolean isSave1 = Save_DS(listDS);
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
