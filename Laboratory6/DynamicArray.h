#pragma once
#include "OfferTest.h"
#include <string>
#include <ostream>
//using namespace std;

using std::ostream;

//typedef Offer ElementType;

template<typename ElementType>

class DynamicArray
{
public:
	DynamicArray(int capacity = 100) {
		length = 0;
		this->capacity = capacity;
		data = new ElementType[capacity]();

		/*if (data == nullptr) {
			cerr << "DynamicArray(): failed to allocate memory" << endl;
			exit(-1);
			throw(-1);
		}*/
	}

	// RULE OF THREE 
	// destructor
	~DynamicArray() {
		//free the allocated memory
		delete[] data;
	}

	// copy constructor
	DynamicArray(const DynamicArray& other) {
		// deep copy of other
		length = other.length;
		capacity = other.capacity;

		// !! data 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		data = new ElementType[other.capacity]();

		//if (data == nullptr) {
		//	cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
		//	exit(-1);
		//}

		for (unsigned int i = 0; i < length; i++)
			data[i] = other.data[i];
	}

	// assignment operator
	DynamicArray& operator=(const DynamicArray& other) {

		if (this != &other) { // self assignment check
			// deep copy of other
			length = other.length;
			capacity = other.capacity;

			delete[] this->data;
			// !! data 
			// data = other.data; NOO! this is shallow copy
			// deep copy of data
			data = new ElementType[other.capacity]();

			/*if (data == nullptr) {
				cerr << "operator=(): failed to allocate memory" << endl;
				exit(-1);
			}*/

			for (unsigned int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		return *this; // the type of this is DynamicArray* -> dereferencing
	}
	// end RULE OF THREE 

	// getter for the length
	// inline - it MUST be implemented in the header
	inline unsigned int getLength() const { return length; }

	inline unsigned int getCapacity() const { return capacity; }

	// adds an element at the end
	void append(ElementType v, bool* err = nullptr)
	{
		// todo 
		// check if the length < capacity
		if (this->isElemIn(v) == false)
		{
			if (length == capacity) {
				// double the capacity
				resize(capacity * 2);
			}
			data[length] = v;
			length++;
		}
		else
		{
			throw(-1);
		}
	}

	// remove the element from the end
	// pre: the array is not empty
	ElementType popBack() {
		// delete and return the last element in the array
		// pre array is not empty
		if (length == 0) {
			// unfriendly way of handling corner cases
			/*cerr << "Precondition does not hold: popBack()" << endl;
			exit(-1);*/
			throw(-1);
		}

		// convention 0 - elements that were not set

		ElementType v = data[length - 1];
		length--;

		return v;
	}

	// remove an element from position i
	// index >= 0 and index < length
	ElementType remove(unsigned int index)
	{
		//  index >= 0 and index < length
		// pre index >=0 and index < length
		if (index >= 0 && index < length) {
			ElementType v = data[index];
			for (unsigned int i = index; i < length - 1; i++)
				data[i] = data[i + 1];
			length--;
			return v;
		}
		else {
			// unfriendly way of handling corner cases
			/*cerr << "Precondition does not hold: remove()" << endl;
			exit(-1);*/
			throw(-1);
		}
	}
	// get the element on a position
	// a[10]
	// index >= 0 and index < length
	// -1 is returned if the index is not valid
	ElementType& get(unsigned int index) {

		// pre index >=0 and index < length
		if (index >= 0 && index < length) {
			return data[index];
		}
		else {
			// unfriendly way of handling corner cases
			/*cerr << "Precondition does not hold: get()" << endl;
			exit(-1);*/
			throw(-1);
		}
	}

	// print the array
	friend ostream& operator<<(ostream& s, const DynamicArray<ElementType>& arr) {
		// [1 2 3 4 5 ]
		s << "[";
		for (unsigned int i = 0; i < arr.length; i++) {
			s << arr.data[i] << " ";
		}
		s << "]";
		return s;
	}

	// operator+ -> append a value to the array
	// opertaor belongs to the class
	// param v -> get appened at the end of the array
	//DynamicArray& operator+(int v); // operator+ -> is a method of DynamicArray

	// second way - friends (the operator does not belong to the class)
	// friend DynamicArray& operator+(DynamicArray& arr, int v);

	bool isElemIn(const ElementType v)
	{
		for (int i = 0; i < this->length; i++)
		{
			if (v == this->get(i))
				return true;
		}
		return false;
	}

	bool operator==(const DynamicArray<ElementType>& other) const
	{
		if (this->getLength() != other.getLength() || this->getCapacity() != other.getCapacity()) return false;
		for (int i = 0; i < this->getLength(); i++)
		{
			if (data[i] != other.data[i])return false;
		}
		return true;
	}

	bool operator!=(const DynamicArray<ElementType>& other) const
	{
		if (*this == other) return false;
		return true;
	}



private:
	// static -> it belongs to the class
	static int count;
	// Length � how many elements do we have(0)
	unsigned int length;
	//	Capacity � the max number of elements
	unsigned int capacity;
	// data - array itself
	ElementType* data;


	void resize(unsigned int newCapacity) {

		this->capacity = newCapacity;
		// no realloc  in c++

		ElementType* newData = new ElementType[newCapacity]();
		//if (newData == nullptr) {
		//	cerr << "resize(): failed to allocate memory" << endl;
		//	exit(-1);
		//}
		// previous elements located in data
		// copy them in newData
		for (unsigned int i = 0; i < length; i++) {
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
	}
};

