find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appObjectListInheritedProperties
    ./src/main.cpp
)

qt_add_qml_module(appObjectListInheritedProperties
    URI ObjectListInheritedProperties
    VERSION 1.0
    QML_FILES
        ./qml/Main.qml
    SOURCES
        ./src/footballteam.cpp
        ./src/player.cpp
        ./inc/footballteam.hpp
        ./inc/player.hpp
        SOURCES inc/stricker.hpp src/stricker.cpp
        SOURCES inc/defender.hpp src/defender.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appObjectListInheritedProperties PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appObjectListInheritedProperties
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appObjectListInheritedProperties PUBLIC ./inc/)

target_link_libraries(appObjectListInheritedProperties
    PRIVATE Qt6::Quick Qt6::QuickControls2
)
