#include "HamHoTro.h"

string NhapChuoiKiTuChu(string str)
{
	string s;
	bool flag = false;
	unsigned int i;
	do
	{
		cout << str;
		getline(cin, s);
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] != 32 && (s[i] < 'A' || s[i] > 'z')) // Các kí tự hợp lệ cho chuỗi kí tự chữ: A->Z và a->z và dấu cách
			{
				flag = false;
				break;
			}
			else if (s[i] == 32 || (s[i] >= 'A'&& s[i] <= 'z')) flag = true;
		}
		if (flag == false)
		{
			if (s.length() == 0)
				cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
			else cout << "Du lieu nhap vao khong hop le. Xin vui long nhap lai." << endl;
		}
	} while (flag == false);
	return s;
}

int ChuoiSangSo(string str)
{
	int s = 0;
	int mu = str.length() - 1;
	for (unsigned int i = 0; i < str.length(); i++)
		s += int(((str[i] - 48) * pow(10, mu-- * 1.0)));
	return s;
}

bool ChuoiSangBool(string str)
{
	if (str == "true") return true;
	else return false;
}

string BoolSangChuoi(bool b)
{
	if (b)
		return "true";
	else return "false";
}

int NhapSoNguyen(string str)
{
	string s;
	bool flag = false;
	unsigned int i;
	do
	{
		cout << str;
		getline(cin, s);
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] < '0' || s[i] > '9')
			{
				flag = false;
				break;
			}
			else if (s[i] >= '0' && s[i] <= '9') flag = true;
		}
		if (flag == false)
		{
			if (s.length() == 0)
				cout << "Du lieu khong duoc de trong. Xin vui long nhap lai." << endl;
			else cout << "Du lieu nhap vao khong hop le. Xin vui long nhap lai." << endl;
		}
	} while (flag == false);
	return ChuoiSangSo(s);
}

void InChu(string word, bool invientren, bool invienduoi)
{
	if (invientren)
	{
		cout << "+------------------------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool khoangtrangtruoc = true;
	for (int i = word.length(); i < 48; i++)
	{
		if (khoangtrangtruoc)
			word = " " + word;
		else
			word = word + " ";
		khoangtrangtruoc = !khoangtrangtruoc;
	}
	cout << word.c_str();
	if (invienduoi)
	{
		cout << "|" << endl;
		cout << "+------------------------------------------------+" << endl;
	}
	else
		cout << "|" << endl;
}

bool CheckChuoiKiTu(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] != 32 && (str[i] < 'A' || str[i] > 'z')) // Các kí tự hợp lệ cho chuỗi kí tự chữ: A->Z và a->z và dấu cách
		{
			return false;
		}
		else if (str[i] == 32 || (str[i] >= 'A'&& str[i] <= 'z')) return true;
	}
	return false;
}

bool CheckChuoiSo(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
		else if (str[i] >= '0' && str[i] <= '9') return true;
	}
	return false;
}

bool CheckKhoangTrang(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			return false;
	}
	return true;
}
