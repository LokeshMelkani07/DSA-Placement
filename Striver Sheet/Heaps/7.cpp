#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Merge K Sorted Arrays
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
Sample Input 1:

1
2
3
3 5 9
4
1 2 3 8

Sample Output 1:

1 2 3 3 5 8 9

Explanation of Sample Input 1:

After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].

Sample Input 2:

1
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 2:

0 1 2 5 6 9 45 78 90 100 234

Explanation of Sample Input 2 :

After merging the given arrays/lists [1, 5, 9], [45, 90], [2, 6, 78, 100, 234] and [0], the output sorted array will be [0, 1, 2, 5, 6, 9, 45, 78, 90, 100, 234].
*/

class node
{
public:
    int data;
    int i;
    int j;
    // Constructor
    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class comparator
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Brute force
    // We will make ans array -> O(1)
    // We will traverse kArrays and put all elements in the ans array -> O(n*k)
    // We will sort that answer array -> n*k log(n*k)

    // Optimised approach
    // We will make use of the information that all data is sorted in each array
    // We will use a min_heap and store first element of each array in it
    // We will take out the top element from heap and store it in our ans array
    // We will put the next element of the array whose first element we stored in the heap now if it exists so we need to store that next element also
    // We will do this till heap.size()>1
    // We will make heap of <node*> type where node contains data,i,j which is used to tell data and position of  element of a certain element in array
    // We cannot use greater<int> while creating min_heap now so we need to write our custom comparator
    // TC: O(n*k logk)
    // SC: O(k)

    // creating a min_heap
    priority_queue<node *, vector<node *>, comparator> pq;

    // store first element of all arrays in heap
    for (int i = 0; i < k; i++)
    {
        node *first = new node(kArrays[i][0], i, 0);
        pq.push(first);
    }

    // get the top element of heap and store in the ans array
    vector<int> ans;
    while (pq.size() > 0)
    {
        node *temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();

        int rowValue = temp->i;
        int colValue = temp->j;

        // check if next value for a given row exits or not for that we check if col < row size
        if (colValue + 1 < kArrays[rowValue].size())
        {
            node *nextElement = new node(kArrays[rowValue][colValue + 1], rowValue, colValue + 1);
            pq.push(nextElement);
        }
    }

    return ans;
}

int main()
{
    return 0;
}
