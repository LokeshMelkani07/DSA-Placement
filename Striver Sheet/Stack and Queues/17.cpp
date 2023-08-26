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
LFU Cache
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
*/

// Least Frequenctly Used means the one with the least frequency of occurence or use

// We will use two maps, one map will store frequency -> DLL
// Other map will store key -> address of that node
// we will make a freq count variable which will store Least Frequenct Used frequency
// In DLL we will maintain a LRU order so that is LFY tie then we remove the LRU element and add new element
// When we get() any key, its frequency increases so we delete it from prev place and make new DLL in the map for that key

struct Node
{
    int key, value, cnt;
    // cnt is used to maintain the frequency of a node
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1; // frequency is initialised with 1
    }
};
struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache
{
    unordered_map<int, Node *> keyNode;
    unordered_map<int, List *> freqListMap; // used to store frequency_number  and list corresponding to it
    int maxSizeCache;
    int minFreq; // minfreq store the least frequency
    int curSize; // stores the current size of the LFUcache
public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0; // initialised the minimum frequency with 0
        curSize = 0; // initialised the current size with 0
    }
    void updateFreqListMap(Node *node)
    { // To update a node in the list
        keyNode.erase(node->key);
        // remove that node from its frequency list
        freqListMap[node->cnt]->removeNode(node);
        // if freuency of that node was minfreq and now size of that list is 0 so we increase that minimum frequency minfreq
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }
        // now we create a new list of that previous minfreq+1
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        { // if a list of prev minfreq + 1 exist already in the freqlist map
            // then equate it with our newly created list
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;                              // increase frequency of that node
        nextHigherFreqList->addFront(node);          // add that node in our new list
        freqListMap[node->cnt] = nextHigherFreqList; // map our new freqlist in the freqlist map
        keyNode[node->key] = node;                   // put new address of that key in  keynode map
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        { // if key is found
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node); // update the frequency of that node in the frequency_list
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
        { // max size of cache is 0 means cannot put anything so return
            return;
        }
        if (keyNode.find(key) != keyNode.end())
        { // if element is found
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == maxSizeCache)
            { // cursize == maxsize means now we have to remove the LFU or if its a tie then remove that LRU
                // so now we access the least frequently used list
                List *list = freqListMap[minFreq];
                // we erase that LRU using tail from our keynode map
                keyNode.erase(list->tail->prev->key);
                // remove that node from that list of minimum frequency
                freqListMap[minFreq]->removeNode(list->tail->prev);
                // size of map decreases now
                curSize--;
            }
            curSize++;
            // new value has to be added who is not there previously so now our minfreq again become 1
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main()
{
    return 0;
}