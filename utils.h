#ifndef UTILS_H
#define UTILS_H

#include <memory>
#include <iostream>
#include <string>
#include <cstdio>

template<typename ... Args>
std::string string_format( const char* format, Args ... args );

#endif
