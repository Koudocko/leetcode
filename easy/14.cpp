#include <iostream>
#include <vector>
#include <string>

using std::vector, std::string;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
      for (int i = 0; i < 200; ++i){
        char curr{};

        for (auto str : strs){
          if (i < str.length()){
            if (curr){
              if (str[i] != curr)
                return str.substr(0, i);
            }
            else
              curr = str[i];
          }
          else
            return str;
        }
      }

      return strs[0];
    }
};

int main(){
  vector<string> cases[]{
    { "flower","flow","flight" },
    { "dog","racecar","car" },
  };

  Solution sol;

  for(auto test : cases)
    std::cout << sol.longestCommonPrefix(test) << std::endl;
}
