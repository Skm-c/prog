#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main(){
    std::setlocale(LC_ALL, "");

    skm::menu_item spbu = {"1 - СПБГУ", skm::spbu};
    skm::menu_item itmo = {"2 - ИТМО", skm::itmo};
    skm::menu_item spbstu = {"3 - Политех ", skm::spbstu};
    skm::menu_item lei = {"4 - ЛЭТИ", skm::lei};
    skm::menu_item universities_go_back = {"0 - Выйти в главное меню", skm::universities_go_back};

    skm::menu_item* universities_children[] {
        &spbu,
        &itmo,
        &spbstu,
        &lei,
        &universities_go_back
    };
    const int universities_size = sizeof(universities_children) / sizeof(universities_children[0]);

    skm::menu_item universities = {"1 - Посмотреть университеты Санкт-Петербурга", skm::universities };
    skm::menu_item exit = {"0 - Я уже студент", skm::exit };

    skm::menu_item* main_children[] = { &exit, &universities};
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);

    int user_input;
    do {
        std::cout << "Пожалуйста, выберите опцию:" << std::endl;
        for (int i = 1; i < main_size; i++) {
            std::cout << main_children[i]->title << std::endl;
        }
        std::cout << main_children[0]->title << std::endl;
        std::cout << "> ";

        std::cin >> user_input;
        main_children[user_input]->func();

        std::cout << std::endl;
    } while (true);
    
    return 0;
}