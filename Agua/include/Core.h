#pragma once
#ifdef AG_PLATFORM_WINDOWS
    #ifdef AG_BUILD_DLL
        #define AG_API __declspec(dllexport)
    #else
        #define AG_API __declspec(dllimport)
    #endif
#else
    #error Agua only support Windows !
#endif