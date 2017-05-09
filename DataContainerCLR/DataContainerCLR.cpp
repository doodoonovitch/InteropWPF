// Il s'agit du fichier DLL principal.

#include "stdafx.h"

#include "DataContainerCLR.h"
#using <mscorlib.dll>

namespace DataContainerCLR
{

DataWrapper::DataWrapper()
	: m_DataContainer(new DataContainer())
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

String^ DataWrapper::Str::get()
{
	String^ str = gcnew String(m_DataContainer->GetString());
	return str;
}

void DataWrapper::Str::set(String^ value)
{
	System::IntPtr ptr = Marshal::StringToHGlobalAnsi(value);
	m_DataContainer->SetString((char*)ptr.ToPointer());
	Marshal::FreeHGlobal(ptr);
	RaisePropertyChanged(gcnew String("Str"));
}

String^ DataWrapper::WStr::get()
{
	String^ str = gcnew String(m_DataContainer->GetWString());
	return str;
}

void DataWrapper::WStr::set(String^ value)
{
	System::IntPtr ptr = Marshal::StringToHGlobalUni(value);
	m_DataContainer->SetString((char*)ptr.ToPointer());
	Marshal::FreeHGlobal(ptr);
	RaisePropertyChanged(gcnew String("WStr"));
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