cmake_minimum_required(VERSION 3.17)
project(VehicleMenagmentSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(VehicleMenagmentSystem main.cpp Controller/MainController.cpp Controller/MainController.h View/GraphicView.cpp View/GraphicView.h View/Pages/PageName.h View/Elements/Button.cpp View/Elements/Button.h View/Elements/Input.cpp View/Elements/Input.h View/Elements/ListItem.cpp View/Elements/ListItem.h View/Pages/HomePage.cpp View/Pages/HomePage.h View/Pages/ClosePage.cpp View/Pages/ClosePage.h Model/Vehicle.cpp Model/Vehicle.h)

include_directories(/usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(VehicleMenagmentSystem ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw-w64/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
