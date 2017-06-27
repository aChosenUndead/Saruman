/**
 * @file
 * Jokenpo library functions "library.cpp"
 */
#include <iostream>
#include "jokenpo.h"

namespace jokenpo 
{
    int comparison (int playerChoice, int sarumanChoice)
    {
        // Rock(1), Paper(2), Scissors(3)
		if (playerChoice == sarumanChoice){
			return 0;
		}
		else if ((playerChoice == 1 and sarumanChoice == 3) or (playerChoice == 2 and sarumanChoice == 1) or (playerChoice == 3 and sarumanChoice == 2)){
			return 1; // You Win
		}
		else if ((playerChoice == 3 and sarumanChoice == 1) or (playerChoice == 1 and sarumanChoice == 2) or (playerChoice == 2 and sarumanChoice == 3)){
			return 2; // You Lose
    	}
    }

    void Tied()
    {
        std::cout << "Do not delude yourself, thou wretched fool!\n\n";
    }

    void YouLose()
    {
        std::cout << "Are you even trying? I don't think you have a brain...\n\n";
    }

    void YouWin()
    {
        std::cout << "Impressive... But you could never compare yourself to me.\n\n";
    }

}