// O2_Guessing_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

/*
- If a player's guess is less than 1 or greater than 10, say "OUT OF BOUND"
- On a player's first turn, if their guess is 
        -within 10 of the number, return "WARM"
        -Further than 10 away from the number, return "COLD"
- On all subsequent turns, if a guess is
        -closer to the number than the previous guess, return "WARMER"
        -father from the number than the previous guess, return "COLDER"
- When the player's guess equals the number, tell them they have guessed correctly and how many guesses it took!.

****************************************PSUEDO CODE*****************************************************************
* A random number is thrown and the number is of the modulus 99 <-- + 1 (of course)
* There is a variable named--->attempt (to track number of guesses)
* There is a variable named ---> current_guess
* 
* say the number is 20
* 
* if attempt == 1{
    * if you guess withing 10 --30 it gives you "WARM"
    * if you guess outside that +-10 range, you get "COLD"
}


else{
    if distance between (answer and current guess) is smaller than the distance between (answer and last guess)--"WARMER"
    if distance between (answer and last guess) is smaller than the distance between (answer and current guess)--"COLDER"
}


*/

int main()
{
    int answer{}, last_try{}, current_try{}, diff{}, attempts{ 0 };
    bool guessed{ false };
    srand(time(nullptr));
    answer = rand() % 99 + 1;
    
    while (!guessed) {
        
        std::cout << "Attempt " << attempts + 1 << ":";
        cin >> current_try;
        
        attempts++;

        //To ensure that the attempts are withing the bounds...
        if (current_try >= 1 && current_try <= 100) {

            if (attempts == 1) {
                diff = abs(answer - current_try);

                if (diff <= 10 && diff > 0) {
                    std::cout << "WARM" << std::endl;
                    last_try = diff;
                }

                else if (diff>10) {
                    std::cout << "COLD" << std::endl;
                    last_try = diff;
                }

                else if (diff == 0) {
                    std::cout << "YOu have guessed correctly with " << attempts << " attempts" << std::endl;
                    guessed = true;
                }
            }

            else {
                diff = abs(answer - current_try);

                if (diff == 0) {
                    std::cout << "YOu have guessed correctly with " << attempts << " attempts" << std::endl;
                    guessed = true;
                }

                else if (diff > last_try) {
                    std::cout << "COLDER" << std::endl;
                    last_try = diff;
                }

                else if (last_try > diff) {
                    std::cout << "WARMER" << std::endl;
                    last_try = diff;
                }

            }

        }
        else {
        std:cout << "OUT OF BOUND" << std::endl;
        }
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
