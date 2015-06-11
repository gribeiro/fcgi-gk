#ifndef CONTENTTYPE_H
#define CONTENTTYPE_H

#include "headerElement.h"
#include <string>

enum Type {
    APPLICATION,
    AUDIO,
    IMAGE,
    MESSAGE,
    MULTIPART,
    TEXT,
    VIDEO,
    XTOKEN
};

class contentType : public headerElement {
    public:
        contentType(Type type, std::string subType) : type(type), subType(subType) {};

       static  std::string typeStr(Type type);
        std::string elementStr() const;
    private:
       Type type;
       std::string subType;
};
#endif
