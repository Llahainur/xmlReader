#ifndef XMLREAD_H
#define XMLREAD_H
#include <tinyxml2/tinyxml2.h>
#include <string>
#include <iostream>

using namespace std;
using namespace tinyxml2;

class Xmlread
{
private:
    XMLElement *getElementByName(XMLDocument &ele, std::string const &elemt_value);
    char  filename;
    XMLDocument doc;
public:
    Xmlread(char f []){
       //cout<<filename;
        doc.LoadFile(f);
        filename = *f;
    };
    string get(string const tag);
    int set(char tag[], char val[], char newname[]);
};

#endif // XMLREAD_H
