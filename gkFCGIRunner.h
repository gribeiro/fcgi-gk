
#ifndef GKFCGIRUNNER_H
#define GKFCGIRUNNER_H

#include <iostream>
#include <list>
#include "headerElement.h"

class gkFCGI;
class gkFCGIRunner {
    private:
       gkFCGI *requestHandler;
    public:
        gkFCGIRunner();
        virtual void main_loop() const = 0;
        virtual std::list<headerElement> headerElements() const = 0;
};
#endif
