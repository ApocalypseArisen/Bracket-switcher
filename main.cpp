#include <iostream>
#include "bracket.h"

using namespace std;

void instructions()
{
    cout<<"Invalid program parameters"<<endl;
}

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
                cout<<"test"<<endl;
            } break;
            case '2':
            {
                cout<<"test1"<<endl;
            } break;
        }
        delete converter;
    }
    else instructions();
    return 0;
}
