#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
using namespace std;

void rules();

void rollingDice()
{
    system("cls");
    cout << "ROLLING THE DICE";
    for (int i = 0; i < 5; i++)
    {
        Sleep(300);
        cout << ".";
    }
    system("cls");
}

void startGame(string name, int balance)
{
    system("cls");
    srand(time(0));
    int bet, n;
    do
    {
        do
        {
            cout << "=========================ENTER -99 AS BET AMOUNT TO EXIT APPLICATION=========================\n\n\n";
            cout << name << " your balance is " << balance << "$" << endl;
            cout << "\nEnter the amount of bet to be placed: ";
            cin >> bet;
            if (bet > balance)
            {
                cout << "\nBet cant be greater than current Balance!\n";
                Sleep(3000);
            }
            else if (bet == -99)
            {
                system("cls");
                cout << "\nTHANKS FOR PLAYING, SEE YOU SOON!\n";
                Sleep(3000);
                exit(1);
            }
            else if (bet <= 0 && bet != -99)
            {
                cout << "\nARE YOU JOKING? WHO PLACES SUCH A BET!\n";
                Sleep(3000);
            }
            system("cls");
        } while (bet > balance || bet <= 0);

        do
        {
            cout << name << " your balance is " << balance << "$" << endl;
            cout << "Your Bet amount is: " << bet << "$" << endl;
            cout << "\n\nSelect a number between 1 and 10: ";
            cin >> n;
            if (n < 1 || n > 10)
            {
                cout << "\nEntered Number isn't between 1-10\n";
                Sleep(4000);
            }
            system("cls");
        } while (n < 1 || n > 10);

        int num = rand() % 10 + 1;

        rollingDice();

        if (n == num)
        {
            system("cls");
            string winMessage = "CONGRATULATIONS YOU WON!\nYOUR CURRENT BALANCE IS: ";
            for (int i = 0; i < winMessage.length(); i++)
            {
                Sleep(30);
                cout << winMessage[i];
            }
            balance += 2 * bet;
            cout << balance << "$" << endl
                 << endl;
            system("PAUSE");
            system("cls");
        }
        else
        {
            system("cls");
            string loseMessage = "SORRY! YOU LOST.\nYOUR CURRENT BALANCE IS: ";
            for (int i = 0; i < loseMessage.length(); i++)
            {
                Sleep(30);
                cout << loseMessage[i];
            }
            balance -= bet;
            cout << balance << "$";
            cout << "\n\nThe Lottery number was: " << num << endl
                 << endl;
            system("PAUSE");
            system("cls");
        }
    } while (balance > 0);

    string endMessage = "YOUR CURRENT BALANCE IS: ";
    cout << endMessage;
    cout << balance << endl
         << endl;

    string GameOver = "GAME OVER!\n";
    for (int i = 0; i < GameOver.length(); i++)
    {
        Sleep(300);
        cout << GameOver[i];
    }
    Sleep(2000);
    system("cls");
    cout << "SEE YOU SOON!\n\n";
    cout << "CODE BY ANSHUMAN SINGH\n\n";
    system("PAUSE");
}

int main()
{
    string name;
    cout << "\n=========================WELCOME TO ROYAL CASINO!=========================\n";
    cout << "\nPlease Enter You Name: ";
    cin >> name;
    system("cls");
    string welcome = "WELCOME ||" + name + "||\n\n";
    for (int i = 0; i < welcome.length(); i++)
    {
        cout << welcome[i];
    }
    rules();
    int balance;

    do
    {
        cout << "\n\nENTER THE AMOUNT YOU WANNA START WITH: ";
        cin >> balance;
        if (balance <= 0)
        {
            cout << "\nEnter Positive Amount!\n\n";
        }
    } while (balance <= 0);

    startGame(name, balance);

    return 0;
}

void rules()
{
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 2 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
