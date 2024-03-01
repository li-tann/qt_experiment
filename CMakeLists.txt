cmake_minimum_required (VERSION 3.8)

project ("Qt_experiment"
		LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS off)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# error,cmake within vscode, CMAKE_BUILD_TYPE is ""
# setting.json: "cmake.configureSettings": {"CMAKE_BUILD_TYPE":"${buildType}"}
message(STATUS "cmake build type: " ${CMAKE_BUILD_TYPE})

# 设置在启动GUI时是否显示CONSOLE窗口
set(GUI_HIDE_CONSOLE_WINDOW false)

set(CONSOLE_TYPE )
if(GUI_HIDE_CONSOLE_WINDOW)
set(CONSOLE_TYPE WIN32)
endif()

# find_package
find_package(nlohmann_json CONFIG REQUIRED)
set(nlohmann_json_IMPLICIT_CONVERSIONS OFF)
find_package(fmt CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)
find_package(GDAL CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(OpenMP REQUIRED)
find_package(Qt5 CONFIG REQUIRED Core Gui PrintSupport Widgets Xml)
find_package(SQLiteCpp CONFIG REQUIRED)
find_package(Qt5Concurrent CONFIG REQUIRED)


add_subdirectory(src)