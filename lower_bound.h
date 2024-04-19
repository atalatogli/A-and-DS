#include <vector>

// finding the first appearance of num in nums
int lower_bound(int num, const std::vector<int>& nums) {
    
    // initializing the search boundaries
    int left = 0;
    int right = std::ssize(nums) - 1;

    // searching while the search boundaries are correct
    while (left <= right) {
        int middle = (left + right) / 2;
        if (nums[middle] < num) {
            left = middle + 1;
        } else if (nums[middle] == num) {
            if (left == right) {
                return left;
            }
            right = middle;
        } else {
            right = middle - 1;
        }
    }

    // returning in case there is not num in nums
    return -1;
}