#include <unordered_map>
#include "twoSum.hpp"

using namespace std;

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> lookup;
        
        int index=0;
        int size = nums.size();
        
        vector<int> result = {0, 0};
        while (index < size) {
            int key = nums[index];
            if (lookup.find(key) == lookup.end()) {
                // Did not find any result.
                // Insert this node.
                lookup.insert(make_pair(target-key, index));
            } else {
                // Found!
                result[0] = lookup[key];
                result[1] = index;
                // No need to continue
                break;
            }
            index++;
        }
        
        return result;
}
