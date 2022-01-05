#include <iostream>
#include <vector>
using namespace std;
int main(){
    char address[80];
    cout << "getline input.\n";
    cin.getline(address, 80);
    cout << "getline output: " << address << endl;
    cout << "cin input.\n";
    cin >> address;
    cout << "cin output: " << address << endl;
    return 0;
}

// int main(){
//     cout << "enter an int num" << endl;
//     int num = 0;
//     cin >> num;
//     int* arr = new int[num];
//     vector<int> arr1(num);
//     cout << "finish\n";
//     delete[] arr;
//     return 0;
// }

// int main(){
//     using namespace std;
//     //char ss[] {1, 2, 3};
// //可以把字符数组当字符串，但不建议
//     char dogs[]{'1', '2', '3', '4', '5', ' ', '6', '7'};     //直到'\0'才停止
//     char cats[]{'1', '2', '3', '\0', '4', '5', '6', '7'};   //遇到'\0'就停止
//     // cout << "size of ss " << sizeof ss << endl;
//     // cout << "size of char " << sizeof (char);
//     cout << "dogs: " << dogs << endl;
//     cout << "cats: " << cats << endl;

//     char birds[] = "new birds"; //字符串长度包括结尾的'\0'，编译器自动添加
//     cout << "size of birds: " << sizeof birds << endl;
//     cout << R"(title name car)" << endl;
//     cout << R"+*(title "(name)" car)+*" << endl;
//     //""字符串常量，''字符常量
//     //char s = "S"; illegal   "S" = 's' + '\0'


// }

