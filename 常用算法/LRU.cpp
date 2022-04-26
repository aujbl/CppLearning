#include <bits/stdc++.h>

using namespace std;

struct DLinkedNode
{
    int key, val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0), val(0), prev(nullptr), next(nullptr){};
    DLinkedNode(int _key, int _val):key(_key), val(_val), prev(nullptr), next(nullptr) {};
};

class LRUCache{
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity):capacity(_capacity), size(0){
        // fake head, tail
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    // 更新key到第一位
    void addTohead(DLinkedNode* node){
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    // 删除指定元素
    void removeNode(DLinkedNode* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // 再次访问已存在元素
    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addTohead(node);
    }

    // 添加新元素，需要删除最近最少使用元素,
    void removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        cache.erase(node->key);
        delete node;
        // return node;
    }

    int get(int key){
        if (!cache.count(key)){
            return -1;
        }
        moveToHead(cache[key]);
        return cache[key]->val;
    } 

    void put(int key, int val){
        if (!cache.count(key)){
            // 不存在的key，需要添加到哈希表，添加到头部
            DLinkedNode* node = new DLinkedNode(key, val);
            cache[key] = node;
            addTohead(node);

            // 注意是否超容量
            size++;
            if (size > capacity){
                removeTail();
                size--;
            }
        }else{
            // 注意更新值
            moveToHead(cache[key]);
            cache[key]->val = val;
        }
    }
};
