#include <iostream>
#include "bracket.h"

using namespace std;

//Displays help message
void instructions()
{
    cout<<"Invalid program parameters"<<endl;
}

//Starting point - handles input parameters
int main(int argc, char *argsv[])
{
    if(argc == 3)
    {
        Bracket *converter;
        try { converter = new Bracket(argsv[2]); }
        catch (const char *error)
        {
            cout<<error;
            return 0;
        }
        switch(*argsv[1])
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
