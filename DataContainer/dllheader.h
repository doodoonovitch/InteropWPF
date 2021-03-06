// Le bloc ifdef suivant est la fa�on standard de cr�er des macros qui facilitent l'exportation 
// � partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compil�s avec le symbole DATACONTAINER_EXPORTS
// d�fini sur la ligne de commande. Ce symbole ne doit pas �tre d�fini pour un projet
// qui utilisent cette DLL. De cette mani�re, les autres projets dont les fichiers sources comprennent ce fichier consid�rent les fonctions 
// DATACONTAINER_API comme �tant import�es � partir d'une DLL, tandis que cette DLL consid�re les symboles
// d�finis avec cette macro comme �tant export�s.
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
