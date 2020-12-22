#include <iostream>
#include <sstream>

#include "xmlfix.h"

int main()
{
    /*
    std::stringstream ss;
    std::string line;
    while (std::getline(std::cin, line))
    {
        ss<<line<<std::endl;
    }
    std::cout << ss.str() << std::endl;
    */
    XmlFix fix;
    fix.change("./test.xml");
    return 1;
}