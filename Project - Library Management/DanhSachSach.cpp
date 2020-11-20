#include "DanhSachSach.h"

void ListSach::MainMenuQuanLySach()
{
	int choice;
	do
	{
		system("CLS");
		InChu("QUAN LY SACH");
		InChu("1. Them sach vao thu vien", false, false);
		InChu("2. Sua thong tin sach trong thu vien", false, false);
		InChu("3. Tim kiem thong tin sach trong thu vien", false, false);
		InChu("4. Xuat ra tat ca sach co trong thu vien", false, false);
		InChu("5. Xoa thong tin sach trong thu vien", false, false);
		InChu("6. Xuat data sach hien tai ra file", false, false);
		InChu("7. Doc data sach tu file va them vao thu vien", false, false);
		InChu("8. Exit", false, true);
		choice = NhapSoNguyen("Select: ");
		switch (choice)
		{
		case 1: MenuThemSach(); 
			break;
		case 2:
		{
			if (ds_Sach.size()>0)
				SuaSach();
			else
			{
				cout << "Hien tai thu vien khong co sach de sua, xin hay them sach truoc." << endl;
				system("pause");
			}
		}
			break;
		case 3:
		{
			if (ds_Sach.size() > 0)
			{
				TimKiemSach();
				system("pause");
			}
			else
			{
				cout << "Hien tai thu vien khong co sach de tim, xin hay them sach truoc." << endl;
				system("pause");
			}
		}
			break;
		case 4:
		{
			if (ds_Sach.size() > 0)
			{
				XuatTatCaSach();
				system("pause");
			}
			else
			{
				cout << "Hien tai thu vien khong co sach de xuat, xin hay them sach truoc." << endl;
				system("pause");
			}
		}
			break;
		case 5:
		{
			if(ds_Sach.size()>0)
				XoaSach();
			else
			{
				cout << "Hien tai thu vien khong co sach de xoa, xin hay them sach truoc." << endl;
				system("pause");
			}
		}
			break;
		case 6:
		{
			if (ds_Sach.size() > 0)
			{
				string temp;
				do
				{
					system("CLS");
					InChu("XUAT DATA RA FILE");
					cout << "Nhap ten file cua file ma ban muon xuat ra ( nhap -1 de quay lai): "; getline(cin, temp);
					if (temp == "-1") break;
					XuatRaFile_Sach_MainMenuFunc(temp);
					cout << "Xuat ra file " << temp << " thanh cong." << endl;
					system("pause");
					break;
				} while (true);
			}
			else
			{
				cout << "Hien tai thu vien khong co sach de xuat ra file, xin hay them sach truoc." << endl;
				system("pause");
			}
		}
			break;
		case 7:
		{
			string temp;
			do
			{
				system("CLS");
				InChu("DOC DATA TU FILE");
				cout << "Nhap ten file cua file ma ban muon doc data vao thu vien ( nhap -1 de quay lai): "; getline(cin, temp);
				if (temp == "-1") break;
				ifstream inputStream(temp);
				if (inputStream.is_open())
				{
					DocDataTuFile(temp);
					cout << "Doc data thanh cong." << endl;
					CapNhapFile_Sach("bookList.txt");
					system("pause");
					break;
				}
				else
				{
					cout << "Khong the doc duoc file. Xin vui long nhap lai." << endl;
					system("pause");
				}
				inputStream.close();
			} while (true);
		}
			break;
		default: break;
		}
	} while (choice != 8);
}

