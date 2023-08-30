#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Allocate Minimum Number of Pages

Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

    Each student gets at least one book.
    Each book should be allocated to only one student.
    Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
Example 1:
Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2:
Input Format: n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result: 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

We can allocate books in several ways but it is clearly said in the question that we have to allocate the books in such a way that the maximum number of pages received by a student should be minimum.

Assume the given array is {25 46 28 49 24} and number of students, M = 4. Now, we can allocate these books in different ways. Some of them are the following:

    25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
    25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
    25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
    25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71


From the above allocations, we can clearly observe that the minimum possible maximum number of pages is 71.

When it is impossible to allocate books:

When the number of books is lesser than the number of students, we cannot allocate books to all the students even if we give only a single book to each student. So, if m > n, we should return -1.

Observations:

    Minimum possible answer: We will get the minimum answer when we give n books of the array to n students(i.e. Each student will receive 1 book). Now, in this case, the maximum number of pages will be the maximum element in the array. So, the minimum possible answer is max(arr[]).
    Maximum possible answer: We will get the maximum answer when we give all n books to a single student. The maximum no. of pages he/she will receive is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).


From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].

How to calculate the number of students to whom we can allocate the books if one can receive at most ‘pages’ number of pages:

In order to calculate the number of students we will write a function, countStudents(). This function will take the array and ‘pages’ as parameters and return the number of students to whom we can allocate the books.

countStudents(arr[], pages):

    We will first declare two variables i.e. ‘students’(stores the no. of students), and pagesStudent(stores the number of pages of a student). As we are starting with the first student, ‘students’ should be initialized with 1.
    We will start traversing the given array.
    If pagesStudent + arr[i] <= pages: If upon adding the pages with the existing number of pages does not exceed the limit, we can allocate this i-th book to the current student.
    Otherwise, we will move to the next student(i.e. students += 1 ) and allocate the book.


Finally, we will return the value of ‘students’.
*/

int countStudents(vector<int> &arr, int pages)
{
    // Brute force
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

bool isPossible(int mid, int n, int m, vector<int> &time)
{
    // min 2 students will always be there according to constraints
    int studentsCount = 1; // we will start from 1 student
    int numberofPages = 0;

    for (int i = 0; i < n; i++)
    {
        if (numberofPages + time[i] <= mid)
        {
            numberofPages += time[i];
        }
        else
        {
            studentsCount++;
            // time[i]>mid means if element of array is itself more than mid means not possible to allot
            if (studentsCount > m || time[i] > mid)
            {
                return false;
            }
            // start allocating to new student
            numberofPages = time[i];
        }
    }

    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Optimised approach
    // We can use binary search for a search space and try to minimize that search space
    // Let say our search space starts from 0
    // max our search space can go to (sum of all element/pages in array)
    // we find mid and check if we can allote mid number of pages to m number of students
    // if we can allot we return true
    // we store that mid in the ans as this can be a potential answer
    // if we can allot mid number of pages successfully means we can also allot mid+1->end number of pages successfully as search space is sorted
    // so we do high = mid-1
    // if we cannot allot mid number of pages means we cannot allot for mid-1->0 number of pages also as search space is sorted
    // so do low = mid+1
    // At the end return ans
    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += time[i];
    }
    int end = sum;
    int ans = -1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (isPossible(mid, n, m, time))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    return 0;
}