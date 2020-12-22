#include "xmlfix.h"

#include <filesystem>
#include <iostream>

bool XmlFix::change(const std::string &toChange)
{
    pugi::xml_document root;
    pugi::xml_parse_result result = root.load_file(toChange.c_str());
    if (result.status == pugi::status_file_not_found)
    {
        std::cout << "change error:file not found " << std::endl;
        return false;
    }
    if (result.status != pugi::status_ok)
    {
        std::cout << "change error:other" << std::endl;
        return false;
    }

    root.node();


    return true;
}
