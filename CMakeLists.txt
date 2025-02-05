cmake_minimum_required(VERSION 3.15)
project(evade LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(evade INTERFACE)

target_include_directories(evade INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(evade INTERFACE
    evade_VERSION="1.0.0"
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/evadeConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/evadeConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/evadeConfig.cmake"
    INSTALL_DESTINATION lib/cmake/evade
)

install(TARGETS evade EXPORT evadeTargets)
install(EXPORT evadeTargets
    FILE evadeTargets.cmake
    NAMESPACE evade::
    DESTINATION lib/cmake/evade
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/evadeConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/evadeConfigVersion.cmake"
    DESTINATION lib/cmake/evade
)
install(DIRECTORY include/ DESTINATION include)