#pragma once

#ifdef AG_PLATFORM_WINDOWS

extern Agua::Application* Agua::CreateApplication();

int main(int argc, char **argv){
    auto app = Agua::CreateApplication();
    app->Run();
    delete app;
}
#endif
