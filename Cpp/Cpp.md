## 3.4 算数运算符

1. `float logs = 120 / 4 * 5;  `'/' 和 '*" 同时作用于4，遵循从左到右的原则

2. `int a {0};  ` 大括号初始化（列表初始化 list-initialization），不允许缩窄初始化（e: float->int)

***

# 4. 复合类型

## 4.2 字符串

```cpp
// 可以把字符数组当字符串，但不建议
char dogs[]{'1', '2', '3', '4', '5', ' ', '6', '7'};     // 直到'\0'才停止
char cats[]{'1', '2', '3', '\0', '4', '5', '6', '7'};   // 遇到'\0'就停止
cout:
    dogs: 12345 67123
    cats: 123
char birds[] = "new birds"; // 字符串长度包括结尾的'\0'，编译器自动添加
cout << "size of birds: " << sizeof birds << endl;
```

1. " "字符串常量，' '字符常量。char s = "S"; illegal   "S" = 's' + '\0'， "S"实际上表示的是字符串所在的内存地址

2. cin读取到空格处停止，cin.getline()、cin.get()都能读取行，getline读取并丢弃换行符，get将换行符保留在输入队列

3. cin.get()返回的是cin对象，所以可以cin.get().get()

## 4.3 String类

1. 可以代替字符数组，更方便

2. 
    ```cpp
    wchar_t title[] = L"title";
    char16_t name[] = u"name";
    char32_t car[] = U"car";
    R"(title name car)" // 原始字符串，"()"界定符，显示)"时可以用"+*(和)+*"代替默认定界符
    ```

## 4.4 结构体
1. 
    ```cpp
    struct fish{
        char kind[20];
        int weight;
        float length;
    };
    fish* p = new fish;
    cout << "enter kind of fish." << endl;
    cin >> p->kind;
    ```

2. 用户定义的类型，C++使用户定义的类型尽可能与内置类型相似

3. 结构体可以成员赋值，可以创建结构体数组，结构体可由为字段构成，通常用于低级编程

## 4.5 共用体
1. 
    ```cpp
    union one4all{
        int int_val;
        long long_val;
        double doube_val;
    }
    ```

2. 共用体只使用多种数据格式中的一种，常用于节省内存空间

3. 匿名共用体，其成员将成为位于相同地址处的变量

## 4.6 枚举

1. enum，另一种创建**符号常量**的方式，可以代替const
    ```cpp
    enum spectrum {red, orang, blue, green};
    ```

##  4.7 指针
1. 
    ```cpp
    int* p1, p2; // 声明了一个指针和一个int变量，每一个指针都需要一个*
    ```

2. 创建指针时，计算机将分配存储地址的内存，但不会分配用来存储所指向的数据的内存

3. 指针应初始化为一个确定的、适当的地址。
    ```cpp
    long* fellow;
    *fellow = 2333; // wrong，指针可能任何位置
    ```

4. 应通过强制类型转换将数字转换为地址类型再赋给指针

    ```cpp
    int* pt;
    pt = (int*) 0xB8000000; // 给指针赋值指定地址
    ```

5. new 

    ```cpp
        int *pt = new int; // 左边向编译器指明数据大小，右边申请适当大小
    ```

6. 变量：存储在stack中；new：heap或free store

7. delete
    ```cpp
    int* ps = new int;
    delete ps;
    int p = 5;
    int* pt = &p;
    delete pt;  // wrong
    ```

    1. 这将释放ps指向的内存，但不会删除ps，可以将ps重新指向新的内存块

    2. 不要重复释放已经释放的内存块，会造成不确定的后果

    3. 只能delete释放new分配的内存

    4. delete空指针是安全的

    5. new [], delete []

8. 动态数组

    1. 通过声明创建的数组，编译时加入程序中，静态联编(static binding)，
    new创建的数组，可以在运行时选择长度，动态联编(dynamic binding)

    2. 不能用sizeof来确定动态分配的数组包含的字节数

    3. 指针和数组
        ```cpp
        double *p3 = new double[3];
        p3[0] = 0;
        p3[1] = 1;
        p3[2] = 2;
        ```
        1. 数组名不能修改，但指针是变量，可以修改

        2. 可以把指针当数组名来使用，*p3 = p3[0]

        3. delete时，p3应指向数组开头, p3[0]不一定是首元素，要适当调整 p3 = p3 + 1; p3 = p3 - 1

## 4.8 指针、数组和指针算术

1. C++将数组名解释为第一个元素的地址
    ```cpp
    double wages[3] {1000., 2000., 300.};
    double* pw = wages;         // 
    double* ps = &wages[0];     // 两者等价
    cout << "pw: " << pw << endl;       // pw: 0x61fe00
    cout << "ps: " << ps << endl;       // ps: 0x61fe00
    cout << "*pw: " << *pw << endl;     // *pw: 1000
    cout << "*ps: " << *ps << endl;     // *ps: 1000
    ```

2. 指针变量+1，其增加的值等于指向的类型占用的字节数

3. 对数组应用sizeof得到的是数组的长度，对指针应用sizeof，得到的是指针的长度

4. 数组的地址
    ```cpp
    short tell[10];                     // 数值上tell = &tell，但实际上tell != &tell
    cout << "tell: " << tell << endl;           // tell: 0x61fe00        &tell[0]
    cout << "&tell: " << &tell << endl;         // &tell: 0x61fe00       &tell
    cout << "tell + 1: " << tell + 1 << endl;   // tell + 1: 0x61fe02
    cout << "&tell + 1: " << &tell + 1 << endl; // &tell + 1: 0x61fe14

    ??? short (*pas)[20] = &tell
    ```
    &tell[0] = tell,是一个2字节内存块的地址
    
    &tell是一个20字节内存块的地址，指向包含20个元素的short数组

5. 使用**方括号数组表示法等同于对指针解除引用**
    ```cpp
    using namespace std;
    float treacle[10];
    float* p = treacle;
    cout << *p << *(p+9) << endl; 
    cout << p[0] << p[9] <<endl;    // 等价
    ```

6. 指针和字符串

    1. 引号括起来的字符串常量，像数组名一样，是第一个元素的地址
    ```cpp
    char flower[10] = "rose";
    cout << flower << "chars\n";
    ```

    2. char数组名、char指针、" "括起来的字符串常量都被解释为字符串的第一个字符的地址

    3. 在C++中，字符串字面值都被视为常量，C++不保证字符串字面值被唯一地存储，如在程序中多次使用，可能存在多个副本

    4. 将字符串赋给数组，应使用strcpy或strncpy

    5. 给cout一个指针，通常打印地址，但当指针的类型是char*时，将显示字符串，需打印地址用(int *)强制类型转换

7. 动态结构

    1. 动态结构只有地址，没有结构名，使用->来访问成员

    2. 结构名：用.访问成员，指针：用->访问成员
        ```cpp
        struct inflatable{
            char name[20];
            float volumn;
            double price;
        };
        inflatable* ps = new inflatable;
        ps->name;
        (*ps).volumn;
        ```

8. 自动存储、静态存储和动态存储

    1. 在函数内部定义的常规变量（自动变量），使用自动存储空间，通常存储在栈中，调用函数时存在

    2. 静态存储的变量在程序执行时存在，1、2严格限制变量的寿命

    3. 动态存储，数据存储在堆空间（自由存储空间），数据的生命周期不完全受程序或函数的生存时间限制

9. 模板类

    1. vector：使用new创建动态数组的替代品，new：存储在堆空间，可自由调整长度，可能效率稍低```vector<int> vt(n) // n可变```

    2. array: 对象长度固定，使用栈空间，效率更高```array<int, 5> ai; // 数组长度不变```

    3. 数组、vector、array

        1. array和数组存储在栈空间

        2. array对象可以用' = '赋值

        3. 数组必须逐元素复制数据

        4. 数组可以将元素存储到数组的外面，C++不检查这种超界错误

        5. vector和array有成员函数at()，可以在运行期间捕获非法索引，终端程序

        
## 4.9 练习

1. ex12 
    ```cpp
    // 使用方括号数组表示法等同于对指针解除引用
    using namespace std;
    float treacle[10];
    float* p = treacle;
    cout << *p << *(p+9) << endl; 
    cout << p[0] << p[9] <<endl;    // 等价
    ```

2. ex16
    ```cpp
    // 获取字符串输入时，使用getline
    char address[20];
    cin.getline(address, 20);  // getline(cin, address);
    cin >> address;  // 会丢弃空格，且只能读取到一个单词
    ```

3. program ex8
    ```cpp
    struct pizza{string name; float radius; float weight;};
    pizza *p1 = new pizza;
    cout << "radius: \n";
    cin >> p1->radius;
    cout << "please enter company's name: \n";
    cin.get();     // 先获取半径，会在输入序列留下一个'\n'(确定时的回车键),导致getline直接跳过
    getline(cin, p1->name);
    ```

4. new记得delete

***

# 5. 循环和关系表达式

## 5.1 for循环

1.  ```(i = 0; i < 5; i++)```初始化、测试、更新(i=0 -> i<5 -> 循环 -> i++)

2. 当判定表达式的值这种操作改变了内存中数据的值时，表达式有副作用(side effect)

