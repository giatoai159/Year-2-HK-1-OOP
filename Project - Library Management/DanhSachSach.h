#ifndef _DANHSACHSACH_H
#define _DANHSACHSACH_H
#include"Sach.h"
#include"CacThuVienSuDung.h"
#include "HamHoTro.h"

class ListSach
{
private:
	vector<Sach*>ds_Sach;
	// Singleton
	ListSach(ListSach const&) = delete;
	void operator=(ListSach const&) = delete;
	ListSach() {}
public:
	// Singleton
	static ListSach& getInstance()
	{
		static ListSach instance;				  
		return instance;
	}
	//
	vector<Sach*> getListSach() { return ds_Sach; }
	//
	void MainMenuQuanLySach();
	//
	void MenuThemSach();
	//
	void XuatTatCaSach();
	//
	void XoaSach();
	bool XoaTheoMaSach(string MaSach);
	//
	void SuaSach();
	//
	void TimKiemSach();
	//
	bool KiemTraTrungMaSach(string MaSach);
	//
	void XuatRaFile_Sach_MainMenuFunc(string outputFile);
	void CapNhapFile_Sach(string outputFile);
	void DocDataTuFile(string inputFile);
};
#endif // !_DANHSACHSACH_H

