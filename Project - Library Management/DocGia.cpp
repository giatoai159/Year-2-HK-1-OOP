#include "DocGia.h"

DocGia::DocGia()
{
	MaDocGia = "";
	HoTen = "";
	NgaySinh = Date();
	GioiTinh = true;
	TrangThai = true;
}

DocGia::DocGia(string MaDocGia, string HoTen, Date NgaySinh, bool GioiTinh, bool TrangThai)
{
	this->MaDocGia = MaDocGia;
	this->HoTen = HoTen;
	this->NgaySinh = NgaySinh;
	this->GioiTinh = GioiTinh;
	this->TrangThai = TrangThai;
}

DocGia::~DocGia()
{
}

void DocGia::Nhap()
{
	string MaDocGia;
NhapLaiMaDocGia:
	cout << "Nhap ma doc gia: "; getline(cin, MaDocGia);
	if (MaDocGia.length() == 0)
	{
		cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
		goto NhapLaiMaDocGia;
	}
	for (unsigned int i = 0; i < MaDocGia.length(); i++)
	{
		if (MaDocGia[i] == ' ')
		{
			cout << "Du lieu ma doc gia khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
			goto NhapLaiMaDocGia;
		}
	}
	this->setMaDocGia(MaDocGia);
	this->setHoTen(NhapChuoiKiTuChu("Nhap ho ten doc gia: "));
	cout << "Nhap ngay sinh doc gia: " << endl;
	this->NgaySinh.NhapNgaySinh();
	int GioiTinh;
NhapLaiGioiTinh:
	GioiTinh = NhapSoNguyen("Nhap gioi tinh( 1: nam, 0: nu) : ");
	if (GioiTinh ==1)
		this->setGioiTinh(true);
	else if (GioiTinh == 0) this->setGioiTinh(false);
	else
	{
		cout << "Du lieu nhap vao khong hop le. Xin vui long chi nhap 1 hoac 0." << endl;
		goto NhapLaiGioiTinh;
	}
}

void DocGia::Xuat()
{
	InChu("DOC GIA", true, true);
	InChu("Ma doc gia: " + getMaDocGia(), false, false);
	InChu("Ho ten: " + getHoTen(), false, false);
	InChu("Ngay sinh: " + getNgaySinh().XuatString(), false, false);
	if (getGioiTinh()) InChu("Gioi tinh: Nam", false, true);
	else InChu("Gioi tinh: Nu", false, true);
	if (getTrangThai()) InChu("Trang thai: Co the muon sach", false, true);
	else InChu("Trang thai: Khong the muon sach", false, true);
}

void DocGia::XuatSimple()
{
	if(getGioiTinh())
		cout << left << setw(13) << getMaDocGia() << setw(25) << getHoTen() << setw(20) << getNgaySinh().XuatString() << setw(15) << "Nam" << setw(15) << BoolSangChuoi(getTrangThai());
	else 
		cout << left << setw(13) << getMaDocGia() << setw(25) << getHoTen() << setw(20) << getNgaySinh().XuatString() << setw(15) << "Nu" << setw(15) << BoolSangChuoi(getTrangThai());
}
