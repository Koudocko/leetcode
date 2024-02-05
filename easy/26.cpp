#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int num_removed{};

      for (int i = 0; i < nums.size(); ++i){
        int streak{};

        while (i + num_removed + streak + 1 < nums.size() &&
            nums[i + num_removed + streak + 1] == nums[i])
          ++streak;

        num_removed += streak;

        if (i + num_removed + 1 < nums.size()){
          int temp = nums[i + 1];
          nums[i + 1] = nums[i + num_removed + 1];
          nums[i + num_removed + 1] = temp;
        }
      }

      return nums.size() - num_removed;
    }
};

int main(){
  vector<int> cases[]{
    { 1, 1, 2 },
    { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }
  };

  Solution sol;

  for (auto test : cases){
    std::cout << sol.removeDuplicates(test) << " : ";

    for(auto ele : test) {
      std::cout << ele << " ";
    }
    endl(std::cout);
  }
}
