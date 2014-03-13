#pragma once
#include <string>
#include <istream>
#include "stdafx.h"

using namespace std;

struct Point2D {
	int X;
	int Y;
	wistream& operator >>(wistream& is);
protected:
	wstring ExtractDigits(wistream& is);
};

wistream& operator >>(wistream& is, Point2D& point);
