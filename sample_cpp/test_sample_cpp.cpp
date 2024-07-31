#include <cassert>
#include "sample_cpp.hpp"

void test_add() {
    Solution solution;

    // Test case 1
    int result1 = solution.add(2, 3);
    assert(result1 == 5);

    // Test case 2
    int result2 = solution.add(-10, 5);
    assert(result2 == -5);

    // Test case 3
    int result3 = solution.add(0, 0);
    assert(result3 == 0);
}

int main() {
    test_add();
    return 0;
}
