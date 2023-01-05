#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
using namespace std;

int mode, scorep1 = 0, scorep2 = 0;
string p1name, p2name;

void playgamevscom();
void playgamevsplayer();
void rules();

void wrongkey(char& playerchoose){
    while (playerchoose != 's' && playerchoose != 'r' && playerchoose != 'p')
    {
         system("color 04");
        
        cout << "\nYou chose wrong key!\nPlease check the rules of the game.";
        rules(); 
       
        cout << "\n\nChoose:---------\n\n";
        cin >> playerchoose; 
        system("color 0A");
    }
}

void endres()
{
    cout << "\n";
    if (scorep1 > scorep2)
        cout << p1name << " Won" << endl;
    else if (scorep2 > scorep1)
        cout << p2name << " Won" << endl;
    else
        cout << "It's a draw" << endl;
}

void scoreboard(int value)
{
    if (value == 1)
        scorep1++;
    if (value == 2)
        scorep2++;
    cout << endl;
    if (mode == 2)
        cout << p1name << " " << scorep1 << " - " << scorep2 << " " << p2name << endl;
    else
        cout << p1name << " " << scorep1 << " - " << scorep2 << " Computer" << endl;
}

void rps(char s)
{
    if (s == 'r')
        cout << "Rock";
    if (s == 'p')
        cout << "Paper";
    if (s == 's')
        cout << "Scissor";
}

void rules()
{
    cout << "\nRules:---------" << endl;
    cout << "1. Press p for Paper, r for Rock, s for Scissor" << endl;
    cout << "2. Rock can break Scissor, Scissor can cut Paper and Paper can catch a Rock" << endl;
    cout << "3. Whoever wins gets a point." << endl;
}

void windrawlosevscom(int value)
{
    cout << endl;
    if (value == 0)
    {
        cout << "Draw" << endl;
    }
    else if (value == 1)
    {
        cout << "You Won" << endl;
    }
    else
    {
        cout << "You Lose" << endl;
    }
}

void windrawlosevsplayer(int value, char p1choose, char p2choose)
{
    cout << endl;
    cout << p1name << " chose ";
    rps(p1choose);
    cout << ", " << p2name << " chose ";
    rps(p2choose);
    cout << "\n\n";
    if (value == 0)
    {
        cout << "Draw" << endl;
    }
    else if (value == 1)
    {
        cout << p1name << " Won" << endl;
    }
    else
    {
        cout << p2name << " Won" << endl;
    }
    scoreboard(value);
}

void result(char playerchoose, char comchoose)
{
    int value;
    if (playerchoose == 'r')
    {
        if (comchoose == 'r')
            value = 0;
        else if (comchoose == 'p')
            value = 2;
        else
            value = 1;
    }
    if (playerchoose == 'p')
    {
        if (comchoose == 'p')
            value = 0;
        else if (comchoose == 's')
            value = 2;
        else
            value = 1;
    }
    if (playerchoose == 's')
    {
        if (comchoose == 's')
            value = 0;
        else if (comchoose == 'r')
            value = 2;
        else
            value = 1;
    }
    if (mode == 1)
    {
        windrawlosevscom(value);
        scoreboard(value);
    }
    else if (mode == 2)
        windrawlosevsplayer(value, playerchoose, comchoose);
}

void playagain()
{
    cout << "\n\nDo you want to play again? (Press 'y' to play again or any other key to quit the game.)" << endl;
    char b;
    cin >> b;
    if (b == 'y')
        playgamevscom();
    else
        return;
}

void playgamevscom()
{
     system("color 0A");
    cout << "\n\nChoose:---------\n\n";
    char playerchoose, comchoose;
    cin >> playerchoose;
    wrongkey(playerchoose);
    cout << "You chose ";
    rps(playerchoose);
    cout << "\n\n";
    int comvalue = rand();
    comvalue %= 3;
    cout << "Computer chooses.";
    usleep(500000);
    cout << ".";
    usleep(500000);
    cout << ".";
    usleep(500000);
    cout << ".";
    usleep(500000);
    if (comvalue == 0)
    {
        comchoose = 'r';
    }
    else if (comvalue == 1)
    {
        comchoose = 'p';
    }
    else if (comvalue == 2)
    {
        comchoose = 's';
    }
    rps(comchoose);
    cout << "\n";
    result(playerchoose, comchoose);
    playagain();
}

void playgamevsplayer()
{
     system("color 0A");
    char player1choose, player2choose;
    cout << endl;
    cout << p1name << " choose now: " << endl;
    cin >> player1choose;
    wrongkey(player1choose);
    system("CLS");
    cout << endl;
    cout << p2name << " choose now: " << endl;
    cin >> player2choose;
    wrongkey(player2choose);
    result(player1choose, player2choose);
}

int main()
{
   system("color E");
    char s;
    cout << "\n----------Rock Paper Scissor----------\n\n";
    cout << "Do you want to play Rock Paper Scissors?\n";
    cout << "Press 'y' to start playing the game or press any other key to exit.\n";
    cin >> s;
    if (s == 'y')
    {
        system("CLS");
        cout << "\nLet's start\n\nDo you know the rules? (Press 'n' to read the rules.)" << endl;
        cin >> s;
        if (s == 'n')
            rules();
        cout << "\n";
        cout << "Which Mode do you want to play?" << endl;
        cout << "1. Play with Computer." << endl;
        cout << "2. Play a series with your friend" << endl;
        cout << "(Press '1' or '2' to make your choice.)" << endl;
        cin >> mode;
        if (mode == 1)
        {
            system("CLS");
            cout << "Enter your name: " << endl;
            cin >> p1name;
            playgamevscom();
        }
        else if (mode == 2)
        {
            system("CLS");
            cout << "Enter name of Player 1: " << endl;
            cin >> p1name;
            cout << "\nEnter name of Player 2: " << endl;
            cin >> p2name;
            int n;
            cout << "\nHow many matches will be in the series?" << endl;
            cin >> n;
            while (n--)
                playgamevsplayer();
            endres();
        }
        else
            cout << "You chose wrong key!\n";
    }
    cout << "\nHave a good day!"<<endl;
}