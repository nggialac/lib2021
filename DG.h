#include "MT.h"

void initialize_NodeDG(ptrNode_DocGia &root)
{
    root = NULL;
}

ptrNode_DocGia getNode_DG(DocGia dg)
{
    ptrNode_DocGia p = new NodeDocGia;
    if (p == NULL)
    {
        return NULL;
    }
    // dg.ptrMuonTra.head = dg.ptrMuonTra.tail = NULL;
    // dg.ptrMuonTra.n = 0;

    p->info = dg;
    p->info.ptrMuonTraFirst = NULL;
    p->left = NULL;
    p->right = NULL;
    return (p);
}

void insert_NodeDG_Load(ptrNode_DocGia &p, DocGia dg)
{
    if (p == NULL) // p = nut la
    {
        p = getNode_DG(dg);
        // ++nNodeDocGia;
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
        cout << " " << p->info.maThe;
        preorder_NodeDG_NLR(p->left);
        preorder_NodeDG_NLR(p->right);
    }
    return 1;
}

int demDocGia(ptrNode_DocGia p)
{
    int count = 1;
    if (p == NULL)
        return 0;
    else
    {
        // count++;
        count += demDocGia(p->left);
        count += demDocGia(p->right);
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
            // nNodeDocGia--;
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
    // fout << soSachDangMuon(root->info.ptrMuonTra) << endl;

    int n = 0;
    ptrNode_MuonTra p = root->info.ptrMuonTraFirst;
    for(p;p!=NULL;p=p->next)
    	n++;
    // fout << root->info.ptrMuonTra.n << endl;
    fout<<n<<endl;
    for (ptrNode_MuonTra p = root->info.ptrMuonTraFirst; p != NULL; p = p->next)
    {
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
        fileOut << demDocGia(root) << endl;
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
        // cout << countDG << endl;
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

            // cout << "\nMa the: ";
            // cout << dg.maThe;

            // insert_NodeDG_Load(root, dg);
            root = insert(root, dg);
            pNDG = layDG_NTDG(root, dg.maThe);
            // if(pNDG->info.ptrMuonTra.head->muonTra.isbn) cout<<"Head NULL";

            //Ma doc gia
            fileIn >> soSach;
            // cout << "\nSo sach: ";
            // cout << soSach << endl;
            //
            getline(fileIn, temp);
            if (soSach == 0)
                dg.ptrMuonTraFirst = NULL;
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
                    themDauList_MT(pNDG->info.ptrMuonTraFirst, mt);
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
    // cout << "\nN Node Doc Gia" << endl;
    // cout << nNodeDocGia << endl;
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

void sort_QH(DocGia *arr, int low, int high)
{
    DocGia temp;
    DocGia pivot = arr[(low + high) / 2]; // pivot
    int left = low;
    int right = high;
    do
    {
        while (soNgayQuaHan(arr[left].ptrMuonTraFirst) < 0)
            left++;
        while (soNgayQuaHan(arr[right].ptrMuonTraFirst) > 0)
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

int treeToArr(ptrNode_DocGia p, DocGia *arr, int indexDG)
{
    // static int index = 0;
    if (p == NULL)
        return indexDG;

    // treeToArr(p->left, arr, indexDG);

    // treeToArr(p->right, arr, indexDG);
    if (p->left != NULL)
        indexDG = treeToArr(p->left, arr, indexDG);
    arr[indexDG++] = p->info;
    if (p->right != NULL)
        indexDG = treeToArr(p->right, arr, indexDG);
    return indexDG;
}

int taoRandom()
{
    int x;
    srand((int)time(0));
    int loop = 100;
    while (loop > 0)
    {
        x = (rand() % 500) + 1;
        loop--;
    }

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

int height(ptrNode_DocGia p)
{
    if (p == NULL)
        return 0;
    return p->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Get Balance factor of node N
int getBalance(ptrNode_DocGia p)
{
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
ptrNode_DocGia rightRotate(ptrNode_DocGia y)
{
    ptrNode_DocGia x = y->left;
    ptrNode_DocGia T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
ptrNode_DocGia leftRotate(ptrNode_DocGia x)
{
    ptrNode_DocGia y = x->right;
    ptrNode_DocGia T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

ptrNode_DocGia newNode(DocGia dg)
{
    ptrNode_DocGia p = new NodeDocGia();
    if (p == NULL)
    {
        return NULL;
    }

    p->info = dg;
    p->info.ptrMuonTraFirst = NULL;
    // p->info.ptrMuonTra.tail = NULL;
    // p->info.ptrMuonTra.n = 0;
    p->left = NULL;
    p->right = NULL;

    p->height = 1; // new node is initially
                   // added at leaf
    return (p);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
ptrNode_DocGia insert(ptrNode_DocGia node, DocGia dg)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(dg));

    if (dg.maThe < node->info.maThe)
        node->left = insert(node->left, dg);
    else if (dg.maThe > node->info.maThe)
        node->right = insert(node->right, dg);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && dg.maThe < node->left->info.maThe)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && dg.maThe > node->right->info.maThe)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && dg.maThe > node->left->info.maThe)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && dg.maThe < node->right->info.maThe)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
ptrNode_DocGia minValueNode(ptrNode_DocGia node)
{
    ptrNode_DocGia current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

ptrNode_DocGia deleteNode(ptrNode_DocGia root, DocGia dg)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if (dg.maThe < root->info.maThe)
        root->left = deleteNode(root->left, dg);

    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if (dg.maThe > root->info.maThe)
        root->right = deleteNode(root->right, dg);

    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            ptrNode_DocGia temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            ptrNode_DocGia temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->info = temp->info;

            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->info);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}