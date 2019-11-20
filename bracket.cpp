#include "bracket.h"

//Constructor - Opens file
Bracket::Bracket(string path)
{
    this->path = path;
    file.open(path);
    if(!file.good()) throw "Cannot open file!\n";
}

//Destructor - Ensures the file is correctly closed
Bracket::~Bracket()
{
    file.close();
}

//
void Bracket::conversionup(char ov)
{

}

//This method separtes gathers info about the input file. File type, path and name
void Bracket::getpath()
{
    string temp = "";
    int dot = -1;
    int slash = -1;
    for(int i = 0; i<path.length(); i++)
    {
        if(path[i] == '/') slash = i;
        if(path[i] == '.') dot = i;
    }
    if(slash == -1 && dot == -1)
    {
        name = path;
        path = "";
    }
    if(slash != -1 && dot == -1)
    {
        for(int i = slash + 1; i<path.length(); i++)
        {
            name = name + path[i];
        }
        for(int i = 0; i<slash+1; i++)
        {
            temp = temp + path[i];
        }
        path = temp;
    }
    if(slash == -1 && dot != -1)
    {
        for(int i = dot + 1; i<path.length(); i++)
        {
            type = type + path[i];
        }
        for(int i = 0; i<dot; i++)
        {
            name = name + path[i];
        }
        path = "";
    }
    if(slash != -1 && dot != -1)
    {
        for(int i = dot + 1; i<path.length(); i++)
        {
            type = type + path[i];
        }
        for(int i = slash+1; i<dot; i++)
        {
            name = name + path[i];
        }
        for(int i = 0; i<slash+1; i++)
        {
            temp = temp + path[i];
        }
        path = temp;
    }
    cout<<path<<endl;
    cout<<name<<endl;
    cout<<type<<endl;
}

