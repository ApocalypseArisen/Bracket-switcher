#include "bracket.h"

//Constructor - Opens file
Bracket::Bracket(string path)
{
    file.open(path);
    if(!file.good()) throw "Cannot open file!\n";
}

//Destructor - Ensures the file is correctly closed
Bracket::~Bracket()
{
    file.close();
}
