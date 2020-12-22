#include <iostream>

#include "xmlfix.h"

/*To be used with bash find and pipe*/
int main()
{
    std::string line;
    int counter{0};
    while (std::getline(std::cin, line))
    {
        XmlFix fix;
        if (fix.change(line))
            counter++;
    }
    std::cout << "DONE on file number:" << counter << std::endl;

    return 1;
}