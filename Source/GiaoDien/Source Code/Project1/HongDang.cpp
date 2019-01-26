#include"ThuVien.h"

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