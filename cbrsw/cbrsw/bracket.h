#ifndef BRACKET_H
#define BRACKET_H

#include<fstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Bracket
{
private:
    //variables
    fstream file;
    ofstream out;
    string path;
    string name = "";
    string type = "";
    vector<string> data;
    vector<string> result;
    //methodes
    void opentarget(bool ovwrite);
    void getpath();
    void loadfile();
    void savefile(char ov, int mode);
public:
    //Constructor & Destructor
    Bracket(string path);
    ~Bracket();
    //methodes
    void conversionup(char ov);
    void conversiondown(char ov);
};

#endif // BRACKET_H
