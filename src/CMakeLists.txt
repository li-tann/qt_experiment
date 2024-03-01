
add_executable(Qt_experiments
	${CONSOLE_TYPE}
	# ../data/q_resource.qrc
	main.cpp
	mainwindow.cpp
    messagepopup.cpp
)

target_include_directories(	Qt_experiments 
							INTERFACE 
							${CMAKE_CURRENT_SOURCE_DIR}
							${CMAKE_SOURCE_DIR}/include
							)

set_target_properties(Qt_experiments PROPERTIES AUTOMOC TRUE AUTOUIC TRUE AUTORCC TRUE)

target_link_libraries(Qt_experiments PRIVATE Qt5::Core Qt5::Widgets Qt5::Gui Qt5::PrintSupport)
target_link_libraries(Qt_experiments PRIVATE magic_enum::magic_enum)
target_link_libraries(Qt_experiments PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Qt_experiments PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
target_link_libraries(Qt_experiments PRIVATE Qt::Concurrent Qt5::Concurrent Qt::ConcurrentPrivate Qt5::ConcurrentPrivate)
