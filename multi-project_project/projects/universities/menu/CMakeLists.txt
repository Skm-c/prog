target_sources(universities
	PRIVATE
		menu.hpp
		menu_functions.cpp
		menu_functions.hpp
		menu_items.cpp
		menu_items.hpp
)
target_include_directories(universities PRIVATE
	"${PROJECT_SOURCE_DIR}/menu"
)