#include <vector>

// sorting the array range from index left to index right
void merge_sort(int left, int right, std::vector<int>& nums) {

    // addressing the case of one-element range
    if (left == right) {
        return;
    }

    // splitting the array range into two subranges and sorting them recursively
    int middle = (left + right) / 2;
    merge_sort(left, middle, nums);
    merge_sort(middle + 1, right, nums);

    // merging the two sorted subranges
    std::vector<int> array;
    int left_iter = left;
    int right_iter = middle + 1;
    while (left_iter <= middle or right_iter <= right) {
        if (left_iter <= middle and right_iter <= right) {
            if (nums[left_iter] < nums[right_iter]) {
                array.push_back(nums[left_iter]);
                ++left_iter;
            } else {
                array.push_back(nums[right_iter]);
                ++right_iter;
            }
        } else if (left_iter <= middle) {
            array.push_back(nums[left_iter]);
            ++left_iter;
        } else {
            array.push_back(nums[right_iter]);
            ++right_iter;
        }
    }

    // copying the sorted range back to initial array
    for (int i = left; i <= right; ++i) {
        nums[i] = array[i - left];
    }
}