#include"Library.h"

// Nhập BigInt ---------------

// Hàm lấy chuỗi số chia 2
// Input: là một con trỏ chuỗi, mọi thao tác thay đổi trong hàm sẽ ảnh hưởng trực tiếp đến vùng nhớ của chuỗi
// Output: trả về chuỗi string sau khi đã bị thay đổi, đồng thời là kí tự "1" hoặc "0" để xác định bit mà truyền vào biến BigInt
char Chia2(string &x)
{// Hàm chia 2
 //input: chuỗi số nhập vào dưới dạng tham số
 //output: số dư là 0/1 để điền vào dãy bit; đồng thời chuỗi tham số cũng bị thay đổi thành chuỗi thương sau phép chia
	int i = 0, j = 0, l = x.length();
	int n = 0;
	char q = 0;
	if (x[0] == '1')
	{
		i++;
		n = 1;
	}
	while (x[i] != '\0')
		//Ở các giá trị sau, chiều dài của chuỗi string không đổi, do dùng chuỗi string nhập vô ban đầu
		//nên đánh dấu bằng kí tự '\0' ở cuối chuỗi số để cho thấy sự thay đổi chiều dài sau mỗi phép chia
	{
		q = (n * 10 + x[i] - 48) / 2 + 48;
		n = x[i] % 2;
		x[j] = q;
		j++;
		i++;
	}
	x[j] = '\0';
	return n + 48;
}

// Hàm biến đổi chuỗi số nhập thành chuỗi char[] là dãy bit khi đổi chuỗi string từ thập phân sang nhị phân
// Input: chuỗi string thập phân ban đầu
// Output: chuỗi char là dãy bit sau khi đổi choit string sang nhị phân
void Binary(string x, char kq[])
{
	int kt = 0;//kiểm tra phải số dương không: dương - 0, âm - 1
	if (x[0] == '-')
	{
		x.erase(0, 1);
		kt = 1;
	}
	int i = 127;
	while (x[0] != '\0')
	{
		kq[i] = Chia2(x);
		i--;
	}
	for (i; i >= 0; i--)
	{
		kq[i] = '0';
	}

	//Trường hợp số âm
	if (kt == 1)
	{
		//Chuyển thành số bù 2: Tìm đến vị trí bit 1 đầu tiên từ phải sáng trái, từ vị trí đó đến sát cùng bên phải thì ta đảo bit hết
		int j = 127;
		while (kq[j] != '1')j--;
		j--;
		for (j; j >= 0; j--)
		{
			if (kq[j] == '1')kq[j] = '0';
			else kq[j] = '1';
		}
	}

}

// Hàm lưu giá trị nhập vào biến BigInt
// Input: chuỗi string là chuỗi được nhập vào từ bàn phím, từ đó mới có thể lưu vào BigInt
// Output: biến BigInt được lưu giá trị từ chuỗi nhập vào
BigInt ScanfBigInt(string value)
{
	BigInt a;
	if (value == "0")
	{
		return a;
	}
	// Xác định chiều dài của số 2^128 - 1 là 38 chữ số, nếu trong trường hợp số âm thì chuỗi dài tối đa 39 chữ số
	if ((value[0] == '-'&&value.length() > 39) || value.length() > 38)
	{
		cout << "Vuot qua gioi han nhap";
		exit(1);
	}


	char kq[129];
	Binary(value, kq);//Biến đổi chuỗi vừa nhập thành chuỗi nhị phân
	kq[128] = 0;
	//Gán giá trị của phần tử cuối của xâu biến đổi
	//vì là ta thao tác trực tiếp trên từng phần tử nên máy sẽ không tự động gán phần tử cuối là '\0' để kết thúc chuỗi

	unsigned int *temp = &a.dat[0];//biến con trỏ để trỏ đến phần tử thử mấy trong struct BigInt tùy vào vị trí của bit

	for (int i = 0; i < 128; i++)
	{
		switch (i)
		{
		case 0:
		{//Ví trị bit 0 là của phần tử thứ nhất trong mảng 4 của struct BigInt
			temp = &a.dat[0];
			break;
		}
		case 32:
		{//Ví trị bit 32 là của phần tử thứ hai trong mảng 4 của struct BigInt
			temp = &a.dat[1];
			break;
		}
		case 64:
		{//Ví trị bit 64 là của phần tử thứ ba trong mảng 4 của struct BigInt
			temp = &a.dat[2];
			break;
		}
		case 96:
		{//Ví trị bit 96 là của phần tử thứ tư trong mảng 4 của struct BigInt
			temp = &a.dat[3];
			break;
		}
		}

		*temp = *temp << 1;
		if (kq[i] == '1')*temp = *temp | 1;
	}
	return a;
}

