#include <iostream>
#include <vector>
#include "merge_sorted_array.hpp"
#include <cassert>

int main() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    int m_1 = 3;
    std::vector<int> nums2_1 = {2, 5, 6};
    int n_1 = 3;
    solution.merge(nums1_1, m_1, nums2_1, n_1);
    std::vector<int> expected_1 = {1, 2, 2, 3, 5, 6};
    assert(nums1_1 == expected_1);

    // Test case 2
    std::vector<int> nums1_2 = {4, 5, 6, 0, 0, 0};
    int m_2 = 3;
    std::vector<int> nums2_2 = {1, 2, 3};
    int n_2 = 3;
    solution.merge(nums1_2, m_2, nums2_2, n_2);
    std::vector<int> expected_2 = {1, 2, 3, 4, 5, 6};
    assert(nums1_2 == expected_2);

    // Test case 3
    std::vector<int> nums1_3 = {1, 2, 3, 0, 0, 0};
    int m_3 = 3;
    std::vector<int> nums2_3 = {4, 5, 6};
    int n_3 = 3;
    solution.merge(nums1_3, m_3, nums2_3, n_3);
    std::vector<int> expected_3 = {1, 2, 3, 4, 5, 6};
    assert(nums1_3 == expected_3);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}