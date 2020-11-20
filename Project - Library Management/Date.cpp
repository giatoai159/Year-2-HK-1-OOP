#include "Date.h"

Date::Date()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	nam = now->tm_year + 1900;
	thang = now->tm_mon + 1;
	ngay = now->tm_mday;
}

Date::Date(int ngay, int thang, int nam)
{
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}

Date::~Date()
{
}

bool Date::KiemTraTinhHopLe()
{
	time_t t = time(0);
	struct tm *now = localtime(&t);
	//
	if (this->ngay < 0 || this->ngay > 31) return false;
	if (this->thang < 0 || this->thang > 12) return false;
	if (this->nam < 1900) return false;
	//
	if (this->nam < now->tm_year + 1900) return false;
	else if (this->nam == now->tm_year + 1900)
	{
		if (this->thang < now->tm_mon + 1) return false;
		else if (this->thang == now->tm_mon + 1)
		{
			if (this->ngay < now->tm_mday) return false;
		}
	}
	//
	if (this->thang == 4 || this->thang == 6 || this->thang == 9 || this->thang == 11)
	{
		if (this->ngay > 30) return false;
	}
	else if (this->thang == 2)
	{
		if (KiemTraNamNhuan(this->nam))
		{
			if (this->ngay > 29) return false;
		}
		else
		{
			if (this->ngay > 28) return false;
		}
	}
	else
	{
		if (this->ngay > 31) return false;
	}
	// 
	if (Date().KhoangCachGiua2Ngay(*this) > 7) return false;
	return true; // ngày tháng năm đều hợp lệ
}

bool Date::KiemTraTinhHopLeNgaySinh()
{
	//
	if (this->ngay < 0 || this->ngay > 31) return false;
	if (this->thang < 0 || this->thang > 12) return false;
	if (this->nam < 1900) return false;
	//
	if (this->thang == 4 || this->thang == 6 || this->thang == 9 || this->thang == 11)
	{
		if (this->ngay > 30) return false;
	}
	else if (this->thang == 2)
	{
		if (KiemTraNamNhuan(this->nam))
		{
			if (this->ngay > 29) return false;
		}
		else
		{
			if (this->ngay > 28) return false;
		}
	}
	else
	{
		if (this->ngay > 31) return false;
	}
	return true; // ngày tháng năm đều hợp lệ
}

void Date::NhapNgaySinh()
{
NhapLai:
	int ngay, thang, nam;
	ngay = NhapSoNguyen("Nhap ngay: ");
	thang = NhapSoNguyen("Nhap thang: ");
	nam = NhapSoNguyen("Nhap nam: ");
	if (Date(ngay,thang,nam).KiemTraTinhHopLeNgaySinh())
	{
		setNgay(ngay);
		setThang(thang);
		setNam(nam);
	}
	else
	{
		cout << "Ngay thang nam nhap vao khong hop le. Xin vui long nhap lai." << endl;
		goto NhapLai;
	}
}

void Date::NhapPhieuMuonTra()
{
NhapLai:
	int ngay, thang, nam;
	ngay = NhapSoNguyen("Nhap ngay: ");
	thang = NhapSoNguyen("Nhap thang: ");
	nam = NhapSoNguyen("Nhap nam: ");
	if (Date(ngay,thang,nam).KiemTraTinhHopLe())
	{
		setNgay(ngay);
		setThang(thang);
		setNam(nam);
	}
	else
	{
		cout << "Ngay thang nam nhap vao khong hop le. Xin vui long nhap lai." << endl;
		goto NhapLai;
	}
}

void Date::Xuat()
{
	cout << getNgay() << "/" << getThang() << "/" << getNam();
}

string Date::XuatString()
{
	return (to_string(getNgay())+"/"+to_string(getThang())+"/"+to_string(getNam()));
}

void Date::SuaNgaySinh()
{
NhapLai:
	system("CLS");
	InChu("SUA NGAY THANG NAM");
	InChu("Day la ngay thang hien tai: " + XuatString(), false, true);
	string ngay, thang, nam;
	cout << "Nhap ngay: "; getline(cin, ngay);
	cout << "Nhap thang: "; getline(cin, thang);
	cout << "Nhap nam: "; getline(cin, nam);
	Date temp = Date(ChuoiSangSo(ngay), ChuoiSangSo(thang), ChuoiSangSo(nam));
	if (temp.KiemTraTinhHopLeNgaySinh())
		*this = temp;
	else
	{
		cout << "Ngay thang nam ban vua nhap vao khong hop le. Xin vui long nhap lai." << endl;
		system("pause");
		goto NhapLai;
	}
}

void Date::SuaPhieuMuonTra()
{
NhapLai:
	system("CLS");
	InChu("SUA NGAY THANG NAM");
	InChu("Day la ngay thang hien tai: " + XuatString(), false, true);
	string ngay, thang, nam;
	cout << "Nhap ngay: "; getline(cin, ngay);
	cout << "Nhap thang: "; getline(cin, thang);
	cout << "Nhap nam: "; getline(cin, nam);
	Date temp = Date(ChuoiSangSo(ngay), ChuoiSangSo(thang), ChuoiSangSo(nam));
	if (temp.KiemTraTinhHopLe())
		*this = temp;
	else
	{
		cout << "Ngay thang nam ban vua nhap vao khong hop le. Xin vui long nhap lai." << endl;
		system("pause");
		goto NhapLai;
	}
}

int Date::DemSoNamNhuan()
{
	int years = this->getNam();
	if (this->getThang() <= 2)
		years--;
	return (years / 4 - years / 100 + years / 400);
}

int Date::KhoangCachGiua2Ngay(Date d)
{
	long int n1 = nam * 365 + ngay;
	for (int i = 0; i < thang - 1; i++)
	{
		if (i == 4 || i == 6 || i == 9 || i == 11)
			n1 += 30;
		else if (i == 2)
			n1 += 28;
		else n1 += 31;
	}
	n1 += DemSoNamNhuan();
	long int n2 = d.nam * 365 + d.ngay;
	for (int i = 0; i < d.thang - 1; i++)
	{
		if (i == 4 || i == 6 || i == 9 || i == 11)
			n2 += 30;
		else if (i == 2)
			n2 += 28;
		else n2 += 31;
	}
	n2 += d.DemSoNamNhuan();
	return (n2 - n1);
}

bool KiemTraNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	return false;
}
