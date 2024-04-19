#include <iostream>
#include <vector>

// sorting the array range from index left to index right
void quick_sort(int left, int right, std::vector<int>& nums) {

    // addressing the case of zero-element or one-element ranges
    if (left >= right) {
        return;
    }

    // partitioning the range into three subranges based on the pivot element
    int pivot = nums[rand() % (right - left + 1) + left];
    std::vector<int> left_nums, middle_nums, right_nums;
    for (int i = left; i <= right; ++i) {
        if (nums[i] < pivot) {
            left_nums.push_back(nums[i]);
        } else if (nums[i] == pivot) {
            middle_nums.push_back(nums[i]);
        } else {
            right_nums.push_back(nums[i]);
        }
    }

    // copying the three subranges back to initial array
    int iter = left;
    for (int num : left_nums) {
        nums[iter] = num;
        ++iter;
    }
    for (int num : middle_nums) {
        nums[iter] = num;
        ++iter;
    }
    for (int num : right_nums) {
        nums[iter] = num;
        ++iter;
    }

    // sorting the first and the third subranges recursively
    quick_sort(left, left + std::ssize(left_nums) - 1, nums);
    quick_sort(right - std::ssize(right_nums) + 1, right, nums);
}