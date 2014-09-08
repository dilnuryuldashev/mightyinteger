//
//  MightyInteger.h
//  MightyInteger
//
//  Created by Dilnur Yuldashev on 2/25/14.
//  Copyright (c) 2014 Dilnur Yuldashev. All rights reserved.
//

//MightyIntegers.h-MightyIntegers class declaration
//Written by D. Yuldashev

#pragma once
#include<iostream>
#include<string>

using namespace std;

class MightyInteger{
public:
	//default constructor
	MightyInteger();
	//init constructor
	MightyInteger(string number);
	// Destructor
	//~MightyInteger();
	// Assignment operator to perform deep copy
	MightyInteger& operator = (const MightyInteger& source);
	// Returns a reference to a single character from this MightyInteger
	int& operator [] (int index) const;
	//unary - operator
	MightyInteger operator -();
	//returns an absolute value of a number
	MightyInteger AbsoluteValue();
	//returs the sum of two MightyIntegers
	MightyInteger operator + (const MightyInteger& myInteger) const;
	//returs the subtraction result of one MightyInteger from another
	MightyInteger operator - (const MightyInteger& myInteger) const;
	//returs the multiplication of two MightyIntegers
	MightyInteger operator * (const MightyInteger& myInteger) const;
	//returs the division result of two MightyIntegers
	MightyInteger operator / (const MightyInteger& myInteger) const;
	//returs the remainder of the division of two MightyIntegers
	MightyInteger operator % (const MightyInteger& myInteger) const;
	// Comparison operators
	bool operator == (const MightyInteger& compareTo) const;
	bool operator != (const MightyInteger& compareTo) const;
	bool operator > (const MightyInteger& compareTo) const;
	bool operator < (const MightyInteger& compareTo) const;
	//returns (*this)^exponent
	MightyInteger Power(int exponent) const;
	//returns factorial(*this)--1*2*3.......(*this)
	MightyInteger Factorial() const;
	//return the square root of (*this)
	MightyInteger Sqrt() const;
	//returnd the logarithm of (*this) base
	int Log(const MightyInteger& compareTo) const;
	//returns the size of a MightyInteger
	int GetSize() const;
	//returns the string version a MightyInteger
	string ToString() const;
private:
	string Number;
	long Size;
	//not that this function is const
	//so the original class string Number
	//should not be given in here
	void minusOperatorInMind(string &a, long index, int &subtract) const;
	bool isNegative() const;
};

// Stream output operator to print String to output stream
ostream& operator << (ostream& out, const MightyInteger &myInteger);
