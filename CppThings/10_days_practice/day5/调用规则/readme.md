# 构造函数和析构函数的构造规则

1. 派生类不定义构造函数

    1. 基类没有定义任何构造函数

    2. 基类构造函数具有缺省参数

    3. 基类有无参构造函数

2. 派生类必须定义构造函数

    1. 基类或成员对象只含有带参数的构造函数

3. 派生类的构造函数只负责直接基类的初始化

    1. 当直接基类只有带参数的构造函数时，必须调用直接基类的构造函数，实现基类子对象的初始化

    2. 例外：当派生类存在虚基类时，所有虚基类都由最后的派生类负责初始化
