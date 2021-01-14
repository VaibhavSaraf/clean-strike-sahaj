#include <iostream>
#include <string.h>

int finalplay1sc = 0;
int finalplay2sc = 0;
int gameres = 0;
int play1count = 0;
int play2count = 0;
int play1foul = 0;
int play2foul = 0;
std::string outcome;
class Play
{
public:
    int play1sc;
    int play2sc;
    int play1his;
    int play2his;
    int moves;
    int count;
    std::string outcome;
    Play()
    {
        play1sc = 0;
        play2sc = 0;
        play1his = 0;
        play2his = 0;
        moves = 0;
        count = 0;
    }
    bool checkplaysc()
    { //Check Player's Score
        if (play1sc >= 5 || play2sc >= 5)
            return true;

        return false;
    }
    void updateplaysc(int player, int score)
    { //Update Player Score
        if (player == 1)
        {
            play1sc = play1sc + score;
        }
        else
            play2sc = play2sc + score;
    }
    void clearcount(int player) // Clearing "Does Not Pocket A Coin" Count
    {
        if (player == 1)
        {
            play1count = 0;
        }
        else
        {

            play2count = 0;
        }
    }
    int history(int player) // Keeping track of player history
    {

        if (player == 1)
        {
            play1count = 0;
            return play1his;
        }
        else
        {

            play2count = 0;
            return play2his;
        }
    }

    void updateplayerhistory(int player)
    { //Update Player History
        if (player == 1)
            play1his = play1sc;
        else
            play2his = play2sc;
    }
    bool gamewin()
    { //Checking Win Condition - For While Loop
        if (gameres == 1)
            return true;
        else
            return false;
    }
    std::string gameresult()
    { //Winner Declaration

        if (play1sc > play2sc && ((play1sc - play2sc) >= 3))
        {
            finalplay1sc = play1sc;
            finalplay2sc = play2sc;
            gameres = 1;
            return "Player 1";
        }
        else if ((play1sc < play2sc) && ((play2sc - play1sc) >= 3))
        {
            finalplay1sc = play1sc;
            finalplay2sc = play2sc;
            gameres = 1;
            return "Player 2";
        }
        finalplay1sc = play1sc;
        finalplay2sc = play2sc;
        gameres = 1;
        return "Draw";
    }

    void playeremptymoves(int player)
    { //When a player does not pocket a coin for 3 successive turns he/she loses a point

        if (player == 1)
            play1count++;
        else
            play2count++;

        if (play1count >= 3)
        {
            play1sc--;
            play1count = 0;
        }
        if (play2count >= 3)
        {
            play2sc--;
            play2count = 0;
        }
    }

    void playerfoulcount(int player)
    { //When a player fouls 3 times (a foul is a turn where a player loses, at least, 1 point),he/she loses an additional point
        if (player == 1)
            play1foul++;
        else
            play2foul++;
        if (play1count >= 3)
        {
            play1sc--;
            play1foul = 0;
        }
        if (play2count >= 3)
        {
            play2sc--;
            play2foul = 0;
        }
    }

    int scoreddifference()
    { //Leading Points Condition
        if (play1sc > play2sc)
            return play1sc - play2sc;
        else
            return play2sc - play1sc;
    }
};
