#include "MT.h"

void initialize_NodeDG(ptrNode_DocGia &root)
{
    root = NULL;
    nNodeDocGia = 0;
}

ptrNode_DocGia getNode_DG(DocGia dg)
{
    ptrNode_DocGia p = new NodeDocGia;
    if (p == NULL)
    {
        return NULL;
    }
    dg.ptrMuonTra.head = dg.ptrMuonTra.tail = NULL;
    dg.ptrMuonTra.n = 0;

    p->info = dg;
    // p->info.ptrMuonTra.head = p->info.ptrMuonTra.tail = NULL;
    // p->info.ptrMuonTra.n=0;
    p->left = NULL;
    p->right = NULL;
    return (p);
}

void insert_NodeDG_Load(ptrNode_DocGia &p, DocGia dg)
{
    if (p == NULL) // p = nut la
    {
        p = getNode_DG(dg);
        ++nNodeDocGia;
        cout << "Da them!";
    }
    else
    {
        if (dg.maThe < p->info.maThe)
            insert_NodeDG_Load(p->left, dg);
        else if (dg.maThe > p->info.maThe)
            insert_NodeDG_Load(p->right, dg);
    }
}

//Traverse
int preorder_NodeDG_NLR(ptrNode_DocGia p)
{
    int count = 0;
    if (p == NULL)
        return 0;
    else
    {
        count++;
        cout << p->info.maThe << " ";
        preorder_NodeDG_NLR(p->left);
        preorder_NodeDG_NLR(p->right);
    }
    return count;
}

int demDocGia(ptrNode_DocGia p)
{
    int count = 1;
    if (p == NULL)
        return 0;
    else
    {
        // count++;
        cout << p->info.maThe << " ";
        count += preorder_NodeDG_NLR(p->left);
        count += preorder_NodeDG_NLR(p->right);
        return count;
    }
    // return count;
}

bool check_MADG(ptrNode_DocGia t, int MADG)
{
    if (t == NULL)
    {
        return false;
    }
    else if (t->info.maThe == MADG)
    {
        return true;
    }
    else if (MADG < t->info.maThe)
    {
        return check_MADG(t->left, MADG);
    }
    else
    {
        return check_MADG(t->right, MADG);
    }
}

bool checkMaThe(ptrNode_DocGia p, int mt)
{
    while (p != NULL && p->info.maThe != mt)
    {
        if (mt < p->info.maThe)
            p = p->left;
        else
            p = p->right;
    }
    if (p == NULL)
        return false;
    return true;
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
            cout << "Ma the: "; //tu sinh
            info.maThe = randomMaThe(root);
            cout << info.maThe;
            // cin >> info.maThe;
            // cin.ignore();
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
            insert_NodeDG_Load(root, info);
            count++;
        }
    } while (key != 0);
}

void remove2Child_NodeDG(ptrNode_DocGia &rp, ptrNode_DocGia &p)
{
    if (p->left != NULL)
        remove2Child_NodeDG(rp, p->left); //nut cuc trai cua cay con ben phai (nut goc rp)
    else
    {
        // rp->key = p->key;
        rp->info = p->info; //sao chep data sang rp
        rp = p;
        p = p->right;
    }
}

int remove_NodeDG(ptrNode_DocGia &p, DocGia dg)
{
    if (p == NULL)
        return 0;
    else
    {
        if (dg.maThe < p->info.maThe)
            remove_NodeDG(p->left, dg);
        else if (dg.maThe > p->info.maThe)
            remove_NodeDG(p->right, dg);
        else
        { //dg.maThe = p->key
            ptrNode_DocGia rp = p;

            if (p->right == NULL)
                p = p->left; //p = nut la or chi co nut left
            else if (p->left == NULL)
                p = p->right; //p = nut la or chi co nut right
            else
                remove2Child_NodeDG(rp, p->right);
            delete rp;
            nNodeDocGia--;
            return 1;
        }
        return 1;
    }
}

