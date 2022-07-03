#include <iostream>
#include <xmlread.h>

using namespace std;

int main()
{
    char filename[] = "testfile.xml";
    char filenamenew[] = "new.xml";
    char readtag[] = "TITLE";
    char tag[] = "TITLE";
    char newtag[] = "NEWTAG";
    Xmlread Reader(filename);
    cout << "found textvalue is: " << Reader.get(readtag) << endl;
    if (!Reader.set(tag, newtag, filenamenew)){
        cout << filename << " was changed, new is " << filenamenew << endl;
    }

    return 0;
}
