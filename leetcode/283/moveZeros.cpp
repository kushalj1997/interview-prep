class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    // slow solution, O(n^2)

    // move all 0's to end of the given array and
    // maintain relative order of non-zero elts

    int num_zeros = 0;

    for (size_t i = 0; i < nums.size() - num_zeros; ++i) {
      if (!nums[i]) {
        // shift all elts from i + 1 to end of array - num zeros
        // over to the left by 1
        for (size_t j = i + 1; j < nums.size() - num_zeros; ++j) {
          nums[j - 1] = nums[j];
        }

        num_zeros++;
        // put this 0 on the end of array
        nums[nums.size() - num_zeros] = 0;

        // // print out the list after shifts
        // std::cout << "[";
        // for (size_t j = 0; j < nums.size(); ++j) {
        //     std::cout << nums[j] << " ";
        // }
        // std::cout << "]" << std::endl;
        i -= 1;
      }
    }
  }
};