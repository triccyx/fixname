#include <iostream>
#include <sstream>
int main()
{
    std::stringstream ss;
    //std::cin >> tmp;

    std::string line;
    while (std::getline(std::cin, line))
    {
        ss<<line<<std::endl;
    }
    std::cout << ss.str() << std::endl;
    return 1;
}