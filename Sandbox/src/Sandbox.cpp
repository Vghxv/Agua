#include "Application.h"
#include "EntryPoint.h"

class Sandbox : public Agua::Application {
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }
};
Agua::Application* Agua::CreateApplication() {
    return new Sandbox();
}


