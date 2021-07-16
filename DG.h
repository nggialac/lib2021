#include "prototype.h"

#ifndef TDG
#define TDG

void initialize_NodeDG(ptrNode_DocGia &root)
{
    root = NULL;
}

void insert_NodeDG(ptrNode_DocGia &p, int x, DocGia dg)
{
    if (p == NULL) // p = nut la
    {
        p = new NodeDocGia;
        p->key = x;
        p->info = dg;
        p->left = NULL;
        p->right = NULL;
    }
    else
    {
        if (x < p->key)
            insert_NodeDG(p->left, x, dg);
        else if (x > p->key)
            insert_NodeDG(p->right, x, dg);
    }
}

//Traverse
int preorder_NodeDG(ptrNode_DocGia p)
{
    int count = 0;
    if (p != NULL)
    {
        count++;
        cout << p->key << endl; //Xu ly nut p
        cout << p->info.ho << endl;
        cout << p->info.maThe << endl;
        cout << p->info.ten << endl;
        cout << p->info.phai << endl;
        cout << p->info.trangThai << endl;
        cout << p->info.ptrMuonTra << endl;
        // cout << p->info.ptrMuonTra->maSach << endl;
        // cout << p->info.ptrMuonTra->ngayMuon.ngay << endl;
        // cout << p->info.ptrMuonTra->ngayTra.ngay << endl;
        // cout << p->info.ptrMuonTra->trangThai << endl;
        preorder_NodeDG(p->left);
        preorder_NodeDG(p->right);
    }
    return count;
}

ptrNode_DocGia search_NodeDG(ptrNode_DocGia root, int xKey)
{
    ptrNode_DocGia p = root;
    while (p != NULL && p->key != xKey)
    {
        if (xKey < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

void create_Tree(ptrNode_DocGia &root)
{
    int key;
    DocGia info;
    int count = 0;
    do
    {
        cout << "Nhap key: " << endl;
        cin >> key;
        if (key != 0)
        {
            cout << "Nhap doc gia thu " << count << " :"
                 << endl;
            cout << "Nhap ma the: " << endl; //tu sinh
            cin >> info.maThe;
            cin.ignore();
            cout << "Nhap ho: " << endl;
            cin.getline(info.ho, 50);
            cout << "Nhap ten: " << endl;
            cin >> info.ten;
            cin.ignore();
            cout << "Nhap phai: " << endl;
            cin >> info.phai;
            cin.ignore();
            cout << "Nhap trang thai: " << endl;
            cin >> info.trangThai;
            cin.ignore();
            insert_NodeDG(root, key, info);
            count++;
        }
    } while (key != 0);
}

void remove2Child_NodeDG(ptrNode_DocGia &p)
{
    if (p->left != NULL)
        remove2Child_NodeDG(p->left); //nut cuc trai cua cay con ben phai (nut goc rp)
    else
    {
        rp->key = p->key;
        rp->info = p->info;
        rp = p;
        p = rp->right;
    }
}

int remove_NodeDG(ptrNode_DocGia &p, int xKey)
{
    if (p == NULL)
        return 0;
    else
    {
        if (xKey < p->key)
            remove_NodeDG(p->left, xKey);
        else if (xKey > p->key)
            remove_NodeDG(p->right, xKey);
        else
        { //xKey = p->key
            rp = p;
            if (rp->right == NULL)
                p = rp->left; //p = nut la or chi co nut left
            else if (rp->left == NULL)
                p = rp->right;
            else
                remove2Child_NodeDG(rp->right);
            delete rp;
        }
    }
    return 1;
}

void writeFile_NodeDG(ptrNode_DocGia &root, FILE *fout)
{
    if (root == NULL)
        return;
    //save file preorder
    else
    {
        writeFile_NodeDG(root->left, fout);
        fwrite(root, sizeof(NodeDocGia), 1, fout);
        // writeFile_NodeDG(root->right, fout);
    }
}

int writeFile_DG(ptrNode_DocGia &root, char *filePath)
{
    FILE *fout;
    if ((fout = fopen(filePath, "wb")) == NULL)
    {
        cout << "Cannot write file!" << endl;
        return 0;
    }
    writeFile_NodeDG(root, fout);
    fclose(fout);
    return 1;
}

void readFile_NodeDG(ptrNode_DocGia &root, FILE *fin)
{
    if (root == NULL)
    {
        root = new NodeDocGia;
        fread(root, sizeof(NodeDocGia), 1, fin);
        cout << root->info.ten << endl;
        //readFile_NodeDG(root->right, fin);
        readFile_NodeDG(root->left, fin);
    }
}

int readFile_DG(ptrNode_DocGia &root, char *filePath)
{
    FILE *fin;
    if ((fin = fopen(filePath, "r")) == NULL)
    {
        cout << "Cannot read file!" << endl;
        return 0;
    }
    else
        cout << "Reading..." << endl;
    readFile_NodeDG(root, fin);
    fclose(fin);
    return 1;
}

#endif