#include <iostream>
#include "matrix3f.h"

using namespace std;

int main(){
	Matrix3f a;
	Matrix3f b;
	
	b.set(0, 0, 1);
	b.set(0, 1, 2);
	b.set(0, 2, 3);
	
	b.set(1, 0, 4);
	b.set(1, 1, 5);
	b.set(1, 2, 6);
	
	b.set(2, 0, 7);
	b.set(2, 1, 8);
	b.set(2, 2, 9);
	
	

	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(0, 2, 3);
	
	a.set(1, 0, 4);
	a.set(1, 1, 5);
	a.set(1, 2, 6);
	
	a.set(2, 0, 7);
	a.set(2, 1, 8);
	a.set(2, 2, 9);
		
	Matrix3f c = a * b;
	
	cout << c;
	c.chg_row(0, 2);
	cout << c;
	c.mult_row(1, 3.14);
	cout << c;
	c.add_row(0, 2, 4);
	cout << c;
	
	
	
	return 0;
}