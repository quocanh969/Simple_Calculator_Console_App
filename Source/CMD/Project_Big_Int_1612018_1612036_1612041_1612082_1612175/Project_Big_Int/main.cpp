#include"Library.h"

void main(int argc, char *argv[])
{
	string temp;
	fstream FileIn, FileOut;

	temp = argv[1];
	FileIn.open(temp, ios_base::in);
	temp = argv[2];
	FileOut.open(temp, ios_base::out);

	string s;
	char **token;
	token = new char*[5];

	int k = 0;
	int HeSo;

	BigInt kq;
	int kt = 0;// Kiểm tra xem có phải dòng đầu tiên bị đọc không??

	while (!FileIn.eof())// Đọc cho đến cuối file
	{
		if (kt == 0) kt = 1;
		else FileOut << endl;

		getline(FileIn, s);

		// Tiến hành xác nhận xem có tất cả bao nhiêu tham số trên một dòng thông qua hàm strtok nhằm tách chuỗi bởi kí tự " "
		// Nếu là 4 tham số thì đây là các phép toán +,-,*,/,AND,OR,XOR,<<,>>
		// Nếu là 3 tham số mà có tồn tại dấu ! thì đây là phép NOT
		// Trong trường hợp còn lại thì đây là phép đổi hệ số
		token[k] = strtok((char*)s.c_str(), " ");
		k++;
		while (token[k - 1] != NULL)
		{
			token[k] = strtok(NULL, " ");
			k++;
		}
		k--;

		HeSo = atoi(token[0]);// Khi nào đến phép đổi thì nhớ đổi hệ số nhé =)))

							  // Kiểm tra xem hệ số nhập có đúng không
		if (HeSo != 2 && HeSo != 10 && HeSo != 16)
		{
			FileOut << "ERROR !!! Khong ton tai he so " << HeSo << ", bo mot dong du lieu";
			goto flag;
		}


		if (k == 4)// Thực hiện phép cộng, trừ, nhân, chia, AND, OR, XOR, phép dịch bit
		{
			if (KiemTraHeSo(HeSo, token[1]) == false)
			{
				FileOut << "Gia tri nhap " << token[1] << " khong dung voi he so " << HeSo << ", Bo mot dong du lieu";
				goto flag;
			}

			if (strcmp(token[2], "<<") == 0 || strcmp(token[2], ">>") == 0)
			{
				BigInt a;
				int b = atoi(token[3]);// Xác định số bit cần dịch
				if (HeSo == 2)
				{
					a = BinToDec(CharToBool(token[1]));
				}
				else if (HeSo == 10)
				{
					a = ScanfBigInt(token[1]);
				}
				else
				{
					a = HexToDec(token[1]);
				}


				if (strcmp(token[2], ">>") == 0) kq = a >> b;
				else kq = a << b;
			}
			else
			{
				if (KiemTraHeSo(HeSo, token[3]) == false)
				{
					FileOut << "Gia tri nhap " << token[3] << " khong dung voi he so " << HeSo << ", Bo mot dong du lieu";
					goto flag;
				}
				kq = PhepToan(token[1], token[3], token[2], HeSo);
			}
		}
		else if (k == 3)
		{
			if (strcmp(token[1], "!") == 0 || strcmp(token[2], "!") == 0)
			{
				if (KiemTraHeSo(HeSo, token[1]) == false && KiemTraHeSo(HeSo, token[2]) == false)
				{
					FileOut << "Gia tri nhap ko dung voi he so" << endl;
					goto flag;
				}

				BigInt a;
				if (HeSo == 2)
				{
					a = BinToDec(CharToBool(token[1]));
				}
				else if (HeSo == 10)
				{
					a = ScanfBigInt(token[1]);
				}
				else
				{
					a = HexToDec(token[1]);
				}

				kq = !a;
			}
			else
			{
				if (KiemTraHeSo(HeSo, token[2]) == false)
				{
					FileOut << "Gia tri nhap " << token[2] << " khong dung voi he so " << HeSo << ", Bo mot dong du lieu";
					goto flag;
				}

				int HeSo2 = atoi(token[1]);
				if (HeSo == 2 && HeSo2 == 10)
				{
					FileOut << PrintBigInt(BinToDec(CharToBool(token[2])));
				}
				else if (HeSo == 2 && HeSo2 == 16)
				{
					string val = DecToHex(BinToDec(CharToBool(token[2])));
					FileOut << val;
				}
				else if (HeSo == 10 && HeSo2 == 2)
				{
					FileOut << BoolToChar(DecToBin(ScanfBigInt(token[2])));
				}
				else if (HeSo == 10 && HeSo2 == 16)
				{
					string val = DecToHex(ScanfBigInt(token[2]));
					FileOut << val;
				}
				else if (HeSo == 16 && HeSo2 == 10)
				{
					FileOut << PrintBigInt(HexToDec(token[2]));
				}
				else
				{
					FileOut << BoolToChar(DecToBin(HexToDec(token[2])));
				}
				goto flag;
			}
		}
		else
		{
			FileOut << "ERROR !! Dong du lieu nay khong dung cu phap";
			goto flag;
		}

		// Lúc này không cần xét trường hợp không có hệ số phù hợp vì nếu có hệ số ko phù hợp thì đã phát hiện ở trên
		if (HeSo == 2)
		{
			FileOut << BoolToChar(DecToBin(kq));
		}
		else if (HeSo == 10)
		{
			FileOut << PrintBigInt(kq);
		}
		else
		{
			FileOut << DecToHex(kq);
		}
	flag:;
		k = 0;// Khởi gán k = 0
	}

	FileIn.close();
	FileOut.close();
	system("pause");
}