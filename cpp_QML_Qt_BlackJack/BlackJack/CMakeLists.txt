cmake_minimum_required(VERSION 3.16)

project(BlackJack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Multimedia)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appBlackJack
    main.cpp
)

qt_add_qml_module(appBlackJack
    URI BlackJack
    VERSION 1.0
    QML_FILES Main.qml
    RESOURCES
    #     resources/cards/1_1.png
    #     resources/cards/1_2.png
    #     resources/cards/1_3.png
    #     resources/cards/1_4.png

    #     resources/cards/2_1.png
    #     resources/cards/2_2.png
    #     resources/cards/2_3.png
    #     resources/cards/2_4.png

    #     resources/cards/3_1.png
    #     resources/cards/3_2.png
    #     resources/cards/3_3.png
    #     resources/cards/3_4.png

    #     resources/cards/4_1.png
    #     resources/cards/4_2.png
    #     resources/cards/4_3.png
    #     resources/cards/4_4.png

    #     resources/cards/5_1.png
    #     resources/cards/5_2.png
    #     resources/cards/5_3.png
    #     resources/cards/5_4.png

    #     resources/cards/6_1.png
    #     resources/cards/6_2.png
    #     resources/cards/6_3.png
    #     resources/cards/6_4.png

    #     resources/cards/7_1.png
    #     resources/cards/7_2.png
    #     resources/cards/7_3.png
    #     resources/cards/7_4.png

    #     resources/cards/8_1.png
    #     resources/cards/8_2.png
    #     resources/cards/8_3.png
    #     resources/cards/8_4.png

    #     resources/cards/9_1.png
    #     resources/cards/9_2.png
    #     resources/cards/9_3.png
    #     resources/cards/9_4.png

    #     resources/cards/10_1.png
    #     resources/cards/10_2.png
    #     resources/cards/10_3.png
    #     resources/cards/10_4.png

    #     resources/cards/11_1.png
    #     resources/cards/11_2.png
    #     resources/cards/11_3.png
    #     resources/cards/11_4.png

    #     resources/cards/12_1.png
    #     resources/cards/12_2.png
    #     resources/cards/12_3.png
    #     resources/cards/12_4.png

    #     resources/cards/13_1.png
    #     resources/cards/13_2.png
    #     resources/cards/13_3.png
    #     resources/cards/13_4.png

        resources/images/promo.jpg
        resources/images/1_table.png
        # resources/cards/backside.png
        # resources/cards/backside_3.png
        # resources/cards/backside_4.png
        # resources/cards/backside_5.png
        # resources/cards/backside_6.png

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appBlackJack PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appBlackJack
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appBlackJack
    PRIVATE Qt6::Quick Qt6::Multimedia
)

include(GNUInstallDirs)
install(TARGETS appBlackJack
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
