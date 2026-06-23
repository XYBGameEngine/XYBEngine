#include "TestApplication.h"

using namespace XYBEngine;

int main() {     
    return std::make_unique<TestApplication>() -> Run();
}