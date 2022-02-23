#include <iostream>
#include <vector>
using namespace std;

int main(){
    //创建一个向量存储
    vector<int> vec;
    int i;

    //显示vec的原始大小
    cout << "vector size: " << vec.size() << endl;

    //插入数据
    for (int i = 0; i < 5; i++){
        vec.push_back(i);
    }

    //大小改变
    cout << "extanded vector size = " << vec.size() << endl;

    //访问数据
    for (int i = 0; i < vec.size(); i++)
        cout << "value of vec[" << i << "]: " << vec[i] << endl;
    
    //使用迭代器访问
    vector<int>::iterator v = vec.begin();
    while (v != vec.end()){
        cout << "value of v = " << *v << endl;
        v++;
    }

    return 0;
}