3. 表达式和语句

    1. 每个**表达式都有值**，表达式=value

    2. 语句 = 表达式 + ；

    3. ```int num; return 0;.....```**不是表达式，没有值**

4. ```for (int i = 0; i < 5; i++) // cpp new feature``` ```int i = 0```声明语句表达式，这种变量只在循环内有效

5. ++和--
    ```cpp
        int x = 5;
        int y = x++;
        cout << "x++: " << x << " y: " << y << endl;  // x++: 6 y: 5,使用x后自增
        int z = 5;
        y = ++z;
        cout << "++z: " << z << " y: " << y << endl;  /++z: 6 y: 6，自增z后使用
    ```

6. 副作用和顺序点
    1. 副作用：在计算表达式时对某些东西进行了修改

    2. 顺序点：程序执行过程中的一个点，在这里，进入下一步之前将确保对所有的副作用都进行评估（副作用执行完毕）

        ```cpp
            int guests = 0;
            while(guests++ < 10)
                cout << guests << "  ";
        // 输出结果：1  2  3  4  5  6  7  8  9  10
        ```
    ```(guests++ < 10)```是一个完整的表达式，该表达式末尾是一个顺序点，因此guests+1将在进入循环体前完成,```++```后缀保证guests先跟10比较再+1

7. 前缀格式和后缀格式
    ```cpp
    cout << "n++: ";
    for (int n = 0; n < 10; n++)
        cout << n;
    cout << endl;                   // n++: 0123456789
    cout << "++n: ";
    for (int n = 0; n < 10; ++n)
        cout << n;
    cout << endl;                   ++n: 0123456789
    ```

    递增表达式的值没有被使用，此时前缀和后缀格式没有区别；将```(n++),(++n)```作为值使用时不一样，如```y=n++, y=++n```

    ```cpp
    int n1, n2;
    n1 = n2 = 0;
    cout << "n++: ";
    for (int n = 0; n < 10; n1 = n++)   // n=0;n<10;cout<<n1=0;n1=n++(n1=0,n=1)n先用后+
        cout << n1;                     // 所以有两个0
    cout << endl;                       // n++: 0012345678
    cout << "++n: ";
    for (int n = 0; n < 10; n2 = ++n)   // n=0;n<10;cout<<n2=0;n2=++n(n=1,n2=1)
        cout << n2;
    cout << endl;                       // ++n: 0123456789
    ```
    前缀：将值+1，然后返回结果
    
    后缀：首先复制一个副本，将其+1，然后返回复制的副本

    对于内置类型，没有差别，但对于用户定义的类型，前缀效率更高

8. ++/--和指针

    ```cpp
    double arr[5]{21.1, 32.8, 23.4, 45.2, 37.4};
    double *pt = arr;                               // 指向arr首地址
    cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fdd0 *pt: 21.1
    ++pt;                                           // pt+1
    cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fdd8 *pt: 32.8
    double x = *++pt;                               // pt+1后解引用
    cout << "x: " << x << endl;                     // x: 23.4
    cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde0 *pt: 23.4
    ++*pt;                                          // 解引用后+1，原地修改，pt不变
    cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde0 *pt: 24.4
    (*pt)++;                                        // 解引用后+1，原地修改，pt不变
    cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde0 *pt: 25.4
    x = *pt++;                                      // pt+1，解引用取出数据，此时用的是+1前的值，(pt++)：pt使用后+1
    cout << "x: " << x << endl;                     // x: 25.4
    cout << "pt: " << pt <<" *pt: " << *pt << endl; // pt: 0x61fde8 *pt: 45.2
    ```
    1. 优先级：后++ ```=``` 后--```  >  ```前++ ```=``` 前-- ```=``` 解除引用*

9. 逗号**运算符**```,```
    
    1. 可以将两个表达式合并为一个

    2. ```int i, j;```在这里，```,```是分隔符，不是运算符

    3. ```i = 20, j = 2 * i;```逗号表达式的值是第二个表达式的值 

    4. 逗号运算符的优先级是最低的

    5.  ```cpp
        int cats;
        cats = 17, 240;
        cout << "cats: " << cats << endl;               // cats: 17
        (cats = 17), 240;
        cout << "cats: " << cats << endl;               // cats: 17
        cats = (17, 240);
        cout << "cats: " << cats << endl;               // cats: 240
        cats = (240, 17);
        cout << "cats: " << cats << endl;               // cats: 17
        ```

10. 字符串比较
    ```cpp
    char word[5] = "mate";
    word == "mate";             // 不能比较，两者都是一个地址，用strcmp比较，可能返回<0, >0, =0的值
    ```

## 5.2 while循环
    
1. 与for的区别
    
    1. ```for(;;)```默认条件为TRUE

    2. for可以声明一个局部变量

    3. 无法预知循环次数时，常用while

2. 类型别名

    1. #define
    ```cpp
    #define float_pt float *
    float a = 0.;
    float_pt pa = &a, pb = 1;                       // pa: pointer, pb: float
    cout << "pa: " << pa << " pb: " << pb << endl;  // pa: 0x61fe1c pb: 1
    ``` 

    2. typedef(alias): 不会创建新类型，建立一个新名称

## 5.4 基于范围的for循环
        ```cpp
        double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
        for (double x : prices)
            cout << "x: " << x << ' ';// x: 4.99 x: 10.99 x: 6.87 x: 7.99 x: 8.49 
        cout << '\n';
        for (double &x : prices)
            cout << "x: " << x << ' ';// x: 4.99 x: 10.99 x: 6.87 x: 7.99 x: 8.49 
        ```

## 5.5 循环和文本输入

1.  ```cpp
    char ch;
    int count = 0;
    cout << "enter '#' to quit.\n";
    cin >> ch;                          // hbjhgjhg ghgjhg  #hghg,在这里输入了一行
    while (ch != '#')
    {
        cout << ch;                     // hbjhgjhgghgjhg
        ++count;
        cin >> ch;
    }
    cout << "\ncount: " << count << endl;       // count: 14
    ```

    1. cin会忽略空格和换行符

    2. 输入的内容会被缓冲，按下回车后，输入才被发送给程序，所以第一个cin可以输入一行,之后cin从缓冲序列中读取内容

    3. 成员函数cin.get(ch)可以读取到输入字符中的空格，可以代替cin >> ch

    4. ```cin.get(ch);```返回cin对象，```ch = cin.get();```返回一个字符

    5. EOF文件尾

## 5.7 总结

```cpp
cin >> ch;          // 将输入中的下一个字符读入到ch中，会忽略空格、换行符和制表符
cin.get(ch);        // 读取输入中的下一个字符（不管是什么）并存储到ch中，返回的是cin对象，该对象可以被转换成bool值，标志读取是否成功
ch = cin.get();     // 成员函数返回下一个输入字符，包括空格、换行符和制表符
```

```cin.get(ch)```**返回的是cin对象**,```cin.get()```**返回字符**```cin >> ch```**会跳过空白、回车、制表符**

## 5.9 编程练习

1. ex5 ```const char* p[2] = {"aaa", "bbb"};```必须加**const**

***
# 6. 分支语句和逻辑运算符

## 6.3 字符函数库cctype

1.  ```cpp
    # include <cctype>;
    using namespace std;
    isalnum(); isalpha(); iscntrl(); isdigit();......
    ```

## 6.4 ?:条件运算符

1. 条件运算符生成一个表达式，因此是一个值

## 6.5 switch语句

1. case标签只是行标签，跳到switch执行特定代码后，需要break，否则继续执行后续case，这使得使用多标签变得简单

2. 可以将枚举量用作标签

## 6.8 简单文件输入/输出
```cpp
#include <fstream>          // 1. 包含fstream；
ofstream outFile;           // 2. 创建一个ofstream对象；
outFile.open("a.txt");      // 3. 将该对象跟一个文件关联；
                            // 像使用cout一样
outFile.close();
```
```cpp
#include <fstream>
#include <cstdlib>          // 包含了exit()，定义了参数EXIT_FAILURE，用来终止程序
ifstream inFile;
inFile.open("a.txt");
if (!inFile.is_open())      // 判断文件打开是否成功
    exit(EXIT_FAILURE);
                            // 像使用cin一样
// inFile.good(); inFile.eof(); inFile.fail();   一些标志，用来判断读取到的数据是否有问题
inFile.close();
```

## 6.10 复习题

1. review7  switch case后记得添加break

2. review8 字符标签好于整数标签，因为输入的数字可以转为字符标签，但输入的字符不会转为整数标签

3. ex4 结构体内包含字符数组，new不成功？？？

***

# 7. 函数

## 7.1 函数

1. 返回值的类型不能是数组，但数组可以作用结构或对象的组成部分来返回

2. 原型描述了函数到编译器的接口

3. 函数原型不要求提供变量名，要求类型列表，原型中的变量名相当于占位符，因此不必与函数定义中的变量名相同

4. 不指定参数列表时应当使用省略号

5. 原型可以让编译器：
    1. 正确处理函数的返回值

    2. 检查使用的参数数目

    3. 检查使用的参数类型

6. C++自动将传递的值转换为原型指定的类型

