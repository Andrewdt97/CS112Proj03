/* Vec.h provides a simple vector class named Vec.
 * Student Name: Andrew Thomas (adt8)
 * Date: Febuary 21, 2017
 * CS112 Lab03
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	// Constructors and Deconstructors
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();

	// Operators
	Vec& operator=(const Vec& original);
    bool operator==(const Vec& v2);
    Item& operator[](unsigned i);
    Item& operator[](unsigned i) const;
    Vec operator+(const Vec& vec2);
    Item operator*(const Vec& vec2);

    // Getters
	unsigned getSize() const { return mySize;}
	unsigned getItem(unsigned index) const;

	// Setters
	void setSize(unsigned newSize);
	void setItem(unsigned index, const Item& it);

	// Read and Write
    void writeTo(ostream& out) const;
    void writeTo(string fileName) const;
    void readFrom(istream& in);


private:
	unsigned mySize;
	Item* myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
