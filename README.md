RouteExaminerRightDownBlockade
==============================

Route examination implementation


The project is written in C++ using VS 2013.
It implements algorithm for counting all possible routes from point A to point B in two-dimensional space.

Task details:

  1) The starting point of the route is always (0, 0) point.
  2) The end point must have strictly positive coordinates.
  3) Any number of squares where the route cannot pass can exist.
  4) The only allowed directions at every step are right and down, only one at a time.
  
Implementation specifics:

  1) The algorithm uses variables of type int to perform calculations.
  2) No validation of the input data is performed.
  
