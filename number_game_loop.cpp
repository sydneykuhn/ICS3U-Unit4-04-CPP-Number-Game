// Copyright (c) 2020 Sydney Kuhn All rights reserved
//
// Created by: Sydney Kuhn
// Created on: Oct 2020
// This program is a random number guessing game

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function is the game
    std::string numberGuessedAsString;
    int numberGuessed;
    int randomNumber;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0, 9]
    randomNumber = idist(rgen);


    // input, process & output
    while (true) {
        try {
            std::cout << "Guess a number between 0-9: ";
            std::cin >> numberGuessedAsString;
            numberGuessed = std::stoi(numberGuessedAsString);
            if (numberGuessed == randomNumber) {
                std::cout << "\nYou guessed correctly!" << std::endl;
                break;
            } else if (numberGuessed > randomNumber) {
                    std::cout << "That number is too high, guess lower."
                    << std::endl;
                } else {
                    std::cout << "That number is too low, guess higher."
                    << std::endl;
                    }
        }catch (std::invalid_argument) {
            std::cout << "Invalid number guessed, please try again.";
    }
    }
    std::cout << "\nDone." << std::endl;
}
