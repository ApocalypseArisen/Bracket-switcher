#include <iostream>
#include "bracket.h"

using namespace std;

//Displays help message
void instructions()
{
	cout << "Bracket switcher (cbrsw) help" <<
		"\nUsage:" <<
		"\n\nTyping 1 and path to the file will convert files written in style:" <<
		"\nint main(){" <<
		"\n}" <<
		"\n\nInto:" <<
		"\nint main()" <<
		"\n{" <<
		"\n}" <<
		"\n\nTyping 2 and path to the file will convert files from style:" <<
		"\nint main()" <<
		"\n{" <<
		"\n}" <<
		"\n\nInto:" <<
		"\nint main(){" <<
		"\n}" <<
		"\n\nExample of usage:" <<
		"\ncbrsw 1 file.cpp" <<
		"\nThis command will result in saving conversion results to file-cbrsw1.cpp" <<
		"\n\nIt is possible to overide source files by adding o to command like this:" <<
		"\ncbrsw 1o file.cpp" <<
		"\nWARNING this option may result in data loss. Use at you own risk.";
}

//Starting point - handles input parameters
int main(int argc, char *argsv[])
{
	if (argc == 3)
	{
		Bracket *converter;
		try { converter = new Bracket(argsv[2]); }
		catch (const char *error)
		{
			cout << error;
			return 0;
		}
		switch (*argsv[1])
		{
		case '1':
		{
			converter->conversionup(argsv[1][1]);
		} break;
		case '2':
		{
			converter->conversiondown(argsv[1][1]);
		} break;
		default: instructions();
		}
		delete converter;
	}
	else instructions();
	return 0;
}
