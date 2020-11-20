#ifndef _HAMHOTRO_H
#define _HAMHOTRO_H
#include"CacThuVienSuDung.h"

string NhapChuoiKiTuChu(string str); // Hàm nhập dữ liệu chỉ nhận các kí tự chữ và không có số
int ChuoiSangSo(string str); // Hàm chuyển chuỗi string sang số nguyên int
bool ChuoiSangBool(string str); // Hàm chuyển chuỗi string sang bool
string BoolSangChuoi(bool b); // Hàm chuyển bool sang string
int NhapSoNguyen(string str); // Hàm nhập dữ liệu chỉ nhận các kí tự số
void InChu(string word, bool invientren = true, bool invienduoi = true); // Hàm in ra khung chữ
bool CheckChuoiKiTu(string str);
bool CheckChuoiSo(string str);
bool CheckKhoangTrang(string str);
#endif // !_HAMHOTRO_H