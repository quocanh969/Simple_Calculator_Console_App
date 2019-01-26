#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class BigInt {//Quyết định xây dựng theo class để có thể viết được các hàm operator
public:
	unsigned int dat[4] = { 0,0,0,0 };//Biến ban đầu được tạo ra toàn là bit 0 hết

	//Lâm Tề Hào các phép toán +, -, *, /
	BigInt operator +(BigInt b);
	BigInt operator -(BigInt b);
	BigInt operator *(BigInt b);
	BigInt operator /(BigInt b);

	//Nguyễn Hồng Đăng các phép so sánh AND, OR, XOR, NOT
	BigInt operator &(BigInt b);
	BigInt operator |(BigInt b);
	BigInt operator ^(BigInt b);
	BigInt operator !();

	//Phạm Phú Quốc Bảo các phép dịch bit
	BigInt operator <<(int a);
	BigInt operator >>(int a);
};

//----------
char Chia2(string &x);
void Binary(string x, char kq[]);
BigInt ScanfBigInt(string value);

BigInt GiaiQuyetSoAm(BigInt a);
int len(char a[]);
void DaoChuoi(char a[]);
void Nhan2(char a[]);
void Cong1(char a[]);
string PrintBigInt(BigInt a);

BigInt PhepToan(char* v1, char* v2, char* ope, int HeSo);
//----------
bool* CharToBool(char* x);
string BoolToChar(bool* x);
bool * DecToBin(BigInt x);
BigInt BinToDec(bool *bit);
char *BinToHex(bool *bit);
char *DecToHex(BigInt x);
BigInt HexToDec(char *x);

//---------
string Cong(string a, string b);
string Tru(string a, string b);
string Nhan(string a, string b);
string Chia(string a, string b);
string UIToS(unsigned int a);
int CharToNum(char a);
char NumToChar(int a);
void AddZero(string &a);
void XoaKiTuDau(string &a);
string Cong(string a, string b);
string Tru(string a, string b);
void AddLastZero(string &a);
string Nhan(string a, string b);
string Chia(string a, string b);
