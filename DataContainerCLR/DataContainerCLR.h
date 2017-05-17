// DataContainerCLR.h

#pragma once

#pragma managed(push, off)
#include "DataContainer.h"
#pragma managed(pop)

#include "CppObjectWrapper.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Runtime::InteropServices;

namespace DataContainerCLR {

public ref class DataWrapper : INotifyPropertyChanged
{
public:

	DataWrapper();
	~DataWrapper();
	!DataWrapper();

	property String^ StrANSI
	{
		String^ get();
		void set(String^);
	}

	property String^ StrUNICODE
	{
		String^ get();
		void set(String^);
	}

	property int Integer
	{
		int get()
		{
			return m_DataContainer->GetInt();
		}
		void set(int value)
		{
			m_DataContainer->SetInt(value);
			RaisePropertyChanged(gcnew String("Integer"));
		}
	}

	property DynamicObject^ CppObject
	{
		DynamicObject^ get()
		{
			return m_CppObjectWrapper;
		}
	}

	virtual event PropertyChangedEventHandler^ PropertyChanged;
	void RaisePropertyChanged(String^ propertyName);

protected:

	void ReleaseNativeData();

private:

	DataContainer* m_DataContainer;
	CppObjectWrapper^ m_CppObjectWrapper;
		
};

}
