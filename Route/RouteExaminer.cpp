#include "stdafx.h"
#include "RouteExaminer.h"


RouteExaminer::RouteExaminer(Point2D& target, Point2D ForbiddenSquares[], int count)
{
	Target = target;
	this->ForbiddenSquares = ForbiddenSquares;
	Count = count;
}


RouteExaminer::~RouteExaminer()
{
}

int RouteExaminer::GetRoutesCount()
{
	int** matrix;
	int LastRowBlock = -1;
	int LastColumnBlock = -1;
	int Routes;

	// Allocate and zerofy matrix.
	matrix = new int*[Target.X + 1];
	for (size_t i = 0; i <= Target.X; i++)
	{
		matrix[i] = new int[Target.Y + 1];
		for (size_t j = 0; j <= Target.Y; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (size_t i = 0; i < Count; i++)
	{
		// Save location of rightmost/bottommost forbidden square last row and column.
		if ((ForbiddenSquares[i].Y == Target.Y) && (ForbiddenSquares[i].X > LastColumnBlock))
		{
			LastColumnBlock = ForbiddenSquares[i].X;
		}
		else if ((ForbiddenSquares[i].X == Target.X) && (ForbiddenSquares[i].Y > LastRowBlock))
		{
			LastRowBlock = ForbiddenSquares[i].Y;
		}
		else
		{
			matrix[ForbiddenSquares[i].X][ForbiddenSquares[i].Y] = -1;
		}
	}

	// Set up last row and column.
	for (size_t i = LastColumnBlock + 1; i <= Target.Y; i++)
	{
		matrix[Target.X][i] = 1;
	}
	for (size_t i = LastRowBlock + 1; i <= Target.X; i++)
	{
		matrix[i][Target.Y] = 1;
	}

	// Solve the problem with dynamic programming.
	for (int row = Target.Y - 1; row >= 0; row--)
	{
		for (int column = Target.X - 1; column >= 0; column--)
		{
			if (matrix[column][row] != -1)
			{
				matrix[column][row] = matrix[column + 1][row] + matrix[column][row + 1];
			}
			else
			{
				matrix[column][row] = 0;
			}
		}
	}

	Routes = matrix[0][0];

	// Release memory.
	for (size_t i = 0; i <= Target.X; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return Routes;
}