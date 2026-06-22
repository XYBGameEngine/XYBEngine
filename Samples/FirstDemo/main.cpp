#include "TestApplication.h"

int main() {
    XYBEngine::UniquePtr<XYBEngine::TestApplication> application =
        XYBEngine::UniquePtr<XYBEngine::TestApplication>(new XYBEngine::TestApplication());
    application->Startup(); 
    return 0;
}