void saveDG(ptrNode_DocGia &root, fstream &fout)
{
    fout << root->info.maThe << "|";
    fout << root->info.ho << "|";
    fout << root->info.ten << "|";
    fout << root->info.phai << "|";
    fout << root->info.trangThai << "|";
    fout << "\n";
    fout << soSachDangMuon(root->info.ptrMuonTra) << endl;
    for (ptrNode_MuonTra p = root->info.ptrMuonTra.head; p != NULL; p = p->next)
    {
        fout << "\n";
        fout << p->muonTra.maSach << "|";
        fout << p->muonTra.ngayMuon.ngay << "|";
        fout << p->muonTra.ngayMuon.thang << "|";
        fout << p->muonTra.ngayMuon.nam << "|";
        fout << p->muonTra.ngayTra.ngay << "|";
        fout << p->muonTra.ngayTra.thang << "|";
        fout << p->muonTra.ngayTra.nam << "|";
        fout << p->muonTra.trangThai << "|";
        fout << p->muonTra.isbn << "|";
        fout << '\n';
    }
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

int writeFile_DG(ptrNode_DocGia &root)
{
    fstream fileOut;
    fileOut.open("DG.txt", ios::out);
    if (fileOut.is_open())
    {
        fileOut << nNodeDocGia << endl;
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

ptrNode_DocGia layDG_NTDG(ptrNode_DocGia root, int MADG)
{
    ptrNode_DocGia t;
    t = root;
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

int readDG(ptrNode_DocGia &root)
{
    initialize_NodeDG(root);
    fstream fileIn;
    // ifstream fileIn(filePath);
    ptrNode_DocGia pNDG = NULL;
    DocGia dg;
    int countDG;
    MuonTra mt;
    int countMT;
    fileIn.open("DG.txt", ios::in);
    if (fileIn.is_open())
    {
        fileIn >> countDG;
        // nNodeDocGia=countDG;
        cout << countDG << endl;
        string temp;
        getline(fileIn, temp);
        string arr[10];
        int soSach;
        for (int i = 0; i < countDG;)
        {
            getline(fileIn, temp);
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

            cout << "\nMa the: ";
            cout << dg.maThe;

            insert_NodeDG_Load(root, dg);
            pNDG = layDG_NTDG(root, dg.maThe);
            // if(pNDG->info.ptrMuonTra.head->muonTra.isbn) cout<<"Head NULL";

            //Ma doc gia
            fileIn >> soSach;
            cout << "\nSo sach: ";
            cout << soSach << endl;
            //
            getline(fileIn, temp);
            if (soSach == 0)
                dg.ptrMuonTra.head = dg.ptrMuonTra.tail = NULL;
            else
                for (int i = 0; i < soSach; i++)
                {
                    getline(fileIn, temp);
                    cout << temp;
                    stringstream ssin(temp);
                    int j1 = 0;
                    while (ssin.good() && j1 < 9)
                    {
                        getline(ssin, arr[j1], '|');
                        // ssin >> arr[j];
                        ++j1;
                    }
                    mt.maSach = arr[0];
                    mt.ngayMuon.ngay = atoi(arr[1].c_str());
                    mt.ngayMuon.thang = atoi(arr[2].c_str());
                    mt.ngayMuon.nam = atoi(arr[3].c_str());
                    mt.ngayTra.ngay = atoi(arr[4].c_str());
                    mt.ngayTra.thang = atoi(arr[5].c_str());
                    mt.ngayTra.nam = atoi(arr[6].c_str());
                    mt.trangThai = atoi(arr[7].c_str());
                    mt.isbn = arr[8];
                    themDauList_MT(pNDG->info.ptrMuonTra, mt);
                }
            //insert_NodeDG_Load(root, dg);
            i++;
        }
    }
    else
    {
        cout << "File DG.txt not found!";
        return 0;
    }

    preorder_NodeDG_NLR(root);
    cout << "\nN Node Doc Gia" << endl;
    cout << nNodeDocGia << endl;
    fileIn.close();
    return 1;
}

int checkSortHoTen(DocGia dg1, DocGia dg2)
{
    int compareResult = dg1.ten.compare(dg2.ten);
    if (compareResult == 0)
    {
        compareResult = dg1.ho.compare(dg2.ho);
    }
    return compareResult;
}

void sort_DG(DocGia *arr, int low, int high)
{
    DocGia temp;
    DocGia pivot = arr[(low + high) / 2]; // pivot
    int left = low;
    int right = high;
    do
    {
        while (checkSortHoTen(arr[left], pivot) < 0)
            left++;
        while (checkSortHoTen(arr[right], pivot) > 0)
            right--;

        if (left <= right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);
    if (low < right)
        sort_DG(arr, low, right); // phan thu 1 co tu 2 ptu tro len
    if (left < high)
        sort_DG(arr, left, high); // phan thu 3 co tu 2 ptu tro len
}

ptrNode_DocGia sortedArrayToBST(DocGia arr[],
                                int start, int end)
{
    /* Base Case */
    if (start > end)
        return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end) / 2;
    ptrNode_DocGia root = getNode_DG(arr[mid]);

    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,
                                  mid - 1);

    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void treeToArr(ptrNode_DocGia p, DocGia *arr)
{
    // static int index = 0;
    if (p == NULL)
        return;

    treeToArr(p->left, arr);
    arr[indexDG++] = p->info;
    treeToArr(p->right, arr);
}

int taoRandom()
{
    int x;
    srand((int)time(0));
    x = (rand() % MAX_RAND) + 1;
    return x;
}

int randomMaThe(ptrNode_DocGia t)
{
    int temp;
    do
    {
        temp = taoRandom();
    } while (check_MADG(t, temp));
    return temp;
}

ptrNode_DocGia Rotate_Left(ptrNode_DocGia root)
{
    ptrNode_DocGia p;
    if (root == NULL)
        printf("Khong the xoay trai vi cay bi rong.");
    else if (root->right == NULL)
        printf("Khong the xoay trai vi khong co nut con ben phai.");
    else
    {
        p = root->right;
        root->right = p->left;
        p->left = root;
    }
    return p;
}

ptrNode_DocGia Rotate_Right(ptrNode_DocGia ya)
{
    ptrNode_DocGia s;
    if (ya == NULL)
        printf("Khong the xoay phai vi cay bi rong.");
    else if (ya->left == NULL)
        printf("Khong the xoay phai vi khong co nut con ben trai.");
    else
    {
        s = ya->left;
        ya->left = s->right;
        s->right = ya;
    }
    return s;
}

void Insert(ptrNode_DocGia &pavltree, int x, DocGia a)
{
    ptrNode_DocGia fp, p, q, // fp là nút cha của p, q là con của p
        fya, ya,             /* ya là nút trước gần nhất có thể mất cân bằng
                           	   fya là nút cha của ya */
        s;                   // s là nút con của ya theo hướng mất cân bằng
    int imbal;               /* imbal =  1 nếu bị lệch về nhánh trái
                                 	   	  = -1 nếu bị lệch về nhánh phải */
    // Khởi động các giá trị
    fp = NULL;
    p = pavltree;
    fya = NULL;
    ya = p;
    // tim nut fp, ya va fya, nut moi them vao la nut la con cua nut fp
    while (p != NULL)
    {
        if (x == p->key) // bi trung khoa
            return;
        if (x < p->key)
            q = p->left;
        else
            q = p->right;
        if (q != NULL)
            if (q->bf != 0) // truong hop chi so can bang cua q la 1 hay -1
            {
                fya = p;
                ya = q;
            }
        fp = p;
        p = q;
    }
    // Thêm nút mới (nut la) la con cua nut fp
    q = new NodeDocGia; // cấp phát vùng nhớ
    q->key = x;
    q->info = a;
    q->bf = 0;
    q->left = NULL;
    q->right = NULL;
    if (x < fp->key)
        fp->left = q;
    else
        fp->right = q;
    /*Hieu chinh chi so can bang cua tat ca cac nut giua ya va q, neu bi lech
      ve phia trai thi chi so can bang cua tat ca cac nut giua ya va q deu la
      1, neu bi lech ve phia phai thi chi so can bang cua tat ca cac nut giua
      ya va q deu la -1 */
    if (x < ya->key)
        p = ya->left;
    else
        p = ya->right;
    s = p; // s la con nut ya
    while (p != q)
    {
        if (x < p->key)
        {
            p->bf = 1;
            p = p->left;
        }
        else
        {
            p->bf = -1;
            p = p->right;
        }
    }
    // xac dinh huong lech
    if (x < ya->key)
        imbal = 1;
    else
        imbal = -1;

    if (ya->bf == 0)
    {
        ya->bf = imbal;
        return;
    }
    if (ya->bf != imbal)
    {
        ya->bf = 0;
        return;
    }

    if (s->bf == imbal) // Truong hop xoay don
    {
        if (imbal == 1) // xoay phai
            p = Rotate_Right(ya);
        else // xoay trai
            p = Rotate_Left(ya);
        ya->bf = 0;
        s->bf = 0;
    }
    else // Truong hop xoay kep
    {
        if (imbal == 1) // xoay kep trai-phai
        {
            ya->left = Rotate_Left(s);
            p = Rotate_Right(ya);
        }
        else // xoay kep phai-trai -
        {
            ya->right = Rotate_Right(s);
            p = Rotate_Left(ya);
        }
        if (p->bf == 0) // truong hop p la nut moi them vao
        {
            ya->bf = 0;
            s->bf = 0;
        }
        else if (p->bf == imbal)
        {
            ya->bf = -imbal;
            s->bf = 0;
        }
        else
        {
            ya->bf = 0;
            s->bf = imbal;
        }
        p->bf = 0;
    }
    if (fya == NULL)
        pavltree = p;
    else if (ya == fya->right)
        fya->right = p;
    else
        fya->left = p;
}
