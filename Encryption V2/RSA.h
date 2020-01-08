#pragma once

class RSA
{
public:
	RSA();
	~RSA();

private:
	void GetPrimes();
	int phi(unsigned int p, unsigned int q);

	int gcd(int a, int b);

	void GetE();
	void GetD();

	unsigned int p;
	unsigned int q;
	unsigned int n;

	double e;
	double d;
};

