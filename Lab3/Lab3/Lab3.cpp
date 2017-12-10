// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InfInt.h"

using namespace std;

InfInt gcdEuclid(InfInt a, InfInt b)
{
	InfInt remainder;
	while (b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

InfInt modularExp(InfInt x, InfInt p, InfInt n) {
	bool bits[1000];
	int bitsSize = 0;
	while (p != 0) {
		if (p % 2 == 0) {
			bits[bitsSize] = 0;
		}
		else {
			bits[bitsSize] = 1;
		}
		bitsSize++;
		p = p / 2;
	}
	InfInt res = 1;
	for (int i = 0; i < bitsSize; i++) {
		if (bits[i] != 0) {
			res *= x;
			res = res%n;
		}
		x = (x*x) % n;
	}
	return res;
}

bool isPowerOf(InfInt bases[], int nrBases, InfInt n) {
	for (int i = 0; i < nrBases; i++) {
		InfInt aux = n;
		while (aux%bases[i] == 0) {
			aux = aux / bases[i];
		}
		if (aux == 1) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	InfInt n, b;
	
	cout << "Choose n: ";
	cin >> n;

	if (n % 2 == 0) {
		cout << "n must be odd!";
		return 1;
	}

	InfInt t = n-1;
	int s=0;
	while (t % 2 == 0) {
		t = t / 2;
		s++;
	}

	InfInt bases[100];
	int nrBases = 0;

	cout << "-1 1" << "\n";

	for (b = 2; b < n; b++) {
		if (isPowerOf(bases, nrBases, b) == 1) {
			cout << "-" << b << " " << b << "\n";
		}
		else {
			if (gcdEuclid(b, n) == 1) {
				if (modularExp(b, t, n) == 1) {
					bases[nrBases++] = b;
					cout << "-" << b << " " << b << "\n";
				}
				else {
					InfInt twoToTheJ = 1;
					for (int j = 0; j < s; j++) {
						if (modularExp(b, twoToTheJ*t, n) == n - 1) {
							bases[nrBases++] = b;
							cout << "-" << b << " " << b << "\n";
						}
						twoToTheJ *= 2;
					}
				}
			}
		}
	}
    return 0;
}

