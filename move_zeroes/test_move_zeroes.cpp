#include <cassert>
#include "move_zeroes.hpp"

void test_move_zeroes() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    assert(nums1 == std::vector<int>({1, 3, 12, 0, 0}));

    // Test case 2
    std::vector<int> nums2 = {0, 0, 0, 0, 0};
    solution.moveZeroes(nums2);
    assert(nums2 == std::vector<int>({0, 0, 0, 0, 0}));

    // Test case 3
    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    solution.moveZeroes(nums3);
    assert(nums3 == std::vector<int>({1, 2, 3, 4, 5}));
}

int main() {
    test_move_zeroes();
    return 0;
}