
#ifndef GKFCGIRUNNER_H
#define GKFCGIRUNNER_H
#include <iostream>

class gkFCGI;
class gkFCGIRunner {
    private:
       gkFCGI *requestHandler;
    public:
        gkFCGIRunner();
        virtual void main_loop() const = 0;
};
#endif
