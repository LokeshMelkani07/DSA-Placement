#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Implement LRU Cache

Problem Statement: “Design a data structure that follows the constraints of Least Recently Used (LRU) cache”.

Implement the LRUCache class:

    LRUCache(int capacity) we need to initialize the LRU cache with positive size capacity.
    int get(int key) returns the value of the key if the key exists, otherwise return -1.
    Void put(int key,int value), Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.if the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Example:

Input:
 ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
       [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

Output:
 [null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation:

LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

class LRUCache
{
    // we will take a Double Linkedlist having head and tail
    // head->prev = NULL, head->next = tail and tail->prev = head and tail->next = NULL initially
    // We will store the element with key-value next to head everytime we insert
    // We will use a hashmap to store key-value but in value we will store the address of that node in DLL having that key
    // when we do get(4) if that exist we check in hashmap, go to its address in DLL and give its value, if it does not exist we give -1
    // Now it becomes recently used so delete it from DLL from current position and store it next to head, store its new address in the map
    // if size of hashmap is == capacity so to insert new value we need to delete the least recently used node from DLL
    // LRU will be the one close to tail in DLL so delete it from DLL and map and store new one next to head and update in the map
    // For clear images: https://takeuforward.org/data-structure/implement-lru-cache/
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add(node *newnode)
    {
        // To add a node in DLL
        node *temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }

    void del(node *delnode)
    {
        // To delete a node in DLL
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *res = m[key];
            int result = res->val;
            del(res);
            add(res);
            m[key] = head->next;
            return result;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *nod = m[key];
            m.erase(key);
            del(nod);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            del(tail->prev);
        }
        add(new node(key, value));
        m[key] = head->next;
    }
};

int main()
{
    return 0;
}