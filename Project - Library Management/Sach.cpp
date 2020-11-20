#include "Sach.h"
#include "CacThuVienSuDung.h"
Sach::Sach()
{
	MaSach = "";
	TenSach = "";
	TacGia = "";
	NhaXuatBan = "";
	ISBN = "";
	GiaSach = NULL;
	TrangThai = true;
}

Sach::Sach(string MaSach, string TenSach, string TacGia, string NhaXuatBan, string ISBN, int GiaSach, bool TrangThai)
{
	this->MaSach = MaSach;
	this->TenSach = TenSach;
	this->TacGia = TacGia;
	this->NhaXuatBan = NhaXuatBan;
	this->ISBN = ISBN;
	this->GiaSach = GiaSach;
	this->TrangThai = TrangThai;
}

Sach::~Sach()
{
}

SachTiengViet::SachTiengViet()
{
	setMaSach("");
	setTenSach("");
	setTacGia("");
	setNhaXuatBan("");
	setISBN("");
	setGiaSach(NULL);
	setTrangThai(true);
}

SachTiengViet::SachTiengViet(string MaSach, string TenSach, string TacGia, string NXB, string ISBN, int GiaSach,bool TrangThai)
{
	this->setMaSach(MaSach);
	this->setTenSach(TenSach);
	this->setTacGia(TacGia);
	this->setNhaXuatBan(NXB);
	this->setISBN(ISBN);
	this->setGiaSach(GiaSach);
	this->setTrangThai(TrangThai);
}

SachTiengViet::~SachTiengViet()
{
	cout << "Xoa sach tieng viet thanh cong." << endl;
}

void SachTiengViet::Nhap()
{
	string MaSach;
	NhapLaiMaSach:
	cout << "Nhap ma sach: "; getline(cin, MaSach);
	if (MaSach.length() == 0)
	{
		cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
		goto NhapLaiMaSach;
	}
	for (unsigned int i = 0; i < MaSach.length(); i++)
	{
		if (MaSach[i] == ' ')
		{
			cout << "Du lieu ma sach khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
			goto NhapLaiMaSach;
		}
	}
	this->setMaSach(MaSach);
	this->setTenSach(NhapChuoiKiTuChu("Nhap ten sach: "));
	this->setTacGia(NhapChuoiKiTuChu("Nhap ten tac gia: ")); 
	this->setNhaXuatBan(NhapChuoiKiTuChu("Nhap ten nha xuat ban: "));
	string ISBN;
	NhapLaiISBN:
	cout << "Nhap ISBN: "; getline(cin, ISBN);
	if (ISBN.length() == 0)
	{
		cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
		goto NhapLaiISBN;
	}
	this->setISBN(ISBN);
	this->setGiaSach(NhapSoNguyen("Nhap gia sach: "));
}

void SachTiengViet::Xuat()
{
	InChu("SACH TIENG VIET", true, true);
	InChu("Ma sach: " + getMaSach(), false, false);
	InChu("Ten sach: " + getTenSach(), false, false);
	InChu("Tac gia: " + getTacGia(), false, false);
	InChu("Nha xuat ban: " + getNhaXuatBan(), false, false);
	InChu("ISBN: " + getISBN(), false, false);
	InChu("Gia sach: " + to_string(getGiaSach()) + "d", false, true);
	if (getTrangThai()) InChu("Trang thai: Co the muon", false, true);
	else InChu("Trang thai: Da co nguoi muon", false, true);
}

void SachTiengViet::XuatSimple()
{
	cout << left << setw(10) << getMaSach() << setw(18) << getTenSach() << setw(20) << getTacGia() << setw(17) << getNhaXuatBan() << setw(15) << getISBN() << setw(13) << getGiaSach() << setw(12) << "Tieng Viet" << setw(15)<< BoolSangChuoi(getTrangThai());
}

/*
void SachTiengViet::Sua() 
{
	int choice;
	system("CLS");
	InChu("Day la thong tin hien tai cua sach: ", false, false);
	this->Xuat();
	choice = NhapSoNguyen("Select: ");
	switch (choice) {
	case 1:
	{
			string MaSach;
		NhapLaiMaSach:
			system("CLS");
			InChu("SUA MA SACH");
			InChu("Day la thong tin hien tai cua sach: ", false, false);
			this->Xuat();
			cout << "Nhap ma sach moi: "; getline(cin, MaSach);
			if (MaSach.length() == 0)
			{
				cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
				system("pause");
				goto NhapLaiMaSach;
			}
			for (unsigned int i = 0; i < MaSach.length(); i++)
			{
				if (MaSach[i] == ' ')
				{
					cout << "Du lieu ma sach khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
					system("pause");
					goto NhapLaiMaSach;
				}
			}
			this->setMaSach(MaSach);
	} break;
	case 2: this->setTenSach(NhapChuoiKiTuChu("Nhap ten sach moi: ")); break;
	case 3: this->setTacGia(NhapChuoiKiTuChu("Nhap ten tac gia moi: ")); break;
	case 4: this->setNhaXuatBan(NhapChuoiKiTuChu("Nhap ten nha xuat ban moi: ")); break;
	case 5: {
			string ISBN;
			cout << "Nhap ISBN moi: "; getline(cin, ISBN); this->setISBN(ISBN);
		} break;
	case 6: this->setGiaSach(NhapSoNguyen("Nhap gia sach moi: ")); break;
	default: break;
	}
}
*/

