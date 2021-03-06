#include "prototype.h"

#ifndef preInput
#define preInput

bool isNamNhuan(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int isNgayDung(DateTime d)
{
    if (d.ngay < 1 || d.ngay > 31)
        return 0;
    if (d.thang < 1 || d.thang > 12)
        return 1;
    if (d.nam < 2000 || d.nam > 2100)
        return 2;
    if ((d.thang == 4 || d.thang == 6 || d.thang == 9 || d.thang == 11) && (d.ngay > 30))
    {
        return 0;
    }
    if (d.thang == 2)
    {
        if (isNamNhuan(d.nam))
        {
            if (d.ngay > 29)
                return 0;
        }
        else
        {
            if (d.ngay > 28)
            {
                return 0;
            }
        }
    }
    return 3;
}

int tinhNgay(DateTime dt)
{
    if (dt.thang < 3)
    {
        dt.nam--;
        dt.thang += 12;
    }
    // 0001-01-01
    //306 ngay tu 01-03
    // return 365 * dt.nam + dt.nam / 4 - dt.nam / 100 + dt.nam / 400 + (153 * dt.thang - 457) / 5 + dt.ngay - 306; 
    return (dt.nam-1900)*(365+1/4-1/100+1/400) + (dt.thang-1)*30.6 + (dt.ngay-1);
}

void layNgayGioHT(DateTime &d)
{
    tm today;
    time_t ltime;
    time(&ltime);
    today = *(localtime(&ltime));
    //localtime_s(&today, &ltime);
    d.ngay = today.tm_mday;
    d.thang = today.tm_mon + 1;
    d.nam = today.tm_year + 1900;
}

int khoangCachNgay(DateTime nt1)
{
    DateTime nt2;
    layNgayGioHT(nt2);
    return (tinhNgay(nt2) - tinhNgay(nt1));
}

int soSanhNgay(DateTime nt1, DateTime nt2) {
	return (tinhNgay(nt2) - tinhNgay(nt1));
}

int quaHan(ptrNode_MuonTra lMT) {
	int soNgay = 0;
	int nngay;
	for (ptrNode_MuonTra p = lMT; p != NULL; p = p->next) {
		if ((p->muonTra.trangThai == 0) || (p->muonTra.trangThai == 2)) {
			nngay = khoangCachNgay(p->muonTra.ngayMuon);
			if (nngay > soNgay) {
				soNgay = nngay;
			}
		}
	}
	return soNgay;
}

int soNgayQuaHan(ptrNode_MuonTra lMT) {
	return (quaHan(lMT) - 7);
}

#endif