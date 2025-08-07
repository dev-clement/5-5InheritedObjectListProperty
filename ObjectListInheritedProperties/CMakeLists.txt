cmake_minimum_required(VERSION 3.16)

project(ObjectListInheritedProperties VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(main/)

include(GNUInstallDirs)
install(TARGETS appObjectListInheritedProperties
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
