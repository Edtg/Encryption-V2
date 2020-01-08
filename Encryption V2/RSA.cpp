#include "RSA.h"
#include <math.h>

RSA::RSA()
{
	GetPrimes();
	GetE();
	GetD();
}

RSA::~RSA()
{
}

void RSA::GetPrimes()
{
	p = 19;
	q = 23;
	n = p * q;
}

int RSA::phi(unsigned int p, unsigned int q)
{
	return (p - 1) * (q - 1);
}

int RSA::gcd(int a, int b)
{
	int t;
	while (1)
	{
		t = a % b;
		if (t == 0)
			return b;
		a = b;
		b = t;
	}
}

void RSA::GetE()
{
	e = 7;
	while (e < phi(p, q))
	{
		double track = gcd(e, phi(p, q));
		if (track == 1)
			break;
		else
			++e;
	}
}

void RSA::GetD()
{
	d = fmod(1 / e, phi(p, q));
}

