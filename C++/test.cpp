#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int kNum(vector<int>& nums1, vector<int>& nums2, int k) {
    int length1 = nums1.size();
    int length2 = nums2.size();
    int index1 = 0; 
    int index2 = 0;
    while (true) {
        if (index1 == length1) {
            return nums2[index2 + k - 1];
        }
        if (index2 == length2) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[index1], nums2[index2]);
        }
        int newIndex1 = min(index1 + k / 2, length1) - 1;
        int newIndex2 = min(index2 + k / 2, length2) - 1;
        if (nums1[newIndex1] <= nums2[newIndex2]) {
            k = k - (newIndex1 - index1 + 1);
            index1 = newIndex1 + 1;
        } else {
            k = k - (newIndex2 - index2 + 1);
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1) {
        return kNum(nums1, nums2, totalLength / 2 + 1);
    } else {
        return (kNum(nums1, nums2, totalLength / 2) + kNum(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;
    vector<int> nums1(m);
    vector<int> nums2(n);
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);
    cout << fixed << setprecision(1) << median << endl;

    return 0;
}