void ListSach::MenuThemSach()
{
	int choice;
	do
	{
		system("CLS");
		InChu("THEM SACH");
		InChu("1. Them sach Tieng Viet", false, false);
		InChu("2. Them sach Ngoai Van", false, false);
		InChu("3. Exit", false, true);
		choice = NhapSoNguyen("Select: ");
		switch (choice)
		{
		case 1: // Nhập sách tiếng việt
		{
			Sach *temp = new SachTiengViet;
			bool KiemTra;
			do
			{
				system("CLS");
				InChu("NHAP SACH TIENG VIET");
				temp->Nhap();
				KiemTra = KiemTraTrungMaSach(temp->getMaSach());
				if (KiemTra)
				{
					cout << "Sach ban vua nhap trung ma sach voi mot sach trong thu vien. Xin vui long nhap lai." << endl;
					string temp;
					cout << "Neu ban khong muon nhap nua, nhap -1 de dung lai hoac enter de nhap lai: "; getline(cin, temp);
					if (temp == "-1") break;
				}
				else
				{
					ds_Sach.push_back(temp);
					cout << "Them sach tieng viet thanh cong." << endl;
					CapNhapFile_Sach("bookList.txt");
					system("pause");
				}
			} while (KiemTra);
		}
			break;
		case 2: // Nhập sách ngoại văn
		{
			Sach *temp = new SachNgoaiVan;
			bool KiemTra;
			do
			{
				system("CLS");
				InChu("NHAP SACH NGOAI VAN");
				temp->Nhap();
				KiemTra = KiemTraTrungMaSach(temp->getMaSach());
				if (KiemTra)
				{
					cout << "Sach ban vua nhap trung ma sach voi mot sach trong thu vien. Xin vui long nhap lai." << endl;
					string temp;
					cout << "Neu ban khong muon nhap nua, nhap -1 de dung lai hoac enter de nhap lai: "; getline(cin, temp);
					if (temp == "-1") break;
				}
				else
				{
					ds_Sach.push_back(temp);
					cout << "Them sach ngoai van thanh cong." << endl;
					CapNhapFile_Sach("bookList.txt");
					system("pause");
				}
			} while (KiemTra);
		}
			break;
		default:break;
		}
	} while (choice != 3);
}

void ListSach::XuatTatCaSach()
{
	cout << "So sach hien tai trong thu vien: " << ds_Sach.size() << endl;
	if(ds_Sach.size()>0)
	{
		cout << left << setw(10) << "Ma sach" << setw(18) << "Ten sach" << setw(20) << "Tac gia" << setw(17) << "Nha xuat ban" << setw(15) << "ISBN" << setw(13) << "Gia sach" << setw(12) << "Loai sach" << setw(15) << "Trang thai" << endl;
		for (unsigned int i = 0; i < ds_Sach.size(); i++)
		{
			ds_Sach[i]->XuatSimple();
			cout << endl;
		}
	}
	else cout << "Hien tai thu vien khong co sach nao." << endl;
}

void ListSach::XoaSach()
{
	string temp;
	bool KiemTra;
	do
	{
		system("CLS");
		InChu("XOA SACH");
		InChu("Danh sach sach hien co cua thu vien", false, true);
		XuatTatCaSach();
		cout << "Nhap ma sach cua cuon sach ban muon xoa ( nhap -1 de thoat): "; getline(cin, temp);
		if (temp == "-1") break;
		KiemTra = XoaTheoMaSach(temp);
		if (KiemTra)
		{
			cout << "Xoa sach thanh cong." << endl;
			CapNhapFile_Sach("bookList.txt");
			system("pause");
		}
		else system("pause");
	} while (!KiemTra);
}

bool ListSach::XoaTheoMaSach(string MaSach)
{
	bool found = false;
	for (unsigned int i = 0; i < ds_Sach.size(); i++)
	{
		if (ds_Sach[i]->getMaSach() == MaSach)
		{
			found = true;
			ds_Sach.erase(ds_Sach.begin() + i);
		}
	}
	if (!found) cout << "Sach ban muon xoa khong ton tai trong thu vien." << endl;
	return found;
}

