project(Agua)

add_library (
    Agua SHARED
    "src/Application.cpp"
    "include/Application.h"
    "include/Core.h"
    "include/EntryPoint.h"
)

set_target_properties(Agua PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-windows-x64/Agua"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}-windows-x64/Agua"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}-windows-x64/Agua"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Agua PROPERTY CXX_STANDARD 20)
endif()

target_compile_definitions(Agua PRIVATE
    AG_PLATFORM_WINDOWS
    AG_BUILD_DLL
)

target_include_directories(
    Agua PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_custom_command(TARGET Agua POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:Agua>
    ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-windows-x64/Sandbox
)

set_property(TARGET Agua PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
