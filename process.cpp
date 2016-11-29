#include <iostream>
#include <stdio.h>
#include "process.h"
using namespace std;
struct rational {
	int up, down;
	rational() {
		up = 0, down = 0;
	}
	rational(int a, int b) {
		up = a; down = b;
	}
};

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		gcd(b, a % b);
		c = a % b;
		a = b; 
		b = c;
	}
	return a;
}

rational operator *(const rational &a, const rational &b) {
	rational rt;
	rt.up = a.up * b.up;
	rt.down = a.down * b.down;
	int g = gcd(rt.up, rt.down);
	rt.up /= g; rt.down /= g;
	return rt;
}

rational operator +(const rational &a, const rational &b) {
	rational rt;
	rt.down = a.down * b.down;
	rt.up = b.down * a.up + a.down * b.up;
	int g = gcd(rt.up, rt.down);
	rt.up /= g; rt.down /= g;
	return rt;
}

rational operator /(const rational &a, const rational &b) {
	rational d = b;
	swap(d.up, d.down);
	return a * d;
}

rational operator * (const rational &a, int b) {
	return a * rational(b, 1);
}

rational operator * (int a, const rational &b) {
	return rational(a, 1) * b;
}

rational operator + (const rational &a, int b) {
	return a + rational(b, 1);
}

rational operator + (int a, const rational &b) {
	return rational(a, 1) + b;
}

rational operator / (const rational &a, int b) {
	return a / rational(b, 1);
}

rational operator / (int a, const rational &b) {
	return rational(a, 1) / b;
}

int main() {
	rational rab = rational(1074, 281); 
	rational rcd = rational(60, 17);
	rational uab = 5 * rab / (rab + 9);
	rational ucd = uab * rcd / (7 + rcd);
	rational u = ucd / 12 * 10;
	cout << uab.up << ' ' << uab.down << endl;
	cout << ucd.up << ' ' << ucd.down << endl;
	cout << u.up << ' ' << u.down << endl;
	char c;
	int t;
	rational cur = rational(0, 1);
	while (1) {
		cin >> c >> t;
		if (c == '+') cur = cur + rational(t, 1);
		if (c == '|') {
			rational d = rational(t, 1);
			cur = (cur * d) / (cur + d);
		}  
		if (c == 't') break;
	}
	cout << cur.up << ' ' << cur.down << endl;
	return 0;
}
