#include"CacThuVienSuDung.h"
#include"Sach.h"
#include"DanhSachSach.h"
#include"DocGia.h"
#include"DanhSachDocGia.h"
#include"HamHoTro.h"
#include"PhieuMuonTra.h"
#include"DanhSachPhieuMuonTra.h"

int main()
{
	string bookList = "bookList.txt";
	string readerList = "readerList.txt";
	string ticketList = "ticketList.txt";
	ListSach::getInstance().DocDataTuFile(bookList);
	ListDocGia::getInstance().DocDataTuFile(readerList);
	ListPhieuMuonTra::getInstance().DocDataTuFile(ticketList);
	int choice;
	do
	{
		system("CLS");
		InChu("QUAN LY THU VIEN");
		InChu("1. Quan ly sach", false, false);
		InChu("2. Quan ly doc gia", false, false);
		InChu("3. Quan ly phieu muon tra", false, false);
		InChu("4. Xuat danh sach doc gia muon sach qua han", false, false);
		InChu("5. Exit", false, true);
		choice = NhapSoNguyen("Select: ");
		switch (choice)
		{
		case 1: ListSach::getInstance().MainMenuQuanLySach();
			break;
		case 2: ListDocGia::getInstance().MainMenuQuanLyDocGia();
			break;
		case 3: ListPhieuMuonTra::getInstance().MainMenuPhieuMuonTra();
			break;
		case 4: ListPhieuMuonTra::getInstance().XuatDanhSachNguoiMuonTreHan();
			break;
		default:
			break;
		}
	} while (choice != 5);
	return 1;
}