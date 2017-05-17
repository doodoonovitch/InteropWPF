// DataContainerCLR.h

#pragma once

#pragma managed(push, off)
#include "CppObject.h"
#pragma managed(pop)

using namespace System;
using namespace System::ComponentModel;
using namespace System::Runtime::InteropServices;
using namespace System::Dynamic;
using namespace System::Collections::Generic;

namespace DataContainerCLR {

public ref class CppObjectWrapper : DynamicObject, INotifyPropertyChanged
{
public:

	CppObjectWrapper(CppObject * cppObject);
	~CppObjectWrapper();
	!CppObjectWrapper();

	virtual bool TryGetMember(GetMemberBinder^ binder, [OutAttribute] Object^% result) override;
	virtual bool TrySetMember(SetMemberBinder^ binder, Object^ value) override;
	
	virtual event PropertyChangedEventHandler^ PropertyChanged;
	void RaisePropertyChanged(String^ propertyName);


protected:

	interface class IProperty
	{
	public:

		property Object^ Value
		{
			Object^ get();
			void set(Object^);
		}
	};

	ref class IntProperty : IProperty
	{
	public:

		IntProperty(CppObject* cppObject)
			: m_Object(cppObject)
			, m_Getter(&CppObject::GetInt)
			, m_Setter(&CppObject::SetInt)
		{

		}

		virtual property Object^ Value
		{
			Object^ get()
			{
				return (m_Object->*m_Getter)();
			}
			void set(Object^ value)
			{
				(m_Object->*m_Setter)((int)value);
			}
		}

	private:

		typedef int (CppObject::*IntGetter)() const;
		typedef void (CppObject::*IntSetter)(int);

		CppObject* m_Object;
		IntGetter m_Getter;
		IntSetter m_Setter;


	};

private:

	Dictionary<String^, IProperty^>^ m_dictionary = gcnew Dictionary<String^, IProperty^>();
		
};

}
