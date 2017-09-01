#include <iostream>

#include "application_arguments.hpp"

int
main(int argc, char* argv[])
{
    x4::util::ApplicationArguments args{ { argc, argv } };

    std::cout << args[ "application_name" ] << std::endl;

    for (auto const& arg : args)
    { std::cout << arg.first << " : " << arg.second << std::endl; }

    std::cout << "port : " << args[ "port" ] << std::endl;
}
