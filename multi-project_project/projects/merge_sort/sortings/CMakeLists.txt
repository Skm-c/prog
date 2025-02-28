target_sources(merge_sort
	PRIVATE
		merge.cpp
		merge.hpp
		merge_sort.cpp
		merge_sort.hpp
)

target_include_directories(merge_sort PRIVATE
	"${PROJECT_SOURCE_DIR}/sortings"
)