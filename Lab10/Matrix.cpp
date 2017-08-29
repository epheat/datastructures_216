//course: CS216-00x
//Project: Lab Assignment 10
//Date: 04/14/2015
//File: Matrix.cpp
//Purpose: to define the class Matrix
//Author: (your name)

#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int sizeX, int sizeY) : dx(sizeX), dy(sizeY)
{
	assert(sizeX > 0 && sizeY > 0);
	p = new long*[dx];		
				// create array of pointers to long integers
	assert(p != 0);
	for (int i = 0; i < dx; i++)
	{	  // for each pointer, create array of long integers
		p[i] = new long[dy];  
		assert(p[i] != 0);
		for (int j = 0; j < dy; j++)
			p[i][j] = 0;
	}
	//cout << "CreatedObject\n";
}

Matrix::Matrix(const Matrix& M) {
	dx = M.dx;
	dy = M.dy;
	p = new long*[dx];
	for (int i=0;i<dx;i++)
	{
		p[i] = new long[dy];
		for (int j=0;j<dy;j++)
			p[i][j] = M.p[i][j];
	}
	//cout << "CopyCreated\n";
}

Matrix::~Matrix()
{
	for (int i = 0; i < dx; i++)
		delete [] p[i];	// delete arrays of long integers
	delete [] p;	// delete array of pointers to long
}

long &Matrix::Element(int x, int y)
{
	assert(x >= 0 && x < dx && y >= 0 && y < dy);
	return p[x][y];
}

void Matrix::Print() const
{
	cout << endl;
	for (int x = 0; x < dx; x++)
	{
		for (int y = 0; y < dy; y++)
			cout << p[x][y] << "\t";
		cout << endl;
	}
}

Matrix operator+(const Matrix& M1, const Matrix& M2) {
	int sampledx,sampledy;
	if (M1.dx < M2.dx)
		sampledx = M1.dx;
	else
		sampledx = M2.dx;

	if (M1.dy < M2.dy)
		sampledy = M1.dy;
	else
		sampledy = M2.dy;

	Matrix sample(sampledx, sampledy);
	for (int i=0;i<sampledx;i++)
	{
		for (int j=0;j<sampledy;j++)
		{
			sample.p[i][j] = M1.p[i][j] + M2.p[i][j];
		}
	}
	return sample;
}

Matrix operator*(const Matrix& M1, const Matrix& M2) {
	int sampledx,sampledy;
	if (M1.dx < M2.dx)
		sampledx = M1.dx;
	else
		sampledx = M2.dx;

	if (M1.dy < M2.dy)
		sampledy = M1.dy;
	else
		sampledy = M2.dy;
	cout << "sampledx: " << sampledx << "sampledy: " << sampledy << "\n";
	Matrix sample(sampledx, sampledy);
	for (int i=0;i<sampledx;i++)
	{
		for (int j=0;j<sampledy;j++)
		{
			sample.p[i][j] = M1.p[i][j] * M2.p[i][j];
		}
	}
	sample.Print();
	return sample;
}

Matrix operator*(int factor, const Matrix& M) {
	Matrix sample(M.dx, M.dy);
	for (int i=0;i<M.dx;i++)
	{
		for (int j=0;j<M.dy;j++)
		{
			sample.p[i][j] = M.p[i][j] * factor;
		}
	}
	return sample;
}

Matrix operator*(const Matrix& M, int factor) {
	Matrix sample(M.dx, M.dy);
	for (int i=0;i<M.dx;i++)
	{
		for (int j=0;j<M.dy;j++)
		{
			sample.p[i][j] = M.p[i][j] * factor;
		}
	}
	return sample;
}

void Matrix::operator=(const Matrix& M) {
	for (int i = 0; i < dx; i++)
                delete [] p[i]; // delete arrays of long integers
        delete [] p;    // delete array of pointers to long
	
	dx = M.dx;
	dy = M.dy;

	p = new long*[dx];
	for (int i = 0; i < dx; i++)
	{         // for each pointer, create array of long integers
	        p[i] = new long[dy];
	        for (int j = 0; j < dy; j++)
	                p[i][j] = M.p[i][j];
	}	
}

long& Matrix::operator() (int x, int y)
{
	return p[x][y];
}

ostream& operator<<(ostream &out, const Matrix& M)
{
	for (int i=0;i<M.dx;i++)
	{
		for (int j=0;j<M.dy;j++)
		{
			out << M.p[i][j] << "\t";
		}
		out << "\n";
	}
	return out;
}
