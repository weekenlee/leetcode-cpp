project(img2txt)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -W")
include_directories(      /usr/include    )
aux_source_directory(./src DIR_SRCS)
link_directories(/usr/lib)
add_executable(img2txt ${DIR_SRCS})
target_link_libraries(img2txt
    tesseract
    lept
)

