1. STL六大部件：容器（模板类）、分配器（模板类）、算法（模板函数）、迭代器（模板类）、适配器（模板类）、仿函数（模板类）

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

3. deque

    1. 分段连续buffer组成

    2. iterator: cur + first + last + node

    3. insert时移动需要搬移数据较少的一边

4. stack、queue其实是adapter，不提供iterator，会破坏FIFO、FILO

5. 模板sort只能用于可以随机访问的容器，所以list不能使用模板sort

6. list:双向链表实现

7. iterator必须提供5种associated types
    
    1. iterator_types
    
    2. value_type
    
    3. pointer
    
    4. reference
    
    5. difference_type

8. Traits:用来区分class iterator和non-class iterator

9. vector/array直接用*ptr作iterator

10. 算法和容器利用迭代器进行关联

11. iterator_category:random_access_iterator/bidirectioinal_iterator/forward_iterator/output_iterator/input_iterator

12. 可以重载()作仿函数

13. 仿函数：是一个对象，像一个函数；有算术类、逻辑运算类、相对关系类三类

14. 仿函数可适配的条件：继承自binary_function（两个操作数）/unary_function（一个操作数）

15. 

