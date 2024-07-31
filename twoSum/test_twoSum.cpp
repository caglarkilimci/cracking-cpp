#include <cassert>
#include "twoSum.hpp"

using namespace std;

void test_twoSum() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> expected1 = {0, 1};
    vector<int> result1 = solution.twoSum(nums1, target1);
    assert(result1 == expected1);

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> expected2 = {1, 2};
    vector<int> result2 = solution.twoSum(nums2, target2);
    assert(result2 == expected2);

    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> expected3 = {0, 1};
    vector<int> result3 = solution.twoSum(nums3, target3);
    assert(result3 == expected3);
}

int main() {
    test_twoSum();
    return 0;
}
