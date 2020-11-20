#include "PhieuMuonTra.h"

PhieuMuonTra::PhieuMuonTra()
{
	MaSachMuon = "";
	MaNguoiMuon = "";
	NgayMuon = Date();
	NgayTra = Date();
	TrangThai = true;
}

PhieuMuonTra::PhieuMuonTra(string MaSachMuon, string MaNguoiMuon, Date NgayMuon, Date NgayTra, bool TrangThai)
{
	this->MaSachMuon = MaSachMuon;
	this->MaNguoiMuon = MaNguoiMuon;
	this->NgayMuon = NgayMuon;
	this->NgayTra = NgayTra;
	this->TrangThai = TrangThai;
}

PhieuMuonTra::~PhieuMuonTra()
{
}

bool PhieuMuonTra::Nhap()
{
	// Nhập mã sách mượn
	string MaSachMuon;
	ListSach &bookList = ListSach::getInstance();
NhapLaiMaSachMuon:
	cout << "Nhap ma sach cuon sach muon: "; getline(cin, MaSachMuon);
	if (MaSachMuon == "-1") return false; // Quay lại.
	// Kiểm tra dữ liệu nhập vào có trống hay không
	if (MaSachMuon.length() == 0)
	{
		cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
		goto NhapLaiMaSachMuon;
	}
	unsigned int i;
	// Kiểm tra dữ liệu nhập vào có chưa khoảng trắng hay không
	for (i = 0; i < MaSachMuon.length(); i++)
	{
		if (MaSachMuon[i] == ' ')
		{
			cout << "Du lieu ma sach muon khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
			goto NhapLaiMaSachMuon;
		}
	}
	// Kiểm tra dữ liệu nhập vào - mã sách, có đúng vào một cuốn sách có tồn tại trong thư viện hay không
	bool found = false;
	for (i = 0; i < bookList.getListSach().size(); i++)
		if (bookList.getListSach()[i]->getMaSach() == MaSachMuon)
			found = true;
	if (!found)
	{
		cout << "Ma sach khong ton tai trong he thong. Xin vui long nhap lai." << endl;
		goto NhapLaiMaSachMuon;
	}
	// Kiểm tra dữ liệu nhập vào - mã sách, xem cuốn sách đó có thể mượn hay không
	for (i = 0; i < bookList.getListSach().size(); i++)
		if (bookList.getListSach()[i]->getMaSach() == MaSachMuon)
			if (bookList.getListSach()[i]->getTrangThai() == false)
				found = false;
	if (!found)
	{
		cout << "Cuon sach nay da co nguoi muon. Xin vui long nhap lai." << endl;
		goto NhapLaiMaSachMuon;
	}
	// Set mã sách mượn
	this->setMaSachMuon(MaSachMuon);
	for (i = 0; i < bookList.getListSach().size(); i++)
		if (bookList.getListSach()[i]->getMaSach() == MaSachMuon)
			bookList.getListSach()[i]->setTrangThai(false); // Không thể mượn cuốn sách này nữa vì đã có người mượn
	// Nhập mã người mượn
	string MaNguoiMuon;
	ListDocGia &readerList = ListDocGia::getInstance();
NhapLaiMaNguoiMuon:
	cout << "Nhap ma nguoi muon: "; getline(cin, MaNguoiMuon);
	if (MaNguoiMuon == "-1") return false; // Quay lại.
	// Kiểm tra dữ liệu nhập vào có trống hay không
	if (MaNguoiMuon.length() == 0)
	{
		cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
		goto NhapLaiMaNguoiMuon;
	}
	// Kiểm tra dữ liệu nhập vào - mã độc giả, có đúng vào một độc giả có đăng kí trong thư viện hay không
	for (unsigned int i = 0; i < MaNguoiMuon.length(); i++)
	{
		if (MaNguoiMuon[i] == ' ')
		{
			cout << "Du lieu ma nguoi muon khong duoc chua khoang trang. Xin vui long nhap lai." << endl;
			goto NhapLaiMaNguoiMuon;
		}
	}
	found = false;
	for (i = 0; i < readerList.getListDocGia().size(); i++)
		if (readerList.getListDocGia()[i]->getMaDocGia() == MaNguoiMuon)
			found = true;
	if (!found)
	{
		cout << "Ma doc gia khong ton tai trong he thong. Xin vui long nhap lai." << endl;
		goto NhapLaiMaNguoiMuon;
	}
	// Kiểm tra dữ liệu nhập vào - mã sách, xem cuốn sách đó có thể mượn hay không
	for (i = 0; i < readerList.getListDocGia().size(); i++)
		if (readerList.getListDocGia()[i]->getMaDocGia() == MaNguoiMuon)
			if (readerList.getListDocGia()[i]->getTrangThai() == false)
				found = false;
	if (!found)
	{
		cout << "Nguoi nay da muon sach roi nen khong the muon nua. Xin vui long nhap lai." << endl;
		goto NhapLaiMaNguoiMuon;
	}
	// Set mã người mượn
	this->setMaNguoiMuon(MaNguoiMuon);
	for (i = 0; i < readerList.getListDocGia().size(); i++)
		if (readerList.getListDocGia()[i]->getMaDocGia() == MaNguoiMuon)
			readerList.getListDocGia()[i]->setTrangThai(false); // Độc giả này không thể mượn sách nữa vì đã mượn rồi.
	// Nhập ngày trả
	this->setNgayMuon(Date());
	cout << "Nhap ngay tra: " << endl;
	Date NgayTra;
	NgayTra.NhapPhieuMuonTra();
	this->setNgayTra(NgayTra);
	this->setTrangThai(true);
	return true;
}

void PhieuMuonTra::Xuat()
{
	InChu("PHIEU MUON TRA", true, true);
	InChu("Ma sach: " + getMaSachMuon(), false, false);
	InChu("Ma nguoi muon: " + getMaNguoiMuon(), false, false);
	InChu("Ngay muon: " + getNgayMuon().XuatString(), false, false);
	InChu("Ngay tra: " + getNgayTra().XuatString(), false, false);
	if (getTrangThai()) InChu("Trang thai: Con thoi han", false, true);
	else InChu("Trang thai: Tre han" + to_string(getNgayMuon().KhoangCachGiua2Ngay(getNgayTra())) + " ngay.", false, true);
}

void PhieuMuonTra::XuatSimple()
{
	if(getTrangThai())
		cout << left << setw(15) << getMaSachMuon() << setw(20) << getMaNguoiMuon() << setw(20) << getNgayMuon().XuatString() << setw(20) << getNgayTra().XuatString() << setw(15) << "Con han";
	else
		cout << left << setw(15) << getMaSachMuon() << setw(20) << getMaNguoiMuon() << setw(20) << getNgayMuon().XuatString() << setw(20) << getNgayTra().XuatString() << setw(15) << "Tre han";
}
