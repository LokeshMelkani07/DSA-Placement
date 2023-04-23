#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

// C++ STL in one video
// Containers : pre-built data structures
// Algorithms : a set of rules that must be followed when solving a particular problem
// When we need a data structure for a particular part of a program we need not to implement that data structure from scratch, we can use STL

// Print array
void print_array(array<int,4> arr,int n)
{
  for(int i = 0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}

// Print vector
void print_vector(vector<int> arr)
{
  for(int i = 0;i<arr.size();i++)
  {
    cout<<arr[i]<<" ";
  }
}


int main()
{
    // Array in STL : It is static so we do not use it much as we need something dynamic so we use vector
    array<int,4> a = {1,2,3,4};
    print_array(a,a.size());
    cout<<endl;
    // These below operations are implemented in o(1)
    cout<<a.at(2)<<endl;;
    cout<<a.empty()<<endl;
    cout<<"First element "<<a.front()<<endl;
    cout<<"Last element "<<a.back()<<endl;
    // Vector
    // Dynamic array, same as array but its dynamic, it doubles its size automatically
    // Capacity means how much memory is allocated to the vector
    // Size means how many elements are inside the vector
    vector<int> arr1{5,6,7,8,9};
    print_vector(arr1);
    cout<<endl;
    arr1.push_back(10);
    print_vector(arr1);
    cout<<endl;
    cout<<arr1.at(4)<<endl;
    cout<<arr1.front()<<endl;
    cout<<arr1.back()<<endl;
    arr1.pop_back();
    print_vector(arr1);
    cout<<endl;
    cout<<"before clear capacity "<<arr1.capacity()<<endl;
    cout<<"before clear size "<<arr1.size()<<endl;
    arr1.clear();
    // After clear only size becomes 0 for the vector, its capacity remains the same
    cout<<"after clear capacity "<<arr1.capacity()<<endl;
    cout<<"after clear size "<<arr1.size()<<endl;
    arr1.push_back(10);
    arr1.push_back(11);
    arr1.push_back(12);
    arr1.push_back(13);
    for(auto i: arr1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    // Declare a vector of size 5 and initialise it with value 1
    vector<int> arr2(5,1);
    for(auto i: arr2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    // Copy a vector inside another vector
    vector<int> arr3(arr2);
    print_vector(arr3);
    cout<<endl;

    // Dequeue
    // At beginning and ending both, insertion and deletion is possible
    // It does not implement through contigious memory location like array or vector
    // It is also dynamic like vector and array
    // random access also possible using .at()
    deque<int> d;
    d.push_back(10);
    d.push_front(11);
    for(auto i: d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    d.pop_back();
    d.pop_front();
    cout<<d.empty()<<endl;
    d.push_front(12);
    d.push_back(15);
    cout<<"First element "<<d.at(0)<<endl;
    cout<<"First element "<<d.at(1)<<endl;
    cout<<d.empty()<<endl;
    // this will erase first element from the beginning
    d.erase(d.begin(),d.begin()+1);
    for(auto i: d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    // List
    // It is implemented using doubly linkedlist
    // Direct access is not possible here using .at()
    // we need to traverse till that element
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    for(auto i: l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    // Erase takes O(n) here because we need to go to that element to erase it.
    l.erase(l.begin());
    for(auto i: l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"size of list is "<<l.size()<<endl;
    list<int> l1(5,100);  // 100, 100, 100, 100, 100
    for(auto it: l1)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    // Stack
    // Stack of plates in a wedding
    // It follows the principle of LIFO ( Last In First Out)
    // Jo Last mai jayega, Woh Sabse Pehele Bahaar ayega
    stack<int> st;
    st.push(10);
    st.push(11);
    st.push(12);
    cout<<st.top()<<endl; // 12
    st.pop();
    cout<<st.top()<<endl; // 11
    cout<<st.empty()<<endl;

    // Queue
    // Queue means a line
    // It follows principle of First In First Out (FIFO)
    queue<string> q;
    q.push("Lokesh");
    q.push("Melkani");
    q.push("Mohit");
    cout<<q.front()<<endl;  // Lokesh
    cout<<q.size()<<endl;  // 3
    q.pop();
    cout<<q.front()<<endl;  // Melkani
    cout<<q.size()<<endl;  // 2

    // Priority Queue
    // Min heap and Max heap
    // Comes under header file #include<queue>
    // Max heap: First element is greatest
    // By default Max heap is formed
    // Min Heap: Gives the minimum element always
    priority_queue<int> max_heap; // by default its the max heap
    priority_queue<int,vector<int>,greater<int>> min_heap;  // This is syntax to create min heap
    max_heap.push(1);
    max_heap.push(16);
    max_heap.push(13);
    max_heap.push(12);
    max_heap.push(18);
    cout<<"Size "<<max_heap.size()<<endl;
    int n = max_heap.size();
    for(int i = 0;i<n;i++)
    {
        // maximum element comes at the top
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }
    cout<<endl;
    min_heap.push(100);
    min_heap.push(10);
    min_heap.push(1);
    min_heap.push(300);
    min_heap.push(156);
    min_heap.push(30);
    cout<<"Size of min heap "<<min_heap.size()<<endl;
    int n1 = min_heap.size();
    for(int i = 0;i<n1;i++)
    {
        // minimum element comes at the top
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    cout<<endl;
    cout<<min_heap.empty()<<endl;
    cout<<max_heap.empty()<<endl;

    // Set
    // Set always stores unique elements
    // If we store 5 times 5 inside a set, it will store it only for one time
    // It uses BST behind the scenes
    // It sorts the element
    // unordered_set do not have sorted element but its more efficient in TC as compared to set
    // insert(), find(), erase(), count() has TC: O(logn)
    // empty(), size() has O(1)

    set<int> st1;
    st1.insert(100);
    st1.insert(10);
    st1.insert(300);
    st1.insert(300);
    st1.insert(180);
    st1.insert(187);
    st1.insert(187);
    st1.insert(123);
    st1.insert(45);
    st1.insert(50);
    st1.insert(50);
    // insert takes O(logn)
    for(auto it: st1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    st1.erase(st1.begin());
    set<int>::iterator it = st1.begin();
    it++;
    st1.erase(it);
    for(auto it: st1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Present or not "<<st1.count(50)<<endl;
    // find() gives you iterator of the element if element is found
    auto it1 = st1.find(300);
    cout<<"Value is "<<*it1<<endl;
    for(auto it2=st1.begin();it2!=st1.end();it2++)
    {
        cout<<*it2<<" ";
    }
    cout<<endl;


    // Map
    // Stores data in key-value pairs
    // Key will be unique
    // Values can be duplicates also
    // It also gives elements in sorted order of keys
    // unordered-map does not have any sorted order
    // map is implemented using red-black tress its TC: O(logn)
    // unordered_map is implemented using hash table its TC on seraching is O(1)
    map<int,string> mpp;
    mpp[1] = "Lokesh";
    mpp[2] = "Tushar";
    mpp[3] = "Mohit";
    mpp[4] = "Rohit";
    for(auto i: mpp)
    {
        cout<<i.first<<" "<<i.second<<" "<<endl;
    }
    mpp.insert({5,"Bheem"});
    for(auto i: mpp)
    {
        cout<<i.first<<" "<<i.second<<" "<<endl;
    }
    cout<<mpp.count(5)<<endl;
    cout<<mpp.count(6)<<endl;
    mpp.erase(5);  // only give key
    for(auto i: mpp)
    {
        cout<<i.first<<" "<<i.second<<" "<<endl;
    }
    auto it5 = mpp.find(3);
    for(auto it = it5; it != mpp.end(); it++)
    {
        cout<<(*it).first<<" ";
    }
    cout<<endl;
    // The multimap and multiset differ from the map and set containers in that they may have some elements with the same keys while the keys in the map and set containers must be unique; but they are all ordered containers that keep their elements sorted by the key values.

    // Algorithms
    // Binary search
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(9);
    v1.push_back(1);
    v1.push_back(10);
    v1.push_back(13);
    sort(v1.begin(),v1.end());
    cout<<"Finding 13 using Binary search is "<<binary_search(v1.begin(),v1.end(),13)<<endl;  // 1
    cout<<"Finding 6 using Binary search is "<<binary_search(v1.begin(),v1.end(),6)<<endl;  // 0
    // Get iterator of the element present
    // Get lower bound
    cout<<"Lower bound of 6 is "<<*lower_bound(v1.begin(),v1.end(),6)<<endl;
    cout<<"Upper bound of 6 is "<<*upper_bound(v1.begin(),v1.end(),6)<<endl;
    int a1 = 4;
    int b1 = 5;
    cout<<" Max of "<<max(a1,b1)<<endl;
    cout<<" Min of "<<min(a1,b1)<<endl;
    vector<int> v2 = { 1, 45, 54, 71, 76, 12 };

    // Print the vector
    cout << "Vector: ";
    for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";
    cout << endl;

    // Find the min element
    cout << "\nMin Element = "
    << *min_element(v2.begin(), v2.end());

    // Find the max element
    cout << "\nMax Element = "
    << *max_element(v2.begin(), v2.end());
    cout<<endl;
    swap(a1,b1);
    cout<<"Swapped a1 is "<<a1<<endl;
    // Reverse a string
    string str = "Lokesh";
    reverse(str.begin(),str.end());
    for(auto it: str)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    // Rotate a vector
    rotate(v1.begin(),v1.begin()+1,v1.end());
    for(auto it: v1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    // Sort the vector
    // Based on Heap sort, Quick Sort and Insertion Sort
    sort(v1.begin(),v1.end());
    return 0;

}