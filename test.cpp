#include <iostream>
using namespace std;

class A{
private:
    friend ostream& operator<<(ostream &out, const A &a);
public: 
    int num1;
    int num2;
public:
    A(int a=0, int b=0):num1(a), num2(b){};
    A(const A& a){};
    A& operator=(const A& a){
        num1 = a.num1 + 1;
        num2 = a.num2 + 1;
        return *this;
    };

};

ostream& operator<<(ostream &out, const A &a){
    out << "num1: " << a.num1 << " num2: " << a.num2 << endl;
    return out;
};

int main(){
    A a(1, 1);
    A a1 = a;
    cout << a;
    A b;
    cout << b;
    b = a;
    cout << b;

    return 0;
}
