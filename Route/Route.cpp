// Route.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include "RouteExaminer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Point2D Target;
	Point2D* ForbiddenSquares;
	int ForbiddenCount;
	RouteExaminer* RouteCounter;
	int NumberOfRoutes;

	wcout << L"Enter column and row of target: ";
	wcin >> Target;

	wcout << L"Enter number of forbidden squares: ";
	wcin >> ForbiddenCount;
	ForbiddenSquares = new Point2D[ForbiddenCount];
	
	for (size_t i = 0; i < ForbiddenCount; i++)
	{
		wcout << L"Square #" << i << L": ";
		wcin >> ForbiddenSquares[i];
	}

	RouteCounter = new RouteExaminer(Target, ForbiddenSquares, ForbiddenCount);
	NumberOfRoutes = RouteCounter->GetRoutesCount();
	delete RouteCounter;

	// Print the result.
	wcout << L"Number of routes: " << NumberOfRoutes << endl;

	return 0;
}

