#include "fieldexception.h"

FieldException::FieldException()
{
}

const char *FieldException::what() const noexcept
{
    return "Wrong point";
}
