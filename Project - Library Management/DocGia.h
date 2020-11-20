#ifndef _DOCGIA_H
#define _DOCGIA_H
#include"CacThuVienSuDung.h"
#include "HamHoTro.h"
#include "Date.h"

class DocGia
{
private:
	string MaDocGia;
	string HoTen;
	Date NgaySinh;
	bool GioiTinh; // true - nam, false - nữ
	bool TrangThai; // Độc giả có thể mượn sách hay không
public:
	DocGia();
	DocGia(string MaDocGia, string HoTen, Date NgaySinh, bool GioiTinh, bool TrangThai);
	~DocGia();
	//
	string getMaDocGia() { return MaDocGia; }
	string getHoTen() { return HoTen; }
	Date getNgaySinh() { return NgaySinh; }
	bool getGioiTinh() { return GioiTinh; }
	bool getTrangThai() { return TrangThai; }
	void setMaDocGia(string MaDocGia) { this->MaDocGia = MaDocGia; }
	void setHoTen(string HoTen) { this->HoTen = HoTen; }
	void setNgaySinh(Date NgaySinh) { this->NgaySinh = NgaySinh; }
	void setGioiTinh(bool GioiTinh) { this->GioiTinh = GioiTinh; }
	void setTrangThai(bool TrangThai) { this->TrangThai = TrangThai; }
	//
	void Nhap();
	void Xuat();
	void XuatSimple();
};

#endif // !_DOCGIA_H
