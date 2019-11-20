#ifndef BRACKET_H
#define BRACKET_H

#include<fstream>
#include<iostream>

using namespace std;

class Bracket
{
private:
    //methodes
    fstream file;
public:
    Bracket(string path);
    ~Bracket();
};

#endif // BRACKET_H
