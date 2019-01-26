#include"ThuVien.h"
//------------
// Hàm dùng để đổi chuỗi nhập vào, chuỗi nhập vào là char*, đổi lại vào hệ thống là bool*
bool* CharToBool(char * x)
{
	int l = len(x);
	if (l > 128)
	{
		cout << "ERROR!!! Du lieu vua nhap bi tran man hinh";
		system("pause");
		exit(1);
	}
	int j = 127;
	bool * kq = new bool[128];
	for (int i = l - 1; i >= 0; i--, j--)
	{
		if (x[i] == '1')
		{
			kq[j] = true;
		}
		else if ( x[i] == '0')
		{
			kq[j] = false;
		}
		else
		{
			cout << "Error";
			system("pause");
			exit(1);
		}
	}
	while (j >= 0)
	{
		kq[j] = false;
		j--;
	}
	return kq;
}

// Hàm dùng để xuất ra giao diện, chuỗi đầu vào là bool*, đổi lại chuỗi để xuất ra màn hình là char*
string BoolToChar(bool* x)
{// chuỗi bool ở đây có 128 phần tử, ứng với số bit tối đa của một biến BigInt
	char kq[128];
	string res;
	for (int i = 127; i >= 0; i--)
	{
		if (x[127 - i] == true)kq[i] = '1';
		else kq[i] = '0';
	}
	int j = 128;
	while (kq[j - 1] == '0')
	{
		j--;
	}
	kq[j] = 0;
	DaoChuoi(kq);
	res = kq;
	return res;
}

bool * DecToBin(BigInt x)
{
	bool* bit0; bit0 = new bool[32];
	bool* bit1; bit1 = new bool[32];
	bool* bit2; bit2 = new bool[32];
	bool* bit3; bit3 = new bool[32];

	for (int i = 0; i < 32; i++)
	{
		bit0[i] = false;
		bit1[i] = false;
		bit2[i] = false;
		bit3[i] = false;
	}

	if (x.dat[0] != 0)
	{
		bool revBit0[32];
		int count0 = 0;
		int temp0 = x.dat[0];
		for (int i = 0; temp0 != 0; i++)
		{
			if (temp0 % 2 == 0)
				revBit0[i] = false;
			else
				revBit0[i] = true;
			temp0 = temp0 / 2;
			count0++;
		}
		for (int i = 0, j = 31; i < count0; i++)
		{
			bit0[j] = revBit0[i];
			j--;
		}
	}

	if (x.dat[1] != 0)
	{
		bool revBit1[32];
		int count1 = 0;
		int temp1 = x.dat[1];
		for (int i = 0; temp1 != 0; i++)
		{
			if (temp1 % 2 == 0)
				revBit1[i] = false;
			else
				revBit1[i] = true;
			temp1 = temp1 / 2;
			count1++;
		}
		for (int i = 0, j = 31; i < count1; i++)
		{
			bit1[j] = revBit1[i];
			j--;
		}
	}

	if (x.dat[2] != 0)
	{
		bool revBit2[32];
		int count2 = 0;
		int temp2 = x.dat[2];
		for (int i = 0; temp2 != 0; i++)
		{
			if (temp2 % 2 == 0)
				revBit2[i] = false;
			else
				revBit2[i] = true;
			temp2 = temp2 / 2;
			count2++;
		}
		for (int i = 0, j = 31; i < count2; i++)
		{
			bit2[j] = revBit2[i];
			j--;
		}
	}

	if (x.dat[3] != 0)
	{
		bool revBit3[32];
		int count3 = 0;
		int temp3 = x.dat[3];
		for (int i = 0; temp3 != 0; i++)
		{
			if (temp3 % 2 == 0)
				revBit3[i] = false;
			else
				revBit3[i] = true;
			temp3 = temp3 / 2;
			count3++;
		}
		for (int i = 0, j = 31; i < count3; i++)
		{
			bit3[j] = revBit3[i];
			j--;
		}
	}

	bool* result;
	result = new bool[128];
	for (int i = 0, j = 0; i < 32; i++, j++)
		result[i] = bit0[j];
	for (int i = 32, j = 0; i < 64; i++, j++)
		result[i] = bit1[j];
	for (int i = 64, j = 0; i < 96; i++, j++)
		result[i] = bit2[j];
	for (int i = 96, j = 0; i < 128; i++, j++)
		result[i] = bit3[j];
	return result;
}

