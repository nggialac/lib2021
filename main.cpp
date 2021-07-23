#include "draw.h"

void show(ptrNode_DocGia &tree, ListDauSach &listDS)
{
    setWindowSize();
    int chon;
    int temp;
    DocGia dg;
    DocGia *arr;
    temp = readDG(tree);
    if (temp > 0)
        cout << "Read file DG success!" << endl;

    temp = readFile_DS(listDS);
    if (temp > 0)
        cout << "Read file DS success!" << endl;
    system("pause");

    while (1)
    {
        chon = MenuDong(mainMenu);
        switch (chon)
        {

        case 1:
            gotoxy(30, 20);
            cout << "Vua chon chuc nang " << chon;
            // int temp = 0;
            // create_Tree(tree);
            Menu_DocGia(tree);
            break;
        case 2:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
            SetBGColor(BLACK);
            do_MuonSach(tree, listDS);
            
            system("pause");
            break;
        case 3:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
            SetBGColor(BLACK);
            do_TraSach(tree, listDS);
            system("pause");
            break;

        case 4:
            gotoxy(10, 20);
            cout << "Vua chon chuc nang " << chon;
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
            // SetBGColor(BLACK);
            // do_MuonSach(tree, listDS);
            system("pause");
            break;

        case so_item:
        temp = writeFile_DG(tree);
        if(temp > 0) cout<<"Save DG thanh cong! \n";
        temp = Save_DS(listDS);
        if(temp > 0) cout<<"Save DS thanh cong! ";
        }
        Sleep(500);
    }
}

int main()
{
    show(tree, listDS);
    return 0;
}
