#include <iostream>
#include <string.h>

int finalplay1Score = 0;
int finalplay2Score = 0;
int gameResult = 0;
int play1Count = 0;
int play2Count = 0;
int play1Foul = 0;
int play2Foul = 0;
std::string outcome;
class Play
{
public:
    int play1Score;
    int play2Score;
    int play1History;
    int play2History;
    int moves;
    int count;
    std::string outcome;
    Play()
    {
        play1Score = 0;
        play2Score = 0;
        play1History = 0;
        play2History = 0;
        moves = 0;
        count = 0;
    }
    bool checkplaysc()
    { //Check Player's Score
        if (play1Score >= 5 || play2Score >= 5)
            return true;

        return false;
    }
    void updateplaysc(int player, int score)
    { //Update Player Score
        if (player == 1)
        {
            play1Score = play1Score + score;
        }
        else
            play2Score = play2Score + score;
    }
    void clearcount(int player) // Clearing "Does Not Pocket A Coin" Count
    {
        if (player == 1)
        {
            play1Count = 0;
        }
        else
        {

            play2Count = 0;
        }
    }
    int history(int player) // Keeping track of player history
    {

        if (player == 1)
        {
            play1Count = 0;
            return play1History;
        }
        else
        {

            play2Count = 0;
            return play2History;
        }
    }

    void updateplayerhistory(int player)
    { //Update Player History
        if (player == 1)
            play1History = play1Score;
        else
            play2History = play2Score;
    }
    bool gamewin()
    { //Checking Win Condition - For While Loop
        if (gameResult == 1)
            return true;
        else
            return false;
    }
    std::string gameresult()
    { //Winner Declaration

        if (play1Score > play2Score && ((play1Score - play2Score) >= 3))
        {
            finalplay1Score = play1Score;
            finalplay2Score = play2Score;
            gameResult = 1;
            return "Player 1";
        }
        else if ((play1Score < play2Score) && ((play2Score - play1Score) >= 3))
        {
            finalplay1Score = play1Score;
            finalplay2Score = play2Score;
            gameResult = 1;
            return "Player 2";
        }
        finalplay1Score = play1Score;
        finalplay2Score = play2Score;
        gameResult = 1;
        return "Draw";
    }

    void playeremptymoves(int player)
    { //When a player does not pocket a coin for 3 successive turns he/she loses a point

        if (player == 1)
            play1Count++;
        else
            play2Count++;

        if (play1Count >= 3)
        {
            play1Score--;
            play1Count = 0;
        }
        if (play2Count >= 3)
        {
            play2Score--;
            play2Count = 0;
        }
    }

    void playerfoulcount(int player)
    { //When a player fouls 3 times (a foul is a turn where a player loses, at least, 1 point),he/she loses an additional point
        if (player == 1)
            play1Foul++;
        else
            play2Foul++;
        if (play1Count >= 3)
        {
            play1Score--;
            play1Foul = 0;
        }
        if (play2Count >= 3)
        {
            play2Score--;
            play2Foul = 0;
        }
    }

    int scoreddifference()
    { //Leading Points Condition
        if (play1Score > play2Score)
            return play1Score - play2Score;
        else
            return play2Score - play1Score;
    }
};
