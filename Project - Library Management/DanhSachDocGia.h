#ifndef _DANHSACHDOCGIA_H
#define _DANHSACHDOCGIA_H
#include"DocGia.h"
#include"CacThuVienSuDung.h"
#include "HamHoTro.h"

class ListDocGia
{
private:
	vector<DocGia*>ds_DocGia;
	// Singleton
	ListDocGia(ListDocGia const&) = delete;
	void operator=(ListDocGia const&) = delete;
	ListDocGia() {}
public:
	// Singleton
	static ListDocGia& getInstance()
	{
		static ListDocGia instance;
		return instance;
	}
	//
	vector<DocGia*> getListDocGia() { return ds_DocGia; }
	//
	void MainMenuQuanLyDocGia();
	//
	void ThemDocGia();
	//
	bool KiemTraTrungMaDocGia(string MaDocGia);
	//
	void SuaDocGia();
	//
	void XoaDocGia();
	bool XoaTheoMaDocGia(string MaDocGia);
	//
	void TimKiemDocGia();
	//
	void XuatTatCaDocGia();
	//
	void XuatRaFile_DocGia_MainMenuFunc(string outputFile);
	void CapNhapFile_DocGia(string outputFile);
	void DocDataTuFile(string inputFile);
};
#endif // !_DANHSACHDOCGIA_H
