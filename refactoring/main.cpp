#include <cmath>
#include <iostream>


void func(double angle){
	double func1;
	if (cos((double)2*angle) != 1){
		func1 = (1 + sin((double)2*angle)) / (1 - cos((double)2*angle));
		std::cout << "F(angle1)= " << func1 << std::endl;
	} else {
		std::cout << "Неверный ввод для F(angle1) " << std::endl;
	}
	
	double func2;
	if (tan((double)angle) != 1){
		func2 = (1 + tan((double)angle)*tan((double)angle)) / 
		(1 - tan((double)angle)*tan((double)angle));
		std::cout << "F(angle2)= " << func2 << std::endl;
	} else {
		std::cout << "Неверный ввод для F(angle2) " << std::endl;
	}

}

int main(int argc, char* argv[]){
	double angle;
	std::cout << "Введите угол: " << std::endl;
	std::cin >> angle;
	func(angle);
	system ("pause");
	return 0;
}