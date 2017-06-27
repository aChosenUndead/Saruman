/**
* @file main.cpp
* @author Vinícius da Costa de Andrade <andradecostavinicius@gmail.com>
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "monster.h"
#include "grimoire.h"
#include "page.h"
#include "jokenpo.h"
#include "generator.h"
using namespace std;

int main ()
{
    srand(time(0));

    Grimoire* playerG = new Grimoire(); //Initializing player's grimoire
    Grimoire* aiG = new Grimoire(); //Initializing AI's grimoire

    SarumanGrimoire* sarumanG = new SarumanGrimoire();//Initializing Saruman's grimoire

     //Creating AI's monsters
    Monster* Astaroth =  new Beast ( "Astaroth", 610, 120, 40, 30, 30, 'b', 1);
    Monster* Nightmare = new Beast ("Nightmare", 410, 180, 50, 40, 30, 'b', 1);
    Monster* Elysium =   new Mage  (  "Elysium", 190, 110, 40, 40, 50, 'm', 1);
    Monster* Algol =     new Mage  (    "Algol", 210, 120, 50, 50, 50, 'm', 1);
    Monster* Abyss =     new Winged(    "Abyss", 290,  90, 30, 50, 70, 'w', 1);
    Monster* Aeon =      new Winged(     "Aeon", 260,  80, 20, 50, 70, 'w', 1);

    //Inserting monsters in AI's grimoire
    aiG->InsertMonster(Astaroth);
    aiG->InsertMonster(Nightmare);
    aiG->InsertMonster(Elysium);
    aiG->InsertMonster(Algol);
    aiG->InsertMonster(Abyss);
    aiG->InsertMonster(Aeon);

    //Creating player's monsters
    Monster* Smough =     new Beast (    "Smough", 600, 130, 40, 30, 30, 'b', 1);
    Monster* Cinder =     new Beast (    "Cinder", 400, 190, 50, 40, 30, 'b', 1);
    Monster* Gwyndolin =  new Mage  ( "Gwyndolin", 200, 100, 40, 40, 50, 'm', 1);
    Monster* Darklurker = new Mage  ("Darklurker", 220, 110, 50, 50, 50, 'm', 1);
    Monster* Kalameet =   new Winged(  "Kalameet", 300,  80, 30, 50, 70, 'w', 1);
    Monster* Sinh =       new Winged(      "Sinh", 250,  90, 20, 50, 70, 'w', 1);

    //Inserting monsters in player's grimoire
    playerG->InsertMonster(Smough);
    playerG->InsertMonster(Cinder);
    playerG->InsertMonster(Gwyndolin);
    playerG->InsertMonster(Darklurker);
    playerG->InsertMonster(Kalameet);
    playerG->InsertMonster(Sinh);

    int playerChoice;
    int aiChoice;

    while (playerG->getQuantity() != 0 && aiG->getQuantity() != 0){

        cout << "CHOOSE YOUR MONSTER:\n";
        for (int i=1; i <= playerG->getQuantity(); i++){
            cout << "(" << i << ")" << " " << playerG->get(i)->getName();
            if (playerG->get(i)->getType() == 'b'){
                cout << " (Beast)\n";
            }
            else if (playerG->get(i)->getType() == 'm'){
                cout << " (Mage)\n";
            }
            else {
                cout << " (Winged)\n";
            }
        }

        cout << "Select: ";
        cin >> playerChoice;
        while (playerChoice < 1 || playerChoice > playerG->getQuantity()){
            cout << "ERROR! Select a number between 1 and 6: ";
            cin >> playerChoice;
        }
        cout << "You chose -> " << playerG->get(playerChoice)->getName() << endl;

        aiChoice = 1 + (rand() % aiG->getQuantity());
        cout << "AI chose -> " << aiG->get(aiChoice)->getName() << endl;

        cout << endl;

        cout << ">> FIGHT! <<\n\n";

        //Updates the monster's data for the player
        string namePlayer = playerG->get(playerChoice)->getName();
        float healthPlayer = playerG->get(playerChoice)->getHealth();
        float strengthPlayer = playerG->get(playerChoice)->getStrength();
        float spiritPlayer = playerG->get(playerChoice)->getSpirit();
        float vitalityPlayer = playerG->get(playerChoice)->getVitality();
        float accuracyPlayer = playerG->get(playerChoice)->getAccuracy();
        int skillPlayer = playerG->get(playerChoice)->getSkill();
        char typePlayer = playerG->get(playerChoice)->getType();

        //Updates the monster's data for the AI
        string nameAI = aiG->get(aiChoice)->getName();
        float healthAI = aiG->get(aiChoice)->getHealth();
        float strengthAI = aiG->get(aiChoice)->getStrength();
        float spiritAI = aiG->get(aiChoice)->getSpirit();
        float vitalityAI = aiG->get(aiChoice)->getVitality();
        float accuracyAI = aiG->get(aiChoice)->getAccuracy();
        int skillAI = aiG->get(aiChoice)->getSkill();
        char typeAI = aiG->get(aiChoice)->getType();

        //Player advantages
        if ((typePlayer == 'b' && typeAI == 'm') || (typePlayer == 'm' && typeAI == 'w') || (typePlayer == 'w' && typeAI == 'b')){
            strengthPlayer = strengthPlayer*1.1;
        }
        //AI advantages
        if ((typePlayer == 'm' && typeAI == 'b') || (typePlayer == 'w' && typeAI == 'm') || (typePlayer == 'b' && typeAI == 'w')){
            strengthAI = strengthAI*1.1;
        }

        int answer;
        int answerAI;

        while (healthPlayer > 0 && healthAI > 0){

            cout << namePlayer << " current health -> " << healthPlayer << endl;
            cout << nameAI << " current health -> " << healthAI << endl;
            cout << endl;
            if (skillPlayer == 1){
                cout << "Do you want to use your skill now? (1)Yes (2)No\n";
                cout << "-> ";
                cin >> answer;
                cout << endl;
            }

            answerAI = 1 + (rand() % 2);

            //Applying Fury/Magic Point/Agility skills for the AI
            if (answerAI == 1 && skillAI == 1){
                skillAI = 0;
                if (typeAI == 'b'){
                    strengthAI = strengthAI*1.5;
                    healthAI = healthAI*1.5;
                    cout << "POWER UP (STR X1,5/HP X1,5)!\n";
                    cout << "strength = " << strengthAI << endl;
                    cout << "HEALTH = " << healthAI << endl << endl;
                }
                else if (typeAI == 'm'){
                    strengthAI = strengthAI*1.25;
                    vitalityAI = vitalityAI*1.5;
                    cout << "POWER UP (STR X1,25/VIT X1,5)!\n\n";
                    cout << "strength = " << strengthAI << endl;
                    cout << "VITALITY = " << vitalityAI << endl << endl;
                }
                else {
                    strengthAI = strengthAI*2;
                    accuracyAI = 100;
                    cout << "POWER UP (2X HITS/100% ACC)!\n\n";
                }
            }

            //Applying Fury/Magic Point/Agility skills for the player
            if (answer == 1 && skillPlayer == 1){
                skillPlayer = 0;
                if (typePlayer == 'b'){
                    strengthPlayer = strengthPlayer*1.5;
                    healthPlayer = healthPlayer*1.5;
                    cout << "POWER UP (STR X1,5/HP X1,5)!\n\n";
                    cout << "strength = " << strengthPlayer << endl;
                    cout << "HEALTH = " << healthPlayer << endl << endl;
                }
                else if (typePlayer == 'm'){
                    strengthPlayer = strengthPlayer*1.25;
                    vitalityPlayer = vitalityPlayer*1.5;
                    cout << "POWER UP (STR X1,25/VIT X1,5)!\n\n";
                    cout << "strength = " << strengthPlayer << endl;
                    cout << "VITALITY = " << vitalityPlayer << endl << endl;
                }
                else {
                    strengthPlayer = strengthPlayer*2;
                    accuracyPlayer = 100;
                    cout << "POWER UP (2X HITS/100% ACC)!\n\n";
                }
            }

            int hit;
            hit = 1 + (rand() % 100); //Hit chance

            if (hit <= accuracyPlayer){ //Calculating if the player hit
                //Testing which defense the AI will use and applying damage
                cout << "YOUR ATTACK HIT!\n";
                if (typePlayer == 'm'){
                    healthAI = healthAI - (strengthPlayer-spiritAI);
                }
                else {
                    healthAI = healthAI - (strengthPlayer-vitalityAI);
                }
            }
            else {
                cout << "YOUR ATTACK MISSED...\n";
            }

            if (hit <= accuracyAI){//Calculating if the AI hit
                //Testing which defense the player will use and applying damage
                cout << "AI'S ATTACK HIT...\n\n";
                if (typeAI == 'm'){
                    healthPlayer = healthPlayer - (strengthAI-spiritPlayer);
                }
                else {
                    healthPlayer = healthPlayer - (strengthAI-vitalityPlayer);
                }
            }
            else {
                cout << "AI'S ATTACK MISSED!\n\n";
            }
        }

        if (healthAI <= 0){
            cout << "YOU DEFEATED HIS MONSTER!\n\n";
            aiG->RemoveMonster(aiG->get(aiChoice));
        }
        else {
            cout << "YOUR MONSTER WAS DEFEATED...\n\n";
            playerG->RemoveMonster(playerG->get(playerChoice));
        }

         if (playerG->getQuantity() == 0 || aiG->getQuantity() == 0){

            if (playerG->getQuantity() == 0){

                cout << "You've lost all your monsters...\n";
                cout << "Now you have access to the Ether!\n";
                cout << "You must play Jokenpo against the great Saruman to recover some monsters.\n";
                cout << "You have 5 tries...!\n\n";

                int jkpPlayer;
                int jkpSaruman;
                int result;
                int monsterCounter = 0;

                for (int i=0; i<5; i++){
                    cout << "Select: Rock(1), Paper(2) or Scissors(3)\n";
                    cin >> jkpPlayer;
                    jkpSaruman = 1 + (rand() % 3);
                    result = jokenpo::comparison(jkpPlayer, jkpSaruman);
                    if (result == 1){
                        jokenpo::YouWin();
                        ++monsterCounter;
                    }
                    else if (result == 0){
                        jokenpo::Tied();
                    }
                    else {
                        jokenpo::YouLose();
                    }
                }

                for (int i=0; i<monsterCounter; i++){
                    Monster* sarumanMonster = sarumanG->getRandomMonster();
                    playerG->InsertMonster(sarumanMonster);
                }
            }

            else if (aiG->getQuantity() == 0){

                cout << "The AI have lost all its monster!\n";
                cout << "Now the AI have access to the Ether!\n";
                cout << "AI is playing Jokenpo against Saruman...\n\n";

                int jkpAI;
                int jkpSaruman;
                int result;
                int monsterCounter = 0;

                for (int i=0; i<5; i++){
                    jkpAI = 1 + (rand() % 3);
                    jkpSaruman = 1 + (rand() % 3);
                    result = jokenpo::comparison(jkpAI, jkpSaruman);
                    if (result == 1){
                        ++monsterCounter;
                    }
                }

                for (int i=0; i<monsterCounter; i++){
                    Monster* sarumanMonster = sarumanG->getRandomMonster();
                    aiG->InsertMonster(sarumanMonster);
                }
            }
        }
    }

    if (aiG->getQuantity() == 0 && playerG->getQuantity() > 0){
        cout << ">>> YOU WON!!! <<<\n";
    }
    else if (aiG->getQuantity() > 0 && playerG->getQuantity() == 0) {
        cout << ">>> YOU LOST... <<<\n";
    }

    delete playerG;
    delete aiG;
    delete sarumanG;

    return 0;
}
