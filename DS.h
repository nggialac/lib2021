#include "DMS.h"
// #include "mylib.h"
bool isDauSach_ISBN(ListDauSach listDS, string ISBN)
{
    for (int i = 0; i < listDS.n; i++)
    {
        if (listDS.nodes[i]->isbn == ISBN)
            return true;
    }
    return false;
}

pDauSach findDSByISBN(ListDauSach listDS, string isbn)
{
	pDauSach temp = NULL;
	for (int i = 0; i < listDS.n; i++)
	{
		temp = listDS.nodes[i];
		if (temp->isbn.compare(isbn))
			return temp;
	}
	return NULL;
}

int isFull_DS(ListDauSach listDS)
{
	return listDS.n == MAX_LIST;
}

int Empty(ListDauSach &ds)
{
	return ds.n == 0;
}



pDauSach layDauSach_Ten(ListDauSach listDS, string tenSach) {
	pDauSach temp = NULL;
	for (int i = 0; i <= listDS.n; i++) {
		temp = listDS.nodes[i];
		if (temp->tenSach.compare(tenSach) == 0)
			return temp;
	}
	return NULL;
}


int Insert_DS(ListDauSach &listDS, pDauSach &pDS)
{
	if (isFull_DS(listDS))
	{
		return 0;
	}
	for(int i=0;i<listDS.n;i++)
	    if(pDS->tenSach<=listDS.nodes[i]->tenSach)
	    {
	    	listDS.n++;
	    	for(int j=listDS.n-1;j>i;j--)
	    	{
	    		listDS.nodes[j]=listDS.nodes[j-1];
			}
			listDS.nodes[i] = pDS;
			return 1;
		}
	listDS.nodes[listDS.n++] = pDS;
    return 1;
}
int Delete_DS(ListDauSach &plist, int i)
{
	int j;
	if (i < 0 || i >= plist.n || plist.n == 0)
		return 0;
	for (j = i + 1; j < plist.n; j++)
		plist.nodes[j - 1] = plist.nodes[j];
	plist.n--;
	return 1;
}
int Search_isbn(ListDauSach &plist, string isbn)
{
	for (int i = 0; i < plist.n; i++)
		if (plist.nodes[i]->isbn == isbn)
			return i;
	return -1;
}
int DocFile_DS(ListDauSach &listDS)
{
	fstream file;
	DauSach info;
	file.open("DS.txt", ios::in);
	pDauSach pDS;
	DanhMucSach dms;
	int soDauSach, soSach;
	if (file.is_open())
	{
		file >> soDauSach;
		string temp;
		getline(file, temp);
		string arr[7];
		for (int i = 0; i < soDauSach; i++)
		{
			getline(file, temp);
			pDS = new DauSach;
			int j = 0;
			stringstream ssin(temp);
			for (int j = 0; ssin.good() && j < 7; j++)
				getline(ssin, arr[j], '|');
			info.isbn = arr[0];
			info.tenSach = arr[1];
			info.tacGia = arr[2];
			info.theLoai = arr[3];
			info.namXuatBan = atoi(arr[4].c_str());
			info.soTrang = atoi(arr[5].c_str());
			info.soLanMuon = atoi(arr[6].c_str());
			*(pDS) = info;		
			getline(ssin, temp, '|');
			soSach = atoi(temp.c_str());
			if (soSach > 0)
			{
				for (int j = 0; j < soSach; j++)
				{
					getline(file, temp);
					stringstream ss2(temp);
					getline(ss2, temp, '|');
					dms.maSach = temp;
					getline(ss2, temp, '|');
					dms.trangThai = atoi(temp.c_str());
					getline(ss2, temp, '|');
					dms.viTri = temp;
					insertFirst_DMS(pDS->First_DMS, dms);
				//	pDS->ptrDMS.n++;
				
				}
			}
			Insert_DS(listDS, pDS);
		}
	}
	else
	{
		cout << "file DS.txt khong tim thay! ";
		return 0;
	}
	file.close();
	return 1;
}
int GhiFile_DS(ListDauSach &listDS)
{
	fstream file;
	file.open("DS.txt", ios::out);
	if (file.is_open())
	{
		file << listDS.n << endl;
		for (int i = 0; i < listDS.n; i++)
		{
			file << listDS.nodes[i]->isbn << "|";
			file << listDS.nodes[i]->tenSach << "|";
			file << listDS.nodes[i]->tacGia << "|";
			file << listDS.nodes[i]->theLoai << "|";
			file << listDS.nodes[i]->namXuatBan << "|";
			file << listDS.nodes[i]->soTrang << "|";
			file << listDS.nodes[i]->soLanMuon << "|";
			int soSach=0;
    		ptrNode_DanhMucSach p;
    		for(p=listDS.nodes[i]->First_DMS;p!=NULL;p=p->next)
    			soSach++;
    		file<<soSach<<"|";
    		if(soSach>0)
    		{
    			p=listDS.nodes[i]->First_DMS;
    			for(p; p != NULL; p = p->next)
    			{
    				file<<endl;
    				file<<p->danhMucSach.maSach<<"|";
    				file<<p->danhMucSach.trangThai<<"|";
    				file<<p->danhMucSach.viTri<<"|";  			
				}
			}
			file << endl;
		}
	}
	else
	{
		cout << "file DS.txt khong tim thay! ";
		return 0;
	}
	file.close();
	return 1;
}
ListDauSach Top10_DS(ListDauSach listDS)
{
	ListDauSach A=listDS;
	DauSach t;
	int dem=0,max,i,j;	
	for(i=0;i<A.n-1;i++){
		max=i;
		for (j = i+1; j < A.n; j++)
        	if (A.nodes[j]->soLanMuon > A.nodes[max]->soLanMuon) max = j;        				      
        DauSach *t=A.nodes[i];
        A.nodes[i]=A.nodes[max];
        A.nodes[max]=t; 
		dem++;
		if(dem>10) break;		              
    }
    return A; 	
}
string DanhMaSach(pDauSach p)
{
	DanhMucSach dms;
	dms.maSach=p->isbn;
	if(p->First_DMS==NULL) dms.maSach+="0";
	else{
		string s=p->First_DMS->danhMucSach.maSach;
		string maSach=s.substr(6,s.length()-6);//3 ký tu cuoi
		int x=atoi(maSach.c_str())+1;// +1
		stringstream ss;
		ss<<x;
				
		dms.maSach+=ss.str();
	}
	return dms.maSach;			
}


