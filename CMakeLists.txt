# cmake_minimum_required(VERSION 3.0.0)
# project(opencvtest VERSION 0.1.0)

# include(CTest)
# enable_testing()

# find_package( OpenCV REQUIRED )
# include_directories( ${OpenCV_INCLUDE_DIRS} )

# add_executable(opencvtest main.cpp)

# target_link_libraries( opencvtest ${OpenCV_LIBS} )

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)


cmake_minimum_required(VERSION 3.10)

project(MyProject VERSION 1.0)

# 사용할 언어 지정
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# openc cv impoart
find_package( OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# 실행 파일과 소스 파일 목록 지정
add_executable(MyProject main.cpp front.cpp)

# targeting
target_link_libraries(MyProject ${OpenCV_LIBS})
