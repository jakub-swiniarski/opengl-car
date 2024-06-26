#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

namespace sd {
    class Exception : public std::exception { 
        const std::string message; 
        const bool type;
      
    public: 
        Exception(const std::string msg, const bool t);
        const char *what() const throw() override;
        const bool is_fatal(void) const;
    }; 
}

#endif // EXCEPTION_HPP
