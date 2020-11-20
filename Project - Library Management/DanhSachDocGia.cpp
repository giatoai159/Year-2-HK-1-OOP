#include "DanhSachDocGia.h"

void ListDocGia::MainMenuQuanLyDocGia()
{
	int choice;
	do
	{
		system("CLS");
		InChu("QUAN LY DOC GIA");
		InChu("1. Them doc gia", false, false);
		InChu("2. Sua thong tin doc gia", false, false);
		InChu("3. Tim kiem thong tin doc gia", false, false);
		InChu("4. Xuat ra tat ca doc gia", false, false);
		InChu("5. Xoa thong tin doc gia", false, false);
		InChu("6. Xuat data sach hien tai ra file", false, false);
		InChu("7. Doc data sach tu file va them vao thu vien", false, false);
		InChu("8. Exit", false, true);
		choice = NhapSoNguyen("Select: ");
		switch (choice)
		{
		case 1: ThemDocGia();
			break;
		case 2:
		{
			if (ds_DocGia.size()>0)
				SuaDocGia();
			else
			{
				cout << "Hien tai thu vien khong co doc gia de sua, xin hay them doc gia truoc." << endl;
				system("pause");
			}
		}
			break;
		case 3:
		{
			if (ds_DocGia.size() > 0)
			{
				TimKiemDocGia();
				system("pause");
			}
			else
			{
				cout << "Hien tai thu vien khong co doc gia nao de tim, xin hay them doc gia truoc." << endl;
				system("pause");
			}
		}
			break;
		case 4:
		{
			if (ds_DocGia.size() > 0)
			{
				XuatTatCaDocGia();
				system("pause");
			}
			else
			{
				cout << "Hien tai thu vien khong co doc gia nao de xuat, xin hay them doc gia truoc." << endl;
				system("pause");
			}
		}
			break;
		case 5:
		{
			if (ds_DocGia.size()>0)
				XoaDocGia();
			else
			{
				cout << "Hien tai thu vien khong co sach de xoa, xin hay them sach truoc." << endl;
				system("pause");
			}
		}
			break;
		case 6:
		{
			if (ds_DocGia.size() > 0)
			{
				string temp;
				do
				{
					system("CLS");
					InChu("XUAT DATA RA FILE");
					cout << "Nhap ten file cua file ma ban muon xuat ra ( nhap -1 de quay lai): "; getline(cin, temp);
					if (temp == "-1") break;
					XuatRaFile_DocGia_MainMenuFunc(temp);
					cout << "Xuat ra file " << temp << " thanh cong." << endl;
					system("pause");
					break;
				} while (true);
			}
			else
			{
				cout << "Hien tai thu vien khong co doc gia de xuat ra file, xin hay them doc gia truoc." << endl;
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
					CapNhapFile_DocGia("readerList.txt");
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

void ListDocGia::ThemDocGia()
{
	DocGia *temp = new DocGia();
	bool KiemTra;
	do
	{
		system("CLS");
		InChu("NHAP DOC GIA");
		temp->Nhap();
		KiemTra = KiemTraTrungMaDocGia(temp->getMaDocGia());
		if (KiemTra)
		{
			cout << "Doc gia ban vua nhap trung ma doc gia voi mot nguoi khac trong thu vien. Xin vui long nhap lai." << endl;
			string temp;
			cout << "Neu ban khong muon nhap nua, nhap -1 de dung lai hoac enter de nhap lai: "; getline(cin, temp);
			if (temp == "-1") break;
		}
		else
		{
			ds_DocGia.push_back(temp);
			cout << "Them doc gia thanh cong." << endl;
			CapNhapFile_DocGia("readerList.txt");
			system("pause");
		}
	} while (KiemTra);
}

bool ListDocGia::KiemTraTrungMaDocGia(string MaDocGia)
{
	for (unsigned int i = 0; i < ds_DocGia.size(); i++)
	{
		if (ds_DocGia[i]->getMaDocGia() == MaDocGia)
			return true;
	}
	return false;
}

void ListDocGia::SuaDocGia()
{
	string sua;
	bool success;
	do
	{
		system("CLS");
		InChu("SUA DOC GIA");
		InChu("Danh sach doc gia hien tai cua thu vien", false, true);
		XuatTatCaDocGia();
		cout << "Nhap ma doc gia cua doc gia ban muon sua ( nhap -1 de quay lai): "; getline(cin, sua);
		if (sua == "-1") break;
		for (unsigned int i = 0; i < ds_DocGia.size(); i++)
		{
			success = false;
			if (ds_DocGia[i]->getMaDocGia() == sua)
			{
				int choice;
				do
				{
					system("CLS");
					InChu("Ban muon sua gi cua doc gia?", true, false);
					InChu("1. Ma doc gia", false, false);
					InChu("2. Ho ten", false, false);
					InChu("3. Ngay sinh", false, false);
					InChu("4. Gioi tinh", false, false);
					InChu("5. Exit", false, true);
					InChu("Thong tin hien tai cua doc gia", false, true);
					ds_DocGia[i]->Xuat();
					choice = NhapSoNguyen("Select: ");
					switch (choice)
					{
					case 1:
					{
					NhapLaiMaDocGia:
						string MaDocGia;
						cout << "Nhap ma doc gia moi: "; getline(cin, MaDocGia);
						if (KiemTraTrungMaDocGia(MaDocGia))
						{
							cout << "Ma doc gia ban vua nhap da ton tai trong he thong thu vien. Xin vui long nhap lai." << endl;
							goto NhapLaiMaDocGia;
						}
						if (MaDocGia.length() == 0)
						{
							cout << "Ma doc gia khong duoc de trong. Xin vui long nhap lai." << endl;
							goto NhapLaiMaDocGia;
						}
						for (unsigned int i = 0; i < MaDocGia.length(); i++)
						{
							if (MaDocGia[i] == ' ')
							{
								cout << "Ma doc gia khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
								goto NhapLaiMaDocGia;
							}
						}
						ds_DocGia[i]->setMaDocGia(MaDocGia);
						cout << "Sua ma doc gia thanh cong." << endl;
						success = true;
						system("pause");
					}
						break;
					case 2:
					{
						string HoTen;
						HoTen = NhapChuoiKiTuChu("Nhap ho ten moi: ");
						ds_DocGia[i]->setHoTen(HoTen);
						cout << "Sua ho ten thanh cong." << endl;
						success = true;
						system("pause");
					}
						break;
					case 3:
					{
						Date temp;
						cout << "Nhap ngay sinh moi: " << endl;
						temp.NhapNgaySinh();
						ds_DocGia[i]->setNgaySinh(temp);
						cout << "Sua ngay sinh thanh cong." << endl;
						success = true;
						system("pause");
					}
						break;
					case 4:
					{
						int temp;
					NhapLaiGioiTinh:
						temp = NhapSoNguyen("Nhap gioi tinh moi ( 1: nam, 0: nu): ");
						if (temp == 1)
						{
							ds_DocGia[i]->setGioiTinh(true);
							cout << "Sua gioi tinh thanh cong." << endl;
						}
						else if (temp == 0)
						{
							ds_DocGia[i]->setGioiTinh(false);
							cout << "Sua gioi tinh thanh cong." << endl;
						}
						else
						{
							cout << "Du lieu nhap vao khong hop le. Xin vui long chi nhap 1 hoac 0." << endl;
							goto NhapLaiGioiTinh;
						}
						success = true;
						system("pause");
					}
						break;
					case 5: success = true;
						break;
					default:
						break;
					}
					if (success) break;
				} while (choice!=5);
				if (success) break;
			}
		}
		if (success)
		{
			CapNhapFile_DocGia("readerList.txt");
			break;
		}
		else
		{
			cout << "Doc gia ban muon sua khong ton tai. Xin vui long nhap lai." << endl;
			system("pause");
		}
	} while (true);
}

void ListDocGia::XoaDocGia()
{
	string temp;
	bool KiemTra;
	do
	{
		system("CLS");
		InChu("XOA DOC GIA");
		InChu("Danh sach doc gia hien co cua thu vien", false, true);
		XuatTatCaDocGia();
		cout << "Nhap ma doc gia ban muon xoa ( nhap -1 de thoat): "; getline(cin, temp);
		if (temp == "-1") break;
		KiemTra = XoaTheoMaDocGia(temp);
		if (KiemTra)
		{
			cout << "Xoa doc gia thanh cong." << endl;
			CapNhapFile_DocGia("readerList.txt");
			system("pause");
		}
		else system("pause");
	} while (!KiemTra);
}

bool ListDocGia::XoaTheoMaDocGia(string MaDocGia)
{
	bool found = false;
	for (unsigned int i = 0; i < ds_DocGia.size(); i++)
	{
		if (ds_DocGia[i]->getMaDocGia() == MaDocGia)
		{
			found = true;
			ds_DocGia.erase(ds_DocGia.begin() + i);
		}
	}
	if (!found) cout << "Doc gia ban muon xoa khong ton tai trong thu vien." << endl;
	return found;
}

void ListDocGia::TimKiemDocGia()
{
	string temp;
	bool success;
	do
	{
		system("CLS");
		InChu("TIM KIEM DOC GIA");
		InChu("Danh sach doc gia hien tai cua thu vien", false, true);
		XuatTatCaDocGia();
		cout << "Nhap ma doc gia ban muon tim ( nhap -1 de quay lai): "; getline(cin, temp);
		if (temp == "-1") break;
		success = false;
		for (unsigned int i = 0; i < ds_DocGia.size(); i++)
		{
			if (ds_DocGia[i]->getMaDocGia() == temp)
			{
				ds_DocGia[i]->Xuat();
				success = true;
				break;
			}
		}
		if (success) break;
		else
		{
			cout << "DocGia ban dang tim khong ton tai. Xin vui long nhap lai." << endl;
			system("pause");
		}
	} while (true);
}

void ListDocGia::XuatTatCaDocGia()
{
	cout << "So doc gia hien tai trong thu vien: " << ds_DocGia.size() << endl;
	if (ds_DocGia.size()>0)
	{
		cout << left << setw(13) << "Ma doc gia" << setw(25) << "Ho ten" << setw(20) << "Ngay sinh" << setw(15) << "Gioi tinh" << setw(15) << "Trang thai" << endl;
		for (unsigned int i = 0; i < ds_DocGia.size(); i++)
		{
			ds_DocGia[i]->XuatSimple();
			cout << endl;
		}
	}
	else cout << "Hien tai thu vien khong co doc gia nao." << endl;
}

void ListDocGia::XuatRaFile_DocGia_MainMenuFunc(string outputFile)
{
	ofstream outputStream(outputFile, ios::trunc);
	unsigned int i;
	if (ds_DocGia.size() > 0)
	{
		for (i = 0; i < ds_DocGia.size(); i++)
			outputStream << ds_DocGia[i]->getMaDocGia() << "," << ds_DocGia[i]->getHoTen() << "," << ds_DocGia[i]->getNgaySinh().getNgay() << "," << ds_DocGia[i]->getNgaySinh().getThang() << "," << ds_DocGia[i]->getNgaySinh().getNam() << "," << BoolSangChuoi(ds_DocGia[i]->getGioiTinh()) << "," << BoolSangChuoi(ds_DocGia[i]->getTrangThai()) << endl;
		outputStream.close();
	}
	else
	{
		cout << "Hien tai thu vien khong co doc gia de xuat ra file, xin hay them doc gia truoc." << endl;
		system("pause");
	}
}

void ListDocGia::CapNhapFile_DocGia(string outputFile)
{
	ofstream outputStream(outputFile, ios::trunc);
	unsigned int i;
	for (i = 0; i < ds_DocGia.size(); i++)
		outputStream << ds_DocGia[i]->getMaDocGia() << "," << ds_DocGia[i]->getHoTen() << "," << ds_DocGia[i]->getNgaySinh().getNgay() << "," << ds_DocGia[i]->getNgaySinh().getThang() << "," << ds_DocGia[i]->getNgaySinh().getNam() << "," << BoolSangChuoi(ds_DocGia[i]->getGioiTinh()) << "," << BoolSangChuoi(ds_DocGia[i]->getTrangThai()) << endl;
	outputStream.close();
}

void ListDocGia::DocDataTuFile(string inputFile)
{
	ifstream inputStream(inputFile);
	string MaDocGia, HoTen, Ngay, Thang, Nam, GioiTinh, TrangThai;
	string readingLine;
	int i = 0;
	while (getline(inputStream, readingLine))
	{
		i++;
		stringstream ss(readingLine);
		// Đọc mã độc giả
		getline(ss, MaDocGia, ',');
		if (MaDocGia.length() == 0)
		{
			cout << "Ma cua doc gia thu " << i << " khong the de trong, khong the them vao thu vien." << endl;
			continue;
		}
		if (!CheckKhoangTrang(MaDocGia))
		{
			cout << "Ma cua doc gia thu " << i << " chua khoang trang, khong the them vao thu vien." << endl;
			continue;
		}
		if (KiemTraTrungMaDocGia(MaDocGia))
		{
			cout << "Ma cua doc gia thu " << i << " trung voi ma sach da co san trong thu vien nen khong the them vao duoc." << endl;
			continue;
		}
		// Đọc họ tên
		getline(ss, HoTen, ',');
		if (!CheckChuoiKiTu(HoTen))
		{
			cout << "Ho ten doc gia thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc ngày sinh
		getline(ss, Ngay, ',');
		if (!CheckChuoiSo(Ngay))
		{
			cout << "Ngay sinh doc gia thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc tháng sinh
		getline(ss, Thang, ',');
		if (!CheckChuoiSo(Thang))
		{
			cout << "Thang sinh doc gia thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc năm sinh
		getline(ss, Nam, ',');
		if (!CheckChuoiSo(Nam))
		{
			cout << "Nam sinh doc gia thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		Date temp = Date(ChuoiSangSo(Ngay), ChuoiSangSo(Thang), ChuoiSangSo(Nam));
		// Đọc giới tính
		getline(ss, GioiTinh, ',');
		if (GioiTinh != "true"&&GioiTinh != "false")
		{
			cout << "Gioi tinh doc gia thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		// Đọc trạng thái mượn sách
		getline(ss, TrangThai, ',');
		if (TrangThai != "true"&&TrangThai != "false")
		{
			cout << "Trang thai doc gia thu " << i << " chua noi dung khong hop le, khong the them vao thu vien." << endl;
			continue;
		}
		if (MaDocGia.length() != 0 && CheckKhoangTrang(MaDocGia) == true && KiemTraTrungMaDocGia(MaDocGia) == false && CheckChuoiKiTu(HoTen) == true && temp.KiemTraTinhHopLeNgaySinh() == true)
			ds_DocGia.push_back(new DocGia(MaDocGia, HoTen, temp, ChuoiSangBool(GioiTinh), ChuoiSangBool(TrangThai)));
	}
	inputStream.close();
}

