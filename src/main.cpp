#include "MyApp.hpp"
#include <exception>
#include <iostream>

int main()
{
    try
    {
        MyApp myApp;
        myApp.Initialize();
        myApp.Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cin.get();
        return 1;
    }
}
