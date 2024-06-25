#include "Exception.hpp"

Exception::Exception(const std::string msg) : message(msg) {}

const char *Exception::what() const throw() {
    return message.c_str(); 
}
