//File: Matrix.h
//Purpose: to declare the class Matrix
//Author: (your name)

#ifndef MATRIX_H
#define	MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
	long **p;       // pointer to a pointer to a long integer
	int dx, dy;

  public:
	  //operators are gucci
	  friend Matrix operator+ (const Matrix& M1, const Matrix& M2);
	  friend Matrix operator* (const Matrix& M1, const Matrix& M2);
	  friend Matrix operator* (const Matrix& M1, int factor);
	  friend Matrix operator* (int factor, const Matrix& M1);
	  void operator= (const Matrix&);
	  long& operator() (int, int);
	  friend ostream& operator<<(ostream &, const Matrix&);


	  Matrix(int sizeX, int sizeY);
	  Matrix(const Matrix& M);
	  ~Matrix();
	  int GetSizeX() const { return dx; }
	  int GetSizeY() const { return dy; }
	  long &Element(int x, int y);        // return reference to an element
	  void Print() const;
};



#endif	/* MATRIX_H */

