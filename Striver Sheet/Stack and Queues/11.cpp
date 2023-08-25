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
The Celebrity Problem
There are ‘N’ people at a party. Each person has been assigned a unique id between 0 to 'N' - 1(both inclusive).  A celebrity is a person who is known to everyone but does not know anyone at the party.
Given a helper function ‘knows(A, B)’, It will returns "true" if the person having id ‘A’ know the person having id ‘B’ in the party, "false" otherwise. Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the party then print -1.
Note:
1. The helper function ‘knows’ is already implemented for you.
2. ‘knows(A, B)’ returns "false", if A doesn't know B.
3. You should not implement helper function ‘knows’, or speculate about its implementation.
4. You should minimize the number of calls to function ‘knows(A, B)’.
5. There are at least 2 people at the party.
6. At most one celebrity will exist.

Sample Input 1:

1
2
Call function ‘knows(0, 1)’ // returns false
Call function ‘knows(1, 0)’ // returns true

Sample Output 1:

0

Explanation For Sample Input 1:

In the first test case, there are 2 people at the party. When we call function knows(0,1), it returns false. That means the person having id ‘0’ does not know a person having id ‘1'. Similarly, the person having id ‘1’  knows a person having id ‘0’ as knows(1,0) returns true. Thus a person having id ‘0’ is a celebrity because he is known to everyone at the party but doesn't know anyone.

Sample Input 2:

1
2
Call ‘knows(0, 1)’ // returns true
Call ‘knows(1, 0)’ // returns true
2
Call ‘knows(0, 1)’ // returns false
Call ‘knows(1, 0)’ // returns false

Sample Output 2:

-1
-1

Explanation For Sample Input 2:

In first test case, there are 2 people at the party. The person having id ‘0’  knows a person having id ‘1’. The person having id ‘1’  knows a person having id ‘0’. Thus there is no celebrity at the party, because both know each other.
In second test case, there are 2 people at the party. The person having id ‘0’ does not knows a person having id ‘1’. The person having id ‘1’  also does not knows a person having id ‘0’. Thus there is no celebrity at the party, because both does not know each other.
*/

/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    // Brute force
    // For each element, we will check
    // For a celebrity, its row = 0 as it knows nobody
    // Its col = 1 except diagnol because everybody knows him, except diagnol
    // diagnol would means ki vo khudko jaanta h ya nhi, which is nonsense
    // if condition satisfies, we return it as celebrity
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        // Here, for every i, we are taking, j which will traverse all element and check one by one if condition satisfies
        while (j < n)
        {
            if (j == i)
            {
                // Diagnol element
                j++;
                continue;
            }

            // Condition check
            /*
                if (knows(j, i) == true && knows(i, j) == false)
                {
                    j++;
                }
            */

            else
            {
                // if coniditon fails, break
                break;
            }
        }

        if (j == n)
        {
            // means all elements traversed completely with condition satisfied so i is a celebrity
            return i;
        }
    }
    return -1;
}

/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{

    // Using a Stack
    // TC: O(n), SC: O(n)
    // Push all elements in the stack
    // Pop out elements from stack, till stack size == 1
    // Check two popped out elements, if they know each other or not
    // if A knows B means A cannot be celebrity but B can be potential celebrity so push B
    // if B knows A means B cannot be celebrity but A can be potential celebrity so push A
    // Now check that whether the left over element in the stack i.e stack top is actually a celebrity or not
    // For that just compare all elements if they know him except diagnol element
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i); // firstly push all
    }

    while (!st.empty() && st.size() != 1)
    {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();

        /*

        if (!knows(A, B))
            st.push(A); // A don't know B so A can be a potential celebrity

        else if (!knows(B, A))
            st.push(B); // B don't know A so B can be a potential celebrity

        */
    }

    if (st.empty())
        return -1; // everyone knows atleast 1 person i.e. no one celebrity

    for (int i = 0; i < n; i++)
    { // check everyone know one remaining person at stack
      // i != st.top means its not a diagnol element
      // Diagnol element means mai khudko jaanta hu, which is non-sense

        /*

        if (i != st.top() && !knows(i, st.top()))
            return -1; // everyone don't know the one remaining person


        */
    }

    // everyone know him
    return st.top(); // the last one is celebrity
}

int main()
{
    return 0;
}