#include <clocale>
#include <cstdlib>
#include <iostream>

int main(){
    std::setlocale(LC_ALL, "");

    int user_input;
    do {
        std::cout << "Пожалуйста, выберите опцию:" << std::endl;
        std::cout << "1 - Посмотреть университеты Санкт-Петербурга" << std::endl;
        std::cout << "0 - Я уже студент" << std::endl;
        std::cout << "> ";
        std::cin >> user_input;
        if (user_input == 1){
            // TODO
        } else if (user_input == 0){
            exit(0);
        }

        std::cout << std::endl;
    } while (true);
    
    return 0;
}