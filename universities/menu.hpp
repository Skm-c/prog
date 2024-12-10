#pragma once

namespace skm {
    struct menu_item {
        const char* const title;
        const menu_item* (*func)(const menu_item* current);

        const menu_item* const *children;
        const int children_count;

        const menu_item* parent;
    };
}