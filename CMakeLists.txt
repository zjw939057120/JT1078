cmake_minimum_required(VERSION 3.18)
project(tcp_client)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(include)
link_directories(lib)
link_libraries(evpp_lite_static event glog  pthread gflags)

add_executable(tcp_client tcp_client.cpp JT808.cpp JT809.cpp JT1078.cpp Toolkit.cpp Toolkit.h Utils.cpp Utils.h MessageCallback.cpp MessageCallback.h ConnectionCallback.cpp ConnectionCallback.h)
add_executable(tcp_server tcp_server.cpp)