SachNgoaiVan::SachNgoaiVan()
{
	setMaSach("");
	setTenSach("");
	setTacGia("");
	setNhaXuatBan("");
	setISBN("");
	setGiaSach(NULL);
	setTrangThai(true);
}

SachNgoaiVan::SachNgoaiVan(string MaSach, string TenSach, string TacGia, string NXB, string ISBN, int GiaSach, bool TrangThai)
{
	this->setMaSach(MaSach);
	this->setTenSach(TenSach);
	this->setTacGia(TacGia);
	this->setNhaXuatBan(NXB);
	this->setISBN(ISBN);
	this->setGiaSach(GiaSach);
	this->setTrangThai(TrangThai);
}

SachNgoaiVan::~SachNgoaiVan()
{
	cout << "Xoa sach ngoai van thanh cong." << endl;
}

void SachNgoaiVan::Nhap()
{
	string MaSach;
	NhapLaiMaSach:
	cout << "Nhap ma sach: "; getline(cin, MaSach); // Nhập mã sách
	if (MaSach.length() == 0)
	{
		cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
		goto NhapLaiMaSach;
	}
	for (unsigned int i = 0; i < MaSach.length(); i++)
	{
		if (MaSach[i] == ' ')
		{
			cout << "Du lieu ma sach khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
			goto NhapLaiMaSach;
		}
	}
	this->setMaSach(MaSach);
	this->setTenSach(NhapChuoiKiTuChu("Nhap ten sach: ")); // Nhập tên sách
	this->setTacGia(NhapChuoiKiTuChu("Nhap ten tac gia: ")); // Nhập tên tác giả
	this->setNhaXuatBan(NhapChuoiKiTuChu("Nhap ten nha xuat ban: "));
	string ISBN;
	NhapLaiISBN:
	cout << "Nhap ISBN: "; getline(cin, ISBN);
	if (ISBN.length() == 0)
	{
		cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
		goto NhapLaiISBN;
	}
	this->setISBN(ISBN);
	this->setGiaSach(NhapSoNguyen("Nhap gia sach: "));
}

void SachNgoaiVan::Xuat()
{
	InChu("SACH NGOAI VAN", true, true);
	InChu("Ma sach: " + getMaSach(), false, false);
	InChu("Ten sach: " + getTenSach(), false, false);
	InChu("Tac gia: " + getTacGia(), false, false);
	InChu("Nha xuat ban: " + getNhaXuatBan(), false, false);
	InChu("ISBN: " + getISBN(), false, false);
	InChu("Gia sach: " + to_string(getGiaSach()) + "d", false, true);
	if (getTrangThai()) InChu("Trang thai: Co the muon", false, true);
	else InChu("Trang thai: Da co nguoi muon", false, true);
}

void SachNgoaiVan::XuatSimple()
{
	cout << left << setw(10) << getMaSach() << setw(18) << getTenSach() << setw(20) << getTacGia() << setw(17) << getNhaXuatBan() << setw(15) << getISBN() << setw(13) << getGiaSach() << setw(12) << "Ngoai Van" << setw(15) << BoolSangChuoi(getTrangThai());
}

/*
void SachNgoaiVan::Sua()
{
	int choice;
	system("CLS");
	MenuSuaSach();
	InChu("Day la thong tin hien tai cua sach: ", false, false);
	this->Xuat();
	choice = NhapSoNguyen("Select: ");
	switch (choice) {
	case 1:
	{
		string MaSach;
	NhapLaiMaSach:
		system("CLS");
		InChu("SUA MA SACH");
		InChu("Day la thong tin hien tai cua sach: ", false, false);
		this->Xuat();
		cout << "Nhap ma sach moi: "; getline(cin, MaSach);
		if (MaSach.length() == 0)
		{
			cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
			system("pause");
			goto NhapLaiMaSach;
		}
		for (unsigned int i = 0; i < MaSach.length(); i++)
		{
			if (MaSach[i] == ' ')
			{
				cout << "Du lieu ma sach khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
				system("pause");
				goto NhapLaiMaSach;
			}
		}
		this->setMaSach(MaSach);
	} break;
	case 2: this->setTenSach(NhapChuoiKiTuChu("Nhap ten sach moi: ")); break;
	case 3: this->setTacGia(NhapChuoiKiTuChu("Nhap ten tac gia moi: ")); break;
	case 4: this->setNhaXuatBan(NhapChuoiKiTuChu("Nhap ten nha xuat ban moi: ")); break;
	case 5: {
		string ISBN;
		cout << "Nhap ISBN moi: "; getline(cin, ISBN); this->setISBN(ISBN);
	} break;
	case 6: this->setGiaSach(NhapSoNguyen("Nhap gia sach moi: ")); break;
	default: break;
	}
}
*/