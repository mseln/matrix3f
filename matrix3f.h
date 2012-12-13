
#ifndef VEC3F_H_INCLUDED
#define VEC3F_H_INCLUDED

#include <iostream>


class Matrix3f{
	friend std::ostream& operator<< ( std::ostream& os, Matrix3f fb );
	
private:
	float a[3][3];
public:	
	Matrix3f(){		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(j >= 0 && j < 3 && i >= 0 && i < 3) a[i][j] = 0;
			}
		}
	}
	
	void disp();
	int get(int i, int j)			{ if(j >= 0 && j < 3 && i >= 0 && i < 3) return a[i][j];	else std::cerr << "Out of bounds! \n"; }
	void set(int i, int j, int v)	{ if(j >= 0 && j < 3 && i >= 0 && i < 3) a[i][j] = v;		else std::cerr << "Out of bounds! \n"; }; 
	
	void chg_row(int x, int y);
	void mult_row(int x,float c);
	void add_row(int x, int y, float c);
	
	Matrix3f operator=  (Matrix3f);
	Matrix3f operator+  (Matrix3f);
	Matrix3f operator-  (Matrix3f);
	Matrix3f operator*  (Matrix3f);
	Matrix3f operator*  (int);
};

#endif