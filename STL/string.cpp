#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";

    // Using the index operator
    std::cout << "Using the index operator:" << std::endl;
    for (size_t i = 0; i < str.size(); ++i) {
        std::cout << str[i] << std::endl;
    }

    // Using the at() method
    std::cout << "\nUsing the at() method:" << std::endl;
    for (size_t i = 0; i < str.size(); ++i) {
        std::cout << str.at(i) << std::endl;
    }

    // Using a range-based for loop
    std::cout << "\nUsing a range-based for loop:" << std::endl;
    for (char c : str) {
        std::cout << c << std::endl;
    }

    // Using iterators
    std::cout << "\nUsing iterators:" << std::endl;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}