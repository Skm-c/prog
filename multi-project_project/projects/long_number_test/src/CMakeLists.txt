target_sources(sort_lib2
	PRIVATE	
		long_number.cpp
	PUBLIC
		long_number.hpp
)

target_include_directories(sort_lib2 PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)