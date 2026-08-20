find_package(Qt6 REQUIRED COMPONENTS Core DBus Widgets)

add_executable(test-settings-dbus-metatype
    test_settings_dbus_metatype.cpp
    ${CMAKE_SOURCE_DIR}/src/settings.cpp
    ${CMAKE_SOURCE_DIR}/src/settings.h
)

target_include_directories(test-settings-dbus-metatype PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(test-settings-dbus-metatype PRIVATE
    Qt6::Core
    Qt6::DBus
    Qt6::Widgets
)

add_test(NAME settings-dbus-metatype COMMAND test-settings-dbus-metatype)
set_tests_properties(settings-dbus-metatype PROPERTIES
    ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
)

add_executable(test-sessiontype
    test_sessiontype.cpp
)

target_include_directories(test-sessiontype PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(test-sessiontype PRIVATE
    Qt6::Core
)

add_test(NAME sessiontype COMMAND test-sessiontype)
