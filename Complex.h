#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
	double Re, Im;
public:
	Complex();
	Complex(double x, double y);
	Complex(double x);
	~Complex();

	Complex operator+ (Complex y);
	Complex operator- (Complex y);
	Complex operator* (Complex y);
	Complex operator/ (Complex y);
	Complex& operator= (Complex y);
	bool operator== (Complex y);
	bool operator!= (Complex y);
	bool operator> (const Complex& y) const;
	bool operator< (const Complex& y) const;


	void prt();
	double getRe();
	double getIm();


	friend istream& operator>> (istream& in, Complex& x);
};


ostream& operator<<(ostream& os, Complex& x);