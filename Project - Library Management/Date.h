#ifndef _DATE_H
#define _DATE_H
#include"CacThuVienSuDung.h"
#include "HamHoTro.h"
class Date
{
private:
	int ngay, thang, nam;
public:
	int getNgay() { return ngay; }
	int getThang() { return thang; }
	int getNam() { return nam; }
	void setNgay(int ngay) { this->ngay = ngay; }
	void setThang(int thang) { this->thang = thang; }
	void setNam(int nam) { this->nam = nam; }
	//
	Date(); // Mặc định lấy ngày hiện tại
	Date(int ngay, int thang, int nam);
	~Date();
	//
	bool KiemTraTinhHopLe(); // Dùng cho ngày trả sách, chỉ được nhập vào ngày tháng trong tương lai
	bool KiemTraTinhHopLeNgaySinh(); // Dùng cho ngày tháng năm sinh của đọc giả
	//
	void NhapNgaySinh();
	void NhapPhieuMuonTra();
	void Xuat();
	string XuatString();
	void SuaNgaySinh();
	void SuaPhieuMuonTra();
	//
	int DemSoNamNhuan();
	int KhoangCachGiua2Ngay(Date d);
};

bool KiemTraNamNhuan(int nam);

#endif // !_DATE_H