7. 编译阶段进行的原型化：静态类型检查

## 7.2 函数参数和按值传递

## 7.3 函数和数组

1. 在函数头或函数原型中，```int arr[]```和```int* arr```含义相同，都表示一个```int```型指针

2. 指针和const

    1. 让指针指向一个常量对象，防止使用该指针来修改所指向的量

        ```cpp
        int age = 18;
        const int * pt = &age; // 可以通过age来修改值，但不能通过pt来修改
        ```
        pt指向一个const int，不能使用pt来修改这个值，但并不意味着它指向的值是个常量，而是对pt而言，这个值是常量

    2. 将指针本身声明为常量，防止改变指针指向的位置
        ```cpp
        int age = 10;
        int * const p = &age;
        ```
        const p指向一个age，可以使用*p来修改age，但不能修改p的指向 

    3.  ```cpp
        const int **pp2;
        int *p1;
        const int n = 13;
        pp2 = &p1;          // not allowed, but suppose it were
        *pp2 = &n;          // valid, both const, but sets p1 to point as n
        *p1 = 10;           // valid, but changes const n
        ```
        只有一层间接关系时，才可以将非const地址或指针赋给const指针
        **非const指针指向非const数据**
        **const指针可以指向const数据或非const数据的地址，该数据类型不能是地址**

    4. 若条件允许，尽可能使用const

        1. 可以避免无意修改数据

        2. const指针可以处理const和非const实参，非const只能接受非const数据

## 7.4 函数和二维数组

1. 传入一个指向数组的指针
    ```cpp
    int sum(int (*arr)[4], int size)    // = int sum(int arr[][4], int size)
    {
        int total = 0;
        for (int r = 0; r < size; ++r)
        {
            for (int c = 0; c < 4; ++c)
                total += arr[r][c];
        }
        return total;
    }
    ```

## 7.5 函数和C-风格字符串

1. 将字符串作为参数来传递，实际上传递的是第一个字符的地址，形参应声明为```char*```

2. 不以空值字符结尾的char数组只是数组，不是字符串

3.  使用数组表示法声明时，参数不一定必须是数组名，可以是其他形式的指针
    ```cpp
    unsigned int c_in_str(const char * str, char ch)
    unsigned int c_in_str(const char str[], char ch)    // 字符数组名 = char*
    ```

## 7.10 函数指针

1. 将另一个函数的地址作为参数的函数，可以在不同的时间传递不同的地址，从而在函数里使用不同的函数

2. 获取函数的地址，只使用函数名
    ```cpp
    process(think);         // 给process传入think函数的地址
    thaught(think());       // 给thaught传入think的返回值
    ```

3. 声明函数指针
    ```cpp
    double (*pf)(int);      // pf points to a function that returns double
    double *pf(int);        // pf() a function that returns a pointer-to-double
    ```
    ```cpp
    double pam(int);
    double (*pf)(int);
    pf = pam;
    double x = pam(4);
    double y = (*pf)(5);
    double z = pf(5);           // 允许直接使用函数指针调用函数
    ```
    ```(*pf)```是函数，```pf```是函数指针，pam的参数列表和返回类型必须和pf的相同

4. auto typedef

## 7.12 

1. ex9：```strspn(s1, s2)```返回s1中有多少个字符属于s2，可用来判断空白行

2. ex10 **hard...**

***
# 8. 函数

## 8.1 内联函数

1. 编译器使用函数代码代替函数调用，占用更多内存

2. 程序员请求将函数作为内联函数，但编译器不一定满足

3. 内联函数不能递归

4. ```inline double square(double x) {return x * x}```可以用整个函数定义充当原型

## 8.2 引用变量

1. 引用：已定义的变量的别名，主要用作函数的形参，此时函数可以使用原始数据

2. 必须在声明时初始化,不能通过赋值来设置
    ```cpp
    int rats = 101;
    int *pt = &rats;
    int &rodents = *pt;     // rodents是(*pt = rats)的别名
                            // rodents指向某个地址处不再改变，使用rodents改变的是该地址里的内容
    int bunnies = 50;
    pt = &bunnies;          // 不影响rodents
    rodents = bunnies;      // = (rats = bunnies)，将bunnies的值赋给rats
    ```

3. 临时变量、引用参数和const

    1. 生成临时变量：
        ```cpp
        double refcube(const double &ra)
        {
            return ra * ra *ra;     
        }
        long edge 5L;

        refcube(sice + 10);         // 1) 实参类型正确但不是左值
        refcube(edge);              // 2) 实参的类型不正确
        refcube(10);                // 3) 类型正确但没有名称
        ```
    
    2. 左值：变量、数组元素、结构成员、引用和解除引用的指针、常规变量和const变量（可通过地址访问）

    3. 不要忽略有关临时变量的警告

    4. 对于形参为const引用的函数，如果实参不匹配，则其行为类似于按值传递

4. 右值引用```&&```

5. 函数返回的引用被赋予了其他值，可以覆盖返回值
    ```cpp
    accumulate(dup, four) = five;  
    //   = 
    accumulate(dup, four);          // 返回的是指向dup的引用
    dup = five;                     // 再次修改dup
    ```

6. 为何要使用引用？

    ```cpp
    struct free_throws & accumulate(free_throws & target, const free_throws & source) 
    // 声明返回的是引用
    {
        return target;
    };
    dup = accumulate(team, five);
    ```

    1. 传统返回机制：返回值被复制到一个临时位置，调用程序使用临时位置的返回值；

    2. 返回的是引用，但是可以用引用接收，也可以不用引用接收。
            
        1. 不使用引用接收时```free_throws receive = accumulate();```，函数返回值直接**复制到receive（此时receive是新变量，不再影响target）中**，省略临时变量，效率更高

        2. 使用引用接收时，```free_throws receive_1 = accumulate();```，receive_1的地址就是传入accumulate的target所指向的地址，修改receive_1等于修改target的原始数据

7. 将const用于引用返回类型

    使用引用返回值，但又不允许给返回值进行赋值操作，加const

8. 返回引用应注意
    ```cpp
    const free_throws & clone2(free_throws & ft)
    {
        free_throws newguy;
        newguy = ft;
        return newguy;
    }
    ```
    声明指出返回的是引用，但引用的是局部变量，所以不合法。应避免返回函数终止时不再存在的内存单元引用，也应避免返回临时变量的指针
    ```cpp
    const free_throws & clone(free_throws & ft)
    {
        free_throws * pt;
        *pt = ft;
        return *pt*;
    }
    ```

9. 例8.6

    ```free_throws dup```dup是一个结构体，所以将accumulate的返回值复制给dup


10. 使用引用还是指针

    |             |  不修改数据    |  修改数据   |
    |  ---------  |   ---------   | ---------  |
    |内置数据类型  | 按值传递       |   使用指针  |
    | 数组        | const指针    |   只能使用指针 |
    | 结构        | const指针或const引用      |   指针或引用    |
    | 类对象      |    const引用   |    引用   |

## 8.3 默认参数

1. 通过原型来设置默认参数，函数定义可以不设置默认参数

2. 从右到左添加默认值

## 8.4 函数重载（多态）

1. 关键：参数列表，也称函数特征标。根据特征标来对函数进行重载

2. 没有匹配的原型，会尝试进行类型转换

3. 检查特征标时，类型引用和类型本身视为同一个特征标
    ```cpp
    double cube(double x);
    double cube(double &x);
    ``` 

4. 匹配函数时，不区分const和非const变量

5. 不允许以这种方式重载，函数特征标相同
```cpp
long gronk(int n, float m);
double gronk(int n, float m);
```

6. 根据参数是左值、const和右值来定制函数的行为
    ```cpp
    void stove(double & r1);
    void stove(const double & r2);
    void stove(double && r1);

    double x = 55.5;
    const double y = 32.0;
    stove(x);                 // call stove(double & r1);
    stove(y);                // call stove(const double & r2);
    stove(x + y);           // call stove(double && r1);
    ```

7. 需要使用不同类型的参数时，使用函数重载

8. 编译器通过名称修饰（名称矫正）来区分重载的函数
```cpp
long MyFunctionFoo(int, float);     // ?MyFunctionFoo@@YAXH
```

## 8.5 函数模板

1. 关键字
    ```cpp
    template;
    typename;       // 可以用class代替

    template <typename T>
    void Swap(T &a, T &b)
    {
        T temp;
        temp = a;
        a = b;
        b = temp;
    }
    ```

2. 模板不创建函数，只是告诉编译器如何定义函数

3. 可以重载模板定义

4. 显式具体化（非模板函数 > 具体化模板函数 > 模板函数）

5. 实例化和具体化
    
    1. 实例化生成函数定义

    2. 具体化可以修改函数内的操作

    3.  ```cpp
        template;            // 显式实例化
        template <>;        // 显式具体化
        ```

6. 重载解析，选择合适的函数版本

    1. 完全匹配 > 提升转换 > 标准转换 > 用户定义的转换

    2. 参数为指针、引用时，非const > const

    3. 完全匹配和最佳匹配：显式具体化 > 模板隐式生成的具体化

    4. 部分排序规则：选择更具体的

7. 声明不知道类型的变量```decltype```

