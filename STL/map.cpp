// #include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<int, string> m;

    m.insert({5, "Alice"});
    m.insert({3, "Bob"});
    m.insert({4, "Cindy"});

    map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++){
        cout << "num: " << it->first << " name: " << it->second << endl;
    }

    return 0;
}