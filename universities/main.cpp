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
        &universities_go_back,
        &spbu,
        &itmo,
        &spbstu,
        &lei
    };
    const int universities_size = sizeof(universities_children) / sizeof(universities_children[0]);

    skm::menu_item universities = {"1 - Посмотреть университеты Санкт-Петербурга", skm::show_menu, universities_children, universities_size };
    skm::menu_item exit = {"0 - Я уже студент", skm::exit };

    skm::menu_item* main_children[] = { &exit, &universities};
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);

    skm::menu_item main = { nullptr, skm::show_menu, main_children, main_size};

    spbu.parent = &universities;
    itmo.parent = &universities;
    spbstu.parent = &universities;
    lei.parent = &universities;
    universities_go_back.parent = &universities;

    universities.parent = &main;
    exit.parent = &main;

    const skm::menu_item* current = &main;
    do {
        current = current->func(current);
    } while (true);
    
    return 0;
}