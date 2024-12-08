#include "TicTacToe.h"
#include <cstdlib>
#include <iostream>
using namespace std;

char board[3][3]; 
char player = 'X';
int plays = 0;
char winner;

// This function checks if the specified cell on the board is available
bool isAvailable(int row, int column)
{
	if (board[row][column] != '_' )
	{
	    cout << "That play has already been done" << endl;
	    return false;
	}
	return true;
}

// This function initializes the board by filling it with '_' (empty spaces)
void init()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			board[i][j] = '_';
		}
	}
}

// This function clears the console screen depending on the operating system
void clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

// This function validates if the input number is between 1 and 3
bool validate(int number){
	if(number >= 1 && number <= 3){
		return true;
	}else{
		cout << "Please pick a value between 1 and 3" << endl;
		return false;
	}
}

// This function checks if the game is over, either due to a winner or all plays being used
bool gameover()
{
    plays++;

    if (plays > 5) // Проверяем победные условия только после 5-го хода
    {
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][1] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
        else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
        else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][1] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
        else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
        else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
        else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
        else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
        else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '_')
        {
            cout << "Player " << winner << " wins!" << endl;
            return true;
        }
    }

    if (plays == 9) 
    {
        cout << "It's a draw!" << endl;
        return true;
    }

    return false;
}


// This function handles the main gameplay, allowing players to make their moves
void showBoard()
{
    while (!gameover())
    {
        winner = player == 'X' ? 'X' : 'O';
        clearScreen();
        int row = 0;
        int col = 0;

        cout << "It's " << player << "'s turn" << endl;
        // Printing column numbers
        cout << "\t";
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << "\t";
        }
        cout << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << "\t";
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
        do
        {
            cout << "In what row would you like to play? =>";
            cin >> row;
        } while (!validate(row));
        do
        {
            cout << "In what column would you like to play? => ";
            cin >> col;
        } while (!validate(col));

        if (isAvailable(row - 1, col - 1))
        {
            board[row - 1][col - 1] = player;
            player = player == 'X' ? 'O' : 'X';
        }
    }

    cout << "Do you want to play again? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        init();      
        plays = 0;   
        player = 'X'; 
        showBoard(); 
    }
    else
    {
        cout << "Thanks for playing!" << endl;
    }
}

