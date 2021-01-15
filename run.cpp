// Clean Strike Game
#include <iostream>
#include <string> // include string library for string functions
#include "modules/play.cpp" // included manually created headers
#include "modules/carrom.cpp"
using namespace std;
// change the input.txt to input[1..3].txt for testing other testcases 
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main()
{
    OJ;
    string score; // final score
    int option; // command line option
    int result; 
    int player = 1;
    Carrom cleanstrikeboard; // created objects of Carrom
    Play gameplayers; // created object of Play
    while (gameplayers.gamewin() != true)
    {
        player = (player + 1) % 2;
        if (((gameplayers.checkplaysc() == true) && (gameplayers.scoreddifference() >= 3)) || (cleanstrikeboard.coinCheck()))
        {
            score = gameplayers.gameresult();
            cout << score << " won the game."
                 << " Final Score: " << finalplay1Score << '-' << finalplay2Score;
            break;
        }

        cout << endl
             << "Player " << player + 1 << ": Choose an outcome from the list below" << endl;
        cout << "1. Strike" << endl;
        cout << "2. Multi Strike" << endl;
        cout << "3. Red Strike" << endl;
        cout << "4. Striker Strike" << endl;
        cout << "5. Defunct Coin" << endl;
        cout << "6. None" << endl;
        cout << "Current Score" << endl
             << "Player 1 Score: " << gameplayers.play1Score << endl
             << "Player 2 Score: " << gameplayers.play2Score;
        cout << endl
             << "Type Your Option";
        cin >> option;
        if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6)
        {
            cout << endl
                 << "Wrong Option Try Again";
            player = (player + 1) % 2;
            continue;
        }
        if (cleanstrikeboard.red < 1 && option == 3)
        {
            cout << endl
                 << "There are not enough red coins on the board";
            cout << endl
                 << "Red coin left on board are: " << cleanstrikeboard.red;
            player = (player + 1) % 2;
            continue;
        }
        if (cleanstrikeboard.black < 2 && option == 2 || cleanstrikeboard.black < 1 && option == 1 || cleanstrikeboard.black <= 0 && option == 5)
        {
            cout << endl
                 << "There are not enough black coins on the board";
            cout << endl
                 << "Black coin left on board are: " << cleanstrikeboard.black;
            player = (player + 1) % 2;
            continue;
        }
        if (option == 1)
        {
            gameplayers.clearcount(player + 1);
            result = cleanstrikeboard.strike();
            gameplayers.updateplaysc(player + 1, result);
            outcome = "Strike";
            gameplayers.history(player + 1);
        }
        if (option == 2)
        {
            gameplayers.clearcount(player + 1);
            result = cleanstrikeboard.multistrick();
            gameplayers.updateplaysc(player + 1, result);
            outcome = "MultiStrike";

            gameplayers.history(player + 1);
        }
        if (option == 3)
        {
            gameplayers.clearcount(player + 1);
            result = cleanstrikeboard.redstrike();
            gameplayers.updateplaysc(player + 1, result);
            outcome = "RedStrike";
            gameplayers.history(player + 1);
        }
        if (option == 4)
        {
            gameplayers.clearcount(player + 1);
            result = cleanstrikeboard.striker();
            gameplayers.updateplaysc(player + 1, result);
            outcome = "StrikerStrike";
            gameplayers.history(player + 1);
            gameplayers.playerfoulcount(player + 1);
        }
        if (option == 5)
        {
            result = cleanstrikeboard.defunct();
            gameplayers.updateplaysc(player + 1, result);
            outcome = "Defunct";
            gameplayers.history(player + 1);
            gameplayers.playerfoulcount(player + 1);
        }
        if (option == 6)
        {
            result = cleanstrikeboard.emptyStrike();
            gameplayers.updateplaysc(player + 1, result);
            outcome = "Empty";
            gameplayers.playeremptymoves(player + 1);
            gameplayers.updateplayerhistory(player + 1);
        }
    }
    
    return 0;
}