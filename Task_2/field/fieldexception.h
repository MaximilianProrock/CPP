#ifndef FIELDEXCEPTION_H
#define FIELDEXCEPTION_H

#include <exception>
#include <string.h>

class FieldException :public std::exception
{
public:
    FieldException();

    const char *what() const noexcept;

};

#endif // FIELDEXCEPTION_H
