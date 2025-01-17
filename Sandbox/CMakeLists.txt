project(Sandbox)

add_executable (
    Sandbox
    "src/Sandbox.cpp" 
    "include/Sandbox.h"
)

set_target_properties(Sandbox PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-windows-x64/Sandbox"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Agua PROPERTY CXX_STANDARD 20)
endif()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Agua)


target_compile_definitions(Sandbox PRIVATE
    AG_PLATFORM_WINDOWS
)

target_link_libraries(Sandbox PRIVATE Agua)
target_include_directories(
    Sandbox PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/Agua/include"
)



