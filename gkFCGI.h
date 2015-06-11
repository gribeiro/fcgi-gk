#ifndef GKFCGI_H
#define GKFCGI_H
#include <iostream>
#include "fcgio.h"
#include "gkFCGIRunner.h"


class gkFCGI {
   public:
    /*
     * Let the class be a singleton*/
    static gkFCGI& getInstance() {
        static gkFCGI instance;
        return instance;
    }
    void init(const gkFCGIRunner& runner);
    gkFCGI() {};
   protected:
    FCGX_Request request;
    fcgi_streambuf *cin_fcgi, *cout_fcgi, *cerr_fcgi;

   private:
    void streamCGI();
    void streamSTD();
    std::streambuf *cin_save, *cout_save, *cerr_save;
    // Singleton class enabler. 
    gkFCGI(gkFCGI const&) = delete;
    void operator=(gkFCGI const&) = delete;
};
#endif
