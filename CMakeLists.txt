cmake_minimum_required(VERSION 3.17)
project(VehicleMenagmentSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(VehicleMenagmentSystem main.cpp Controller/MainController.cpp Controller/MainController.h View/GraphicView.cpp View/GraphicView.h View/Pages/PageName.h View/Elements/Button.cpp View/Elements/Button.h View/Elements/Input.cpp View/Elements/Input.h View/Elements/ListItem.cpp View/Elements/ListItem.h View/Pages/HomePage.cpp View/Pages/HomePage.h View/Pages/ClosePage.cpp View/Pages/ClosePage.h Model/Vehicle/Vehicle.cpp Model/Vehicle/Vehicle.h Model/Fleet.cpp Model/Fleet.h Model/Driver.cpp Model/Driver.h Model/Status/Status.cpp Model/Status/Status.h Model/Status/Available.cpp Model/Status/Available.h Model/Status/Road.cpp Model/Status/Road.h Model/Others/Date.cpp Model/Others/Date.h Model/Status/Broke.cpp Model/Status/Broke.h Model/Status/Repair.cpp Model/Status/Repair.h Model/Vehicle/WareTransport.cpp Model/Vehicle/WareTransport.h Model/Vehicle/PeopleTransport.cpp Model/Vehicle/PeopleTransport.h Model/Vehicle/Car.cpp Model/Vehicle/Car.h Model/Vehicle/Bus.cpp Model/Vehicle/Bus.h Model/Vehicle/Van.cpp Model/Vehicle/Van.h Model/Vehicle/Truck.cpp Model/Vehicle/Truck.h Model/Others/File.cpp Model/Others/File.h View/Pages/FleetStatePage.cpp View/Pages/FleetStatePage.h Model/Others/VehicleType.h Model/Others/StatusType.h View/Pages/ShowVehiclesPage.cpp View/Pages/ShowVehiclesPage.h View/Pages/VehicleDataPage.cpp View/Pages/VehicleDataPage.h View/Pages/BasePage.cpp View/Pages/BasePage.h View/Pages/ShowRegisterPage.cpp View/Pages/ShowRegisterPage.h View/Pages/ShowRepairsPage.cpp View/Pages/ShowRepairsPage.h View/Pages/Page.cpp View/Pages/Page.h View/Pages/AddEditVehiclePage.cpp View/Pages/AddEditVehiclePage.h View/Pages/ChangeStatusPage.cpp View/Pages/ChangeStatusPage.h)

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
