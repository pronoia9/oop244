// OOP244 Workshop 10: Function Templates
// File:               String.cpp
// Version:            1.0
// Date:               Nov 23, 2016      
/////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;
namespace ict
{
	void String::deallocate()
	{
		//clog << "[INFO]  -  deallocate()" << endl;
		delete[] m_data;
		m_data = nullptr;
		m_memSize = 0;
	}


	void String::allocate(int memsize)
	{
		//clog << "[INFO]  -  allocate(int memsize)" << endl;
		delete[] m_data;  //deallocate();
		m_data = new char[memsize];
		m_memSize = memsize;
	}


	void String::init(const char * str, int memsize)
	{
		//clog << "[INFO]  -  init(const char * str, int memsize)" << endl;
		int len = strlen(str);
		m_data = nullptr;
		if (memsize < len) { memsize = len + 1; }	//memsize < len + 1
		allocate(memsize);
		strcpy(m_data, str);
		m_len = strlen(m_data);
	}


	void String::resize(int newsize)
	{
		//clog << "[INFO]  -  resize(int newsize)" << endl;
		char * temp = new char[newsize];
		//int len = strlen(m_data);
		int i = 0;
		if (m_data != nullptr)
		{
			//if (len < newsize) { len = newsize - 1; }
			for (i = 0; i < getMemSize() && i < newsize - 1; i++)  { temp[i] = m_data[i]; }
			deallocate();
		}
		temp[i] = 0;
		m_data = temp;
		m_memSize = newsize;
		m_len = strlen(m_data);
	}


	String::String()
	{
		//clog << "[INFO]  -  String()" << endl;
		m_data = nullptr;
		m_memSize = 0;
		m_len = 0;
	}


	String::String(const char * str, int memsize)
	{
		//clog << "[INFO]  -  String(const char * str, int memsize)" << endl;
		init(str, memsize);
	}


	String::String(const String & str)
	{
		//clog << "[INFO]  -  String(const String & str)" << endl;
		init(str.m_data, str.getMemSize());
	}


	String & String::operator = (const String & str)
	{
		//clog << "[INFO]  -  operator = (const String & str)" << endl;
		if (this != &str)
		{
			deallocate();
			init(str.m_data, str.getMemSize());
		}
		return *this;
	}


	String::~String()
	{
		//clog << "[INFO]  -  ~String()" << endl;
		//deallocate();
		delete[] m_data;
	}


	int String::getLength() const
	{
		//clog << "[INFO]  -  getLength() const" << endl;
		return m_len;
	}


	int String::getMemSize() const
	{
		//clog << "[INFO]  -  getMemSize() const" << endl;
		return m_memSize;
	}


	String::operator const char*() const
	{
		//clog << "[INFO]  -  operator const char*() const" << endl;
		return m_data;
	}


	String::operator int() const
	{
		//clog << "[INFO]  -  operator int() const" << endl;
		return strlen(m_data);
	}


	String & String::operator ++ ()
	{
		//clog << "[INFO]  -  operator ++ ()" << endl;
		char temp[500];
		strcpy(temp, " ");
		strcpy(temp, m_data);
		if (!(getMemSize() - getLength() > 1)) { resize(getMemSize() + 1); }
		strcpy(m_data, temp);
		m_len = strlen(m_data);
		return *this;
	}

	
	String String::operator ++ (int)
	{
		//clog << "[INFO]  -  operator ++ (int)" << endl;
		String temp = *this;
		//temp += " ";	
		operator+=(" ");
		return temp;
	}

	
	String & String::operator += (const char * str)
	{
		//clog << "[INFO]  -  operator += (const char * str)" << endl;
		int slen = strlen(str);
		int len = slen + m_len;
		if (len + 1 > getMemSize()) { resize(len + 1); }
		strcat(m_data, str);
		m_len = strlen(m_data);
		return *this;
	}

	
	String & String::operator += (String & str)
	{
		//clog << "[INFO]  -  operator += (String & str)" << endl;
		//*this += str.m_data;	
		operator+=(str.m_data);
		return *this;
	}

	
	String String::operator + (const String & str) const
	{
		//clog << "[INFO]  -  operator + (const String & str) const" << endl;
		String temp(m_data);
		temp += str;
		return temp;
	}
	

	char & String::operator [] (int idx)
	{
		//clog << "[INFO]  -  operator [] (int idx)" << endl;
		if (idx > m_len)
		{
			resize(idx + ExpansionSize);
			return m_data[idx + ExpansionSize];
		}
		else
			return m_data[idx];
	}
	

	std::istream & String::read(std::istream & istr)
	{
		//clog << "[INFO]  -  read(istream & istr)" << endl;
		char temp;
		for (int i = 0; temp != '\n'; i++)
		{
			istr >> m_data[i] >> temp;
			if (i == m_memSize)  { resize(m_memSize + ExpansionSize); }
			m_data[i] = temp;
		}
		m_data[0] = 0;
		return istr;
	}


	std::ostream & operator << (std::ostream & ostr, const String & str)
	{
		//clog << "[INFO]  -  operator << (std::ostream & ostr, const String & str)" << endl;
		if (str.getLength()) { ostr << (const char*)str; }
		return ostr;
	}

	
	std::istream & operator >> (std::istream & istr, String & str)
	{
		//clog << "[INFO]  -  operator >> (std::istream & istr, String & str)" << endl;
		return str.read(istr);
	}
}