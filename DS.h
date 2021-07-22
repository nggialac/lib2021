#include "prototype.h"

pDauSach findDSByISBN(ListDauSach listDS, string isbn) {
	pDauSach temp = NULL;
	for (int i = 0; i <= listDS.n; i++) {
		temp = listDS.nodes[i];
		if (temp->isbn == isbn)
			return temp;
	}
	return NULL;
}

int Save_DS(ListDauSach listDS) {
	fstream outFile;
	outFile.open("DS.txt", ios::out);
	if (outFile.is_open()) {
		outFile << listDS.n + 1 << endl;
		for (int i = 0; i <= listDS.n; i++) {
			outFile << listDS.nodes[i] -> tenSach << endl;
			outFile << listDS.nodes[i] -> isbn << endl;
			outFile << listDS.nodes[i] -> tacGia << endl;
			outFile << listDS.nodes[i] -> theLoai << endl;
			outFile << listDS.nodes[i] -> soTrang << endl;
			outFile << listDS.nodes[i] -> namXuatBan << endl;
			outFile << listDS.nodes[i]->soLanMuon << endl;
			outFile << listDS.nodes[i]->ptrDMS.n << endl;
			for (ptrNode_DanhMucSach p = listDS.nodes[i]->ptrDMS.FirstNode_DanhMucSach; p != NULL; p = p -> next) {
				outFile << p -> danhMucSach.maSach << endl;
				outFile << p -> danhMucSach.trangThai << endl;
				outFile << p -> danhMucSach.viTri << endl;
			}
		}
	} else {
		cout << "ERROR! File DS not found!";
		return 0;
	}
	outFile.close();
	return 1;
}