cmake_minimum_required(VERSION 3.15)
project(evadeapi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(evadeapi INTERFACE)

target_include_directories(evadeapi INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(evadeapi INTERFACE
    EVADEAPI_VERSION="1.0.0"
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/evadeapiConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/evadeapiConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/evadeapiConfig.cmake"
    INSTALL_DESTINATION lib/cmake/evadeapi
)

install(TARGETS evadeapi EXPORT evadeapiTargets)
install(EXPORT evadeapiTargets
    FILE evadeapiTargets.cmake
    NAMESPACE evadeapi::
    DESTINATION lib/cmake/evadeapi
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/evadeapiConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/evadeapiConfigVersion.cmake"
    DESTINATION lib/cmake/evadeapi
)
install(DIRECTORY include/ DESTINATION include)