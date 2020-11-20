#ifndef _DANHSACHPHIEUMUONTRA_H
#define _DANHSACHPEIUMUONTRA_H
#include"HamHoTro.h"
#include"CacThuVienSuDung.h"
#include"PhieuMuonTra.h"

class ListPhieuMuonTra
{
private:
	vector<PhieuMuonTra*>ds_Phieu;
	// Singleton
	ListPhieuMuonTra(ListPhieuMuonTra const&) = delete;
	void operator=(ListPhieuMuonTra const&) = delete;
	ListPhieuMuonTra() {}
public:
	// Singleton
	static ListPhieuMuonTra& getInstance()
	{
		static ListPhieuMuonTra instance;
		return instance;
	}
	vector<PhieuMuonTra*> getListPhieuMuonTra() { return ds_Phieu; }
	//
	void MainMenuPhieuMuonTra();
	//
	bool KiemTraTrungMaSachMuon(string MaSachMuon)
	{
		for (unsigned int i = 0; i < ds_Phieu.size(); i++)
		{
			if (ds_Phieu[i]->getMaSachMuon() == MaSachMuon)
				return true;
		}
		return false;
	}
	bool KiemTraTrungMaNguoiMuon(string MaNguoiMuon)
	{
		for (unsigned int i = 0; i < ds_Phieu.size(); i++)
		{
			if (ds_Phieu[i]->getMaNguoiMuon() == MaNguoiMuon)
				return true;
		}
		return false;
	}
	//
	void LapPhieuMuonTra();
	void XuatTatCaPhieuMuonTra();
	//
	void CapNhapFile_PhieuMuonTra(string outputFile);
	void DocDataTuFile(string inputFile);
	//
	void MenuTraSach();
	bool TraSachTheoMaSachMuon(string MaSachMuon);
	bool TraSachTheoMaNguoiMuon(string MaNguoiMuon);
	//
	void CapNhatTrangThai();
	//
	void XuatDanhSachNguoiMuonTreHan();
};
#endif // !_DANHSACHPHIEUMUONTRA_H
