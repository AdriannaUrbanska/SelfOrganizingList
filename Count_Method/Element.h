#pragma once
#include <iostream>

/** Template class which keeps one element of the list. */
template <typename T>
class Element
{
	T data;	/** Value of the data stored in the element. */
	unsigned int count;	/** Count number of finding the data. */

public:
	
	Element <T> * next; /** Next neighbor of the element. */
	Element <T> * prev;	/** Previous neighbor of the element. */

	Element( T _data ) : data{_data}, count{0} {}

	/**
	*	Method which returns value of the element.
	*/
	T GetData() const
	{
		return data;
	}

	/**
	*	Method which returs count number of finding the data.
	*/
	T GetCount() const
	{
		return count;
	}

	/**
	*	Method which increases count number of finding the data.
	*/
	void Increase()
	{
		count++;
	}
};
