/*******************************************************************
Made By: Hosein Ghahremanzadeh on 7/11/2016
String.cpp String class and String manipulation functions
*******************************************************************/
#ifndef HG_String
#define HG_String

#include "Types.h"

namespace HGString//String name space
{
	class String
	{
	public:
		String();
		String(HG_UINT64);
		String(char*);
		String(String&);
		String(String&&);
		~String();
		bool operator==(const String&) const;
		bool operator==(const char*) const;
		bool operator==(const char) const;
		String &operator=(const String&);
		String &operator=(const char*);
		String &operator=(const char);
		String &operator=(const String&&);

		char* get_char_array() const;

	private:
		static HG_UINT64 ExtraAllocation;//extra allocation size
		static HG_UINT64 AllocationAlignment;//allocation alignment
		static bool(*Equals)(const char, const char);//char char equals test

		static void SET_EXTRA_ALLOCATION_SIZE(const HG_UINT64);//set the extra allocation size
		static void SET_ALLOCATION_ALIGNMENT(const HG_UINT64);//set allocation alignment

		HG_UINT64 size;//actuall size of the allocated memory
		char* char_array;//poHG_UINT64er to allocated memory

		void allocate_memory();//allocates new memory to the char array
		void deallocate_memory();//deacllocate memory for the char array
	};
}

#endif // !HG_String