#include "gkFCGIRunner.h"
#include "gkFCGI.h"

gkFCGIRunner::gkFCGIRunner() {
    this->requestHandler = &gkFCGI::getInstance();
}
