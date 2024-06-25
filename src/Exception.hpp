#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

class Exception : public std::exception { 
    std::string message; 
  
public: 
    Exception(const char *msg);
    const char *what() const throw();
}; 

#endif // EXCEPTION_HPP
