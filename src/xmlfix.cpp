#include "xmlfix.h"

#include <filesystem>
#include <regex>
#include <iostream>

bool XmlFix::change(const std::string &toChange) const
{
    pugi::xml_document root;
    pugi::xml_parse_result result = root.load_file(toChange.c_str(), pugi::parse_default | pugi::parse_declaration | pugi::parse_doctype | pugi::parse_comments);
    if (result.status == pugi::status_file_not_found)
    {
        std::cout << "change error:file not found file:" << toChange << std::endl;
        return false;
    }
    if (result.status != pugi::status_ok)
    {
        std::cout << "change error:other file:" << toChange << std::endl;
        return false;
    }

    int index = 0;
    bool changed = false;
    pugi::xpath_node_set xnodes = root.select_nodes("//paramlist[@name='networks']/elem");
    for (auto current : xnodes)
    {
        index++;
        std::string tmp = std::string(current.node().first_child().value());
        if (containsPatternToChange(tmp))
        {
            //std::cout << "ToChange" << std::endl;
            std::string out = "(" + tmp + ")";
            current.node().first_child().set_value(out.c_str());
            changed = true;
        }
        else
        {
            //std::cout << "Not ToChange" << std::endl;
        }

        //std::cout << index << ") " << tmp << std::endl;
    }

    if (changed)
    {
        bool res = root.save_file(toChange.c_str());
        if (res)
            return true;
    }
    return false;
}

bool XmlFix::containsPatternToChange(const std::string &toCheck) const
{
    std::regex selfRegexNot("([\\(\\)])+", std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(toCheck, selfRegexNot))
        return false;

    std::regex selfRegexNot2("([A-Za-z])+", std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(toCheck, selfRegexNot2))
        return false;

    std::regex selfRegex("([0-9 ]{6})", std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(toCheck, selfRegex))
        return true;
    return false;
}