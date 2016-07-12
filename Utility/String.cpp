/*******************************************************************
Made By: Hosein Ghahremanzadeh on 7/11/2016
String.cpp String class and String manipulation functions implementation
*******************************************************************/
#define DefaultExtraAllocation					20ULL
#define DefaultAllocationAlignment				64ULL

#include "String.h"


namespace HGString
{
	bool Equals(const char chr1, const char chr2)//check if two string are equal, default test function
	{
		return chr1 == chr2;
	}

	//static member initialization
	HG_UINT64 String::ExtraAllocation = DefaultExtraAllocation;
	HG_UINT64 String::AllocationAlignment = DefaultAllocationAlignment;
	bool(*String::Equals)(const char, const char) = HGString::Equals;

	//static public fucntion implmentation
	void String::SET_EXTRA_ALLOCATION_SIZE(const HG_UINT64 ExtraAllocation = DefaultExtraAllocation)
	{
		String::ExtraAllocation = ExtraAllocation;
	}
	void String::SET_ALLOCATION_ALIGNMENT(const HG_UINT64 AllocationAlignment = DefaultAllocationAlignment)
	{
		String::AllocationAlignment = AllocationAlignment;
	}

	//private function implementation
	//memory allocation functions
	void String::allocate_memory()
	{
		size += AllocationAlignment - (size%AllocationAlignment) - 1ULL;//align the memory
		char_array = new char[size + 1ULL];//extra 1 char for the null char
	}
	void String::deallocate_memory()
	{
		delete[] char_array;
	}

	//public function implementation
	//constructor/destructor
	String::String()
	{
		size = ExtraAllocation;
		allocate_memory();//allocate memory
		char_array[0] = '\0';//string with length 0
	}
	String::String(char* str)
	{
		for (HG_UINT64 i = 0; true; ++i)
			if (String::Equals(str[i], '\0'))//early bail
			{
				size = i + 1 + ExtraAllocation;
				allocate_memory();//allocate
				break;
			}
		for (HG_UINT64 i = 0; i < size; ++i)
		{
			char_array[i] = str[i];//copy
			if (String::Equals(char_array[i], '\0'))//early bail
				break;
		}
	}
	String::String(String &str)
	{
		size = str.size;//change size
		allocate_memory();//reallocate

		for (HG_UINT64 i = 0; i < str.size; ++i)
		{
			char_array[i] = str.char_array[i];//copy
			if (String::Equals(char_array[i], '\0'))//early bail
				break;
		}
	}
	String::String(String &&str)
	{
		size = str.size;
		char_array = str.char_array;
	}
	String::~String()
	{
		size = 0;
		deallocate_memory();//deallocate memory
	}
	//== operators
	bool String::operator==(const String &str) const
	{
		return *this == str.char_array;//pass to the string==char* operator
	}
	bool String::operator==(const char* str) const
	{
		HG_UINT64 index = 0;
		while (String::Equals(char_array[index], str[index]))//while current chars are equal
		{
			if (String::Equals(char_array[index], '\0'))//string reached the null char
				return true;
			index++;
		}
		return false;
	}
	bool String::operator==(const char chr) const
	{
		return String::Equals(this->char_array[0], chr) && String::Equals(this->char_array[1], '\0');//use the equals given 
	}
	//copy operators
	String &String::operator=(const String &str)
	{
		if (size < str.size)//doesnt fit
		{
			size = str.size;//change size
			deallocate_memory();//delete memory
			allocate_memory();//reallocate
		}
		for (HG_UINT64 i = 0; i < str.size; ++i)
		{
			char_array[i] = str.char_array[i];//copy
			if (String::Equals(char_array[i], '\0'))//early bail
				break;
		}
		return *this;
	}
	String &String::operator=(const char* str)
	{
		for (HG_UINT64 i = 0; true; ++i)
			if (String::Equals(str[i], '\0'))//early bail
			{
				if (size <= i)
				{
					size = i + 1 + ExtraAllocation;
					deallocate_memory();//delete memory
					allocate_memory();//reallocate
				}
				break;
			}
		for (HG_UINT64 i = 0; i < size; ++i)
		{
			char_array[i] = str[i];//copy
			if (String::Equals(char_array[i], '\0'))//early bail
				break;
		}
		return *this;
	}
	String &String::operator=(const char chr)
	{
		if (size < 1)
		{
			size = 1 + ExtraAllocation;
			deallocate_memory();//delete memory
			allocate_memory();//reallocate
		}
		char_array[0] = chr;
		char_array[1] = '\0';
		return *this;
	}
	//move operator
	String &String::operator=(const String &&str)
	{
		size = str.size;
		char_array = str.char_array;
		return *this;
	}
	//get functions
	char* String::get_char_array() const
	{
		return char_array;//get the char array
	}
}