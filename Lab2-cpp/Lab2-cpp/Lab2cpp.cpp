// Lab2cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "InfInt.h"
#include <chrono>

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

int gcdSmallEuclid(int a, int b)
{
	int remainder;
	while (b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int gcdDifference(int a, int b)
{
	while (a != b)
	{
		if(a > b)
			a = a - b;
		if (b > a)
			b = b - a;
	}
	return a;
}

int gcdBrute(int a, int b) {
	if (a < b) {
		for (int d = a; d > 0; d--) {
			if (a%d == 0 && b%d == 0)
				return d;
		}
	}
	else {
		for (int d = b; d > 0; d--) {
			if (a%d == 0 && b%d == 0)
				return d;
		}
	}
}

int main() {
	ifstream fin;
	fin.open("big_nr.in");
	ofstream fout;
	fout.open("big_nr.out");

	InfInt x, y;
	for(int i=0;i<1;i++){
		fin >> x >> y;
		auto t1 = chrono::high_resolution_clock::now();
		InfInt z = gcdEuclid(x, y);
		auto t2 = chrono::high_resolution_clock::now();
		fout << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << ' ' << z << '\n';
	}

	int x2, y2;
	ifstream fin2;
	fin2.open("reg_nr.in");
	ofstream foutEuclid, foutDifference, foutBrute;
	foutEuclid.open("reg_nr_euclid.out");
	foutDifference.open("reg_nr_diff.out");
	foutBrute.open("reg_nr_brute.out");
	for (int i = 0; i<2; i++) {
		fin2 >> x2 >> y2;
		auto t1 = chrono::high_resolution_clock::now();
		int x = gcdSmallEuclid(x2, y2);
		auto t2 = chrono::high_resolution_clock::now();
		foutEuclid << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << ' ' << x << '\n';
		t1 = chrono::high_resolution_clock::now();
		x = gcdDifference(x2, y2);
		t2 = chrono::high_resolution_clock::now();
		foutDifference << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << ' ' << x << '\n';
		t1 = chrono::high_resolution_clock::now();
		x = gcdBrute(x2, y2);
		t2 = chrono::high_resolution_clock::now();
		foutBrute << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << ' ' << x << '\n';
	}
	return 0;
}


