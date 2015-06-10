#include <iostream>
#include "fcgio.h"
#include "gkFCGI.h"
#include "gkFCGIRunner.h"

using namespace std;
void gkFCGI::init(const gkFCGIRunner &runner) {
    this->cin_save = cin.rdbuf();
    this->cout_save = cout.rdbuf();
    this->cerr_save = cerr.rdbuf();
    FCGX_Request request = this->request;
    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);
    
    while(FCGX_Accept_r(&request) == 0) {
        this->cin_fcgi = new fcgi_streambuf(request.in);
        this->cout_fcgi = new fcgi_streambuf(request.out);
        this->cerr_fcgi = new fcgi_streambuf(request.err);
        this->streamCGI();
        cout << "Content-type: text/html\r\n\r\n";
        runner.main_loop();
    }
    this->streamSTD();
    delete this->cin_fcgi;
    delete this->cout_fcgi;
    delete this->cerr_fcgi;

}

void gkFCGI::streamCGI() {
    cin.rdbuf(this->cin_fcgi);
    cout.rdbuf(this->cout_fcgi);
    cerr.rdbuf(this->cerr_fcgi);
    
}

void gkFCGI::streamSTD() {
    cin.rdbuf(this->cin_save);
    cout.rdbuf(this->cout_save);
    cerr.rdbuf(this->cerr_save);
}