void ListSach::SuaSach()
{
	string sua;
	bool success;
	do
	{
		system("CLS");
		InChu("SUA SACH");
		InChu("Danh sach sach hien tai cua thu vien", false, true);
		XuatTatCaSach();
		cout << "Nhap ma sach cua cuon sach ban muon sua ( nhap -1 de quay lai): "; getline(cin, sua);
		if (sua == "-1") break;
		for (unsigned int i = 0; i < ds_Sach.size(); i++)
		{
			success = false;
			if (ds_Sach[i]->getMaSach() == sua)
			{
				int choice;
				do
				{
					system("CLS");
					InChu("Ban muon sua gi cua sach? ", true, false);
					InChu("1. Ma sach", false, false);
					InChu("2. Ten sach", false, false);
					InChu("3. Tac gia", false, false);
					InChu("4. Nha xuat ban", false, false);
					InChu("5. ISBN", false, false);
					InChu("6. Gia sach", false, false);
					InChu("7. Exit", false, true);
					InChu("Day la thong tin hien tai cua sach: ", false, false);
					ds_Sach[i]->Xuat();
					choice = NhapSoNguyen("Select: ");
					switch (choice)
					{
					case 1:
					{
					NhapLaiMaSach:
						string MaSach;
						cout << "Nhap ma sach moi: "; getline(cin, MaSach);
						if (KiemTraTrungMaSach(MaSach))
						{
							cout << "Ma sach ban vua nhap da ton tai trong he thong thu vien. Xin vui long nhap lai." << endl;
							goto NhapLaiMaSach;
						}
						if (MaSach.length() == 0)
						{
							cout << "Ma sach khong duoc de trong. Xin vui long nhap lai." << endl;
							goto NhapLaiMaSach;
						}
						for (unsigned int i = 0; i < MaSach.length(); i++)
						{
							if (MaSach[i] == ' ')
							{
								cout << "Ma sach khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
								goto NhapLaiMaSach;
							}
						}
						ds_Sach[i]->setMaSach(MaSach);
						cout << "Sua ma sach thanh cong." << endl;
						success = true;
						system("pause");
					}
					break;
					case 2:
					{
						string TenSach;
						TenSach = NhapChuoiKiTuChu("Nhap ten sach moi: ");
						ds_Sach[i]->setTenSach(TenSach);
						cout << "Sua ten sach thanh cong." << endl;
						success = true;
						system("pause");
					}
					break;
					case 3:
					{
						string TacGia;
						TacGia = NhapChuoiKiTuChu("Nhap ten tac gia moi: ");
						ds_Sach[i]->setTacGia(TacGia);
						cout << "Sua ten tac gia thanh cong." << endl;
						success = true;
						system("pause");
					}
					break;
					case 4:
					{
						string NXB;
						NXB = NhapChuoiKiTuChu("Nhap ten NXB moi: ");
						ds_Sach[i]->setNhaXuatBan(NXB);
						cout << "Sua ten NXB thanh cong." << endl;
						success = true;
						system("pause");
					}
					break;
					case 5:
					{
					NhapLaiISBN:
						string ISBN;
						cout << "Nhap ISBN moi: "; getline(cin, ISBN);
						if (ISBN.length() == 0)
						{
							cout << "ISBN khong duoc de trong. Xin vui long nhap lai." << endl;
							goto NhapLaiMaSach;
						}
						for (unsigned int i = 0; i < ISBN.length(); i++)
						{
							if (ISBN[i] == ' ')
							{
								cout << "Ma sach khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
								goto NhapLaiISBN;
							}
						}
						ds_Sach[i]->setISBN(ISBN);
						cout << "Sua ISBN thanh cong." << endl;
						success = true;
						system("pause");
					}
					break;
					case 6:
					{
						int GiaSach;
						GiaSach = NhapSoNguyen("Nhap gia sach moi: ");
						ds_Sach[i]->setGiaSach(GiaSach);
						cout << "Sua gia sach thanh cong." << endl;
						success = true;
						system("pause");
					}
					break;
					case 7: success = true;
						break;
					default:
						break;
					}
					if (success) break;
				} while (choice != 7);
				if (success) break;
			}
		}
		if (success)
		{
			CapNhapFile_Sach("bookList.txt");
			break;
		}
		else
		{
			cout << "Sach ban muon sua khong ton tai. Xin vui long nhap lai." << endl;
			system("pause");
		}
	} while (true);
}

void ListSach::TimKiemSach()
{
	string temp;
	bool success;
	do
	{
		system("CLS");
		InChu("TIM KIEM SACH");
		InChu("Danh sach sach hien tai cua thu vien", false, true);
		XuatTatCaSach();
		cout << "Nhap ma sach cua cuon sach ban muon tim ( nhap -1 de quay lai): "; getline(cin, temp);
		if (temp == "-1") break;
		success = false;
		for (unsigned int i = 0; i < ds_Sach.size(); i++)
		{
			if (ds_Sach[i]->getMaSach() == temp)
			{
				ds_Sach[i]->Xuat();
				success = true;
				break;
			}
		}
		if (success) break;
		else
		{
			cout << "Sach ban dang tim khong ton tai. Xin vui long nhap lai." << endl;
			system("pause");
		}
	} while (true);
}

bool ListSach::KiemTraTrungMaSach(string MaSach)
{
	for (unsigned int i = 0; i < ds_Sach.size(); i++)
	{
		if (ds_Sach[i]->getMaSach() == MaSach)
			return true;
	}
	return false;
}

