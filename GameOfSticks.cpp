#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void gameOfSticks() {

    srand(time(NULL));

    int sticksOnTable, playerOneSticks, playerTwoSticks, gameOption;

    int playAgain;

    do {

        //Output welcome message
        //Input initial number of sticks on table
        //Check that the number meets the condition (10-100)

        cout << "Welcome to the game of sticks!\n"
             << "How many sticks are there on the table initially (10-100)? ";
        cin >> sticksOnTable;
        while (sticksOnTable < 10 || sticksOnTable > 100) {
            cout << "Please enter a number between 10 and 100\n"
                 << "How many sticks are there on the table initially (10-100)? ";
            cin >> sticksOnTable;
        }

        cout << "\nOptions:\n"
             << " Play against a friend (1)\n"
             << " Play against the computer (2)\n"
             << "Which option do you take (1-2)? ";
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

            vector<vector<int>> hat (sticksOnTable, vector<int> {1,2,3});

            playerTwoSticks = rand() % hat[sticksOnTable-1].size() + 1 ;

            vector<int> beside (sticksOnTable);

            beside[sticksOnTable] = playerTwoSticks;

            cout << "The AI chooses " << playerTwoSticks << " sticks.\n";

            //Update number of sticks on table.
            sticksOnTable -= playerTwoSticks;



            //If no sticks left, AI loses
            if (sticksOnTable <= 0) {
                cout << "The AI loses.\n";
                break;
            }

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
