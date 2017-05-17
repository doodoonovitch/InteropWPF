#pragma once
#include "dllheader.h"

class DATACONTAINER_API CppObject
{
public:
	CppObject();
	virtual ~CppObject();

	int GetInt() const
	{
		return m_int;
	}

	void SetInt(int value)
	{
		m_int = value;
	}

private:

	int m_int;

};

