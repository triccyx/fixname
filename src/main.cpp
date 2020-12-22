#include <iostream>

#include "xmlfix.h"

int main()
{
    std::string line;
    int counter{0};
    while (std::getline(std::cin, line))
    {
        XmlFix fix;
        if(fix.change(line))
            counter++;
    }
    std::cout << "DONE on file number:"<<counter << std::endl;

    return 1;
}