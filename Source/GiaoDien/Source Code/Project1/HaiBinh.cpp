#include "ThuVien.h"
const unsigned int Max = INT_MAX * 2 + 1;

//Thư viện mini của 4 hàm, có thể hàm này dùng hàm kia...
string Cong(string a, string b);
string Tru(string a, string b);
string Nhan(string a, string b);
string Chia(string a, string b);


//Hàm đổi từ 1 số unsigned int thành 1 chuỗi string
//Input: một số dạng unsigned int
//Output: giá trị của số dưới dạng chuỗi kí tự
string UIToS(unsigned int a)
{
	string kq = "";
	while (a > 0)
	{
		char b = a % 10;
		b = b + '0';
		kq = b + kq;
		a /= 10;
	}
	return kq;
}


//Hàm đổi 1 kí tự sang số
//Input: 1 kí tự duy nhất có dạng số
//Output: Giá trị của kí tự đó dạng số
int CharToNum(char a)
{
	return a - '0';
}


//Hàm đổi 1 số ra kí tự dạng char của số đó
//Input: Một số từ 0 tới 9
//Output: Kí tự của số đó dạng char
char NumToChar(int a)
{
	return a + '0';
}


//Hàm thêm số 0 vào đầu
//Input: Chuỗi cần thêm số 0 vào đầu
//Output: Chuỗi sau khi được thêm số 0 ở đầu
void AddZero(string &a)
{
	a = "0" + a;
}


//Hàm xóa kí tự đầu tiên của chuỗi số
//Input: Chuỗi số
//Output: Chuỗi số với kí tự đầu đã bị xóa
void XoaKiTuDau(string &a)
{
	int len = size(a);
	for (int i = 0; i<len; i++)
	{
		a[i] = a[i + 1];
	}
	a.resize(len - 1);
}


//Hàm thực hiện phép cộng 2 số dạng chuỗi
//Input: 2 chuỗi số
//Output: Kết quả của phép cộng 2 chuỗi số
string Cong(string a, string b)
{
	//Xử lý vào đầu vào có số âm
	int flag = 0;
	if (a[0] == '-'&&b[0] != '-')	//Nếu số a âm còn số b dương thì sẽ xóa hết dấu và thực hiện phép toán b-a (dương - dương)
	{
		XoaKiTuDau(a);
		return Tru(b, a);
	}
	else if (b[0] == '-'&&a[0] != '-')	//Nếu số a dương còn số b âm thì sẽ xóa hết dấu và thực hiện phép toán a-b (dương - dương)
	{
		XoaKiTuDau(b);
		return Tru(a, b);
	}
	else if (a[0] == '-'&&b[0] == '-')	//Nếu 2 số cùng âm thì sẽ xóa hết dấu và thực hiện phép toán a+b rồi thêm số trừ vào đầu (dương + dương)
	{
		flag = 1;
		XoaKiTuDau(a);
		XoaKiTuDau(b);
	}
	//Kết thúc phần xử lý đầu vào có số âm, lúc này 2 chuỗi a,b đều không còn dấu nữa

	string c;
	int len1 = size(a);
	int len2 = size(b);
	int len = 0;	//Đây sẽ là độ dài của chuỗi kết quả

					//Thêm số 0 vào đầu chuỗi ngắn hơn để 2 chuỗi có độ dài bằng nhau
	if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
		{
			AddZero(b);
		}
		len = len1;
	}
	else
	{
		for (int i = 0; i < len2 - len1; i++)
		{
			AddZero(a);
		}
		len = len2;
	}

	c.resize(len);
	int nho = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		//Thực hiện phép cộng như hồi học Tiểu Học
		int avalue = CharToNum(a[i]);
		int bvalue = CharToNum(b[i]);
		int cvalue = avalue + bvalue + nho;
		if (cvalue >= 10) nho = 1;
		else nho = 0;
		c[i] = NumToChar(cvalue % 10);
	}
	if (nho != 0)	//Nếu khi cộng hết tất cả lại mà biến nhớ còn khác 0 thì phải thêm số 1 ở đầu
	{
		AddZero(c);
		c[0] = '1';
	}
	if (flag == 1)	//Trường hợp cộng 2 số âm đã được đánh dấu ở trên
	{
		AddZero(c);
		c[0] = '-';
	}
	return c;
}


