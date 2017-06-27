/**
 * @file
 * Jokenpo library headers "library.h"
 */
#ifndef JOKENPO_H
#define JOKENPO_H
/**
 * @brief Namespace for the jokenpo functions
 */
namespace jokenpo
{
	/**
	 * @brief      Player and AI can play Jokenpo against Saruman
	 *
	 * @return     Returns the result of the game
	 */
    int comparison (int playerChoice, int sarumanChoice);

    /**
     * @brief      Prints a message when you and Saruman tied
     */
    void Tied();

    /**
     * @brief      Prints a message when you won against Saruman
     */
    void YouWin();

    /**
     * @brief      Prints a  message when you lost against Saruman
     */
    void YouLose();
}
#endif
