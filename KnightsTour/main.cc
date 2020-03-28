// AUTHOR: Austin Rafuls
#include <iostream>
#include <iomanip>

// Define our board and initialize it to zero.
const int RC = 8;
int matrix[RC][RC] = { { 0,0 },{ 0,0 } };

/*
NAME
	bool Move(int row, int col, int step)
PARAMS
	int row		<-- Represents what row we are accessing.
	int col		<-- Represents what column we are accessing.
	int step	<-- Represents what step we are on in the Knight's Tour.
PURPOSE
	A recursive function that solves for the Knight's Tour by attempted to
	access locations on the board.
RETURNS
	Returns a bool representing success or failure when trying to a location.
*/
bool Move(int row, int col, int step)
{
	/* Already Vistited Condition */
	if (matrix[row][col] != 0) { return false; }
	/* Out-of-Bounds Condition */
	else if (row < 0 || row > (RC-1) || col < 0 || col > (RC-1)) { return false; }
	/* Valid Move Condition */
	else 
	{ 
		matrix[row][col] = step;

		/* Completed Tour Condition */
		if ( step == (RC*RC) ) { return true; }
	}

	/* Knight Movement */
	/* These are recursive calls that will return either true or false. */
	//std::cout << "Recursive call " << step << " executed." << std::endl;
	if      ( Move(row+2, col+1, step+1) ) { return true; } // Down 2, Right 1
	else if ( Move(row+1, col+2, step+1) ) { return true; } // Down 1, Right 2
	else if ( Move(row+1, col-2, step+1) ) { return true; } // Down 1, Left 2
	else if ( Move(row+2, col-1, step+1) ) { return true; } // Down 2, Left 1
	else if ( Move(row-1, col+2, step+1) ) { return true; } // Up 1, Right 2
	else if ( Move(row-2, col-1, step+1) ) { return true; } // Up 2, Left 1
	else if ( Move(row-2, col+1, step+1) ) { return true; } // Up 2, Right 1
	else if ( Move(row-1, col-2, step+1) ) { return true; } // Up 1, Left 2
	else
	{
		// None of the above moves were valid, set current tile to zero and
		// return false to return to the previous call on the stack.
		matrix[row][col] = 0;
		return false;
	}
}

/*
NAME
	void DisplayMatrix()
PARAMS

PURPOSE
	Displays our matrix to standard out.
RETURNS
	
*/
void DisplayMatrix()
{
	for (int i = 0; i < RC; i++)
	{
		for (int j = 0; j < RC; j++)
		{
			std::cout << std::setw(3) << matrix[i][j];
		}
		std::cout << std::endl;
	}
}


/* <----------------------> Driver Code <----------------------> */
int main()
{
	Move(0,0,1);
	DisplayMatrix();
	return 0;
}