//Hàm thực hiện phép trừ 2 số dạng chuỗi
//Input: 2 chuỗi số
//Output: Kết quả phép trừ của 2 số đó
string Tru(string a, string b)
{
	//Xử lý với đầu vào có số âm
	if (a[0] == '-'&&b[0] != '-')	//Nếu a âm và b dương thì sẽ thêm dấu trừ cho b rồi thực hiện phép a+b (âm + âm)
	{
		AddZero(b);
		b[0] = '-';
		return Cong(a, b);
	}
	else if (a[0] != '-'&&b[0] == '-')	//Nếu a dương b âm thì sẽ xóa dấu trừ cho b rồi thực hiện phép a+b (dương + dương)
	{
		XoaKiTuDau(b);
		return Cong(a, b);
	}
	else if (a[0] == '-'&&b[0] == '-')	//Nếu a âm và b âm thì sẽ xóa dấu trừ cho a,b và thực hiện phép b-a (dương - dương)
	{
		XoaKiTuDau(a);
		XoaKiTuDau(b);
		return Tru(b, a);
	}


	string c;
	int len1 = size(a);
	int len2 = size(b);
	int len = 0; //Đây sẽ là độ dài của chuỗi kết quả

				 //Thêm số 0 vào đầu chuỗi ngắn hơn để 2 chuỗi có độ dài bằng nhau
	if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
		{
			AddZero(b);
		}
		len = len1;
	}
	else
	{
		for (int i = 0; i < len2 - len1; i++)
		{
			AddZero(a);
		}
		len = len2;
	}

	if (a.compare(b) < 0)		//Nếu a < b
	{
		//Thì ta sẽ thực hiện phép b - a thay thế cho a - b rồi thêm dấu trừ ở đầu kết quả
		c = Tru(b, a);
		AddZero(c);
		c[0] = '-';
		return c;
	}

	c.resize(len);
	int  muon = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		//Thực hiện phép trừ như hồi học Tiểu Học
		int avalue = CharToNum(a[i]);
		int bvalue = CharToNum(b[i]);
		int cvalue = avalue - bvalue - muon;
		if (cvalue < 0)
		{
			muon = 1;
			cvalue += 10;
		}
		else muon = 0;
		c[i] = NumToChar(cvalue);
	}
	for (int i = 0; c[0] == '0';)
	{
		//Nếu kết quả trả về có nhiều số 0 ở đầu thì phải xóa bớt số 0
		XoaKiTuDau(c);
	}
	return c;
}


//Hàm thêm số 0 vào cuối chuỗi số
//Input: Chuỗi số a
//Output: Chuỗi số a sau khi được thêm số 0 vào cuối
void AddLastZero(string &a)
{
	a = a + "0";
}


//Hàm thực hiện phép nhân 2 chuỗi số
//Input: 2 chuỗi số
//Output: Kết quả của phép nhân 2 chuỗi số
string Nhan(string a, string b)
{
	//Phần xử lý nếu đầu vào có dấu trừ
	int flag = 0;
	if (a[0] == '-'&&b[0] != '-')
	{
		flag = 1;
		XoaKiTuDau(a);
	}
	else if (a[0] != '-'&&b[0] == '-')
	{
		flag = 1;
		XoaKiTuDau(b);
	}
	else if (a[0] == '-'&&b[0] == '-')
	{
		XoaKiTuDau(a);
		XoaKiTuDau(b);
	}

	string c;
	int len1 = size(a);
	int len2 = size(b);
	string *h;
	h = new string[len2];	//Mảng chuỗi h dùng để lưu các dãy phép nhân rồi sau đó cộng lại
	for (int i = 0; i < len2; i++)
	{
		h[i].resize(len1);
		//Thực hiện phép nhân như hồi học tiểu học, nhân từng thành phần rồi cộng chúng lại
		int nho = 0;
		int bvalue = CharToNum(b[i]);
		for (int j = len1 - 1; j >= 0; j--)
		{
			int avalue = CharToNum(a[j]);
			int hvalue = avalue * bvalue + nho;
			if (hvalue >= 10)
			{
				nho = hvalue / 10;
				hvalue = hvalue % 10;
			}
			else nho = 0;
			h[i][j] = NumToChar(hvalue);
		}
		if (nho != 0)
		{
			AddZero(h[i]);
			h[i][0] = NumToChar(nho);
		}
	}
	c = h[0];

	for (int i = 1; i < len2; i++)
	{
		AddLastZero(c);
		c = Cong(c, h[i]);
	}
	if (flag == 1)
	{
		AddZero(c);
		c[0] = '-';
	}
	delete[] h;
	return c;
}


