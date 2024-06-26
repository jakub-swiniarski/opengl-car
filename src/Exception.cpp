#include "Exception.hpp"

sd::Exception::Exception(const std::string msg, const bool t) 
    : message(msg), type(t) {}

const char *sd::Exception::what() const throw() {
    return message.c_str(); 
}

const bool sd::Exception::is_fatal(void) const {
    return type;
}
