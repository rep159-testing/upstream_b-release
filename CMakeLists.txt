cmake_minimum_required(VERSION 3.22)
project(upstream_b VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(upstream_a 0.1 REQUIRED)

add_library(upstream_b SHARED src/upstream_b.cpp)
add_library(upstream_b::upstream_b ALIAS upstream_b)
target_include_directories(upstream_b PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(upstream_b PRIVATE upstream_a::upstream_a)

install(TARGETS upstream_b EXPORT upstream_bTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT upstream_bTargets NAMESPACE upstream_b::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_b)
configure_package_config_file(cmake/upstream_bConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_bConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_b)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_bConfigVersion.cmake
  COMPATIBILITY SameMajorVersion)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_bConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_bConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_b)

include(CTest)
if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  add_executable(test_upstream_b test/test_upstream_b.cpp)
  target_link_libraries(test_upstream_b PRIVATE upstream_b GTest::gtest_main)
  add_test(NAME test_upstream_b COMMAND test_upstream_b)
endif()
