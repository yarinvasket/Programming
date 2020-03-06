#include "Run.hpp"
#include <thread>
#include <iostream>

int main()
{
    std::thread t(run);

    for (;;) {
        getchar();
        std::cout << primeNumbers.tail->data << "\n";
    }
    return 0;
}