// Xuất BigInt ---------------

// Hàm giải quyết số âm được gọi khi giá trị BigInt được lưu số âm, nhầm biến đổi thành số bù 2
// Input: Biến BigInt với 4 giá trị dữ liệu dat[0], dat[1], dat[2], dat[3]
// Output: 4 giá trị dat[0], dat[1], dat[2], dat[3] của BigInt bị thay đổi theo giá trị của các dãy 32 bit sau khi đổi thành số bù 2
BigInt GiaiQuyetSoAm(BigInt a)
{//Hàm chuyển bit của số âm dạng bù 2 thành dang không dấu, bằng cách làm ngược so với bước chuyển thành bù ở hàm Binary
	int kt = 0;//biến kiểm tra xem đã tìm được bit 1 đầu tiên từ phải sang trái chưa
	unsigned int n;
	for (int i = 3; i >= 0; i--)
	{
		n = 1;//biến n dùng để xác định vị trí có số 1 trong dãy bit của các dat
		for (int j = 0; j < 32; j++, n = (n << 1))
		{
			if (kt == 0)
			{
				if ((a.dat[i] & n) != 0)	kt = 1;//Đánh dấu là đã tìm được vị trí của bit 1 đầu tiên từ phải qua
			}
			else
			{
				if ((a.dat[i] & n) != 0)
				{
					a.dat[i] -= n;
				}
				else
				{
					a.dat[i] += n;
				}
			}
		}
	}
	return a;
}

// Hàm tìm chiều dài của chuỗi vừa nhập
// Input: chuỗi char
// Output: chiều dài của chuỗi
int len(char a[])
{
	int i = 0;
	while (a[i] != 0)
	{
		i++;
	}
	return i;
}

// Hàm đảo chuỗi
// Input: Chuỗi char[] cần đảo
// Output: chuỗi char[] đã bị đảo
void DaoChuoi(char a[])
{
	int l = len(a);
	char *b = new char[l / 2 + 1];
	b[0] = a[0];
	for (int i = 0; i < l; i++)
	{
		if (i < l / 2)
		{
			b[i + 1] = a[i + 1];
			a[i] = a[l - 1 - i];
		}
		else
		{
			a[i] = b[l - 1 - i];
		}
	}
	delete b;
}

// Hàm nhân 2 cho chuỗi số char[]
// Input: chuỗi số cần được nhân 2, ví dụ 1234
// Output: chuỗi số đã được nhân 2, ví dụ 2468
void Nhan2(char a[])
{
	//Hàm nhân thêm 2 vào chuỗi số, ta tiến hành thao tác trên chuỗi bị đảo ngược
	int i = 0, t = 0;//i là biến đếm, t là biến nhớ khi kết quả vượt quá 10
	int l = len(a);
	while (i<l)
	{
		a[i] = (a[i] - 48) * 2 + t;//nhân dưới dạng số
		t = 0;//cài lại biến nhớ
		if (a[i] >= 10)
		{
			t = a[i] / 10;
			a[i] = a[i] - t * 10;
		}
		a[i] += 48;//chuyển về dạng ký tự
		i++;
	}

	if (t != 0)
	{
		a[i] = t + 48;
		i++;
	}

	a[i] = 0;
}

// Hàm cộng thêm 1 vào chuỗi số char[]
// Input: chuỗi số cần được cộng 1, ví dụ 1234
// Output: chuỗi số đã được cộng 1, ví dụ 1235
void Cong1(char a[])
{
	//Hàm cộng thêm 1 vào chuỗi số, ta tiến hành thao tác trên chuỗi bị đảo ngược
	int i = 0, t = 0;//i là biến đếm, t là biến nhớ khi kết quả vượt quá 10
	do
	{
		a[i]++;
		if (a[i] >= 58)
		{
			a[i] -= 10;
			t = 1;
		}
		i++;
	} while (t != 0);
	if (i >= len(a))a[i] = 0;
}