BigInt BinToDec(bool *bit)
{
	BigInt result;
	int n = 1;
	for (int i = 31; i >= 0; i--, n = n * 2)
	{
		if (bit[i] == true)
			result.dat[0] = result.dat[0] + n;
		if (bit[i + 32] == true)
			result.dat[1] = result.dat[1] + n;
		if (bit[i + 64] == true)
			result.dat[2] = result.dat[2] + n;
		if (bit[i + 96] == true)
			result.dat[3] = result.dat[3] + n;
	}
	return result;
}

char *BinToHex(bool *bit)
{
	char* result;
	result = new char[33];
	bool temp[4];
	int dec;
	int n;
	int traverse = 0;
	for (int i = 0; i < 128; i++)
	{
		dec = 0;
		n = 1;
		temp[0] = bit[i];
		temp[1] = bit[i + 1];
		temp[2] = bit[i + 2];
		temp[3] = bit[i + 3];
		for (int j = 3; j >= 0; j--, n = n * 2)
		{
			if (temp[j] == true)
				dec = dec + n;
		}
		switch (dec)
		{
		case 0: { result[traverse] = '0'; break; }
		case 1: { result[traverse] = '1'; break; }
		case 2: { result[traverse] = '2'; break; }
		case 3: { result[traverse] = '3'; break; }
		case 4: { result[traverse] = '4'; break; }
		case 5: { result[traverse] = '5'; break; }
		case 6: { result[traverse] = '6'; break; }
		case 7: { result[traverse] = '7'; break; }
		case 8: { result[traverse] = '8'; break; }
		case 9: { result[traverse] = '9'; break; }
		case 10: { result[traverse] = 'A'; break; }
		case 11: { result[traverse] = 'B'; break; }
		case 12: { result[traverse] = 'C'; break; }
		case 13: { result[traverse] = 'D'; break; }
		case 14: { result[traverse] = 'E'; break; }
		case 15: { result[traverse] = 'F'; break; }
		}
		traverse++;
	}
	result[32] = '\0';
	return result;
}

