#include "TestApplication.h"

using namespace XYBEngine;
int main() {    
    UniquePtr<TestApplication> application = UniquePtr<TestApplication>(std::make_unique<TestApplication>());
    application->Startup();     
    application->Shutdown();
    return 0;
}