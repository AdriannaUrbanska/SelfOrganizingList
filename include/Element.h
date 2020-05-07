#pragma once
#include <iostream>

/** Template class which keeps one element of the list. */
template <typename T>
class Element
{
	T data;	/** Value of the data stored in the element. */

public:
	
	Element <T> * next; /** Next neighbor of the element. */
	Element <T> * prev;	/** Previous neighbor of the element. */

	Element( T _data ) : data{_data} {}

	/**
	*	Method which returns value of the element.
	*/
	T GetData() const
	{
		return data;
	}
};
