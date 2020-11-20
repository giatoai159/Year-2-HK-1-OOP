#ifndef _PHIEUMUONTRA_H
#define _PHIEUMUONTRA_H
#include"CacThuVienSuDung.h"
#include"HamHoTro.h"
#include"Sach.h"
#include"DocGia.h"
#include"Date.h"
#include"DanhSachSach.h"
#include"DanhSachDocGia.h"
class PhieuMuonTra
{
private:
	string MaSachMuon;
	string MaNguoiMuon;
	Date NgayMuon;
	Date NgayTra;
	bool TrangThai; // true - còn hạn, false - trễ hạn
public:
	PhieuMuonTra();
	PhieuMuonTra(string MaSachMuon, string MaNguoiMuon, Date NgayMuon, Date NgayTra, bool TrangThai);
	~PhieuMuonTra();
	//
	string getMaSachMuon() { return MaSachMuon; }
	string getMaNguoiMuon() { return MaNguoiMuon; }
	Date getNgayMuon() { return NgayMuon; }
	Date getNgayTra() { return NgayTra; }
	bool getTrangThai() { return TrangThai; }
	void setMaSachMuon(string masachmuon) { this->MaSachMuon = masachmuon; }
	void setMaNguoiMuon(string manguoimuon) { this->MaNguoiMuon = manguoimuon; }
	void setNgayMuon(Date ngaymuon) { this->NgayMuon = ngaymuon; }
	void setNgayTra(Date ngaytra) { this->NgayTra = ngaytra; }
	void setTrangThai(bool trangthai) { this->TrangThai = trangthai; }
	//
	bool Nhap();
	void Xuat();
	void XuatSimple();
};
#endif // !_PHIEUMUONTRA_H
