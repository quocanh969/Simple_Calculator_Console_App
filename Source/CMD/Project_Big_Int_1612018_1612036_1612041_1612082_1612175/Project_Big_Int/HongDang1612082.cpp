#include"Library.h"

// Hàm toán tử AND giữa 2 số BigInt
// Input: là một biến BigInt có giá trị khác
// Output: biến BigInt mới là kết quả của quá trình AND hai số BigInt
BigInt BigInt::operator &(BigInt b)
{
	BigInt kq;
	for (int i = 0; i < 4; i++)
	{
		int n = 1;
		for (int j = 0; j < 32; j++, n = n * 2)
		{
			int t1 = dat[i] & n;
			int t2 = b.dat[i] & n;
			if (t1 == t2 && t1 == n)
			{
				kq.dat[i] = kq.dat[i] | n;
			}
		}
	}
	return kq;
}

// Hàm toán tử OR giữa 2 số BigInt
// Input: là một biến BigInt có giá trị khác
// Output: biến BigInt mới là kết quả của quá trình OR hai số BigInt
BigInt BigInt::operator |(BigInt b)
{
	BigInt kq;
	for (int i = 0; i < 4; i++)
	{
		int n = 1;
		for (int j = 0; j < 32; j++, n = n * 2)
		{
			int t1 = dat[i] & n;
			int t2 = b.dat[i] & n;
			if (t1 == n || t2 == n)
			{
				kq.dat[i] = kq.dat[i] | n;
			}
		}
	}
	return kq;
}

// Hàm toán tử XOR giữa 2 số BigInt
// Input: là một biến BigInt có giá trị khác
// Output: biến BigInt mới là kết quả của quá trình XOR hai số BigInt
BigInt BigInt::operator ^(BigInt b)
{
	BigInt kq;
	for (int i = 0; i < 4; i++)
	{
		int n = 1;
		for (int j = 0; j < 32; j++, n = n * 2)
		{
			int t1 = dat[i] & n;
			int t2 = b.dat[i] & n;
			if (t1 != t2)
			{
				kq.dat[i] = kq.dat[i] | n;
			}
		}
	}
	return kq;
}

// Hàm toán tử NOT giữa 2 số BigInt
// Input: là một biến BigInt có giá trị khác
// Output: biến BigInt mới là kết quả của quá trình NOT hai số BigInt
BigInt BigInt::operator !()
{
	BigInt kq;
	for (int i = 0; i < 4; i++)
	{
		int n = 1;
		for (int j = 0; j < 32; j++, n = n * 2)
		{
			int t1 = dat[i] & n;
			if (t1 != n)
			{
				kq.dat[i] = kq.dat[i] | n;
			}

		}
	}
	return kq;
}