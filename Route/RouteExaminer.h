#pragma once
#include "stdafx.h"

class RouteExaminer
{
public:
	RouteExaminer(Point2D& target, Point2D ForbiddenSquares[], int count);
	~RouteExaminer();
	int GetRoutesCount();
private:
	Point2D Target;
	Point2D* ForbiddenSquares;
	int Count;
};

