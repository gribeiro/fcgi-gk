#include "contentType.h"
#include <string>

std::string contentType::typeStr(Type type) {
    switch(type) {
        case APPLICATION:
            return "application";
        case AUDIO:
            return "audio";
        case IMAGE:
            return "image";
        case MESSAGE:
            return "message";
        case MULTIPART:
            return "multipart";
        case TEXT:
            return "text";  
        case VIDEO:
            return "video";
        case XTOKEN:
            return "x-token";
        default:
            return "";
    }
}

std::string contentType::elementStr() const {
    std::string type = contentType::typeStr(this->type);
    
}
