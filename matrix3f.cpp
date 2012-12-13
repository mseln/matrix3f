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

void Matrix3f::get_eigenvektors(){
	float eig[3];
	float p = a[0][1] * a[0][1] + a[0][2] * a[0][2] + a[1][2] * a[1][2];
	float q, r, phi;
	Matrix3f B; Matrix3f I;
	for (int i = 0; i < 3; i++) I.set(i, i, 1);
	
	if ( p == 0 ){
		eig[0] = a[0][0];
		eig[1] = a[1][1];
		eig[2] = a[2][2];
	}
	else {
		q = a[0][0] + a[1][1] + a[2][2];
		p = (a[0][0] - q) * (a[0][0] - q) + 
			(a[1][1] - q) * (a[1][1] - q) + 
			(a[2][2] - q) * (a[2][2] - q) + 2 * q;
		p = sqrt( p / 6 );
		
		B = ((*this) - I * q);
		B = B * (1 / p);
		r = B.get_det();
		
		if (r <= -1)
			phi = M_PI / 3;
		else if (r >= 1)
			phi = 0;
		else
			phi = acos(r) / 3;
		
		eig[0] = q + 2 * p * cos(phi);
		eig[2] = q + 2 * p * cos(phi + M_PI * (2/3));
		eig[1] = 3 * q - eig[0] - eig[2]; 
	}
	
	std::cout << eig[0] << ' ' << eig[1] << ' ' << eig[2] << ' ';
}

float Matrix3f::get_det(){
	return	a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - 
			a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
}

Matrix3f Matrix3f::get_inverse(){
	Matrix3f temp = (*this) , inverse;
	for (int i = 0; i < 3; i++) inverse.set(i, i, 1);
	
	for (int i = 0; i < 3; i++){
		if(temp.get(i, i) == 0){
			for (int j = i; j < 3; j++){
				if(temp.get(j, i) != 0){
					temp.chg_row(i, j);
					inverse.chg_row(i, j);
					
					std::cout << "Change row " << i << " and " << j << ".\n";
					std::cout << temp << '\n';
					std::cout << inverse << '\n';
					
					break;
				}
			}
			
			if(temp.get(i, i) == 0){ 
				std::cout << "Singularity!\n";
				break;
			}
		}
		
		
		float mult_val = temp.get(i, i);
		temp.mult_row(i, 1 / mult_val );
		inverse.mult_row(i, 1 / mult_val );
		
		std::cout << "Divide row " << i << " by " << mult_val << ".\n";
		std::cout << temp << '\n';
		std::cout << inverse << '\n';
		
		for (int j = 0; j < 3; j++){
			if(i != j){
				
				float mult_val = -temp.get(j, i);
				
				temp.add_row(j, i, mult_val);
				inverse.add_row(j, i, mult_val);
				
				std::cout << "Multiply row " << i << " by " << mult_val << " and adding it to " << j << ".\n";
				std::cout << temp << '\n';
				std::cout << inverse << '\n';
			}
		}
	}
	
	return inverse;
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
Matrix3f Matrix3f::operator* (float param){
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