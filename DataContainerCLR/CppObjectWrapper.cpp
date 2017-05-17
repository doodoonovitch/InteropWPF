#include "stdafx.h"

#include "CppObjectWrapper.h"
#using <mscorlib.dll>

namespace DataContainerCLR
{

CppObjectWrapper::CppObjectWrapper(CppObject * cppObject)
{
	m_dictionary["PropI"] = gcnew IntProperty(cppObject);
}

CppObjectWrapper::~CppObjectWrapper()
{
}

CppObjectWrapper::!CppObjectWrapper()
{
}

bool CppObjectWrapper::TryGetMember(GetMemberBinder^ binder, [OutAttribute] Object^% result) 
{
	String^ name = binder->Name;
	IProperty^ prop;
	if (m_dictionary->TryGetValue(name, prop))
	{
		result = prop->Value;
		return true;
	}
	else
	{
		return false;
	}
}

bool CppObjectWrapper::TrySetMember(SetMemberBinder^ binder, Object^ value) 
{
	String^ name = binder->Name;
	IProperty^ prop;
	if (m_dictionary->TryGetValue(name, prop))
	{
		prop->Value = value;
		RaisePropertyChanged(name);
		return true;
	}
	else
	{
		return false;
	}
}


void CppObjectWrapper::RaisePropertyChanged(String^ propertyName)
{
	PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
}



}