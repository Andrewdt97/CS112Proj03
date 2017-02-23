/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Andrew Thomas (adt8)
 * Date: Febuary 21, 2017
 * CS112 Lab03
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <cassert>
#include <fstream>
using namespace std;
//////////////////////////////////////////////
// Constructors and Deconstructors
//////////////////////////////////////////////

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size) {
	mySize = size;
	if (size != 0) {
		myArray = new Item[size]();
	} else {
		myArray = NULL;
	}

}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0 ) {
		myArray = new Item[original.mySize];
		for (unsigned i = 0; i < original.mySize; i++) {
			myArray[i] = original.myArray[i];
		}

	} else {
	myArray = NULL;
	}
  }

Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}



//////////////////////////////////////////////
// Operators
//////////////////////////////////////////////


Vec& Vec::operator=(const Vec& original) {
	/*Assingment operator method
	 * @param: original, a Vec
	 * Precondition: An existing Vec
	 * Return: Copy of the original vec into whatever assignment was performed on
	 */
	if (myArray != original.myArray) {

		}
		if (mySize != original.mySize) {
			if (mySize > 0) {
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}

		for (unsigned i = 0; i < mySize; i++) {
			myArray[i]=original.myArray[i];
		}
     return *this;
  }

bool Vec::operator==(const Vec& v2) {
	/*Equality operator method
	 * @param: v2, a Vec
	 * Precondition: Two existing Vecs
	 * Return: A bool declaring if they are equal or not
	 */
	if (mySize != v2.mySize) {
		return false;
	} else {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] != v2.myArray[i]) { return false;}
		}
	}
	return true;
}

//////////////////////////////////////////////
// Setters
//////////////////////////////////////////////
void Vec::setItem(unsigned index, const Item& it) {
	/* Sets item at index to it
	 * @param: index, an unsigned
	 * @param: it, an Item
	 * Precondition: A valid index and an Item
	 * Postcondition: it placed into the vector at slot index
	 */
	if (index >= mySize) {
		throw range_error("Vec::setItem(): Bad Index");
	} else {
		myArray[index] = it;
	}
}


void Vec::setSize(unsigned newSize) {
	/* Sets the size of the vector and copies over values as needed
	 * @param: newSize, an unsigned
	 * Precondition: An existing Vec
	 * Postcondition: A copy of the original Vec with whatever newSize is requested
	 */
	if (mySize != newSize) {
		if (newSize == 0) {
			mySize = 0;
			delete [] myArray;
			myArray = NULL;
		} else {

			Item* tempArray = myArray;
			myArray = new Item[newSize];

			if (newSize > mySize) {

				for (unsigned i = 0; i < mySize; i++) {
					myArray[i] = tempArray[i];
				}
				for (unsigned i = mySize; i < newSize; i++) {
					myArray[i] = Item();
				}
			} else {
				for (unsigned i = 0; i < newSize; i++) {
								myArray[i] = tempArray[i];
				}
			}
			mySize = newSize;
			delete [] tempArray;
		}
	}
}

//////////////////////////////////////////////
// Getters
//////////////////////////////////////////////
unsigned Vec::getItem(unsigned index) const{
	if (index >= mySize) {
		throw range_error("Vec::getItem(): Bad index");
	} else {
		return myArray[index];
	}
}






//////////////////////////////////////////////
// Read and Write
//////////////////////////////////////////////
void Vec::writeTo(ostream& out) const {
	/* Writes the content of the array to out
	 * @param: out, an ostream
	 * Precondition: An existing Vec and open ostream
	 * Postcondition: The array printed to whatever out is requested
	 */
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << " " << flush;
	}
	out << endl;
}

void Vec::readFrom(istream& in) {
	/* Reads the contents from in and puts them in an array
	 * @param: in, an istream
	 * Precondition: An existing Vec and open istream
	 * Postcondition: Contents from in put into an array
	 */
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}


//////////////////////////////////////////////
// End Lab and Start Project
//////////////////////////////////////////////

Item& Vec::operator[](unsigned i) const {
	/* Subscript operator for read
	 * @param: i, an unsgined index
	 * Return: The object at the i index of myArray
	 * Andrew Thomas
	 */
	if ( i >= mySize ) {
		throw range_error("Subscript []: bad index");
	}
	return myArray[i];
}


Item& Vec::operator[](unsigned i) {
	/* Subscript operator for write
	 * @param: i, an unsgined index
	 * Return: The object at the i index of myArray
	 * Andrew Thomas
	 */
	if ( i >= mySize ) {
		throw range_error("Subscript []: bad index");
	}
	return myArray[i];
}

void Vec::writeTo(string fileName) const{
	/* Writes array to file of fileName
	 * @param: fileName, a string
	 * Precondtion: A Vec and a valid fileName
	 * Postcodition: The Vec is written to the file and can be read with readFrom()
	 * Andrew Thomas (adt8)
	 */
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );
	fout << mySize << "\n";
	for (unsigned i = 0; i < mySize; i++) {
		fout << myArray[i] << "\n";;
	}
	fout.close();

}

Vec Vec::operator+(const Vec& vec2) {
	/* Adds two Vecs together
	 * @param: vec2, a Vec
	 * Precondtion: Two Vecs
	 * Return: a Vec is returned with each item of the two inputs added together
	 * Andrew Thomas (adt8)
	 */
	if (mySize != vec2.getSize()) {
		throw invalid_argument("Vec operator+: Vecs are different sizes");
	}
	Vec returnVec(mySize);
	for (unsigned i = 0; i < mySize; i++) {
		returnVec[i] = myArray[i] + vec2[i];
	}

	return returnVec;
}

Item Vec::operator*(const Vec& vec2){
	/* Gets the dot product of two Vecs
	 * @param: vec2, a Vec
	 * Precondtion: Two Vecs
	 * Return: The summation of the products of each item in the two Vecs
	 * Andrew Thomas (adt8)
	 */
	if (mySize != vec2.getSize()) {
		throw invalid_argument("Vec operator*: Vecs are different sizes");
	}
	Item returnVal = Item();
	for (unsigned i = 0; i < mySize; i++) {
		returnVal += myArray[i] * vec2[i];
	}

	return returnVal;
}
