/***********************************************************************
* Program:
*    Assignment 40, TicTacToe          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int readFile(char fileName[], char moves[][3]);
void display(char moves[][3]);
void writeFile(char dFileName[], char moves[][3]);
void getFileName(char fileName[]);
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char dFileName[256];
   char moves[3][3];
   
   getFileName(fileName);

   int good =readFile(fileName, moves);

   if (good != -1)
      display(moves);

   cout << "Enter destination filename: ";
   cin >> dFileName;

   writeFile(dFileName, moves);
   cout << "File written\n";
   
   return 0;
}

void getFileName(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;
   return;
}

int readFile(char fileName[], char moves[][3])
{
   ifstream fin(fileName);

   if (fin.fail())
      return -1;

   for (int movesY = 0; movesY < 3; movesY++)
   {
      for (int movesX = 0; movesX < 3; movesX++)
         fin >> moves[movesY][movesX];

   }

   return 1;
}

void display(char moves[][3])
{
   for (int cY = 0; cY < 3; cY++)
   {
      for (int cX = 0; cX < 3; cX++)
      {
         if (cX == 0)
            cout << " ";
         
         cout << (moves[cY][cX] == '.' ? ' ' : moves[cY][cX])
              << (cX == 2 ? " \n" : " | ");

         if (cX == 2 && cY != 2)
            cout << "---+---+---\n";
      }
     
   }
   return;
}

void writeFile(char dFileName[], char moves[][3])
{
   ofstream fout(dFileName);

   for (int y = 0; y < 3; y++)
   {
      for (int x = 0; x < 3; x++)
         fout << moves[y][x];
   }

   fout.close();
}
