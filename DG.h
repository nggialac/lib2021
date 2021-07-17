#include "prototype.h"

#ifndef TDG
#define TDG

void initialize_NodeDG(ptrNode_DocGia &root)
{
    root = NULL;
    // nNDG = 0;
}

ptrNode_DocGia getNode_DG(DocGia dg)
{
    ptrNode_DocGia p = new NodeDocGia;
    if (p == NULL)
    {
        return NULL;
    }
    // khoi tao DMS
    // taoListMT(p->listMT);
    p->info = dg;
    p->left = p->right = NULL;
    return (p);
}

void insert_NodeDG(ptrNode_DocGia &p, DocGia dg, int x)
{
    if (p == NULL) // p = nut la
    {
        p = getNode_DG(dg);
        ++nNodeDocGia;
    }
    else
    {
        if (x < p->info.maThe)
        insert_NodeDG(p->left, dg);
        else if (x > p->info.maThe)
        insert_NodeDG(p->right, dg);
    }
}

void insert_NodeDG_Load(ptrNode_DocGia &p, DocGia dg)
{
    if (p == NULL) // p = nut la
    {
        // p = new NodeDocGia;
        // p->key = x;
        // p->info = dg;
        // p->left = NULL;
        // p->right = NULL;
        p = getNode_DG(dg);
        ++nNodeDocGia;
    }
    else
    {
        // if (x < p->key)
        insert_NodeDG(p->left, dg);
        // else if (x > p->key)
        insert_NodeDG(p->right, dg);
    }
}

//Traverse
int preorder_NodeDG(ptrNode_DocGia p)
{
    int count = 1;
    if (p == NULL)
        return 0;
    else
    {
        // cout << p->key << endl; //Xu ly nut p
        // cout << p->info.ho << endl;
        // cout << p->info.maThe << endl;
        // cout << p->info.ten << endl;
        // cout << p->info.phai << endl;
        // cout << p->info.trangThai << endl;
        // cout << p->info.ptrMuonTra << endl;
        // cout << p->info.ptrMuonTra->maSach << endl;
        // cout << p->info.ptrMuonTra->ngayMuon.ngay << endl;
        // cout << p->info.ptrMuonTra->ngayTra.ngay << endl;
        // cout << p->info.ptrMuonTra->trangThai << endl;
        count += preorder_NodeDG(p->left);
        count += preorder_NodeDG(p->right);
        return count;
    }
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
            cout << "STT: " << count << " :"
                 << endl;
            cout << "Nhap ma the: " << endl; //tu sinh
            cin >> info.maThe;
            cin.ignore();
            cout << "Nhap ho: " << endl;
            cin >> info.ho;
            cout << "Nhap ten: " << endl;
            cin >> info.ten;
            cin.ignore();
            cout << "Nhap phai: " << endl;
            cin >> info.phai;
            cin.ignore();
            cout << "Nhap trang thai: " << endl;
            cin >> info.trangThai;
            cin.ignore();
            insert_NodeDG(root, info);
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

void saveDG(ptrNode_DocGia &root, fstream &fout)
{
    fout << root->info.maThe << "|";
    fout << root->info.ho << "|";
    fout << root->info.ten << "|";
    fout << root->info.phai << "|";
    fout << root->info.trangThai << "|";
    fout << '\n';
    // fout << '\n';
    // fout << root->listMT.n << endl;
    // 	for (NodeMT* p = t->listMT.headLMT ; p != NULL; p = p->rightNMT ) {
    // 	file << p->info.maSach << endl;

    // 	file << p->info.ngayMuon.ngay << endl;
    // 	file << p->info.ngayMuon.thang << endl;
    // 	file << p->info.ngayMuon.nam << endl;

    // 	file << p->info.ngayTra.ngay << endl;
    // 	file << p->info.ngayTra.thang << endl;
    // 	file << p->info.ngayTra.nam << endl;

    // 	file << p->info.tenSach << endl;
    // 	file << p->info.trangThai << endl;
    // 	file << p->info.viTriSach << endl;
    // }
}

void writeFile_NodeDG(ptrNode_DocGia &root, fstream &fout)
{
    if (root == NULL)
        return;
    else
    {
        saveDG(root, fout);
        writeFile_NodeDG(root->left, fout);
        writeFile_NodeDG(root->right, fout);
    }
}

int writeFile_DG(ptrNode_DocGia &root, char *filePath)
{
    fstream fileOut;
    fileOut.open("DG.txt", ios::out);
    if (fileOut.is_open())
    {
        fileOut << preorder_NodeDG(root) << endl;
        // fileOut << "||";
        writeFile_NodeDG(root, fileOut);
    }
    else
    {
        cout << " DG.txt not found! ";
        return 0;
    }
    fileOut.close();
    return 1;
}

NodeDocGia *layDG_NTDG(ptrNode_DocGia t, int MADG)
{
    while (t != NULL && t->info.maThe != MADG)
    {
        if (MADG < t->info.maThe)
        {
            t = t->left;
        }
        else
            t = t->right;
    }
    return (t);
}

int readDG(ptrNode_DocGia &root, char *filePath)
{
    initialize_NodeDG(root);
    fstream fileIn;
    // ifstream fileIn(filePath);
    NodeDocGia *pNDG = NULL;
    DocGia dg;
    int countDG;
    // MuonTra mt;
    int countMT;
    fileIn.open(filePath, ios::in);
    if (fileIn.is_open())
    {
        fileIn >> countDG;
        cout << countDG << endl;
        string temp;
        getline(fileIn, temp);
        string arr[5];
        for (int i = 0; i < countDG;)
        {
            getline(fileIn, temp);
            cout << "temp: " + temp << endl;
            int j = 0;

            stringstream ssin(temp);
            while (ssin.good() && j < 5)
            {
                getline(ssin, arr[j], '|');
                // ssin >> arr[j];
                ++j;
            }
            dg.maThe = atoi(arr[0].c_str());
            dg.ho = arr[1];
            dg.ten = arr[2];
            dg.phai = atoi(arr[3].c_str());
            dg.trangThai = atoi(arr[4].c_str());
            insert_NodeDG_Load(root, dg);
            pNDG = layDG_NTDG(root, dg.maThe);
            i++;
        }
    }
    else
    {
        cout << "File DG.txt not found!";
        return 0;
    }
    fileIn.close();
    return 1;
}

void readFile_NodeDG(ptrNode_DocGia &root, FILE *fin)
{
    if (root == NULL)
    {
        root = new NodeDocGia;
        readFile_NodeDG(root->right, fin);
        fread(root, sizeof(NodeDocGia), 1, fin);
        cout << root->info.ten << endl;
        // readFile_NodeDG(root->right, fin);
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
    preorder_NodeDG(root);
    fclose(fin);
    return 1;
}


// DAU SACH

#endif