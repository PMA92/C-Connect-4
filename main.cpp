/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int ROWS = 6;
int COLS = 7;
int CONNECT = 4;

string board[6][7] = {
  {"x", "x", "x", "x", "x", "x", "x"}
  ,
  {"x", "x", "x", "x", "x", "x", "x"}
  ,
  {"x", "x", "x", "x", "x", "x", "x"}
  ,
  {"x", "x", "x", "x", "x", "x", "x"}
  ,
  {"x", "x", "x", "x", "x", "x", "x"}
  ,
  {"x", "x", "x", "x", "x", "x", "x"}
  ,
};

bool
checkWin (string board[6][7], string player)
{
  // Check horizontally
  for (int i = 0; i < ROWS; ++i)
    {
      for (int j = 0; j <= COLS - CONNECT; ++j)
	{
	  bool win = true;
	  for (int k = 0; k < CONNECT; ++k)
	    {
	      if (board[i][j + k] != player)
		{
		  win = false;
		  break;
		}
	    }
	  if (win)
	    {
	      return true;
	    }
	}
    }

  // Check vertically
  for (int i = 0; i <= ROWS - CONNECT; ++i)
    {
      for (int j = 0; j < COLS; ++j)
	{
	  bool win = true;
	  for (int k = 0; k < CONNECT; ++k)
	    {
	      if (board[i + k][j] != player)
		{
		  win = false;
		  break;
		}
	    }
	  if (win)
	    {
	      return true;
	    }
	}
    }

  // Check diagonally (positive slope)
  for (int i = 0; i <= ROWS - CONNECT; ++i)
    {
      for (int j = 0; j <= COLS - CONNECT; ++j)
	{
	  bool win = true;
	  for (int k = 0; k < CONNECT; ++k)
	    {
	      if (board[i + k][j + k] != player)
		{
		  win = false;
		  break;
		}
	    }
	  if (win)
	    {
	      return true;
	    }
	}
    }

  // Check diagonally (negative slope)
  for (int i = CONNECT - 1; i < ROWS; ++i)
    {
      for (int j = 0; j <= COLS - CONNECT; ++j)
	{
	  bool win = true;
	  for (int k = 0; k < CONNECT; ++k)
	    {
	      if (board[i - k][j + k] != player)
		{
		  win = false;
		  break;
		}
	    }
	  if (win)
	    {
	      return true;
	    }
	}
    }

  return false;			// No winner
}

bool
checkTie (string board[6][7], int rows, int columns)
{
  int xCount = 0;
  for (int x = 0; x < rows; x++)
    {
      for (int y = 0; y < columns; y++)
	{

	  if (board[x][y] == "x")
	    {
	      xCount++;
	    }
	}
    }
  if (xCount == 0)
    {
      return true;
    }
  else
    {
      return false;
    }

}

bool
availableSpace (string board[6][7], int row, int column)
{
  if (board[row][column - 1] == "x")
    {
      return true;
    }
  else
    {
      return false;
    }

}

int
firstAvailableSpot (string board[6][7], int sizeOfRow, int column)
{
  for (int x = 5; x < sizeOfRow; x--)
    {
      if (availableSpace (board, x, column) == 1)
	{
	  return x;
	  break;
	}
    }
}

void
print2dArray (string board[6][7], int sizeOfRow, int sizeOfCol)
{


  for (int x = 0; x < sizeOfRow; x++)
    {

      cout << "\n";
      for (int y = 0; y < sizeOfCol; y++)
	{

	  cout << board[x][y] << " ";
	}
    }
}


int
main ()
{
  int slot;
  print2dArray (board, 6, 7);
  cout << "\n" << "Here's your connect 4 board." << "\n" <<
    "This requires two people taking turns. " << "\n";
  int turn = 0;
  bool win = false;
  
  while (win == false)
    {
      cout << "Pick a column to place your piece(Only numbers 1-7): ";
      cin >> slot;

      if (turn % 2 == 0)
	{
	  board[firstAvailableSpot (board, 6, slot)][slot - 1] = "I";
	}
      else
	{
	  board[firstAvailableSpot (board, 6, slot)][slot - 1] = "O";
	}




      turn++;
      print2dArray (board, 6, 7);
      cout << "\n" << "\n";
      
      if (checkWin (board, "I") == 1)
	{
	  win = true;
	}
      if (checkWin (board, "O") == 1)
	{
	  win = true;
	}
      if (checkTie (board, 6, 7) == 1)
	{
	  win = true;
	}
    }
  print2dArray (board, 6, 7);
  cout << "\n";
  if (checkTie (board, 6, 7) == 0)
    {
      if ((turn % 2) - 1 == 0)
	{
	  cout << "Congrats, player 1 wins!";
	}
      else
	{
	  cout << "Congrats, player 2 Won!";
	}
    }
  else
    {
      cout << "Tie game.";
    }


  return 0;


}



