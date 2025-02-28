target_sources(sort_lib
	PRIVATE	
		merge.cpp
		merge_sort.cpp
	PUBLIC
		merge.hpp
		merge_sort.hpp
)

target_include_directories(sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)