8. 后置返回类型
    ```cpp
    template<class T1, class T2>
    auto gt(T1 x, T2 y) -> decltype(x + y)
    {
        return x + y;
    }
    ```

9.  ```cpp
    double xx = 4.4;
    decltype(xx) v1;        // v1 is type double;
    decltype((xx)) v2;      // v2 is type double &;
    ```

# 9. 内存模型和名称空间

1. 头文件：包含结构声明和使用这些结构的函数的原型

    1. 包含了用户定义类型的定义

    2. 不要将函数定义或变量声明放到头文件中

    3. 常包含：函数原型、define或const符号常量、结构声明、类声明、模板声明、内联函数

2. 源代码文件：包含与结构有关的函数的代码；包含调用与结构相关的函数的代码

    1. 包含操纵用户定义类型的函数的代码

3. ``` <aaa.h> ```在存储标准头文件的文件系统中查找尖括号包含的文件名，``` "aaa.h" ```首先在当前工作目录或源代码目录查找双引号包含的头文件，然后再标准位置查找

4. 避免多次包含同一个头文件
    ```cpp
    #ifndef AAA_H_
    ....
    #endif
    ```

5. 在编译连接模块时，请确保所有对象文件或库由同一个编译器生成。防止编译器为同一个函数生成不同的修饰名称，导致无法正确链接。

存储持续性：
    
    1. 自动存储
    
    2. 静态存储

    3. 线程存储

    4. 动态存储 

6. 自动存储持续性
    ```cpp
    int main()
    {
        int x = 2021;
        cout << "main x = " << x << endl;               // main x = 2021
        {
            cout << "block x = " << x << endl;          // block x = 2021
            int x = 1202;                               // new var, hide main x
        //  x = 1202;                                     not change x
            cout << "new block x = " << x << endl;      // new block x = 1202
        }
        cout << "after block x = " << x << endl;        // after block x = 2021
        return 0;
    }
    ```
    1. 在函数中声明的函数参数和变量的存储持续性为自动，作用域为局部，没有链接性

    2. 自动存储持续性变量的作用域：从定义它的位置到该代码块的结尾

    3. 可以使用任何在声明时其值为已知的表达式来初始化自动变量

    4. 使用栈来管理自动变量的增减

    5. register：寄存器变量

7. 静态持续变量

    1. 外部链接性，声明在代码块外

    2. 内部链接性，声明在代码块外+static

    3. 无链接性，声明在代码块内+static

8. 所有静态变量都被零初始化，然后执行常量表达式初始化

9. 静态持续性、外部链接性

    1. 单定义规则：变量只有一次定义，引用声明使用extern，且不进行初始化

    ```cpp
    double up;              // definition, up is 0
    extern int blem;        // defined elsewhere
    entern char gr = 'z';   // definition, because initialized
    ```

    2. 作用域解析运算符```::var```，表示使用变量```var```的全局版本

10. 静态持续性、内部链接性

    1. 链接性为内部的变量只能在其所属的文件中使用

11. 静态持续性、无链接性

    1. 将static限定符用于在代码块中定义的变量。虽然该变量只在该代码块中可用，但它在该代码块不活跃时仍然存在；在两次调用函数之间，静态局部变量的值将保持不变。
    ```cpp
    int main()
    {
        static int s = 1;
        def_static();                   // static s = 20
        cout << "s = " << s << endl;    // s = 1
        def_static();                   // static s = 30
        return 0;
    }

    void def_static()
    {
        static int s = 10;
        s += 10;
        cout << "static s = " << s << endl;
    }
    ```

12. cv-限定符

    1. const：

        1. 默认，全局变量的链接性是外部的，但const全局变量的链接性为内部```const = static const```

        2. 可以使用extern来覆盖默认的内部链接性

    2. volatile：即使程序没有对内存单元进行修改，其值也可能发生改变（如硬件修改其中的值）

13. mutable：可以用它来指出，即使结构（类）变量为const，其某个成员也可以被修改

14. 函数和链接性

    1. 函数的存储持续性都自动为静态，即在整个程序执行期间一直存在；链接性为外部，可以在文件间共享

    2. 可以使用extern来指出函数是在另一个文件中定义的

    3. 可以使用static将函数的链接性设置为内部的，使其只能在文件中使用

    4. 非内联函数适用单定义原则

15. 语言链接性

    1. 函数是静态的，编译器只在该文件中查找函数定义；否则在所有的程序文件中查找

    2. 编译器将函数名翻译为符号名称，C++使用名称修饰

    ```cpp
    extern "C" void spiff(int);         // use C protocol for name look-up       _spiff
    extern void spoff(int);             // use C++ protocol for name look-up     _spoff_i
    extern "C++" void spaff(int);       // use C++ protocol for name look-up     _spaff_i
    ```

16. ```new```失败：旧：返回空指针；新：引发异常```std::bad_alloc```

17. 定位new运算符，可以指定要使用的位置
    ```
    char buffer[50];
    char *pt;
    pt = new (buffer) char[10];
    ```
    1. 当buffer指定的内存是静态内存时，不能使用delete；当buffer使用的也是new运算符创建的内存，可以使用delete

    2. 将定位new运算符与初始化结合使用，可以将信息放在特定的硬件位置处。

# 9.3 名称空间

1. 声明区域、潜在作用域、限定的名称

2. 名称空间可以是全局的，也可以位于另一个名称空间中，但不能位于代码块中；链接性为外部的（除非引用了常量）

3. 作用域解析运算符```::```

4. using声明和using编译指令
    ```
    using std::cin;         // using声明，将特定名称添加到它所属的声明区域中，使一个名称可用
    using namespace std;    // using编译指令，使所有名称可用
    ```
    1. 当名称空间和声明区域定义了相同的名称时，若使用using声明，则这两个名称会发生冲突；使用using编译指令，该名称的局部版本将隐藏名称空间版本

5. namespace是可传递的
    ```
    namaspace myth
    {
        using namespace elements;
    }
    ```
    1. ```using namespace myth;``` = ```using namespace myth; using namespace elements;```

    2. 创建别名```namespace ME = myth::elements;```

6. 未命名的名称空间，可作为链接性为内部的静态变量的替代品
# 10. 对象和类

## 10.2 抽象和类

1. OOP特性：抽象、封装和数据隐藏、多态、继承、代码的可重用性

2. 类：将抽象转换为用户定义类型，将数据表示和操纵数据的方法组合成一个整洁的包。

3. 类规范：类声明、类方法定义

4. 将接口（类定义）放在头文件，将实现（类方法的代码）放在源代码中；要存储的数据以类数据成员的形式出现，要执行的操作以类成员函数的形式出现

5. 使用类对象的程序可以直接访问共有部分；但只能通过公有成员函数来访问对象的私有成员

6. 封装：将实现细节和抽象分开。例：数据隐藏、将类函数定义和类声明放在不同的文件中

7. 默认访问控制：private

8. 结构和类

    1. 类是结构的拓展

    2. 区别：结构，默认public；类，默认private

9. 定义成员函数时，用``` :: ```来标识函数所属的类

10. 类方法可以访问类的private组件

11. 位于类声明中的函数将自动成为内联函数，可以使用inline限定符

## 10.3 类的构造函数和析构函数

1. 构造函数使得类可以像标准类型一样初始化，构造函数的名称和类名相同，可以通过重载创建多个重名的构造函数

2. 构造函数没有声明类型，声明对象时，自动调用构造函数；不能通过对象来调用构造函数

3. 构造函数的参数不能与类成员相同，数据成员常使用1、m_前缀；2、后缀_

4.  
    ```cpp
    // class Stock
    Stock garment = Stock("Furry", 0, 2.5);     // 显式调用构造函数
    Stock garment("Furry", 0, 2.5);             // 隐式调用
    ```

5. 定义默认构造函数

    1. 给已有构造函数的所有参数提供默认值

    2. 通过函数重载来定义一个没有参数的构造函数

6. 析构函数```~Stock();```没有返回值和声明类型，没有参数

7.  ```cpp
    Stock stock2 = Stock("Boffo", 2, 2.0);      // 初始化，可能会创建临时变量，也可能不创建，编译器决定
    stock1 = Stock("Nifty", 10, 50.0);          // Stock一定会创建临时变量，然后赋值给stock1
    ```

8. 先构造，后析构；中间用新构造的变量给变量重新赋值了，依然根据构造顺序后析构

9. 既可以赋值，也可以初始化来设置对象的值时，优先使用初始化，效率更高

10. 类可以使用列表初始化 **"{ }"**
    ```cpp
    Stock hot_tip = {"derivatives Plus Plus", 100, 45.0};
    Stock jock {"Sport Age Storage, Inc"};
    Stock temp {};
    ```

11. const成员函数``` void Stock::show() const       // promises not to change invoking object```;const放在函数后面，保证不修改对象内容

12. 警告：接受一个参数的构造函数允许使用赋值语法将对象初始化为一个值

## 10.4 this指针

1. this指针指向用来调用成员函数的对象（this被作为隐藏参数传递给方法）

2. 引用整个对象，可以使用*this

## 10.5 对象数组

