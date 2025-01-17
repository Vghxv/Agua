#pragma once

#include "Core.h"
namespace Agua {
    class AG_API Application
    {
        public:
            Application();
            virtual ~Application();
            void Run();
    };
    
    Application* CreateApplication();
}