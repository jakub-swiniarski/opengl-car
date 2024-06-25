#include "Exception.hpp"

Exception::Exception(const std::string msg, const bool t) 
    : message(msg), type(t) {}

const char *Exception::what() const throw() {
    return message.c_str(); 
}

const bool Exception::is_fatal(void) const {
    return type;
}
