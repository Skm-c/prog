#include <cmath>
#include <iostream>


void func(double angle){
	double func1;
	if (cos(2*angle) != 1){
		func1 = (1 + sin(2*angle)) /
		(1 - cos(2*angle));
		std::cout << "Func1(angle1)= " << func1 << std::endl;
	} else {
		std::cout << "Неверный ввод для Func1(angle1) " << std::endl;
	}
	
	double func2;
	if (tan(angle) != 1){
		func2 = (1 + tan(angle)*tan(angle)) / 
		(1 - tan(angle)*tan(angle));
		std::cout << "Func2(angle2)= " << func2 << std::endl;
	} else {
		std::cout << "Неверный ввод для Func2(angle2) " << std::endl;
	}

}

int main(){
	double angle;
	std::cout << "Введите угол: " << std::endl;
	std::cin >> angle;
	func(angle);
	return 0;
}