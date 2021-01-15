class Carrom
{
public:
    int black; // variable for no. of black coins 
    int red; // variable for no. of red coin 
    Carrom()
    {
        black = 9;
        red = 1;
    }
    int strike()
    {
        if (black == 0)
            return 0;
        black--;
        return 1;
    }
    int multistrick()
    {
        if (black == 0)
            return 0;
        black = black - 2;
        return 2;
    }
    int redstrike()
    {
        if (red == 0)
            return 0;

        red--;
        return 3;
    }
    int striker()
    {
        return -1;
    }
    int defunct()
    {
        if (black == 0)
            return 0;
        black--;
        return -2;
    }
    int emptyStrike()
    {
        return 0;
    }
    bool coinCheck()
    {
        if (black == 0 && red == 0)
            return true;
        else
            return false;
    }
};