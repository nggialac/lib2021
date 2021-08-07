#include "DMS.h"


pDauSach findDSByISBN(ListDauSach listDS, string isbn)
{
	pDauSach temp = NULL;
	for (int i = 0; i <= listDS.n; i++)
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


// int Save_DS(ListDauSach listDS)
// {
// 	fstream outFile;
// 	outFile.open("DS.txt", ios::out);
// 	if (outFile.is_open())
// 	{
// 		outFile << listDS.n + 1 << endl;
// 		for (int i = 0; i <= listDS.n; i++)
// 		{
// 			outFile << listDS.nodes[i]->tenSach << endl;
// 			outFile << listDS.nodes[i]->isbn << endl;
// 			outFile << listDS.nodes[i]->tacGia << endl;
// 			outFile << listDS.nodes[i]->theLoai << endl;
// 			outFile << listDS.nodes[i]->soTrang << endl;
// 			outFile << listDS.nodes[i]->namXuatBan << endl;
// 			outFile << listDS.nodes[i]->soLanMuon << endl;
// 			outFile << listDS.nodes[i]->ptrDMS.n << endl;
// 			for (ptrNode_DanhMucSach p = listDS.nodes[i]->ptrDMS.FirstNode_DanhMucSach; p != NULL; p = p->next)
// 			{
// 				outFile << p->danhMucSach.maSach << endl;
// 				outFile << p->danhMucSach.trangThai << endl;
// 				outFile << p->danhMucSach.viTri << endl;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		cout << "ERROR! File DS not found!";
// 		return 0;
// 	}
// 	outFile.close();
// 	return 1;
// }


void DS_TheoTen(ListDauSach &listDS, string mten)
{
	for (int i = 0; i < listDS.n; i++)
	{
		if (strstr(listDS.nodes[i]->tenSach.c_str(), mten.c_str()) != NULL)
		{
			cout << listDS.nodes[i]->tenSach << endl;
			//vv
		}
	}
}


int Insert_DS(ListDauSach &listDS, pDauSach &pDS)
{
	if (isFull_DS(listDS))
	{
		return 0;
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
		//cout << soDauSach << endl;
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
			//			cout<<info.isbn<<"|";
			//			cout<<info.tenSach<<"|";
			//			cout<<info.tacGia<<"|";
			//			cout<<info.theLoai<<"|";
			//			cout<<info.namXuatBan<<"|";
			//			cout<<info.soTrang<<"|";
			//			cout<<info.soLanMuon<<"|";
			getline(ssin, temp, '|');
			soSach = atoi(temp.c_str());
			//			cout<<soSach<<"|"<<endl;
			initializeListNode_DMS(pDS->ptrDMS);
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
					//	            	cout<<dms.maSach<<"|";
					//	            	cout<<dms.trangThai<<"|";
					//	            	cout<<dms.viTri<<"|";
					//	            	cout<<endl;
					insertFirst_DMS(pDS->ptrDMS.FirstNode_DanhMucSach, dms);
					pDS->ptrDMS.n++;
					//                //themCuoiList_DMS(pDS->ptrListNode_DMS, dms);
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
			int soSach = listDS.nodes[i]->ptrDMS.n;
			file << soSach << "|";
			if (soSach > 0)
			{
				ptrNode_DanhMucSach p;
				p = listDS.nodes[i]->ptrDMS.FirstNode_DanhMucSach;
				for (p; p != NULL; p = p->next)
				{
					file << endl;
					file << p->danhMucSach.maSach << "|";
					file << p->danhMucSach.trangThai << "|";
					file << p->danhMucSach.viTri << "|";
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
	ListDauSach A = listDS;
	DauSach t;
	int B[10];
	int dem = 0, max, i, j;
	for (i = 0; i < A.n - 1; i++)
	{
		max = i;
		for (j = i + 1; j < A.n; j++)
			if (A.nodes[j]->soLanMuon > A.nodes[max]->soLanMuon)
				max = j;
		DauSach *t = A.nodes[i];
		A.nodes[i] = A.nodes[max];
		A.nodes[max] = t;
		dem++;
		if (dem > 10)
			break;
	}
	return A;
}

// void ve_MenuDS()
// {
// 	// ListDauSach listDS;
// 	// DocFile_DS(listDS);
// 	int chon;
// 	//chon = MenuDong(MenuDS);
// 	system("cls");
// 	do
// 	{
// 		chon = MenuDong(MenuDS);
// 		switch (chon)
// 		{
// 		case 1:
// 			DanhSachDS(listDS);
// 			break;
// 		case 2:
// 		{
// 			Normal();
// 			system("cls");
// 			cout << "SACH CAN TIM: ";
// 			string mten;
// 			cin >> mten;
// 			TimSach(listDS, mten);
// 		}

// 		break;
// 		case 3:
// 			ve_TheLoai(listDS);
// 			break;
// 		case 4:
// 			ve_TopDS(listDS);
// 			break;
// 		case 5:
// 			return;
// 		}
// 	} while (1);
// }