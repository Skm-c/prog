#pragma once

#include "menu.hpp"

namespace skm {
    const menu_item* show_menu(const menu_item* current);

    const menu_item* exit(const menu_item* current);
    
    const menu_item* spbu(const menu_item* current);
    const menu_item* itmo(const menu_item* current);
    const menu_item* spbstu(const menu_item* current);
    const menu_item* lei(const menu_item* current);
    const menu_item* universities_go_back(const menu_item* current);
}