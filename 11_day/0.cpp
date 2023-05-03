#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> numss1, numss2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                numss1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                numss2.push_back(num);
            }
        }

        return {numss1, numss2};
    }

int main () {

    int num  = 5 ;

    cout << num << endl;

    // address of Operator - &

    cout <<" address of num is " << &num << endl;

    int *ptr = &num;

    cout << "Address is : " << ptr << endl;
    cout << "value is : " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d;

    cout << "Address is : " << p2 << endl;
    cout << "value is : " << *p2 << endl;

    cout << " size of integer is " << sizeof(num) << endl;
    cout << " size of pointer is " << sizeof(ptr) << endl;
    cout << " size of pointer is " << sizeof(p2) << endl;



    return 0;
}