#ifndef _SACH_H
#define _SACH_H
#include "CacThuVienSuDung.h"
#include "HamHoTro.h"

class Sach
{
private:
	string MaSach;
	string TenSach;
	string TacGia;
	string NhaXuatBan;
	string ISBN;
	int GiaSach;
	bool TrangThai;
public:
	Sach();
	Sach(string MaSach, string TenSach, string TacGia, string NhaXuatBan, string ISBN, int GiaSach, bool TrangThai);
	virtual ~Sach();
	//
	string getMaSach() { return MaSach; }
	string getTenSach() { return TenSach; }
	string getTacGia() { return TacGia; }
	string getNhaXuatBan() { return NhaXuatBan; }
	string getISBN() { return ISBN; }
	int getGiaSach() { return GiaSach; }
	bool getTrangThai() { return TrangThai; }
	virtual string getLoaiSach() = 0;
	virtual string getLoaiSachFancy() = 0;
	//
	void setMaSach(string MaSach) { this->MaSach = MaSach; }
	void setTenSach(string TenSach) { this->TenSach = TenSach; }
	void setTacGia(string TacGia) { this->TacGia = TacGia; }
	void setNhaXuatBan(string NhaXuatBan) { this->NhaXuatBan = NhaXuatBan; }
	void setISBN(string ISBN) { this->ISBN = ISBN; }
	void setGiaSach(int GiaSach) { this->GiaSach = GiaSach; }
	void setTrangThai(bool TrangThai) { this->TrangThai = TrangThai; }
	//
	virtual void Nhap() = 0;
	virtual void Xuat() = 0;
	virtual void XuatSimple() = 0;
	//
	virtual int TienPhat() = 0;
};

class SachTiengViet : public Sach
{
public:
	SachTiengViet();
	SachTiengViet(string MaSach, string TenSach, string TacGia, string NXB, string ISBN, int GiaSach, bool TrangThai);
	~SachTiengViet();
	//
	string getLoaiSach() { return "stv"; }
	string getLoaiSachFancy() { return "Tieng viet"; }
	//
	void Nhap();
	void Xuat();
	void XuatSimple();
	//
	int TienPhat() { return 10000; }
};

class SachNgoaiVan : public Sach
{
public:
	SachNgoaiVan();
	SachNgoaiVan(string MaSach, string TenSach, string TacGia, string NXB, string ISBN, int GiaSach, bool TrangThai);
	~SachNgoaiVan();
	//
	string getLoaiSach() { return "snv"; }
	string getLoaiSachFancy() { return "Ngoai van"; }
	//
	void Nhap();
	void Xuat();
	void XuatSimple();
	//
	int TienPhat() { return 20000; }
};

#endif // !_SACH_H