1. STL六大部件：容器、分配器、算法、迭代器、适配器、仿函数

2. 结构与分类

    1. 序列式容器

        ||||
        |:---:|:---:|:---:|
        |Array| [----------------] |元素数量固定|
        |Vector|[----------------|右边进出|
        |Deque|----------------|两端进出|
        |List|<=><=><=>|双向链表|
        |Forward-List|->->->->->|单向链表|
   

    2. 关联式容器：红黑树实现

        |||
        |:---:|:---:|
        |Set|key|
        |Multiset||
        |Map|key+value|
        |Multimap||

    3. 无序（不定序）容器:HashTable(Separate Chainging)实现

        |||
        |:---:|:---:|
        |Unordered-Set|HashTable(Separate Chainging)|
        |Unordered-Multiset||
        |Unordered-Map||
        |Unordered-Multimap||

3. deque:分段连续buffer组成

4. stack、queue其实是adapter，不提供iterator，会破坏FIFO、FILO

5. 模板sort只能用于可以随机访问的容器，所以list不能使用模板sort

# list

1. 双向链表实现

2. 



