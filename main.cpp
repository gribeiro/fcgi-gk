#include <iostream>
#include "gkFCGI.h"
#include "eigenRunner.h"

using namespace std;

int main() {
    gkFCGI *fcgi = &gkFCGI::getInstance();
    eigenRunner myRunner; 
    fcgi->init(myRunner);
    return 0; 
}
