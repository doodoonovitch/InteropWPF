#pragma once;

#include "dllheader.h"
#include "CppObject.h"

// Cette classe est exportée de DataContainer.dll
class DATACONTAINER_API DataContainer {
public:
	DataContainer(void);
	~DataContainer();
	// TODO: ajoutez ici vos méthodes.
	const char* GetStrANSI() const;
	void SetStrANSI(const char* value);
	const wchar_t* GetStrUNICODE() const;
	void SetStrUNICODE(const wchar_t* value);
	int GetInt() const;
	void SetInt(int value);
	CppObject* GetCppObject() const;

private:

	char* m_str;
	wchar_t* m_wstr;
	CppObject* m_cppObject;
	int m_int;

};

extern DATACONTAINER_API int nDataContainer;

DATACONTAINER_API int fnDataContainer(void);
