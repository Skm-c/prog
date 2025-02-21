#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"


const skm::menu_item skm::PMPU = {
    "1 - Факультет ПМ-ПУ", skm::pmpu, &skm::SPBU
};
const skm::menu_item skm::MATH = {
    "2 - Факультет МатМех", skm::math, &skm::SPBU
};
const skm::menu_item skm::LANG = {
    "3 - Лингвистический факультет ", skm::lang, &skm::SPBU
};
const skm::menu_item skm::SPBU_GO_BACK = {
    "0 - Выйти в предыдущее", skm::go_back, &skm::SPBU
};

namespace{
    const skm::menu_item* const spbu_children[] {
            &skm::SPBU_GO_BACK,
            &skm::PMPU,
            &skm::MATH,
            &skm::LANG,
    };
    const int spbu_children_size = sizeof(spbu_children) / sizeof(spbu_children[0]);
}

const skm::menu_item skm::SPBU = {
    "1 - СПБГУ", skm::show_menu, &skm::UNIVERSITIES, spbu_children, spbu_children_size
};
const skm::menu_item skm::ITMO = {
    "2 - ИТМО", skm::itmo, &skm::UNIVERSITIES
};
const skm::menu_item skm::SPBSTU = {
    "3 - Политех ", skm::spbstu, &skm::UNIVERSITIES
};
const skm::menu_item skm::LEI = {
    "4 - ЛЭТИ", skm::lei, &skm::UNIVERSITIES
};
const skm::menu_item skm::UNIVERSITIES_GO_BACK= {
    "0 - Выйти в главное меню", skm::go_back, &skm::UNIVERSITIES
};

namespace{
    const skm::menu_item* const look_universities_children[] {
            &skm::UNIVERSITIES_GO_BACK,
            &skm::SPBU,
            &skm::ITMO,
            &skm::SPBSTU,
            &skm::LEI
    };
    const int look_universities_size = sizeof(look_universities_children) / sizeof(look_universities_children[0]);
}
const skm::menu_item skm::UNIVERSITIES = {
    "1 - Посмотреть университеты Санкт-Петербурга", skm::show_menu, &skm::MAIN, look_universities_children, look_universities_size 
};
const skm::menu_item skm::EXIT = {
    "0 - Я уже студент", skm::exit 
};

namespace {
    const skm::menu_item* const main_children[] = {
        &skm::EXIT,
        &skm::UNIVERSITIES
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]); 
}


const skm::menu_item skm::MAIN = { 
    nullptr, skm::show_menu, nullptr, main_children, main_size
};