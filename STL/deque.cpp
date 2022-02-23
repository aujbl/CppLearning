// #include <iostream>
// #include <deque>

// using namespace std;

// int main(){
//     deque<float> q;
//     for (int i = 0; i < 6; i++){
//         q.push_back(i);
//     }
//     for (int i = 0; i < q.size(); i++){
//         cout << "q[" << i << "]=" << q[i] << ", ";
//     }

//     return 0;
// }


//------------------


#include <iostream>
#include <deque>
using namespace std;

class Guest {
public:
    string name;
    bool vip;

    Guest(string name, bool vip) {
        this->name = name;
        this->vip = vip;
    }
};

deque<Guest> & pushFrontOrBack(Guest g, deque<Guest> &dq){
    if (g.vip){
        dq.push_front(g);
    }else{
        dq.push_back(g);
    }
    return dq;
}

int main() {

    Guest guest1("a", false);
    Guest guest2("b", false);
    Guest vipGuest("c", true);
    deque<Guest> dq;

    // write your code here......
    dq = pushFrontOrBack(guest1, dq);
    dq = pushFrontOrBack(guest2, dq);
    dq = pushFrontOrBack(vipGuest, dq);

    for (Guest g : dq) {
        cout << g.name << " ";
    }

    return 0;
}