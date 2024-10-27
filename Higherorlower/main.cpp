#include <iostream>

int main()
{
    srand((unsigned) time(NULL));
    int number = 0;
    int guess = 0;
    std::cout << "Enter the max range to guess from: \n";
    std::cin >> number;
    int answer = rand() % number;
    while(answer != guess) {
        std::cout << "Enter Guess:" << std::endl;
        std::cin >> guess;
        if(guess == answer) {
            std::cout << "You got it!" << std::endl;
        }
        else {
            if(guess > answer) {
                std::cout << "Answer is lower then guess try again" << std::endl;
            }
            else {
                std::cout << "Answer is higher then guess try again" << std::endl;
            }
        }
    }
}
