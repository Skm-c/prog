#pragma once

namespace skm {
    struct menu_item {
        const char* const title;
        void (*func)();
    };
}