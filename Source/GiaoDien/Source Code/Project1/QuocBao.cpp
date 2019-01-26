#include"ThuVien.h"

BigInt BigInt::operator <<(int a)
{
	BigInt kq = *this;
	unsigned int t;
	int kt;// kiểm tra xem bit bị dịch có phải là bit 1 không, 0 - không phải bit 1, 1 - bit dịch là bti 1
	for (int j = 0; j < a; j++)
	{
		// Dịch theo dat từ phải sang trái nên t dịch lần lượt từ dat[3] đến dat[0]
		kt = 0;
		for (int i = 3; i >= 0; i--)
		{
			t = kq.dat[i] << 1;
			if (kt == 1)
			{
				t++;
			}
			if (kq.dat[i] >= 2147483648)
			{
				kt = 1;
			}
			else
			{
				kt = 0;
			}
			kq.dat[i] = t;
		}
	}
	return kq;
}
BigInt BigInt::operator >> (int a)
{
	BigInt kq = *this;
	unsigned int t;
	int kt;// kiểm tra xem bit bị dịch có phải là bit 1 không, 0 - không phải bit 1, 1 - bit dịch là bti 1
	for (int j = 0; j < a; j++)
	{
		// Vì dịch từ trái sang phải, nên ta lần lượt dich từ dat[0] đến dat[3]
		kt = 0;
		for (int i = 0; i < 4; i++)
		{
			t = kq.dat[i] >> 1;
			if (kt == 1)
			{
				t += 2147483648;
			}
			if (kq.dat[i] % 2 == 0)
			{
				kt = 0;
			}
			else
			{
				kt = 1;
			}
			kq.dat[i] = t;
		}
	}
	return kq;
}