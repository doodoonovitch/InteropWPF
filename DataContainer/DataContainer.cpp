// DataContainer.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "DataContainer.h"
#include <malloc.h>


// Il s'agit d'un exemple de variable exportée
DATACONTAINER_API int nDataContainer=0;

// Il s'agit d'un exemple de fonction exportée.
DATACONTAINER_API int fnDataContainer(void)
{
    return 42;
}

// Il s'agit du constructeur d'une classe qui a été exportée.
// consultez DataContainer.h pour la définition de la classe
DataContainer::DataContainer()
	: m_str(_strdup("English (ANSI string)"))
	, m_wstr(_wcsdup(L"日本語 (UNICODE string)"))
	, m_cppObject(new CppObject())
	,m_int(10)
{
    return;
}

DataContainer::~DataContainer()
{
	free(m_str);
	free(m_wstr);
	delete m_cppObject;
}

const char* DataContainer::GetStrANSI() const
{
	return m_str;
}

void DataContainer::SetStrANSI(const char* value)
{
	if (value == m_str)
	{
		return;
	}

	free(m_str);
	m_str = nullptr;
	if (value != nullptr)
	{
		m_str = _strdup(value);
	}
}

const wchar_t* DataContainer::GetStrUNICODE() const
{
	return m_wstr;
}

void DataContainer::SetStrUNICODE(const wchar_t* value)
{
	if (value == m_wstr)
	{
		return;
	}

	free(m_wstr);
	m_wstr = nullptr;
	if (value != nullptr)
	{
		m_wstr = _wcsdup(value);
	}
}


int DataContainer::GetInt() const
{
	return m_int;
}

void DataContainer::SetInt(int value)
{
	m_int = value;
}

CppObject* DataContainer::GetCppObject() const
{
	return m_cppObject;
}

