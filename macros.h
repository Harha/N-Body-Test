#ifndef MACROS_H
#define MACROS_H

// std includes
#include <iostream>
#include <cstring>

// Default log output
#define LOG(msg)  std::cout << "LOG | " << msg << std::endl;

// Default error output
#define ERR(msg)  std::cerr << "ERR | " << msg << std::endl;

#endif // MACROS_H
