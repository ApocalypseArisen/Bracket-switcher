#ifndef BRACKET_H
#define BRACKET_H

#include<fstream>
#include<iostream>

using namespace std;

class Bracket
{
private:
    //variables
    fstream file;
    fstream target;
    string path;
    string name = "";
    string type = "";
    //methodes
    void opentarget(bool ovwrite);
public:
    //Constructor Destructor
    Bracket(string path);
    ~Bracket();
    //methodes
    void conversionup(char ov);
    void getpath();
};

#endif // BRACKET_H