//Hàm in ra màn hình BigInt
//Input: biến BigInt a, ta tận dụng 4 biến dat
//Output: Xuất ra màn hình giá trị của biến BigInt
string PrintBigInt(BigInt a)
{
	string res;

	//Hương giải quyết: 
	// - Ta sẽ sử dụng 4 biến unsigned int trong struct. Biến nào có giá trị là 0 nghĩa là ở biến đó toàn lưu bit 0 nên ta sẽ bỏ qua mà không tính
	//Đối với từng biến mà có giá trị, ta sẽ dịch bit của mỗi biến sang trái một bit, nếu gặp bit 1 thì ta tiến hành công thêm 1 vào chuỗi kq
	//sau mỗi lần vậy thì ta phải nhân 2 chuỗi kq. Dùng phep &(and) để tìm bit ở sát bên trái sau mỗi lần dịch bit


	BigInt t = a;//biến tạm để lưu giá phần tử trong BigInt sẽ được xét, tránh trường hợp dữ liệu bị thay đổi
	char kq[40];//vì đối với phần tử lớn nhất mà BigInt có thể thể hiện được là 2^127 có 38 chữ số, công thêm 1 chữ số là dấu '-' nếu là số âm
	int kt = 0;//biến kiểm tra xem có phải số âm không, nếu âm - 1, dương - 0

			   //Kiểm tra có phải số âm không, nếu bit đầu tiên bên trái là 1 - nghĩa là giá trị a.dat[0] >= 2147483648
	if ((t.dat[0] & 2147483648) != 0)
	{
		t = GiaiQuyetSoAm(t);
		kt = 1;
	}


	kq[0] = '0';
	kq[1] = 0;//Vì là chuỗi không phải nhập tay, nên ta cần một phần tử trong chuỗi để đánh dấu vị trí kết thúc chuỗi
	for (int i = 0; i < 4; i++)
	{
		t.dat[i];
		if (t.dat[i] != 0)
		{
			for (int j = 0; j < 32; j++)
			{
				Nhan2(kq);
				if ((t.dat[i] & 2147483648) != 0)//Kiểm tra từng bit trái nhất có phải 1 không bằng cách dùng phep and với 100..00 (31 số 0)
				{
					Cong1(kq);
				}
				t.dat[i] = t.dat[i] << 1;
			}
		}
	}

	if (kt == 1)
	{
		int l = len(kq);
		kq[l] = '-';
		kq[l + 1] = 0;
	}
	DaoChuoi(kq);//Trong quá trình Cong1, nhan2 ta toàn là thao tác trên chuỗi đã bị đảo ngược, nên trước khi xuất kq thì đảo chuỗi lại
	res = kq;
	return res;
}

// Thực hiện phép toán -------------
// Hàm thực hiện các phép toán +, -, *, / giữa 2 số BigInt
// Input: 2 chuỗi số tương ứng với 2 giá trị thật của BigInt ( vì giá trị lưu trong BigInt chỉ là các dãy bit ), chuỗi o xác định phép toán thực hiện
//biến Hệ số xác định hệ số mà phép toán đang diễn ra
// Output: giá trị của biến BigInt sau khi thực hiện phép toán
BigInt PhepToan(char* v1, char* v2, char* o, int HeSo)
{
	BigInt kq, a, b;
	if (HeSo == 2)
	{
		a = BinToDec(CharToBool(v1));
		b = BinToDec(CharToBool(v2));
	}
	else if (HeSo == 10)
	{
		a = ScanfBigInt(v1);
		b = ScanfBigInt(v2);
	}
	else
	{
		a = HexToDec(v1);
		b = HexToDec(v2);
	}


	if (strcmp(o, "+") == 0)
	{
		kq = a + b;
	}
	else if (strcmp(o, "-") == 0)
	{
		kq = a - b;
	}
	else if (strcmp(o, "*") == 0)
	{
		kq = a * b;
	}
	else if (strcmp(o, "/") == 0)
	{
		kq = a / b;
	}
	else if (strcmp(o, "&") == 0)
	{
		kq = a & b;
	}
	else if (strcmp(o, "|") == 0)
	{
		kq = a | b;
	}
	else
	{
		kq = a ^ b;
	}

	return kq;
}
