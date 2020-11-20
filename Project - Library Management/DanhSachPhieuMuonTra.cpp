#include "DanhSachPhieuMuonTra.h"

void ListPhieuMuonTra::MainMenuPhieuMuonTra()
{
	CapNhatTrangThai();
	int choice;
	do
	{
		system("CLS");
		InChu("QUAN LY PHIEU MUON TRA");
		InChu("1. Lap phieu muon tra", false, false);
		InChu("2. Tra sach", false, false);
		InChu("3. Xuat tat ca phieu muon tra", false, false);
		InChu("4. Exit", false, true);
		choice = NhapSoNguyen("Select: ");
		switch (choice)
		{
		case 1: LapPhieuMuonTra();
			break;
		case 2:
		{
			if (ds_Phieu.size()>0)
				MenuTraSach();
			else
			{
				cout << "Hien tai thu vien khong co ai muon sach de tra sach, xin hay lap phieu truoc truoc." << endl;
				system("pause");
			}
		}
		break;
		case 3:
		{
			if (ds_Phieu.size() > 0)
			{
				XuatTatCaPhieuMuonTra();
				system("pause");
			}
			else
			{
				cout << "Hien tai thu vien khong co phieu muon tra nao de xuat, xin hay lap phieu truoc." << endl;
				system("pause");
			}
		}
		break;
		default: break;
		}
	} while (choice != 4);
}

void ListPhieuMuonTra::LapPhieuMuonTra()
{
	PhieuMuonTra* temp=new PhieuMuonTra;
	string t;
	system("CLS");
	InChu("LAP PHIEU MUON TRA");
	InChu("Danh sach sach hien tai co trong thu vien", false, true);
	ListSach::getInstance().XuatTatCaSach();
	InChu("Danh sach doc gia hien tai co trong thu vien", true, true);
	ListDocGia::getInstance().XuatTatCaDocGia();
	if (temp->Nhap())
	{
		ds_Phieu.push_back(temp);
		cout << "Them phieu muon tra thanh cong." << endl;
		ListSach::getInstance().CapNhapFile_Sach("bookList.txt");
		ListDocGia::getInstance().CapNhapFile_DocGia("readerList.txt");
		CapNhapFile_PhieuMuonTra("ticketList.txt");
	}
	system("pause");
}

void ListPhieuMuonTra::XuatTatCaPhieuMuonTra()
{
	CapNhatTrangThai();
	cout << "So phieu muon tra hien tai trong thu vien: " << ds_Phieu.size() << endl;
	if (ds_Phieu.size()>0)
	{
		cout << left << setw(15) << "Ma sach" << setw(20) << "Ma doc gia" << setw(20) << "Ngay muon" << setw(20) << "Ngay tra" << setw(15) << "Trang thai" << endl;
		for (unsigned int i = 0; i < ds_Phieu.size(); i++)
		{
			ds_Phieu[i]->XuatSimple();
			cout << endl;
		}
	}
	else cout << "Hien tai thu vien khong co ai muon sach nao." << endl;
}

void ListPhieuMuonTra::CapNhapFile_PhieuMuonTra(string outputFile)
{
	ofstream outputStream(outputFile, ios::trunc);
	unsigned int i;
	for (i = 0; i < ds_Phieu.size(); i++)
		outputStream << ds_Phieu[i]->getMaSachMuon() << "," << ds_Phieu[i]->getMaNguoiMuon() << "," << ds_Phieu[i]->getNgayMuon().getNgay() << "," << ds_Phieu[i]->getNgayMuon().getThang() << "," << ds_Phieu[i]->getNgayMuon().getNam() << "," << ds_Phieu[i]->getNgayTra().getNgay() << "," << ds_Phieu[i]->getNgayTra().getThang() << "," << ds_Phieu[i]->getNgayTra().getNam() << "," << BoolSangChuoi(ds_Phieu[i]->getTrangThai()) << endl;
	outputStream.close();
}

