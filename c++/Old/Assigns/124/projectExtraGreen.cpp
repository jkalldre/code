/***********************************************************************
* Program:
*    Project 4, Sudoku          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*    
*   Program is a Sudoku game. Program will open an indicated file,   
*   receive and respond to user input and then save the game to a
*   target location indicated by the user.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void getFileName(char fileName[]);
int readFile(char fileName[], int board[][9]);
void fileWrite(char writeFile[], int board[][9]);
void getWriteFile(char writeFile[]);
void userInput(char writeFile[], int board[][9]);
void display(int board[][9]);
int editSquare(int board[][9]);
int possibleVal(int board[][9]);

/************************************************************************
 * main serves to call all the other functions and hold the values of   *
 * variables obtained through other functions, it will show the initial *
 * instructions to player of how to navigate the game.                  *
 ************************************************************************/
int main(int argc, char** argv)
{
   char fileName[256];
   char writeFile[256];

   if (argc > 1)
      strcpy(fileName, argv[1]);
   
   else
      getFileName(fileName);
   
   int board[9][9];
   int size = readFile(fileName, board);

   if (size != -1)
   {
      cout << "Options:\n"
           << "   ?  Show these instructions\n"
           << "   D  Display the board\n"
           << "   E  Edit one square\n"
           << "   S  Show the possible values for a square\n"
           << "   Q  Save and Quit\n" << endl;

      display(board);
      
      userInput(writeFile, board);

      cout << "Board written sucessfully\n";
   }
   
   return 0;
}

/*********************************************************************
 * getFileName will simply retrieve the desired board to play sudoku *
 *********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
   
   return;
}

/***********************************************************************
 * readFile is a standard read file function to retrieve the requested *
 * board to be displayed and/ modified                                 *
 ***********************************************************************/
int readFile(char fileName[], int board[][9])
{
   ifstream fin(fileName);

   if (fin.fail())
      return -1;

   int i = 0;
   for (int y = 0; y < 9; y++)
   {
      for (int x = 0; x < 9; x++)
         fin >> board[y][x];
      i++;
   }

   fin.close();
   
   return i;
}

/*******************************************************************
 * getWriteFile will received desired file save location from user *
 *******************************************************************/
void getWriteFile(char writeFile[])
{
   cout << "What file would you like to write your board to: ";
   cin >> writeFile;
   return;
}

/**********************************************************************
 * fileWrite will write the retrieved file and save it to the same or *
 * a new location                                                     *
 **********************************************************************/
void fileWrite(char writeFile[], int board[][9])
{
   ofstream fout(writeFile);

   for (int y = 0; y < 9; y++)
   {
      for (int x = 0; x < 9; x++)
         fout << board[y][x] << " ";
      fout << endl;
   }

   fout.close();
}

/*********************************************************************
 * userInput runs a loop so the user can navigate the game. They can *
 * choose between several options to edit / display / save the board *
 *********************************************************************/
void userInput(char writeFile[], int board[][9])
{
   char input;
              
   do
   {
      cout << "> ";
      cin >> input;
      switch(input)
         {
            case '?':
               cout << "Options:\n"
                    << "   ?  Show these instructions\n"
                    << "   D  Display the board\n"
                    << "   E  Edit one square\n"
                    << "   S  Show the possible values for a square\n"
                    << "   Q  Save and Quit\n" << endl;
               break;
            case 'D':
               display(board);
            case 'E':
               editSquare(board);
               break;
            case 'S':
               possibleVal(board);
               break;
            case 'Q':
               getWriteFile(writeFile);
               fileWrite(writeFile, board);
               break;
         }
   }
   while(input != 'Q');
}

/**********************************************************************
 * display will display the retrieved file on the screen for the user *
 **********************************************************************/
void display(int board[][9])
{
   cout << "   A B C D E F G H I\n";
   
   for (int cY = 0; cY < 9; cY++)
   {
      cout << cY + 1 << " ";
      for (int cX = 0; cX < 9; cX++)
      {
         if (cX == 2)
         {
            if (board[cY][cX] == 0)
               cout << "  |";
            else
               cout << " " << "\E[22;32m" << board[cY][cX] << "\E[0m" << "|";
         }
         
         else if (cX == 5)
         {
            if (board[cY][cX] == 0)
               if (board[cY][cX - 1] != 0)
                  cout << "  |";
               else
                  cout << " |";
            else
               cout << " " << "\E[22;32m" << board[cY][cX] << "\E[0m" << "|";
         }
         
         else
            if (cX == 3)
            {
               if (board[cY][cX] == 0)
                  cout << "  ";
               else
                  cout << "\E[22;32m" << board[cY][cX] << "\E[0m";
            }
         
            else if (cX == 6)
            {
               if (board[cY][cX] == 0)
                  cout << " ";
               else
                  cout << "\E[22;32m" << board[cY][cX] << "\E[0m";
            }
         
            else
            {
               if (board[cY][cX] == 0)
                  cout << "  ";
               else
                  if (cX == 4)
                     if (board[cY][cX - 1] != 0)
                        cout << " " << "\E[22;32m" << board[cY][cX] << "\E[0m";
                     else
                        cout << "\E[22;32m" << board[cY][cX] << "\E[0m";
                  else
                     cout << " " << "\E[22;32m" << board[cY][cX] << "\E[0m";
            }
      }
      
      cout << endl;
      
      if (cY == 2 || cY == 5)
         cout << "   -----+-----+-----\n";
   }
   
   cout << endl;
   
   return;
}

/**********************************************************************
 * editSquare will edit the coordinate selected by the user and place *
 * the requested value in the location                                *
 **********************************************************************/
int editSquare(int board[][9])
{
   cout << "What are the coordinates of the square: " << endl;
   
}

/*********************************************************************
 * possibleVal will show the user what values could potentially work *
 * in the selected coordinate                                        *
 *********************************************************************/
int possibleVal(int board[][9])
{
   cout << "What are the coordinates of the square: " << endl;
   cout << "The possible values for \'_\' are: " << endl;
}
