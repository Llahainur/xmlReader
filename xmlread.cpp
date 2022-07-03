#include "xmlread.h"

XMLElement * Xmlread::getElementByName(XMLDocument &ele, std::string const &elemt_value)
    {
    XMLElement *elem = ele.FirstChildElement(); //Tree root

    while (elem)
    {
        if (!std::string(elem->Value()).compare(elemt_value))
            return elem;
        if (elem->FirstChildElement())
        {
            elem = elem->FirstChildElement();
        }
        else if (elem->NextSiblingElement())
        {
            elem = elem->NextSiblingElement();
        }
        else
        {
            if (elem->Parent()->ToElement()->NextSiblingElement())
            {
                elem = elem->Parent()->ToElement()->NextSiblingElement();
            }
            else if (elem->Parent()->ToElement()->FirstChildElement()
                        &&  strcmp(elem->Name(), elem->Parent()->ToElement()->FirstChildElement()->Name()))
            {
                elem = elem->Parent()->ToElement()->FirstChildElement();
            }
            else {
                break;
            }
        }
    }
    return NULL;
};

string Xmlread::get(string const tag){
    XMLElement * foundElem;
    foundElem = getElementByName(doc,tag);
    return foundElem->GetText();
}

int Xmlread::set(char tag[], char val[], char newname[]){
      XMLElement * foundElem;
      foundElem = getElementByName(doc,tag);
      if (foundElem){
        //foundElem->SetAttribute(tag,val);
        foundElem->SetName(val);
        doc.SaveFile(newname);
        return 0;
      }
      else{
          return 1;
      }

};