void ListPhieuMuonTra::DocDataTuFile(string inputFile)
{
	ifstream inputStream(inputFile);
	string MaSachMuon, MaNguoiMuon, NgayMuon, ThangMuon, NamMuon, NgayTra, ThangTra, NamTra, TrangThai;
	string readingLine;
	int i = 0;
	while (getline(inputStream, readingLine))
	{
		i++;
		stringstream ss(readingLine);
		// Đọc mã sách mượn
		getline(ss, MaSachMuon, ',');
		if (MaSachMuon.length() == 0)
		{
			cout << "Ma sach cua phieu " << i << " khong the de trong, khong the them vao thu vien." << endl;
			continue;
		}
		if (!CheckKhoangTrang(MaSachMuon))
		{
			cout << "Ma sach cua phieu " << i << " chua khoang trang, khong the them vao thu vien." << endl;
			continue;
		}
		if (KiemTraTrungMaSachMuon(MaSachMuon))
		{
			cout << "Ma sach cua phieu " << i << " trung voi ma sach trong mot phieu da co san trong thu vien nen khong the them vao duoc." << endl;
			continue;
		}
		// Đọc mã người mượn
		getline(ss, MaNguoiMuon, ',');
		if (MaNguoiMuon.length() == 0)
		{
			cout << "Ma nguoi muon cua phieu " << i << " khong the de trong, khong the them vao thu vien." << endl;
			continue;
		}
		if (!CheckKhoangTrang(MaNguoiMuon))
		{
			cout << "Ma nguoi muon cua phieu " << i << " chua khoang trang, khong the them vao thu vien." << endl;
			continue;
		}
		if (KiemTraTrungMaNguoiMuon(MaNguoiMuon))
		{
			cout << "Ma nguoi muon cua phieu " << i << " trung voi ma nguoi trong mot phieu da co san trong thu vien nen khong the them vao duoc." << endl;
			continue;
		}
		// Đọc ngày mượn
		getline(ss, NgayMuon, ',');
		if (!CheckChuoiSo(NgayMuon))
		{
			cout << "Ngay muon phieu thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc tháng mượn
		getline(ss, ThangMuon, ',');
		if (!CheckChuoiSo(ThangMuon))
		{
			cout << "Thang muon phieu thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc năm mượn
		getline(ss, NamMuon, ',');
		if (!CheckChuoiSo(NamMuon))
		{
			cout << "Nam muon phieu thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		Date temp1 = Date(ChuoiSangSo(NgayMuon), ChuoiSangSo(ThangMuon), ChuoiSangSo(NamMuon));
		// Đọc ngày trả
		getline(ss, NgayTra, ',');
		if (!CheckChuoiSo(NgayTra))
		{
			cout << "Ngay tra phieu thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc tháng trả
		getline(ss, ThangTra, ',');
		if (!CheckChuoiSo(ThangTra))
		{
			cout << "Thang tra phieu thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc năm trả
		getline(ss, NamTra, ',');
		if (!CheckChuoiSo(NamTra))
		{
			cout << "Nam Tra phieu thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		Date temp2 = Date(ChuoiSangSo(NgayTra), ChuoiSangSo(ThangTra), ChuoiSangSo(NamTra));
		// Đọc trạng thái mượn sách
		getline(ss, TrangThai, ',');
		if (TrangThai != "true"&&TrangThai != "false")
		{
			cout << "Trang thai phieu thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		if (MaSachMuon.length() != 0 && CheckKhoangTrang(MaSachMuon) == true && KiemTraTrungMaSachMuon(MaSachMuon) == false &&
			MaNguoiMuon.length() != 0 && CheckKhoangTrang(MaNguoiMuon) == true && KiemTraTrungMaNguoiMuon(MaNguoiMuon) == false &&
			temp1.KiemTraTinhHopLeNgaySinh() == true && temp2.KiemTraTinhHopLeNgaySinh() == true)
			ds_Phieu.push_back(new PhieuMuonTra(MaSachMuon, MaNguoiMuon, temp1, temp2, ChuoiSangBool(TrangThai)));
	}
	inputStream.close();
	CapNhatTrangThai();
}

void ListPhieuMuonTra::MenuTraSach()
{
	int choice;
	do
	{
		system("CLS");
		InChu("TRA SACH");
		InChu("1. Tra theo ma sach muon", false, false);
		InChu("2. Tra theo ma nguoi muon", false, false);
		InChu("3. Exit", false, true);
		choice = NhapSoNguyen("Select: ");
		switch (choice)
		{
		case 1: 
		{
			string temp;
			bool KiemTra;
			do
			{
				system("CLS");
				InChu("Tra sach theo ma sach muon");
				InChu("Danh sach cac cuon sach dang duoc muon", false, true);
				cout << left << setw(10) << "Ma sach" << setw(18) << "Ten sach" << setw(20) << "Tac gia" << setw(17) << "Nha xuat ban" << setw(15) << "ISBN" << setw(13) << "Gia sach" << setw(12) << "Loai sach" << setw(15) << "Trang thai" << endl;
				for (unsigned int i = 0; i < ListSach::getInstance().getListSach().size(); i++)
				{
					if (ListSach::getInstance().getListSach()[i]->getTrangThai() == false)
						ListSach::getInstance().getListSach()[i]->XuatSimple();
				}
				cout << "Nhap ma sach ban muon tra ( nhap -1 de thoat): "; getline(cin, temp);
				if (temp == "-1") break;
				KiemTra = TraSachTheoMaSachMuon(temp);
				if (KiemTra)
				{
					cout << "Tra sach thanh cong." << endl;
					ListSach::getInstance().CapNhapFile_Sach("bookList.txt");
					ListDocGia::getInstance().CapNhapFile_DocGia("readerList.txt");
					CapNhapFile_PhieuMuonTra("ticketList.txt");
					system("pause");
				}
				else system("pause");
			} while (!KiemTra);
		}
			break;
		case 2:
		{
			string temp;
			bool KiemTra;
			do
			{
				system("CLS");
				InChu("Tra sach theo ma nguoi muon");
				InChu("Danh sach cac doc gia muon sach", false, true);
				cout << left << setw(13) << "Ma doc gia" << setw(25) << "Ho ten" << setw(20) << "Ngay sinh" << setw(15) << "Gioi tinh" << setw(15) << "Trang thai" << endl;
				for (unsigned int i = 0; i < ListDocGia::getInstance().getListDocGia().size(); i++)
				{
					if (ListDocGia::getInstance().getListDocGia()[i]->getTrangThai() == false)
					{
						ListDocGia::getInstance().getListDocGia()[i]->XuatSimple();
						cout << endl;
					}
				}
				cout << "Nhap ma nguoi muon ban muon tra ( nhap -1 de thoat): "; getline(cin, temp);
				if (temp == "-1") break;
				KiemTra = TraSachTheoMaNguoiMuon(temp);
				if (KiemTra)
				{
					cout << "Tra sach thanh cong." << endl;
					ListSach::getInstance().CapNhapFile_Sach("bookList.txt");
					ListDocGia::getInstance().CapNhapFile_DocGia("readerList.txt");
					CapNhapFile_PhieuMuonTra("ticketList.txt");
					system("pause");
				}
				else system("pause");
			} while (!KiemTra);
		}
			break;
		default: break;
		}
	} while (choice != 3);
}

bool ListPhieuMuonTra::TraSachTheoMaSachMuon(string MaSachMuon)
{
	bool found = false;
	ListSach &bookList = ListSach::getInstance();
	ListDocGia &readerList = ListDocGia::getInstance();
	unsigned int i, j, k;
	for (i = 0; i < ds_Phieu.size(); i++)
	{
		if (ds_Phieu[i]->getMaSachMuon() == MaSachMuon)
		{
			found = true;
			for (j = 0; j < bookList.getListSach().size(); j++)
				if (bookList.getListSach()[j]->getMaSach() == ds_Phieu[i]->getMaSachMuon())
					bookList.getListSach()[j]->setTrangThai(true);
			for (k = 0; k < readerList.getListDocGia().size(); k++)
				if (readerList.getListDocGia()[k]->getMaDocGia() == ds_Phieu[i]->getMaNguoiMuon())
					readerList.getListDocGia()[k]->setTrangThai(true);
			ds_Phieu.erase(ds_Phieu.begin() + i);
		}
	}
	if (!found) cout << "Phieu muon tra chua ma sach nay khong ton tai trong thu vien." << endl;
	return found;
}

bool ListPhieuMuonTra::TraSachTheoMaNguoiMuon(string MaNguoiMuon)
{
	bool found = false;
	ListSach &bookList = ListSach::getInstance();
	ListDocGia &readerList = ListDocGia::getInstance();
	unsigned int i, j, k;
	for (i = 0; i < ds_Phieu.size(); i++)
	{
		if (ds_Phieu[i]->getMaNguoiMuon() == MaNguoiMuon)
		{
			found = true;
			for (j = 0; j < bookList.getListSach().size(); j++)
				if (bookList.getListSach()[j]->getMaSach() == ds_Phieu[i]->getMaSachMuon())
					bookList.getListSach()[j]->setTrangThai(true);
			for (k = 0; k < readerList.getListDocGia().size(); k++)
				if (readerList.getListDocGia()[k]->getMaDocGia() == ds_Phieu[i]->getMaNguoiMuon())
					readerList.getListDocGia()[k]->setTrangThai(true);
			ds_Phieu.erase(ds_Phieu.begin() + i);
		}
	}
	if (!found) cout << "Phieu muon tra chua ma doc gia nay khong ton tai trong thu vien." << endl;
	return found;
}

void ListPhieuMuonTra::CapNhatTrangThai()
{
	Date now = Date();
	if (ds_Phieu.size() > 0)
	{
		for (unsigned int i = 0; i < ds_Phieu.size(); i++)
		{
			if (now.KhoangCachGiua2Ngay(ds_Phieu[i]->getNgayTra()) < 0)
			{
				ds_Phieu[i]->setTrangThai(false);
			}
		}
	}
	CapNhapFile_PhieuMuonTra("ticketList.txt");
}

void ListPhieuMuonTra::XuatDanhSachNguoiMuonTreHan()
{
	CapNhatTrangThai();
	Date now = Date();
	system("CLS");
	InChu("DANH SACH DOC GIA CHUA TRA SACH");
	cout << left << setw(12) << "Ma sach" << setw(15) << "Ma doc gia" << setw(13) << "Ngay muon" << setw(13) << "Ngay tra" << setw(15) << "Ngay hom nay" << setw(15) << "So ngay tre" << setw(15) << "Loai sach" << setw(15) << "Tien phat" << endl;
	for (unsigned int i = 0; i < ds_Phieu.size(); i++)
	{
		if (ds_Phieu[i]->getTrangThai() == false)
		{
			for (unsigned int j = 0; j < ListSach::getInstance().getListSach().size(); j++)
			{
				if (ListSach::getInstance().getListSach()[j]->getMaSach() == ds_Phieu[i]->getMaSachMuon())
				{
					cout << left << setw(12) << ds_Phieu[i]->getMaSachMuon() << setw(15) << ds_Phieu[i]->getMaNguoiMuon() << setw(13) << ds_Phieu[i]->getNgayMuon().XuatString() << setw(13) << ds_Phieu[i]->getNgayTra().XuatString() << setw(15) << now.XuatString() << setw(15) << -now.KhoangCachGiua2Ngay(ds_Phieu[i]->getNgayTra()) << setw(15) << ListSach::getInstance().getListSach()[j]->getLoaiSachFancy() << setw(15) << -now.KhoangCachGiua2Ngay(ds_Phieu[i]->getNgayTra()) * ListSach::getInstance().getListSach()[j]->TienPhat();
					cout << endl;
				}
			}
		}
	}
	system("pause");
}


