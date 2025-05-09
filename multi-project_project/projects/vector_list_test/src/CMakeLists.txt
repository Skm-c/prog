target_sources(sort_lib3
	PRIVATE	
		doubly_linked_list.cpp
		vector.cpp
	PUBLIC
		doubly_linked_list.hpp
		vector.hpp
)

target_include_directories(sort_lib3 PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)