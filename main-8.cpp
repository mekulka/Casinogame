#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
using namespace std;
 
void drawLine(int n, char symbol);
void rules();
 
int main()
{
    string playerName;
    int amount; // hold the players balance 
    int bettingAmount; 
    int guess;
    int dice; // hold generated number
    char choice;
 
    srand(time(0)); 

    drawLine(60,'_');
    cout << "\n\n\n\tWelcome to Matts Casino!\t\n\n\n\n";
    drawLine(60,'_');
 
    cout << "\n\nWhat is your name? : ";
    getline(cin, playerName);
 
    cout << "\n\nHow much would you like to deposit into your casino account?: $";
    cin >> amount;
    
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current casino balance is $ " << amount << "\n";
		
		// Get player's betting amount
        do
        {
            cout <<playerName<<", enter betting amount : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current casino balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
		// Get the players number
        do
        {
            cout << "Guess a number to bet that is between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check your number!! your number should be between 1 and 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
    drawLine(70,'=');
 
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tHow to play\n";
    drawLine(80,'-');
    cout << "\t1. You will choose a number between 1 and 10\n";
    cout << "\t2. If your number is correct you will get 10 times your betting amount\n";
    cout << "\t3. If you bet on wrong number you will lose the amount that you bet\n\n";
    drawLine(80,'-');
}


