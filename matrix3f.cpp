#include "Matrix3f.h"

void Matrix3f::disp(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void Matrix3f::chg_row(int x, int y){
	int temp[3] = {a[x][0], a[x][1], a[x][2]};
	
	for(int i = 0; i < 3; i++){
		a[x][i] = a[y][i];
		a[y][i] = temp[i];
	}
	
}
void Matrix3f::mult_row(int x, float c){
	for(int i = 0; i < 3; i++){
		a[x][i] *= c;
	}
}
void Matrix3f::add_row(int x, int y, float c){
	for(int i = 0; i < 3; i++){
		a[x][i] += c * a[y][i];
	}
}

Matrix3f Matrix3f::operator= (Matrix3f param){
	Matrix3f temp;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			temp.set(i, j, param.get(i, j));
		}
	}
	
	return temp;
}
Matrix3f Matrix3f::operator+ (Matrix3f param){
	Matrix3f temp;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			temp.set(i, j, a[i][j] + param.get(i, j));
		}
	}
	
	return temp;
}
Matrix3f Matrix3f::operator- (Matrix3f param){
	Matrix3f temp;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			temp.set(i, j, a[i][j] - param.get(i, j));
		}
	}
	
	return temp;
}
Matrix3f Matrix3f::operator* (int param){
	Matrix3f temp;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			temp.set(i, j, a[i][j] * param);
		}
	}
	
	return temp;
}
Matrix3f Matrix3f::operator* (Matrix3f param){
	Matrix3f temp;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			temp.set(i, j,	a[i][0] * param.get(0,j) + 
							a[i][1] * param.get(1,j) + 
							a[i][2] * param.get(2,j)  );
		}
	}
	
	return temp;
}

std::ostream& operator << ( std::ostream& os, Matrix3f m ){
	for(int i = 0; i < 3; i++){
		os << "(";
		for(int j = 0; j < 3; j++){
			os << m.get(i, j) << ",\t";
		}
		os << ") \n";
	}
	
	return os;
}