1. 初始化对象数组，首先使用默认构造函数创建数组元素，然后花括号中的构造函数将创建临时对象，然后将临时对象复制给相应元素
    ```cpp
    Stock stocks[4] = {
        Stock("Nano", 12.5, 20),
        Stock()
    };

## 10.6 类作用域

1. 作用域为类的常量
    ```cpp
    // 在类中定义常量，适用于所有对象的常量
    class Bakery
    {
        private:
        const int Months = 12;              // fails
        static const int Months;            // valid
        enum {Months = 12};
    }
    ```
    1. 枚举并不会创建类数据成员，所有对象中都不包含枚举，Months只是一个符号名称，编译器遇到时用12替换

    2. Months常量与其他静态常量存储在一起，不是存储在对象中，只有一个Months常量

2. 作用域内枚举

    1. 新枚举```enum class```，可以用```struct```代替```class```
    ```cpp
    enum class egg {Small, Medium, Large};
    enum class t_shirt {Small, Medium, Large};
    ```

    2. 枚举量的作用域为类后，不同枚举定义中的枚举量不会发生名称冲突

    3. 作用域内枚举不能隐式地转换为整型，可显示转换
    ```cpp
    int Frodo = int(t_shirt::Small);
    ```

    4. 使用枚举名来限定枚举量
    ```cpp
    enum choice = egg::Large;
    enum Floyd = t_shirt::Large;
    ```

    5. 可以指定枚举的底层整数类型```:short```
    ```cpp
    enum class :short pizza {Small, Medium, Large};
    ```

# exercise

1. ex2
    
    1. 默认参数在声明和定义的地方只能出现一次

    ```cpp
    Person(const std::string &ln, const char * fn = "Heyyou");      // declare
    Person(const std::string &ln, const char * fn)                  // definition
    {
        ...
    } 
    ```

# 11. 使用类

## 11.1 运算符重载

1. 运算符函数：
    
    ```cpp
        operator+();    operator*();    operator[]();   // 只能重载有效的C++运算符，[]是数组索引运算符        
    ```

2. 重载限制：

    1. 重载后的运算符至少有一个操作数是用户定义的类型，防止用户为标准类型重载运算符

    2. 不能违反运算符原来的句法规则，不能修改优先级

    3. 不能创建新的运算符

    4. 不能重载下面的运算符
    
        ```cpp
        sizeof  . .*  ::  ?:  typeid  const_cast  dynamic_cast  reinterpret_cast static_cast
        ```

## 11.3 友元

1. 另一种形式的访问权限

2. 友元函数、友元类、友元成员函数

3. 关键字：```friend```，不能用成员运算符来调用、与成员函数的访问权限相同，在类声明中声明原型时使用

4. 友元函数的定义不用关键字```friend```

5. 操作符使用两种不同类型的操作数时，可以使用友元函数重载运算符。需要访问类对象的私有成员时，要成为该类的友元函数

6. 

## 11.6 类的自动转换和强制类型转换

1. 只接受一个参数的构造函数可以作为转换函数，多个参数时，其他参数需要有默认值

2. 关键字```explicit```可以关闭隐式转换

3. 只接受一个参数，可以使用```=```来初始化类对象

    ```cpp
    Stonewt incognito = 275;                // 接受一个参数
    Stonewt incognito(275);                 // 
    Stonewt incognito = Stonewt(275);       // 可以同时接受多个参数
    ```

4. 构造函数：某种类型到类类型的转换

5. 转换函数

    1. 类对象到某种类型的转换

    2. 转换函数必须是类方法

    3. 转换函数不能指定返回类型

    4. 转换函数没有参数

    5. 通过类对象来调用
    ```cpp
    operator typeName();    // operator double();
    ```

6. 

# 12. 类和动态内存分配

## 12.1 动态内存和类

1. 类的静态类成员，所有对象共享，只创建一个静态类变量副本

2. 类声明内只对类静态变量进行声明，不初始化（声明描述如何分配内存，但并不分配内存），初始化在类方法文件中进行

3. 如果静态成员是const整数类型或枚举类型，则可以在类声明中初始化

4. 删除对象可以释放对象本身占用的内存，但并不能自动释放属于对象成员的指针指向的内存。因此，必须使用析构函数，delete构造函数中new分配的内存

5. 特殊成员函数

    1. 默认构造函数

    2. 默认析构函数

    3. 复制构造函数

    4. 复制运算符

    5. 地址运算符

    6. 其他：移动构造函数、移动赋值运算符

6. 当按值传递和返回对象时，调用复制构造函数

7. 默认的复制构造函数逐个复制**非静态成员（浅复制）**，复制的是成员的值

8. 复制构造函数的原型```StringBad::StringBad(const StringBad &);```一个指向类对象的常量引用作为参数

9. 如果类中包含使用new初始化的指针成员，应当定义一个复制构造函数，完成深拷贝

10. 空指针关键字```nullptr```

11. 可以将成员函数声明为静态的，静态成员函数不与特定对象关联，因此只能使用静态数据成员

12. 可以使用静态成员函数设置类级（classwide）标记，以控制某些类接口的行为

## 12.3 在构造函数中使用new应注意

1. 如果有多个构造函数，必须使用相同的方式使用new（是否带[]），因为析构函数只有一个，delete可以用于空指针

2. 应定义一个复制构造函数，完成深拷贝

3. 应定义一个赋值运算符，完成深拷贝，检查自我赋值，释放成员指针以前指向的内存，返回一个指向调用对象的引用（直接修改调用对象，不用生成临时对象）

4. 重载cout使用的<<必须返回指向cout的引用。如果返回对象，则要求调用ostream类的复制构造函数，但ostream没有公有的复制构造函数

5. 返回const对象
    ```cpp
    net  = force1 + force2;
    force1 + force2 = net;      // force1 + force2返回的是局部对象时，将生成临时对象，返回类型+const可以防止误用和滥用
    cout << (force1 + force2 = net) << endl;
    ```

6. 析构函数调用

    1. 动态变量，执行完程序块时调用

    2. 静态变量，程序结束时调用

    3. new创建，delete时调用

7. 定位new运算符

    1. 直接在buffer中new两个对象，会从同一地址创建对象，因此需要自行管理需要使用的内存单元

    2. delete时，使用delete[]直接delete掉buffer的内存。
    
    3. 需要显式调用对象的析构函数来析构该对象所占用的内存

 ## 12.7 队列模拟

 1. 成员初始化列表
    ```cpp
    class Queue
    {
        private:
            const int qsize;
            Agency & belong;        
    }
        // 成员初始化列表只能用于构造函数
    Queue::Queue(int qs) : qsize(qs)        // const类成员、被声明为引用的类成员，必须使用成员初始化列表来初始化
    {
        front = rear = NULL;                // 对于其它类成员，使用成员初始化列表效率更高
        items = 0;
    }
    ```

2. 使用成员初始化列表的构造函数将覆盖相应的类内初始化

# 13 类继承

## 13.1 基类

1. 派生类

    1. 派生类对象存储了基类的数据成员，可以使用基类的方法

    2. 派生类需要自己的构造函数，根据需要添加数据成员和成员函数

    3. 派生类不能直接访问基类的私有成员，必须通过基类方法访问

    4. 创建派生类对象时，首先创建基类对象。
    
    5. 基类对象在进入派生类构造函数前被创建，所以使用成员初始化列表来完成。需要显式调用，否则使用默认构造函数

2. 继承类只能将值传递回相邻的基类，但基类可以继续传给相邻的基类

3. 基类指针（或引用）可以在不进行显式转换的情况下指向派生类对象

4. 基类指针或引用只能用于调用基类方法

5. 可以用派生类对象来初始化基类对象（隐式复制构造函数）；也可以将派生对象赋给基类对象（隐式重载赋值运算符）

## 13.2 继承

1. 共有继承建立```is-a```关系，不建立```has-a / is-implemented-as-a / uses-a```关系

## 13.3 多态共有继承

1. 同一种方法在派生类和基类的行为不同

    1. 可以在派生类重新定义多态共有继承

    2. 使用虚方法

2.  不使用```virtual```，程序根据 **引用或指针的类型** 来选择方法；

    使用时，根据引用或指针 **指向的对象的类型** 来选择方法

    （基类不为虚，使用基类方法）

3. ```virtual```只用于类声明的方法原型中

4. 派生类构造函数使用成员初始化列表初始化基类私有数据

5. 创建指向基类类型的指针数组，数组元素可以指向基类对象，也可以指向派生类对象

6. 为什么使用虚析构函数

    1. 如果析构函数不为虚，则只调用对应于指针类型的析构函数。即即使指针指向派生类对象，也只调用基类析构函数

    2. 如果析构函数是虚函数，则先调用派生类的析构函数，然后调用基类的析构函数。

    3. 如果派生类的析构函数执行某些操作，则基类必须有一个虚析构函数，即使该函数不执行任何操作

## 13.4 静态联编和动态联编

1. 将源代码中的函数调用解释为执行特定的函数代码块被称为函数名联编

2.  静态联编：在编译过程中联编

    动态联编：编译器必须生成能够在程序运行时选择正确的虚方法的代码

3.  向上强制转换：将派生类引用或指针转换为基类引用或指针

    按引用、指针传递参数时，可以完成向上强制转换；按值传递时，只能将派生类对象的基类部分传递给参数

4. 编译器对非虚方法使用静态联编；虚方法使用动态联编

5. 仅将那些预期将被重新定义的方法声明为虚的

6. 编译器处理虚函数

    1. 给每个对象添加一个隐藏成员。隐藏成员保存一个指向虚函数表（数组）的指针。

    2. 如果派生类重新定义了虚函数，则修改虚函数表的地址

7. 虚函数注意事项

    1. 派生类不继承基类的构造函数，因此构造函数不能是虚函数

    2. 使用基类指针指向派生类对象时，析构函数应该是虚函数。当析构函数是虚函数时，可以先调用派生类的析构函数，然后调用基类的析构函数；若不为虚，则只调用基类的析构函数，只释放派生类对象的基类部分

    3. 通常应该给基类提供一个虚析构函数，即使它并不需要

    4. 友元函数不能是虚函数，只有类成员函数才能使虚函数。可以让友元函数调用虚成员函数来解决相关问题

    5. 派生类未重新定义虚函数，将使用基类版本

    6. 重新定义继承的方法不是重载。无论参数列表是否相同，重新定义将隐藏所有的同名基类方法。

    7. 如果重新定义继承的方法，应确保与原来的原型完全相同。如果返回类型是基类引用或指针，可以修改为派生类引用或指针

    8. 如果基类声明被重载，应在派生类中重新定义所有的基类版本，否则会隐藏不同的版本，派生类无法使用

## 13.5 访问控制

1. 派生类的成员可以直接访问基类的保护成员，但不能直接访问基类的私有成员

2. 对外部，保护成员的行为与私有成员类似，但对派生类，保护成员与共有成员类似

3. 类数据成员最好用私有访问控制，通过基类方法访问；对于成员函数，保护访问控制很有用

## 13.6 抽象基类（abstract base class，ABC）

1. C++通过使用纯虚函数提供未实现的函数

    ```cpp
    virtual double Area() const=0;      // a pure virtual function
    ```

2. 当类声明中包含纯虚函数时，不能创建该类的对象，包含纯虚函数的类只能用作基类。但C++允许纯虚函数有定义

## 13.7 继承和动态内存分配

1. 派生类不使用new

    1. 不需要为派生类定义显式析构函数、复制构造函数和赋值运算符

2. 派生类使用new

    1. 需要显式析构函数，清理派生类构造函数申请的内存；基类的析构函数负责清理基类申请的内存

    2. 需要复制构造函数，派生类只能访问派生类的数据，所以需要显式调用基类的复制构造函数处理基类数据。否则会调用默认构造函数

    3. 需要显式赋值运算符，调用基类赋值运算符完成基类数据复制

    总之，派生类的析构函数、复制构造函数、赋值运算符需要使用相应的基类方法来处理基类元素。

## 13.8 类设计回顾

1. 默认构造函数

    1. 要么没有参数、要么所有的参数都有默认值

    2. 确保对象能够被正确地初始化

2. 复制构造函数

    1. 接受所属类对象作为参数

        1. 将新对象初始化为一个同类对象

        2. 按值将对象传递给函数

        3. 按值返回对象

        4. 编译器生成临时对象

    2. 有```new```初始化的成员指针，需要执行深拷贝。则需要定义自己的复制构造函数

3. 赋值运算符

    1. 用于同类对象之间的赋值

    2. 可以显式定义、可以使用转换函数（转换函数可以将类对象转换为其他类型）

4. 传递引用

    1. 节省时间和内存，提高效率

    2. 在继承使用虚函数时，被定义为接受基类引用参数的函数可以接受派生类

5. 返回引用

    1. 如果可以不返回对象，则应返回引用。避免生成临时对象带来的时间成本

    2. 函数内生成的局部对象不应该返回引用

    3. 如果函数返回的是通过引用或指针传递给它的对象，则应按引用返回对象

6. 共有继承：赋值运算符

    1. 将派生类对象赋给基类，赋值运算符只处理基类成员（赋值运算符使用基类引用，基类引用可以指向派生类）

    2. 不能直接将基类对象赋给派生类，除非有转换构造函数（初始化除基类成员外的元素）

7. 如果希望派生类能够重新定义方法，则应在基类中将方法定义为虚的，这样可以启用动态联编

8. 希望派生类友元函数能够使用基类的友元函数，可以通过强制类型转换将派生类引用转换为基类引用或指针，然后使用转换后的指针或引用调用基类友元函数

9. 成员函数属性

    |   函数    |   能否继承    |   成员/友元   |    默认能否生成   |   能否为虚函数   |   是否可以有返回类型    |
    |  -------  |   ---------  | ---------  |  -------  |   ---------  | ---------  |
    | 构造函数 | 否 | 成员 | 能 | 否 | 否 | 
    | 析构函数 | 否 | 成员 | 能 | 能 | 否 |
    | = | 否 | 成员 | 能 | 能 | 能 |
    | & | 能 | 任意 | 能 | 能 | 能 |
    | 转换函数 | 能 | 成员 | 否 | 能 | 否 |
    | () | 能 | 成员 | 否 | 能 | 能 |
    | [] | 能 | 成员 | 否 | 能 | 能 |
    | -> | 能 | 成员 | 否 | 能 | 能 |
    | op= | 能 | 任意 | 否 | 能 | 能 |
    | new | 能 | 静态成员 | 否 | 否 | void* |
    | delete | 能 | 静态成员 | 否 | 否 | void |
    | 其他运算符 | 能 | 任意 | 否 | 能 | 能|
    | 其他成员 | 能 | 成员 | 否 | 能 | 能 |
    | 友元 | 否 | 友元 | 否 | 否 | 能 |

# 14 C++中的代码重用

## 14.1 包含对象成员的类

1. valarray类，具有模板特性，声明对象时，必须指定具体的数据类型
    ```cpp
    valarray<int> q_values;
    valarray<double> weights;
    ```

2. 使用共有继承时，类可以继承接口，可能还有实现；使用组合，类可以获得实现，但不能使用接口

3. 使用explicit防止**单参数构造函数**的隐式转换

4. 如果省略初始化列表，将使用成员对象所属类的默认构造函数

5. 成员 **初始化的顺序** 是它们在类定义中 **被声明的顺序**，如果用一个成员的值作为另一个初始化表达式的一部分时，要注意顺序

## 14.2 私有继承

1. 私有继承，基类的公有成员、保护成员都将成为派生类的私有成员；基类方法不会成为派生对象公有接口的一部分，但可以在派生类的成员函数中使用基类方法

2. **包含** 将对象作为一个 **命名** 的成员对象添加到类中，**私有继承** 将对象作为一个 **未被命名** 的继承对象添加到类中

3. 私有继承类的构造函数使用成员初始化列表语法，但它使用类名而不是成员名来标识基类的构造函数

4. **包含** 使用对象名来调用方法，**私有继承** 使用类名和作用域解析运算符来调用方法

5. 如果要使用基类对象本身，需要使用强制类型转换，创建一个引用

6. 可以通过显式地转换为基类来调用基类的友元函数

7. 在私有继承中，未进行显式类型转换的派生类引用或指针，无法赋值给基类的引用或指针

8. 使用 **包含** 可以声明多个独立的成员对象，而私有继承只能使用一个对象

9. 如果新类需要访问基类的保护成员，或者需要重新定义虚函数，使用私有继承；否则使用包含

10. 保护继承，从派生类再派生出新类时，私有继承不能使用基类的接口；而保护继承可以

11. 让基类的方法在派生类外可用，可以定义一个使用该基类方法的派生类方法；可以将函数调用包装在另一个函数中，用一个using声明，using声明只使用成员名--没有圆括号、函数特征标和返回类型

12. using声明只适用于私有继承，不适用于包含；老式方法，将方法名放在派生类的共有部分

## 14.3 多重继承

1. 必须使用public来限定每一个基类，否则默认private

2. 不同的父类中含有相同的对象时，应使用类型转换来指定对象

3. 虚基类：从多个类（它们的基类相同）派生出的对象只继承一个基类对象，它们共享一个基类对象

    ```cpp
    class Singer : virtual public Worker{};     // 将Worker用作虚基类
    class Waiter : public virtual Worker{};
    ```

4. 如果基类是虚基类，构造函数的自动传递将不起作用；可以显式调用基类构造函数，否则使用默认基类构造函数

5. 对于非虚基类函数，跳过派生类父类显式调用基类的构造函数是非法的

6. 混合使用虚基类和非虚基类时，该类将包含一个虚途径的基类子对象和多个非虚途径的基类子对象

7. ```dominates```派生类中的名称优先于直接或间接祖先类中的相同名称

8. ```strchr("wstq", choice)```该函数返回参数```choice```在字符串中第一次出现的地址，没有则返回```NULL```

## 14.4 类模板

1. 模板提供参数化类型，即能够将类型名作为参数传递给接收方来建立类或函数

2. 模板类，每个函数头都以相同的模板声明打头
    ```cpp
    template <class Type>;
    template <typename Type>;
    ```

3. 内联定义可以省略模板前缀和类限定符

4. 模板不是类和成员函数定义

    1. 模板是C++编译器指令

    2. 模板的具体实现被称为实例化或具体化

    3. 不能将模板成员函数放在独立的实现文件中，将所有模板信息放在一个头文件中

    4. 由于模板不是函数，它们不能单独编译

5. 编译器会按传入参数生成多个独立的类声明和独立的类方法

6. 模板类必须显式地提供所需的类型；常规函数模板可以隐式提供

7. 数组模板和非类型（表达式）参数

    ```template <class T, int n>```

    1. 可以使用模板非类型参数来提供数组的大小
    
    2. 表达式参数可以是**整型、枚举、引用或指针**，不可以是```double```，但可以是```double * pt```

    3. 模板代码不能修改参数的值，也不能使用参数的地址

    4. 模板数组使用表达式参数提供大小时，每种数组大小都将生成自己的模板

8. 可以将用于常规类的技术用于模板类

    1. 类名```Pair<string, int>```，实例化后作为类名  
        ```cpp
        template <class T1, class T2>
        class Pair
        {
            private:
                T1 1;
                ...
        }
        ```

    1. 递归使用模板类```ArrayTp< ArrayTp<int, 5> > twodee;```

    2. 使用多个类型参数```template <class T1, class T2>;```

    3. 可以为类模板的 **类型参数** 提供默认值，但不能为函数模板参数提供默认值；非类型参数都可以提供默认值

9. 模板的具体化

    1. 隐式实例化：编译器在需要对象前，不会生成类的隐式实例化；第二条语句导致编译器生成类定义，并创建对象

    ```cpp
    ArrayTp<double, 100> *pt;
    pt = new ArrayTp<double, 30>;
    ```

    2. 显式实例化```template class ArrayTp<string, 100>;```，使用关键字```template```声明类，虽然没有创建对象，编译器也将生成类声明和方法定义

    3. 显式具体化：可能需要在为特殊类型实例化时，对模板进行修改，使其行为不同
        ```cpp
        template <> class SortedArray<const char char *>
        {
            ...
        }
        ```

    4. 部分具体化
        ```cpp
        template <class T1> class Pair<T1, int> {...}
        ```
        1. 如果有多个模板可以选择，使用具体化程度最高的

        2. 为指针提供特殊版本```template<class T*>```，指针都适用

10. 成员模板：

    1. 模板可用作结构、类或模板类的成
    
    2. 可以在类外定义模板成员，在类外定义时，需要使用```::```指出类成员

11. 将模板用作从参数
    ```cpp
    template <template <typename T> class Thing>
    class Crab
    ```
    1. ```template <typename T> class```是类型，```Thing```是参数

    2. ```Crab<King> legs;```模板参数```King```必须是一个模板类

    3. 可以混合使用模板参数和常规参数
        ```cpp
        template <template <typename T> class Thing, typename U, typename V>
        class Crab
        {
            ...
        }
        ```

12. 模板类和友元

    1. 非模板友元
        ```cpp
        template <class T>
        class HasFriend
        {
            public:
                friend void counts();
                ...
        };
        ```
        上述声明使```counts()```成为模板所有实例化的友元

    2. 约束模板友元：使友元函数本身成为模板
        
        1. 在类定义的前面声明每个模板函数
           
            ```cpp
            template <typename T> void counts();
            template <typename T> void report(T &);
            ```

        2. 在函数中再次将模板声明为友元

            ```cpp
            template <typename TT>
            class HasFriendT
            {
                ...
                friend void counts<TT>();
                friend void report<>(HasFriendT<TT> &);
            }
            ```

    3. 非约束模板友元

        1. 通过在类内部声明模板，可以创建非约束友元函数，即每个函数具体化都是每个类具体化的友元

            ```cpp
            template <typename T>
            class ManyFriend
            {
                ...
                template <typename C, typename D> friend void show2(C &, D &);
            };
            ```

13. 模板别名

    1. 可以用```typedef```

        ```cpp
        typedef std::array<double, 12> arrd;
        typedef std::array<int, 12> arri;
        ```

    2. 使用模板提供一系列别名

        ```cpp
        template<typename T>
        using arrtype = std::array<T, 12>;
        ```

    3. 使用```using```

    ```cpp
    using pc2 = const char *;
    using pa2 = const int *(*)[10];
    ```

# 15 友元、异常和其他

## 15.1 友元

1. 友元类```friend class Remote;```

2. 友元成员函数：可以选择仅让特定的类成员成为另一个类的友元```friend void Remote::set_chan(Tv &t, int c);```

3. 使用前向声明避免循环依赖

4. 可以让类彼此互为对方的友元

5. 可以将函数同时作为两个类的友元

## 15.2 嵌套类

1. 在一个类中声明的另一个类，通常为了帮助实现该类，并避免名称冲突

2. 可以通过使用两次作用域运算符来完成访问

3. 对嵌套类的访问权的控制规则和对常规类的相同

## 15.3 异常

1. 调用```abort();```向标准错误流发送信息，然后终止程序，不返回main；是否刷新文件缓冲区取决于实现

2. 返回错误码：使用函数的返回值来指出问题；可以用指针或者引用，对内置类型，优先使用指针

3. ```throw```语句实际上是跳转，```throw```关键字表示引发异常，其后的值指出了异常的特征

4. ```catch```用于捕获异常，其后是位于括号中的类型声明，指出异常处理程序要响应的异常类型

5. ```try```块标识其中特定的异常可能被激活的代码块，它后面跟一个或多个```catch```块

6. 执行```throw```语句类似于执行返回语句，它将终止函数的执行，但不将控制权返回给调用程序，而是导致程序沿函数调用序列后退，直到找到包含```try```块的函数

7. 将对象用作异常类型：可以使用不同的异常类型来区分不同的函数在不同情况下引发的异常，对象可以携带信息

8. 栈解退：函数出现异常而终止时，程序将释放栈中的内存，但不会在释放栈的第一个返回地址后停止，而是继续释放栈，直到找到一个位于```try```中的返回地址。随后，控制权将转到块尾的异常处理程序，而不是函数调用后面的第一条语句。

9. 其他异常特性

    1. 引发异常时，编译器总是创建一个指向异常对象的临时拷贝，而不是本身

    2. 为何使用引用？基类引用可以执行派生类对象。有继承关系的异常类型，可以只用一个基类引用来匹配。

    3. ```catch```块的排列顺序应该与派生顺序相反

    4. ```catch(...)```可以捕获任何异常

10. ```exception```类

    1. ```exception```基类有一个```what();```虚拟成员函数，它返回一个字符串，该字符串的特征随实现而异

    2. ```stdexcepy```异常类

        1. ```logic_error: domain_error, invalid_argument, length_error, out_of_bounds;```

        2. ```runtime_error: range_error, overflow_error, underflow_error;```

    3. ```bad_alloc```异常处理```new```导致的内存分配问题（以前返回空指针）

    4. 内存失败返回空指针
        ```cpp
        struct Big{double stuff[20000];};
        Big * pb;
        pb = new (std::nothrow) Big[10000];
        if (pb == 0){
            ....
            exit(EXIT_FAILURE);
        }
        ```

11. 异常出错

    1. 意外异常：在带异常规范的函数中引发的，不能与规范列表匹配的某种异常

        1. 调用```unexpected();```，然后调用```terminate();```，然后调用```abort();```，可使用```set_unexpected();```修改

        2. ```set_unexpected(unexpected_handler);```

            1. ```unexpected_handler```可以通过调用```abort();```结束程序

            2. ```unexpected_handler```可以引发新的异常，新异常可被```std::bad_exception```替代

    2. 未捕获异常：不是在函数中引发的，或函数没有异常规范

        1. 程序将首先调用函数```terminate();```，然后默认调用```abort();```，可使用```set_terminate();```修改

12. 注意事项

    1. 异常可能导致```new```分配的内存未被正确释放，栈解退只可以清理掉指向内存的指针，会导致内存泄漏

    2. 可以在```catch```块中```delete```释放内存

## 15.4 RTTI：运行阶段类型识别

1. ```dynamic_cast```运算符，使用一个指向基类的指针来生成一个指向派生类的指针
    ```cpp
    Grand -> Superb -> Magnigicent;
    Grand * pg;
    Superb * ps;

    *pg = new Grand;
    ps = dynamic_cast<Superb *>(pg);
    ```

2. ```dynamic_cast```可以用于引用，但没有与空指针对应的引用值，所以无法使用特殊的引用值来指示失败；会引发```bad_cast```异常

3. ```typeid```返回一个对```type_info```对象的引用

4. ```type_info```类重载了```==```和```!=```运算符，可以用来对类型进行比较```typeid(Magnificent) == typeid(*pg)```

5. ```type_info```类包含一个```name()```成员，该函数返回一个字符串

6. 如果在```if else```语句系列中使用了```typeid```，则应考虑是否应该使用虚函数和```dynamic_cast```

## 15.5 类型转换运算符

1. ```const_cast```将常量转换为可修改量

2. ```static_cast <type-name> expression```当```type-name```和```expression```的类型可以隐式转换的时候，转换合法

3. ```reinterpret_cast```可以用于危险的类型转换，不能将函数指针转换为数据指针

4. ```static_cast```与```dynamic_cast```：前者允许向上转换和向下转换，还允许枚举类型和整型之间以及数值类型之间的转换；后者只允许沿类层次结构向上转换

# 16 string类和标准模板库

## 16.1 string类

1. 7种构造函数

2. C++11新增两种，```string(string && str) no expect```和```string(initializer_list<char>il)```

3.  输入方式
    
    1. C-风格字符串

        ```cpp
        char info[100];
        cin >> info;                    // read a word
        cin.getline(info, 100);         // read a line, discard '\n'
        cin.get(info, 100);             // read a line, discard '\n'

        cin.getline(info, 100, ':');    // read up to :, discard ':'
        ```

    2. string对象
        
        ```cpp
        string stuff;
        cin >> stuff;
        getline(cin, stuff);            // read a line, discard '\n'
        getline(stuff, ':');            // read up to :, discard ':'
        ```
    
    3. 两者区别：string的getline()将自动调整目标string对象的大小，使之刚好能够存储输入的字符

4. String类重载了6个关系运算符，每个运算符都以3种方式重载，使得能够与C-风格字符串比较

5. ```string::npos```string对象的最大允许长度

6. 搜索子字符串

    ```cpp
    find(const string &str, size_type pos = 0)const;            // 返回子字符串首次出现时其首字符的索引
    rfind();                                                    // 最后一次出现的位置
    s.find_first_of("abc");                                     // 查找参数中任何字符首次出现的位置
    s.find_first_not_of();
    s.find_last_of();
    s.find_last_not_of();
    ```

7. 字符串相关函数

    ```cpp
    int atoi(const char * nptr);                    // 将整数字符串转换成int类型的整数

    char strtok(char str, const char * delim);      // 使用delim作为分隔符分割str，返回被分解的第一个子字符串或空指针，第一个参数传入NULL，则继续分割原来的字符串

    capacity();                                     // 返回当前分配给字符串的内存块的大小
    reserve(len);                                   // 请求内存块的最小长度，实际长度不一定等于len

    c_str();                                        // 返回一个指向C-风格字符串的指针

    ```

## 16.2 智能指针模板类

1. 解决内存泄漏问题

2. 三个智能指针模板```(auto_ptr, unique_ptr, shated_ptr)```都定义了类似指针的 **对象** ，可以将new获得的地址赋给这种对象

3. 创建智能指针对象，需要包含```<memory>```

4. 所有智能指针都有一个```explicit```构造函数，该构造函数将指针作为参数

5. 两个指针指向同一对象时，可能导致删除一个对象两次的现象

    1. 定义赋值运算符，执行深拷贝

    2. 建立所有权概念，对于特定对象，只能有一个智能指针可拥有它```auto_ptr, unique_ptr```，后者更严格

    3. 创建智能更高的指针，使用引用计数```shared_ptr```

    4. 让出所有权会导致留下悬挂指针

    5. ```std::move()```能够将一个```unique_ptr```赋给另一个

    6. 需要使用多个指向同一对象的指针，选择shared_ptr，不需要时使用uniqu_ptr



# 17 STL

1. 容器：用来管理某一类对象的集合，如```deque\list\vector\map```等

2. 算法：作用于容器，提供各种操作方式，如初始化、排序、搜索、转换等

3. 迭代器：用于遍历对象元素的集合

4. STL将数据和操作分离，数据由容器进行管理，操作由算法进行

5. vector

    1. 一种序列式容器，相当于可拓展的数组
    
    2. 拥有一段连续的内存空间，随机访问快，在中间插入和删除慢，但在末尾插入和删除快

    3. 适用于对象简单，变化小，频繁随机访问的场景

    4. 方法

        ```cpp
        push_back();            // 在向量的末尾插入值
        size();                 // 显示向量的大小，vector容器真实占用的大小
        capacity();             // 是指预分配的空间

        begin();                // 返回一个指向向量开头的迭代器
        end();                  // 返回一个指向向量末尾的迭代器

        []; 
        .at();                  // 支持随机访问
        ```

6. deque

    1. 由一段一段的定量连续空间构成，一旦要在前段或尾端增加新空间，便配置一段定量连续空间

    2. 修改头尾方便，中间插入删除比较费时，必须移动其他元素

    3. 适用于既要频繁随机读取，又要关心两端插入和删除的场景

7. list

    1. 由双向链表实现，元素存放在堆中，每个元素放在一块内存中，空间不连续，通过指针进行数据访问

    2. 不预留空间，每分配或删除一个元素都分配、释放内存

    3. 不支持随机访问

    4. 适用于经常插入删除但不经常随机访问的场景

8. set

    1. 由红黑树实现，内部元素自动排序，无重复值

    2. 插入删除效率比其他序列容器高，因为不需要做内存拷贝和移动

    3. 每次插入值时都需要调整红黑树，影响效率

    4. 适用于经常查找某元素是否在集合中且需要排序的场景

    5. 当集合中的元素为结构体时，必须重载运算符 '<' 

    6.  ```cpp
        char str[100] = {0};
        set<char> s(str, str+strlen(str));      // string -> set
        ```

9. map

    1. 由红黑树实现，元素都是键值对，键作为排序的基础，不允许重复

    2. 用于一对一映射的情况

    3. 根据key值快速查找记录，复杂度O(logN)，增删节点对迭代器影响小

    4. 对迭代器来说，可以修改实值，不能修改key

10. stack: LIFO

11. queue: FIFO

12. priority_queue: 优先队列

13. 顺序容器共有函数

    ```cpp
    begin();
    end();
    rbegin();               // 返回逆向迭代器指针
    rend();
    clear();                // 删除所有元素
    erase(it);              // 删除指针it处的元素
    ```

14. STL算法

    ```cpp
    #include <algorithm>
    vector<int> v;

    sort(v.begin(), v.end(), greater<int>);         // STL遍历算法
    for_each(v.begin(), v.end(), print);            // STL遍历输出算法
    reverse(v.begin(), v.end());
    ```




# 17 STL

1. 容器：用来管理某一类对象的集合，如```deque\list\vector\map```等

2. 算法：作用于容器，提供各种操作方式，如初始化、排序、搜索、转换等

3. 迭代器：用于遍历对象元素的集合

4. STL将数据和操作分离，数据由容器进行管理，操作由算法进行

5. vector

    1. 一种序列式容器，相当于可拓展的数组
    
    2. 拥有一段连续的内存空间，随机访问快，在中间插入和删除慢，但在末尾插入和删除快

    3. 适用于对象简单，变化小，频繁随机访问的场景

    4. 方法

        ```cpp
        push_back();            //在向量的末尾插入值
        size();                 //显示向量的大小，vector容器真实占用的大小
        capacity();             //是指预分配的空间

        begin();                //返回一个指向向量开头的迭代器
        end();                  //返回一个指向向量末尾的迭代器

        []; 
        .at();                  //支持随机访问
        ```

6. deque

    1. 由一段一段的定量连续空间构成，一旦要在前段或尾端增加新空间，便配置一段定量连续空间

    2. 修改头尾方便，中间插入删除比较费时，必须移动其他元素

    3. 适用于既要频繁随机读取，又要关心两端插入和删除的场景

7. list

    1. 由双向链表实现，元素存放在堆中，每个元素放在一块内存中，空间不连续，通过指针进行数据访问

    2. 不预留空间，每分配或删除一个元素都分配、释放内存

    3. 不支持随机访问

    4. 适用于经常插入删除但不经常随机访问的场景

8. set

    1. 由红黑树实现，内部元素自动排序，无重复值

    2. 插入删除效率比其他序列容器高，因为不需要做内存拷贝和移动

    3. 每次插入值时都需要调整红黑树，影响效率

    4. 适用于经常查找某元素是否在集合中且需要排序的场景

    5. 当集合中的元素为结构体时，必须重载运算符 '<' 

    6.  ```cpp
        char str[100] = {0};
        set<char> s(str, str+strlen(str));      //string -> set
        ```

9. map

    1. 由红黑树实现，元素都是键值对，键作为排序的基础，不允许重复

    2. 用于一对一映射的情况

    3. 根据key值快速查找记录，复杂度O(logN)，增删节点对迭代器影响小

    4. 对迭代器来说，可以修改实值，不能修改key

10. stack: LIFO

11. queue: FIFO

12. priority_queue: 优先队列

13. 顺序容器共有函数

    ```cpp
    begin();
    end();
    rbegin();               //返回逆向迭代器指针
    rend();
    clear();                //删除所有元素
    erase(it);              //删除指针it处的元素
    ```

14. STL算法

    ```cpp
    #include <algorithm>
    vector<int> v;

    sort(v.begin(), v.end(), greater<int>);         //STL遍历算法
    for_each(v.begin(), v.end(), print);            //STL遍历输出算法
    reverse(v.begin(), v.end());
    ```

# 字符串相关函数

1.  ```cpp
    int atoi(const char * nptr);                    //将整数字符串转换成int类型的整数

    char strtok(char str, const char * delim);      //使用delim作为分隔符分割str，返回被分解的第一个子字符串或空指针，第一个参数传入NULL，则继续分割原来的字符串



    ```


































