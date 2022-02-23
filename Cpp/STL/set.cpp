#include <iostream>
#include <set>

using namespace std;

struct People
{
    string name;
    int age;

    bool operator<(const People p)const
    {
        return age < p.age;
    }

    // ostream & operator<<(ostream &o)
    // {
    //     return o << "姓名： " << name << " 年龄： " << age << endl;
    // }
};


int main(){
    // set<int> s;

    // s.insert(3);
    // s.insert(1);
    // s.insert(2);
    // s.insert(1);

    // set<int>::iterator it;
    // for (it = s.begin(); it != s.end(); it++){
    //     cout << *it << " ";
    // }

    //---------

    set<People> s;
    s.insert({"Alice", 14});
    s.insert({"Bob", 16});
    s.insert({"Cindy", 10});

    set<People>::iterator it;
    for (it = s.begin(); it != s.end(); it++){
        cout << "name: " << (*it).name << " age: " << it->age << endl;
    }

        return 0; 
}




#include <iostream>
// write your code here......
#include <set>
#include <bits/stdc++.h>

using namespace std;

int main() {

    char str[100] = { 0 };
    cin.getline(str, sizeof(str));

    // write your code here......
    set<char> s(str, str+strlen(str));
    
    set<char>::iterator it;
    for (it=s.begin(); it!=s.end(); it++){
        cout << (*it);
    }
    cout << endl;
    return 0;
}