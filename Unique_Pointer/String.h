#pragma once
#include <iterator>     // std::iterator, std::input_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
class String
{
public:
	String();
	String(const char* givenString);
	~String();

	String(const String& string);//Copy Constructor
	String(String&& string)noexcept;//Move Constructor
	String& operator=(const String& rhs); //Copyassignment
	String& operator=(String&& rhs)noexcept; //Moveassignment

	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	char* operator+(const String& rhs);
	char* operator+(const char* rhs);
	operator const char* () { return this->string; };

	void stringcpy(char* destination, int length, const char* content);
	void stringcat(char* destination, int length, const char* content);

	void append(const String& stringToAppend);
	int length(const char* toLength);
	int olength();
	const char* c_str();



	class Iterator
	{
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = const char;
		using pointer = const char*;  // or also value_type*
		using reference = const char&;  // or also value_type&

		Iterator(pointer ptr) : pter(ptr) {}

		Iterator& operator=(const char* pointer);//*  removed
		void operator++();
		void operator--();
		bool operator==(const Iterator it);
		bool operator!=(const Iterator it);
		reference operator*();
		const char* operator->();
		const char* getAdress();//*  removed

		operator const char* () { return this->pter; };

	private:
		pointer pter;//*  removed
	};
	String::Iterator begin();
	String::Iterator end();
private:
	using iterator_category = std::forward_iterator_tag;
	char* string;
	char* add(const char* rhs);
};

