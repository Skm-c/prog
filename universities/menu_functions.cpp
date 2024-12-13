#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const skm::menu_item* skm::show_menu(const menu_item* current) {
    std::cout << "Пожалуйста, выберите опцию:" << std::endl;
        for (int i = 1; i < current->children_count; i++) {
            std::cout << current->children[i]->title << std::endl;
        }
        std::cout << current->children[0]->title << std::endl;
        std::cout << "> ";

        int user_input;
        std::cin >> user_input;
        std::cout << std::endl;

        return current->children[user_input];
}

const skm::menu_item* skm::exit(const menu_item* current) {
    std::exit(0);
}

const skm::menu_item* skm::go_back(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const skm::menu_item* skm::spbu(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const skm::menu_item* skm::itmo(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const skm::menu_item* skm::spbstu(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const skm::menu_item* skm::lei(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const skm::menu_item* skm::pmpu(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const skm::menu_item* skm::math(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const skm::menu_item* skm::lang(const menu_item* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
