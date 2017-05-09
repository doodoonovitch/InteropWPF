// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation 
// à partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole DATACONTAINER_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini pour un projet
// qui utilisent cette DLL. De cette manière, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions 
// DATACONTAINER_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés.
#ifdef DATACONTAINER_EXPORTS
#define DATACONTAINER_API __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define DATACONTAINER_API __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif

#pragma once;

//#include <string>
//
//EXPIMP_TEMPLATE template class DATACONTAINER_API std::allocator<char>;
//EXPIMP_TEMPLATE template class DATACONTAINER_API std::basic_string< char, std::char_traits<char>, std::allocator<char> >;
//EXPIMP_TEMPLATE template class DATACONTAINER_API std::allocator<wchar_t>;
//EXPIMP_TEMPLATE template class DATACONTAINER_API std::basic_string< wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >;


// Cette classe est exportée de DataContainer.dll
class DATACONTAINER_API DataContainer {
public:
	DataContainer(void);
	~DataContainer();
	// TODO: ajoutez ici vos méthodes.
	const char* GetString() const;
	void SetString(const char* value);
	const wchar_t* GetWString() const;
	void SetString(const wchar_t* value);
	int GetInt() const;
	void SetInt(int value);

private:

	char* m_str;
	wchar_t* m_wstr;
	int m_int;

};

extern DATACONTAINER_API int nDataContainer;

DATACONTAINER_API int fnDataContainer(void);
