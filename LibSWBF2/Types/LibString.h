#pragma once
#include "FileWriter.h"
#include "FileReader.h"

namespace LibSWBF2::Types
{
	struct LIBSWBF2_API String
	{
		String();
		String(const char* cStr);
		String(const String& other);
		String(String&& other);
		~String();

		const char* Buffer() const;
		size_t Length() const; // without NULL terminator

		String& operator=(const String& other);
		bool operator==(const String& other);
		bool operator!=(const String& other);

		String operator+=(const String& a);
		friend String operator+(const String&, const String&);
		friend String operator+(const String&, const char*);
		friend String operator+(const char*, const String&);

	private:
		const static size_t WARN_LENGTH = 0xffff;
		const static size_t MAX_LENGTH = 0xffffffff;

		char* buffer = nullptr;		//should always contain a valid pointer to a zero terminated c string (even if length == 0). nullptr indicates an invalid String!
		size_t length = 0;			//zero termination byte not included!
	};
}