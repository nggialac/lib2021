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