void ListSach::XuatRaFile_Sach_MainMenuFunc(string outputFile)
{
	ofstream outputStream(outputFile, ios::trunc);
	unsigned int i;
	if (ds_Sach.size() > 0)
	{
		for (i = 0; i < ds_Sach.size(); i++)
			outputStream << ds_Sach[i]->getMaSach() << "," << ds_Sach[i]->getTenSach() << "," << ds_Sach[i]->getTacGia() << "," << ds_Sach[i]->getNhaXuatBan() << "," << ds_Sach[i]->getISBN() << "," << ds_Sach[i]->getGiaSach() << "," << ds_Sach[i]->getLoaiSach() << "," << BoolSangChuoi(ds_Sach[i]->getTrangThai()) << endl;
		outputStream.close();
	}
	else
	{
		cout << "Hien tai thu vien khong co sach de xuat ra file, xin hay them sach truoc." << endl;
		system("pause");
	}
}

void ListSach::CapNhapFile_Sach(string outputFile)
{
	ofstream outputStream(outputFile, ios::trunc);
	unsigned int i;
	for (i = 0; i < ds_Sach.size(); i++)
		outputStream << ds_Sach[i]->getMaSach() << "," << ds_Sach[i]->getTenSach() << "," << ds_Sach[i]->getTacGia() << "," << ds_Sach[i]->getNhaXuatBan() << "," << ds_Sach[i]->getISBN() << "," << ds_Sach[i]->getGiaSach() << "," << ds_Sach[i]->getLoaiSach() << "," << BoolSangChuoi(ds_Sach[i]->getTrangThai()) << endl;
	outputStream.close();
}

void ListSach::DocDataTuFile(string inputFile)
{
	ifstream inputStream(inputFile);
	string MaSach, TenSach, TacGia, NXB, ISBN, GiaSach, LoaiSach, TrangThai;
	string readingLine;
	int i = 0;
	while (getline(inputStream, readingLine))
	{
		i++;
		stringstream ss(readingLine);
		// Đọc mã sách
		getline(ss, MaSach, ',');
		if (MaSach.length() == 0)
		{
			cout << "Ma sach cua sach " << i << " khong the de trong, khong the them vao thu vien." << endl;
			continue;
		}
		if (!CheckKhoangTrang(MaSach))
		{
			cout << "Ma sach cua sach " << i << " chua khoang trang, khong the them vao thu vien." << endl;
			continue;
		}
		if (KiemTraTrungMaSach(MaSach))
		{
			cout << "Ma sach cua sach " << i << " trung voi ma sach da co san trong thu vien nen khong the them vao duoc." << endl;
			continue;
		}
		// Đọc tên sách
		getline(ss, TenSach, ',');
		if (!CheckChuoiKiTu(TenSach))
		{
			cout << "Ten sach thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc tên tác giả
		getline(ss, TacGia, ',');
		if (!CheckChuoiKiTu(TacGia))
		{
			cout << "Ten tac gia cua sach thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc tên nhà xuất bản
		getline(ss, NXB,',');
		if (!CheckChuoiKiTu(NXB))
		{
			cout << "Ten nha xuat ban cua sach " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc ISBN
		getline(ss, ISBN, ',');
		if (ISBN.length() == 0)
		{
			cout << "ISBN cua sach thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc giá sách
		getline(ss, GiaSach, ',');
		if (!CheckChuoiSo(GiaSach))
		{
			cout << "Gia sach " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc loại sách
		getline(ss, LoaiSach,',');
		if (LoaiSach != "stv" && LoaiSach != "snv")
		{
			cout << "Loai sach thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc trạng thái mượn sách
		getline(ss, TrangThai, ',');
		if (TrangThai != "true"&&TrangThai != "false")
		{
			cout << "Trang thai sach thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		if (MaSach.length() != 0 && CheckKhoangTrang(MaSach) == true && KiemTraTrungMaSach(MaSach) == false && CheckChuoiKiTu(TenSach) == true && CheckChuoiKiTu(TacGia) == true && CheckChuoiKiTu(NXB) == true && ISBN.length() != 0 && CheckChuoiSo(GiaSach) == true && CheckChuoiKiTu(LoaiSach) == true)
		{
			if (LoaiSach == "stv")
			{
				Sach *temp = new SachTiengViet(MaSach, TenSach, TacGia, NXB, ISBN, ChuoiSangSo(GiaSach), ChuoiSangBool(TrangThai));
				ds_Sach.push_back(temp);
			}
			else if (LoaiSach == "snv")
			{
				Sach *temp = new SachNgoaiVan(MaSach, TenSach, TacGia, NXB, ISBN, ChuoiSangSo(GiaSach), ChuoiSangBool(TrangThai));
				ds_Sach.push_back(temp);
			}
		}
	}
	inputStream.close();
}