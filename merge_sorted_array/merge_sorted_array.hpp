#ifndef MERGE_SORTED_ARRAY_H
#define MERGE_SORTED_ARRAY_H

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/96/sorting-and-searching/587/

// Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two
// integers m and n, representing the number of elements in nums1 and nums2 respectively.

#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
};

#endif // MERGE_SORTED_ARRAY_H
