cmake_minimum_required(VERSION 3.0)

project(CMake_Qt_Example)

find_package(Qt5 COMPONENTS Widgets CONFIG REQUIRED)

set(TARGET cmake_qt_example)

add_executable(${TARGET}
	src/main.cpp
	src/MainWindow.cpp
	src/MainWindow.h
)

set_target_properties(${TARGET}
	PROPERTIES
		AUTOMOC ON
		AUTOUIC ON
)

target_link_libraries(${TARGET} PRIVATE Qt5::Widgets)

if(TARGET Qt5::QXcbIntegrationPlugin)
	# Static Qt on X11: link to platform plugin
	target_compile_definitions(${TARGET} PRIVATE QT_INCLUDE_PLUGIN QT_INCLUDE_XCB_INTEGRATION_PLUGIN)
	target_link_libraries(${TARGET} PRIVATE Qt5::QXcbIntegrationPlugin)
endif()

if(TARGET Qt5::QWindowsIntegrationPlugin)
	# Static Qt on Windows: link to platform plugin
	target_compile_definitions(${TARGET} PRIVATE QT_INCLUDE_PLUGIN QT_INCLUDE_WINDOWS_INTEGRATION_PLUGIN)
	target_link_libraries(${TARGET} PRIVATE Qt5::QWindowsIntegrationPlugin)
endif()

if(TARGET Qt5::QCocoaIntegrationPlugin)
	# Static Qt on macOS: link to platform plugin
	target_compile_definitions(${TARGET} PRIVATE QT_INCLUDE_PLUGIN QT_INCLUDE_COCOA_INTEGRATION_PLUGIN)
	target_link_libraries(${TARGET} PRIVATE Qt5::QCocoaIntegrationPlugin)
endif()
