// Il s'agit du fichier DLL principal.

#include "stdafx.h"

#include "DataContainerCLR.h"
#using <mscorlib.dll>

namespace DataContainerCLR
{

DataWrapper::DataWrapper()
	: m_DataContainer(new DataContainer())
	, m_CppObjectWrapper(gcnew CppObjectWrapper(m_DataContainer->GetCppObject()))
{

}

DataWrapper::~DataWrapper()
{
	ReleaseNativeData();
}

DataWrapper::!DataWrapper()
{
	ReleaseNativeData();
}

String^ DataWrapper::StrANSI::get()
{
	String^ str = gcnew String(m_DataContainer->GetStrANSI());
	return str;
}

void DataWrapper::StrANSI::set(String^ value)
{
	System::IntPtr ptr = Marshal::StringToHGlobalAnsi(value);
	m_DataContainer->SetStrANSI((char*)ptr.ToPointer());
	Marshal::FreeHGlobal(ptr);
	RaisePropertyChanged(gcnew String("StrANSI"));
}

String^ DataWrapper::StrUNICODE::get()
{
	String^ str = gcnew String(m_DataContainer->GetStrUNICODE());
	return str;
}

void DataWrapper::StrUNICODE::set(String^ value)
{
	System::IntPtr ptr = Marshal::StringToHGlobalUni(value);
	m_DataContainer->SetStrUNICODE((wchar_t*)ptr.ToPointer());
	Marshal::FreeHGlobal(ptr);
	RaisePropertyChanged(gcnew String("StrUNICODE"));
}

void DataWrapper::RaisePropertyChanged(String^ propertyName)
{
	PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
}

void DataWrapper::ReleaseNativeData()
{
	delete m_DataContainer;
	m_DataContainer = nullptr;
}

}