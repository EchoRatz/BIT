#include "header.h"
#include "header2.h"

namespace sh = MyNamespace;

void functionWithScopeResolution(){
    sh::function1(); 
}

void functionWithUsingDirective(){
    using namespace MyNamespace; 
    function5();
}

int main(){
    functionWithScopeResolution();
    functionWithUsingDirective();
    return 0;
}