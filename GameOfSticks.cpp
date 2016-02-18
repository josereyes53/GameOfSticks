/*
 * José A. Reyes Zayas
 * 801-14-6087
 *
 * The following is an implementation
 * of the Game of Sticks in C++
 *
 * We'll be defining a void function (gameOfSticks)
 * for convenience.
 *
 * In gameOfSticks we'll define three integer variables:
 *     sticksOnTable; initialized at 1 because, in addition
 *         to it storing the inital numbers of sticks on the table,
 *         it will serve as the condition for the do while loop for
 *         the game itself
 *     playerOneSticks; where player one's choice each turn will be stored
 *     playerTwoSticks; where player two's choice each turn will be stored
 *
 * Pseudocode:
 *
 * Output welcome message
 * Input initial number of sticks on table
 * Check that the number meets the condition (10-100)
 *
 * REPEAT
 *     Input player one's choice
 *     Check that the choice meets the condition (1-3)
 *
 *     Update the number of sticks on table
 *
 *     If the number of sticks left is zero or less
 *         player one loses
 *
 *     Input player two's choice
 *     Check that the choice meets the condition (1-3)
 *
 *     Update the number of sticks on table
 *
 *     If the number of sticks left is zero or less
 *         player two loses loses
 * UNTIL no more sticks on table
 *
 * For Human vs AI, we will randomly choose a number for
 * the AI based upon the number of sticks on the table.
 * A vector of vectors will be populated by the possible
 * choices every step of the game, and every winning step
 * by the AI will be added to the vector and as such, there
 * will be a higher probablity of the AI choosing winning moves.
 *
 * For AI vs AI, the same will occur, but between two vectors.
 * Afterwards, the human player shall play agasint the winning AI.
 *
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void gameOfSticks() {

    srand(time(NULL));

    int sticksOnTable, playerOneSticks, playerTwoSticks, gameOption, ctr = 1, sticksForAI;
    int aiOneSticks, aiTwoSticks;
    int playAgain;

    do {

        //Output welcome message
        //Input initial number of sticks on table
        //Check that the number meets the condition (10-100)

        cout << "Welcome to the game of sticks!\n"
             << "How many sticks are there on the table initially (10-100)? ";
        cin >> sticksOnTable;
        sticksForAI = sticksOnTable;

        while (sticksOnTable < 10 || sticksOnTable > 100) {
            cout << "Please enter a number between 10 and 100\n"
                 << "How many sticks are there on the table initially (10-100)? ";
            cin >> sticksOnTable;
        }

        cout << "\nOptions:\n"
             << " Play against a friend (1)\n"
             << " Play against the computer (2)\n"
             << " Play against a trained computer (3)\n"
             << "Which option do you take (1-3)? ";
        cin >> gameOption;

        //REPEAT [...] UNTIL
        while (gameOption == 1) {
            //Output formatting (There is/There are)
            if (sticksOnTable == 1)
                cout << "\nThere is " << sticksOnTable << " stick on the board.\n";
            else cout << "\nThere are " << sticksOnTable << " sticks on the board.\n";

            //Player one input
            cout << "Player 1: How many do you take? (1-3) ";
            cin >> playerOneSticks;

            while (playerOneSticks < 1 || playerOneSticks > 3) {
                cout << "Please enter a number between 1 and 3\n"
                     << "Player 1: How many sticks do you take (1-3)? ";
                cin >> playerOneSticks;
            }

            //Update number of sticks on table
            sticksOnTable -= playerOneSticks;

            //If no sticks left, player one loses
            if (sticksOnTable <= 0) {
                cout << "Player 1, you lose.\n";
                break;
            }

            //Output formatting (There is/There are)
            if (sticksOnTable == 1)
                cout << "\nThere is " << sticksOnTable << " stick on the board.\n";
            else cout << "\nThere are " << sticksOnTable << " sticks on the board.\n";

            //Player two input
            cout << "Player 2: How many do you take? (1-3) ";
            cin >> playerTwoSticks;

            while (playerTwoSticks < 1 || playerTwoSticks > 3) {
                cout << "Please enter a number between 1 and 3\n"
                     << "Player 2: How many sticks do you take (1-3)? ";
                cin >> playerTwoSticks;
            }

            //Update number of sticks on table.
            sticksOnTable -= playerTwoSticks;

            //If no sticks left, player two loses
            if (sticksOnTable <= 0) {
                cout << "Player 2, you lose.\n";
                break;
            }

        }

        //Creation of AI vectors
        vector<vector<int>> aiOneChoice(sticksOnTable+1, vector<int> {1,2,3});
        vector<vector<int>> aiTwoChoice(sticksOnTable+1, vector<int> {1,2,3});


        while (gameOption == 2) {

            //Output formatting (There is/There are)
            if (sticksOnTable == 1)
                cout << "\nThere is " << sticksOnTable << " stick on the board.\n";
            else cout << "\nThere are " << sticksOnTable << " sticks on the board.\n";

            //Player one input
            cout << "Player 1: How many do you take? (1-3) ";
            cin >> playerOneSticks;

            while (playerOneSticks < 1 || playerOneSticks > 3) {
                cout << "Please enter a number between 1 and 3\n"
                     << "Player 1: How many sticks do you take (1-3)? ";
                cin >> playerOneSticks;
            }

            //Update number of sticks on table
            sticksOnTable -= playerOneSticks;

            //If no sticks left, player one loses
            if (sticksOnTable <= 0) {
                cout << "Player 1, you lose.\n";
                break;
            }

            //Output formatting (There is/There are)
            if (sticksOnTable == 1)
                cout << "\nThere is " << sticksOnTable << " stick on the board.\n";
            else cout << "\nThere are " << sticksOnTable << " sticks on the board.\n";

            //AI's choice based on the number of sticks on the table, and size
            //of every vector corresponding to the number of sticks on the table.
            playerTwoSticks = aiOneChoice[sticksOnTable][rand() % aiOneChoice[sticksOnTable].size()];

            cout << "The AI chooses " << playerTwoSticks << " sticks.\n";

            //Update number of sticks on table.
            sticksOnTable -= playerTwoSticks;

            //If no sticks left, AI loses
            if (sticksOnTable <= 0) {
                cout << "The AI loses.\n";
                aiOneChoice.clear();
                break;
            }

            //The AI's choice is added to to vector that corresponds to the
            //number of stick on the table at that point
            aiOneChoice[sticksOnTable].push_back(playerOneSticks);
        }

        if (gameOption == 3) cout << "Please wait, training AI...\n";

        while (gameOption == 3) {

            while (ctr <= 100000) {

                aiOneSticks = aiOneChoice[sticksOnTable][rand() % aiOneChoice[sticksOnTable].size()];

                if (sticksOnTable == 3) {
                    aiOneSticks = 2;
                }

                if (sticksOnTable <= 2) {
                    aiOneSticks = 1;
                }

                //Update number of sticks on table.


                //If no sticks left, AI loses
                if (sticksOnTable -= aiOneSticks <= 0) {
                     //Output formatting (There is/There are)
                    if (sticksForAI == 1)
                        cout << "\nThere is " << sticksForAI << " stick on the board.\n";
                    else cout << "\nThere are " << sticksForAI << " sticks on the board.\n";

                    //Player one input
                    cout << "Player 1: How many do you take? (1-3) ";
                    cin >> playerOneSticks;

                    while (playerOneSticks < 1 || playerOneSticks > 3) {
                        cout << "Please enter a number between 1 and 3\n"
                             << "Player 1: How many sticks do you take (1-3)? ";
                        cin >> playerOneSticks;
                    }

                    //Update number of sticks on table
                    sticksForAI -= playerOneSticks;

                    //If no sticks left, player one loses
                    if (sticksForAI <= 0) {
                        cout << "Player 1, you lose.\n";
                        exit(1);
                    }

                    //Output formatting (There is/There are)
                    if (sticksForAI == 1)
                        cout << "\nThere is " << sticksForAI << " stick on the board.\n";
                    else cout << "\nThere are " << sticksForAI << " sticks on the board.\n";

                    if (sticksForAI == 3) {
                        playerTwoSticks = 2;
                    }

                    else if (sticksForAI <= 2) {
                        playerTwoSticks = 1;
                    }

                    else playerTwoSticks = aiOneChoice[sticksForAI][rand() % aiOneChoice[sticksForAI].size()];

                    cout << "The AI chooses " << playerTwoSticks << " sticks.\n";

                    //Update number of sticks on table.
                    sticksForAI -= playerTwoSticks;

                    //If no sticks left, AI loses
                    if (sticksForAI <= 0) {
                        cout << "The AI loses.\n";
                        aiOneChoice.clear();
                        exit(1);

                        }

                    }

                aiOneChoice[sticksOnTable].push_back(aiOneSticks);

                aiTwoSticks = aiTwoChoice[sticksOnTable][rand() % aiTwoChoice[sticksOnTable].size()];

                if (sticksOnTable == 3) {
                    aiTwoSticks = 2;
                }

                if (sticksOnTable <= 2) {
                    aiTwoSticks = 1;
                }

                //Update number of sticks on table.


                //If no sticks left, AI loses
                if (sticksOnTable -= aiTwoSticks <= 0) {
                    //Output formatting (There is/There are)
                    if (sticksForAI == 1)
                        cout << "\nThere is " << sticksForAI << " stick on the board.\n";
                    else cout << "\nThere are " << sticksForAI << " sticks on the board.\n";

                    //Player one input
                    cout << "Player 1: How many do you take? (1-3) ";
                    cin >> playerOneSticks;

                    while (playerOneSticks < 1 || playerOneSticks > 3) {
                        cout << "Please enter a number between 1 and 3\n"
                             << "Player 1: How many sticks do you take (1-3)? ";
                        cin >> playerOneSticks;
                    }

                    //Update number of sticks on table
                    sticksForAI -= playerOneSticks;

                    //If no sticks left, player one loses
                    if (sticksForAI <= 0) {
                        cout << "Player 1, you lose.\n";
                        exit(1);
                    }

                    //Output formatting (There is/There are)
                    if (sticksForAI == 1)
                        cout << "\nThere is " << sticksForAI << " stick on the board.\n";
                    else cout << "\nThere are " << sticksForAI << " sticks on the board.\n";

                    if (sticksForAI == 3) {
                        playerTwoSticks = 2;
                    }

                    else if (sticksForAI <= 2) {
                        playerTwoSticks = 1;
                    }

                    else playerTwoSticks = aiTwoChoice[sticksForAI][rand() % aiTwoChoice[sticksForAI].size()];

                    cout << "The AI chooses " << playerTwoSticks << " sticks.\n";

                    //Update number of sticks on table.
                    sticksForAI -= playerTwoSticks;

                    //If no sticks left, AI loses
                    if (sticksForAI <= 0) {
                        cout << "The AI loses.\n";
                        //aiOneChoice.clear();
                        exit(1);

                    }

                }
            }

                aiTwoChoice[sticksOnTable].push_back(aiTwoSticks);

                ctr++;
        }

        cout << "\nEnter the number 1 if you wish to play again: ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 1);



}

int main() {

    gameOfSticks();

    return 0;
}