//Hàm thực hiện phép chia 2 chuỗi số
//Input: 2 chuỗi số 
//Output: Kết quả của phép chia 2 chuỗi số vừa nhập
string Chia(string a, string b)
{
	string c = "";
	//Xử lý trường hợp số chia = 0...
	if (b == "0")
	{
		c = "-";
		return c;
	}
	//Xử lý với trường hợp đầu vào có số âm
	int flag = 0;
	if (a[0] == '-'&&b[0] != '-')
	{
		flag = 1;
		XoaKiTuDau(a);
	}
	else if (a[0] != '-'&&b[0] == '-')
	{
		flag = 1;
		XoaKiTuDau(b);
	}
	else if (a[0] == '-'&&b[0] == '-')
	{
		XoaKiTuDau(a);
		XoaKiTuDau(b);
	}
	//Kết thúc phần xử lý đầu vào là số âm, 

	if (size(a) < size(b) || (size(a) == size(b) && a.compare(b) < 0))	//Nếu số bị chia nhỏ hơn số chia thì kết quả là 0
	{
		c = "0";
		return c;
	}

	//Bắt đầu xử lý phép chia, thực hiện chia như hồi học Tiểu Học
	//Lúc này số bị chia và số chia đều là số dương và số bị chia > số chia nên kết quả >=1
	int k = 0;
	int bienchay = 0;
	string temp;	//temp là chuỗi lưu tạm thời giá trị của a cho đến khi temp >= b thì mới bắt đầu thực hiện phép chia
	temp.resize(k + 1);
	temp[k++] = a[bienchay++];	//temp[0] = a[0]	k=1, bienchay=1
	while (size(temp) < size(b) || (size(temp) == size(b) && temp.compare(b) < 0))	// Khi mà temp vẫn còn < b thì tiếp tục lấy thêm số đằng sao, khi hồi Tiểu học
	{
		temp.resize(k + 1);
		temp[k++] = a[bienchay++];
	}
	c = "1";	//giờ mới xác định là temp/b có kết quả là bao nhiêu, ban đầu cho là 1
	string sodu = Tru(temp, b);	//xem số dư là bao nhiêu, nếu số dư âm thì ngừng lại và lùi c 1 đơn vị, còn nếu dương thì tiếp tục tăng c lên
	while (sodu[0] != '-')
	{
		c[0]++;
		sodu = Tru(sodu, b);
	}
	//Lúc này là số dư đã âm, thì chúng ta trả lại giá trị trước đó
	c[0]--;
	sodu = Cong(sodu, b);
	int lenc = 1; c.resize(lenc);	//Độ dài của chuỗi kết quả hiện tại là 1
	int lena = size(a);
	k = size(sodu);	//Độ dài của chuỗi số dư gán vào k, để từ đó tiếp tục tăng k cho đúng


	while (bienchay < lena)	//Khi mà số bị chia vẫn còn các chữ số để hạ xuống
	{
		//Hạ thêm 1 chữ số xuống và thực hiện phép chia
		sodu.resize(k + 1);
		sodu[k++] = a[bienchay++];
		temp = sodu;	//Gắn temp = sodu để sau này cần thiết thì trả sodu về giá trị ban đầu
		string kq = "1";
		//Kiểm tra giá trị như trên
		sodu = Tru(temp, b);
		while (sodu[0] != '-'&&kq[0] <= '9')
		{
			kq[0]++;
			sodu = Tru(sodu, b);
		}
		kq[0]--;
		sodu = Cong(sodu, b);
		c.resize(lenc + 1);
		c[lenc++] = kq[0];
		if (kq[0] != '0')
		{
			//Nếu kết quả của phép chia này khác 0 thì gán k = độ dài của số dư hiện tại để lần sau tiếp tục thực hiện
			k = size(sodu);
		}
		else
		{
			sodu = temp;
		}
	}

	if (flag == 1)
	{
		//Thêm dấu trừ dựa vào flag ban đầu, nếu âm chia dương hoặc dương chia âm thì flag = 1 và phải thêm dấu trừ
		AddZero(c);
		c[0] = '-';
	}
	return c;
}



//Phương thức cộng của số nguyên lớn BigInt
//Input: 2 số nguyên lớn BigInt
//Output: kết quả của phép cộng 2 số nguyên lớn
BigInt BigInt::operator+(BigInt b)
{
	string str1, str2, kq;
	str1 = PrintBigInt(*this);
	str2 = PrintBigInt(b);
	kq = Cong(str1, str2);
	return ScanfBigInt(kq);
}


//Phương thức trừ của số nguyên lớn BigInt
//Input: 2 số nguyên lớn BigInt
//Output: kết quả của phép trừ 2 số nguyên lớn
BigInt BigInt::operator-(BigInt b)
{
	string str1, str2, kq;
	str1 = PrintBigInt(*this);
	str2 = PrintBigInt(b);
	kq = Tru(str1, str2);
	return ScanfBigInt(kq);
}


//Phương thức nhân của số nguyên lớn BigInt
//Input: 2 số nguyên lớn BigInt
//Output: kết quả của phép nhân 2 số nguyên lớn
BigInt BigInt::operator*(BigInt b)
{
	string str1, str2, kq;
	str1 = PrintBigInt(*this);
	str2 = PrintBigInt(b);
	kq = Nhan(str1, str2);
	return ScanfBigInt(kq);
}

//Phương thức chia của số nguyên lớn BigInt
//Input: 2 số nguyên lớn BigInt
//Output: kết quả của phép chia 2 số nguyên lớn
BigInt BigInt::operator/(BigInt b)
{
	string str1, str2, kq;
	str1 = PrintBigInt(*this);
	str2 = PrintBigInt(b);
	kq = Chia(str1, str2);
	return ScanfBigInt(kq);
}