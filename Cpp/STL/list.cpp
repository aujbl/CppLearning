#include <iostream>
#include <list>

using namespace std; 

int main(){
    list<char> l;
    for (char c = 'a'; c <= 'z'; c++){
        l.push_back(c);
    }

    while (!l.empty()){
        cout << l.front() << " ";
        l.pop_front();
    }

    return 0;
}

