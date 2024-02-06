#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      std::unordered_map<char, int> repeated(s.size());
      std::vector<char> ordered(s.begin(), s.end());
      int sub_len{};

      for(int i = 0; i < s.length(); ++i){
        auto found = repeated.find(s[i]);

        if (found != repeated.end()){
          sub_len = repeated.size() > sub_len ? repeated.size() : sub_len;

          int offset = found->second + 1;
          for (auto it = ordered.begin(); it != (ordered.size() < offset ?
                ordered.end() : ordered.begin() + offset); ++it){
            if (*it != 0)
              repeated.erase(*it);
          }

          std::fill(ordered.begin(), ordered.begin() + offset, 0);
        }

        repeated.insert({ s[i], i });
      }

      return repeated.size() > sub_len ? repeated.size() : sub_len;
    }
};

int main(){
  string cases[]{
    "abcabcbb",
    "bbbbb",
    "pwwkew"
  };

  Solution sol;

  for (auto test : cases)
    std::cout << sol.lengthOfLongestSubstring(test) << std::endl;
}