char *DecToHex(BigInt x)
{
	char *result;
	result = new char[33];

	unsigned int temp0 = x.dat[0];
	unsigned int temp1 = x.dat[1];
	unsigned int temp2 = x.dat[2];
	unsigned int temp3 = x.dat[3];
	int traverse = 0;
	int rem;
	if (x.dat[3] != 0)
	{
		int count3 = 0;
		for (int i = 0; temp3 != 0; i++)
		{
			rem = temp3 % 16;
			switch (rem)
			{
			case 0: { result[traverse] = '0'; break; }
			case 1: { result[traverse] = '1'; break; }
			case 2: { result[traverse] = '2'; break; }
			case 3: { result[traverse] = '3'; break; }
			case 4: { result[traverse] = '4'; break; }
			case 5: { result[traverse] = '5'; break; }
			case 6: { result[traverse] = '6'; break; }
			case 7: { result[traverse] = '7'; break; }
			case 8: { result[traverse] = '8'; break; }
			case 9: { result[traverse] = '9'; break; }
			case 10: { result[traverse] = 'A'; break; }
			case 11: { result[traverse] = 'B'; break; }
			case 12: { result[traverse] = 'C'; break; }
			case 13: { result[traverse] = 'D'; break; }
			case 14: { result[traverse] = 'E'; break; }
			case 15: { result[traverse] = 'F'; break; }
			}
			temp3 = temp3 / 16;
			count3++;
			traverse++;
		}
	}
	if (x.dat[2] != 0)
	{
		int count2 = 0;
		for (int i = 0; temp2 != 0; i++)
		{
			rem = temp2 % 16;
			switch (rem)
			{
			case 0: { result[traverse] = '0'; break; }
			case 1: { result[traverse] = '1'; break; }
			case 2: { result[traverse] = '2'; break; }
			case 3: { result[traverse] = '3'; break; }
			case 4: { result[traverse] = '4'; break; }
			case 5: { result[traverse] = '5'; break; }
			case 6: { result[traverse] = '6'; break; }
			case 7: { result[traverse] = '7'; break; }
			case 8: { result[traverse] = '8'; break; }
			case 9: { result[traverse] = '9'; break; }
			case 10: { result[traverse] = 'A'; break; }
			case 11: { result[traverse] = 'B'; break; }
			case 12: { result[traverse] = 'C'; break; }
			case 13: { result[traverse] = 'D'; break; }
			case 14: { result[traverse] = 'E'; break; }
			case 15: { result[traverse] = 'F'; break; }
			}
			temp2 = temp2 / 16;
			count2++;
			traverse++;
		}
	}
	if (x.dat[1] != 0)
	{
		int count1 = 0;
		for (int i = 0; temp1 != 0; i++)
		{
			rem = temp1 % 16;
			switch (rem)
			{
			case 0: { result[traverse] = '0'; break; }
			case 1: { result[traverse] = '1'; break; }
			case 2: { result[traverse] = '2'; break; }
			case 3: { result[traverse] = '3'; break; }
			case 4: { result[traverse] = '4'; break; }
			case 5: { result[traverse] = '5'; break; }
			case 6: { result[traverse] = '6'; break; }
			case 7: { result[traverse] = '7'; break; }
			case 8: { result[traverse] = '8'; break; }
			case 9: { result[traverse] = '9'; break; }
			case 10: { result[traverse] = 'A'; break; }
			case 11: { result[traverse] = 'B'; break; }
			case 12: { result[traverse] = 'C'; break; }
			case 13: { result[traverse] = 'D'; break; }
			case 14: { result[traverse] = 'E'; break; }
			case 15: { result[traverse] = 'F'; break; }
			}
			temp1 = temp1 / 16;
			count1++;
			traverse++;
		}
	}
	if (x.dat[0] != 0)
	{
		int count0 = 0;
		for (int i = 0; temp0 != 0; i++)
		{
			rem = temp0 % 16;
			switch (rem)
			{
			case 0: { result[traverse] = '0'; break; }
			case 1: { result[traverse] = '1'; break; }
			case 2: { result[traverse] = '2'; break; }
			case 3: { result[traverse] = '3'; break; }
			case 4: { result[traverse] = '4'; break; }
			case 5: { result[traverse] = '5'; break; }
			case 6: { result[traverse] = '6'; break; }
			case 7: { result[traverse] = '7'; break; }
			case 8: { result[traverse] = '8'; break; }
			case 9: { result[traverse] = '9'; break; }
			case 10: { result[traverse] = 'A'; break; }
			case 11: { result[traverse] = 'B'; break; }
			case 12: { result[traverse] = 'C'; break; }
			case 13: { result[traverse] = 'D'; break; }
			case 14: { result[traverse] = 'E'; break; }
			case 15: { result[traverse] = 'F'; break; }
			}
			temp0 = temp0 / 16;
			count0++;
			traverse++;
		}
	}
	result[traverse] = '\0';
	DaoChuoi(result);
	return result;
}

BigInt HexToDec(char *x)
{
	BigInt kq;
	int l = len(x);

	if (l > 32)
	{
		cout << "ERROR !!! Du lieu nhap vao bi tran";
		system("pause");
		exit(1);
	}

	int n = 1, j = 3, d;
	// n là biến xác định vị trí mỗi khi công thêm số mới vào kq
	// j  là biến đếm giúp xác định dat thứ mấy của kq đang được thao tác
	// d là biến đánh dấu chuyển về giá trị thực của biến char '1', '2' , ...
	for (int i = l - 1; i >= 0; i-- , n = n * 16)
	{
		if (n == 0) n = 1;// Đặt điều kiện quay lại

		if (x[i] >= 48 && x[i] <= 57)d = 48;
		else if (x[i] >= 65 && x[i] <= 70) d = 55;
		else
		{
			cout << "ERROR !! Ma Hex khong phu hop";
			system("pause");
			exit(1);
		}

		kq.dat[j] += n*(x[i] - d);

		if (n >= 268435456)
		{
			n = 0;
			j--;
		}
	}
	return kq;
}
