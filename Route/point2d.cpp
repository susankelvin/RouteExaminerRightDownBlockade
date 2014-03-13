#include <wchar.h>
#include "stdafx.h"

using namespace std;

wstring Point2D::ExtractDigits(wistream& is)
{
	wstring result(L"");
	wchar_t achar;

	do
	{
		achar = is.peek();
		if (!iswdigit(achar))
			break;
		is.get(achar);
		result += achar;
	} while (true);

	return result;
}

wistream& Point2D::operator >>(wistream& is)
{
	wistream::sentry sentry(is);
	wchar_t achar;
	wstring input;

	if (sentry)
	{
		X = stoi(ExtractDigits(is));
		do
		{
			is.get(achar);
		} while (iswspace(achar));
		input = achar + ExtractDigits(is);
		Y = stoi(input);
	}
	return is;
}

wistream& operator >>(wistream& is, Point2D& point)
{
	point.operator>>(is);
	return is;
}