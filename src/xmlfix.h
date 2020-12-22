#pragma once

#include "pugixml.hpp"
#include <string>

class XmlFix
{
    public:
        bool change(const std::string& toChange);
};