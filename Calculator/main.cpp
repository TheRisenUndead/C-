#include <iostream>
#include <bits/locale_facets_nonio.h>

int calc(int const a, int const b, char const op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return false;
}
int main() {
    int value = calc(3,6, '-');
    if(value == false){
        std::cout << "Operator not valid" << std::endl;
    }
    else {
        std::cout << value << std::endl;
    }
}
