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
	: m_str(_strdup("An ANSI or multi - bytes string"))
	, m_wstr(_wcsdup(L"UNICODE string"))
	,m_int(10)
{
    return;
}

DataContainer::~DataContainer()
{
	free(m_str);
	free(m_wstr);
}

const char* DataContainer::GetString() const
{
	return m_str;
}

void DataContainer::SetString(const char* value)
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

const wchar_t* DataContainer::GetWString() const
{
	return m_wstr;
}

void DataContainer::SetString(const wchar_t* value)
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
