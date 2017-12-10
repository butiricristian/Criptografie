// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InfInt.h"
#include<fstream>
#include<iostream>
#include <chrono>

using namespace std;


InfInt classicalFactorization(InfInt n) {
	if (n % 2 == 0) {
		return 2;
	}
	for (InfInt d = 3; d*d <= n; d+=2) {
		if (n%d == 0) {
			return d;
		}
	}
	return 0;
}

InfInt computeFunc(InfInt nr, InfInt func[], int funcDegree) {
	InfInt s = 0, x = 1;
	for (int i = 0; i < funcDegree; i++) {
		s += func[i] * x;
		x = x*nr;
	}
	return s;
}

InfInt euclid(InfInt a, InfInt b) {
	InfInt r;
	while (b != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

InfInt modulus(InfInt x) {
	return x > 0 ? x : -x;
}

InfInt pollardp(InfInt n, InfInt func[], int funcDegree) {
	if (n % 2 == 0) {
		return 2;
	}
	InfInt x0=2, x1=2;
	InfInt j = 1;
	InfInt d = 0;
	while (d != n) {
		x0 = computeFunc(x0, func, funcDegree) % n;
		if (j % 2 == 0) {
			x1 = computeFunc(x1, func, funcDegree) % n;
			d = euclid(modulus(x0 - x1), n);
			if (d > 1 && d < n) {
				return d;
			}
			else if (d == n) {
				return d;
			}
		}
		j++;
	}
}

int main()
{
	ifstream fin;
	fin.open("input.txt");
	ifstream fin2;
	fin2.open("function.txt");
	ofstream fout;
	fout.open("output.txt");
	InfInt x;
	int funcDegree;
	fin2 >> funcDegree;
	InfInt function[100], res1, res2;
	for (int i = 0; i < funcDegree; i++) {
		fin2 >> function[i];
	}
	for (int i = 0; i < 10; i++) {
		fin >> x;
		auto t1 = chrono::high_resolution_clock::now();
		res1 = classicalFactorization(x);
		auto t2 = chrono::high_resolution_clock::now();
		res2 = pollardp(x, function, funcDegree);
		auto t3 = chrono::high_resolution_clock::now();
		fout << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << ' ' << chrono::duration_cast<chrono::nanoseconds>(t3 - t2).count() << ' ' << res1 << ' ' << res2 << '\n';
	}

    return 0;
}

