#pragma once
#include <iostream>
#include "Element.h"

template <typename T>
class List
{
public:

	Element <T> * head; /** Head element of the list. */
	Element <T> * tail; /** Tail element of the list. */

	List();

	/**
	*	Destructor which deletes all elements from the list by using PopFront() function.
	*/
	~List();

	/**
	*	Method which finds given value and replaces the whole element with the previous one.
	*/
	Element <T> * Find( T _data );

	/**
	*	Methods which prints all elements from the list.
	*/
	void Print() const;

	/**
	*	Methods which insterts new element at the beginning of the list.
	*/
	void PushFront(T _data);

	/**
	*	Methods which removes the first element of the list.
	*/
	void PopFront();
};


template <typename T>
List<T>::List() : head{nullptr}, tail{nullptr} {}

template <typename T>
List<T>::~List() 
{
	while( head )
		PopFront();
}

template <typename T>
Element <T> * List<T>::Find( T _data )
{
	Element <T> * ptr = head;

	// Iteration through the list until an element is found.
	while( ptr )
	{
		if( ptr->GetData() == _data )
		{
			// Moving the found element out of the list.

			// If there is no previous element than found element was a head and remains a head.
			if( ptr->prev )
				ptr->prev->next = ptr->next;
			else
				break;

			// If there is no next element than found element was a tail.
			if( ptr->next )
				ptr->next->prev = ptr->prev;
			else
				tail = ptr->prev;

			// Inserting the found element between previous of the previous element and previous element.
			ptr->next = ptr->prev;
			ptr->prev = ptr->next->prev;
			ptr->next->prev = ptr;

			// If there is no previous element than now the found element is a head.
			if( ptr->prev )
				ptr->prev->next = ptr;
			else
				head = ptr;
			
			break;
		}

		ptr = ptr->next;
	}
	
	if( !ptr )
		std::cout << "Element not found." << std::endl;

	return ptr;
}


template <typename T>
void List<T>::Print() const
{
	if( !head )
	{
		std::cout << "List is empty." <<std::endl;
		return;
	}

	Element <T> * ptr = head;
	
	std::cout << "List: ";

	while(ptr)
	{
		std::cout << ptr->GetData() << " ";
		ptr = ptr->next;
	}

	std::cout << std::endl;
}

template <typename T>
void List<T>::PushFront(T _data)
{
	Element <T> * ptr = new Element <T>(_data);

	// Inserted element become a new head.
	ptr->prev = nullptr;
	ptr->next = head;


	// If there is no tail than now the list has one element with head equal to tail.
	if( tail )
		head->prev = ptr;
	else
		tail = ptr;

	head = ptr;
}

template <typename T>
void List<T>::PopFront()
{
	if( head )
	{
		Element <T> * ptr = head;

		// Setting a new head.
		head = ptr->next;

		// If there is no head than the list is empty.
		if( head )
			head->prev = nullptr;
		else
			tail = nullptr;

		delete ptr;
	}
}
