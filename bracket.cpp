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

void Bracket::conversiondown(char ov)
{
    int index;
    bool found = false;
    getpath();
    loadfile();
    for(int i=0; i<data.size(); i++)
    {
        for(int j=0; j<data[i].length(); j++)
        {
            if(data[i][j] == '{') found = true, index = j;
            if(found && data[i][j] == '}') found = false;
        }
        if(found)
        {
            result[result.size() - 1] = result[result.size() - 1] + " {";
            found = false;
        }
        else result.push_back(data[i]);
    }
    try { savefile(ov, 2); }
    catch (const char *error)
    {
        cout<<error;
    }
}

//
void Bracket::conversionup(char ov)
{
    int index;
    int level = 0;
    bool found = false;
    bool closed = false;
    string text;
    getpath();
    loadfile();
    for(int i=0; i<data.size(); i++)
    {
        text = "";
        for(int j = (data[i].length() - 1); j >= 0; j--)
        {
            if(data[i][j] = '}')
            {
                level--;
                closed = true;
            }
            if(data[i][j] == '{' && closed)
            {
                closed = false;
                level++;
                break;
            }
            if(data[i][j] == '{')
            {
                found = true;
                level++;
                index = j;
                break;
            }
        }
        if(found)
        {
            data[i].erase(data[i].begin() + index);
            result.push_back(data[i]);
            for(int j=0; j<level - 1; j++)
            {
                text = text + "\t";
            }
            text = text + '{';
            result.push_back(text);
            found = false;
        }
        else result.push_back(data[i]);
    }
    try { savefile(ov, 1); }
    catch (const char *error)
    {
        cout<<error;
    }
}

//Method loading contents of the file to data structure
void Bracket::loadfile()
{
    string temp;
    while(!file.eof())
    {
        getline(file, temp);
        data.push_back(temp);
    }
    file.close();
}

//Method saving procesed file
void Bracket::savefile(char ov, int mode)
{
    string newpath;
    if(ov == 'o')
    {
        newpath = path + name + "." + type;
        const int rs = remove(newpath.c_str());
        if (rs != 0) throw "Could not delete existing file!\n";
    }
    else newpath = path + name + "-cbrsw" + to_string(mode) + "." + type;
    out.open(newpath);
    if(out.good())
    {
        for(int i=0; i<result.size(); i++)
        {
            out<<result[i]<<endl;
        }
    }
    else throw "Could not open result file!\n";
    cout<<"Conversion successfully finished!"<<endl;
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
}
