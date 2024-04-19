#include <vector>

// finding any appearance of num in nums
int binary_search(int num, const std::vector<int>& nums) {

    // initializing the search boundaries
    int left = 0;
    int right = std::ssize(nums) - 1;

    // searching while the search boundaries are correct
    while (left <= right) {
        int middle = (left + right) / 2;
        if (nums[middle] < num) {
            left = middle + 1;
        } else if (nums[middle] == num) {
            return middle;
        } else {
            right = middle - 1;
        }
    }

    // returning in case there is not num in nums
    return -1;
}