#include <cmath>
#include <iostream>

using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
      string converted;
      converted.resize(s.length());

      const int SET_SIZE = (2 + (2 * (numRows - 2)));
      int offset{};

      if (numRows > 1){
        for (int k = 0; k < numRows; ++k){
          for (int i = 0; i < std::ceil(float(s.length()) / SET_SIZE); ++i){
            int set_offset = i * SET_SIZE;

            for (int j = 0; j < SET_SIZE; ++j){
              if ((j >= numRows ? numRows - (j - numRows + 2) : j) == k){
                if (offset >= converted.length())
                  return converted;

                if (set_offset + j < s.length())
                  converted[offset++] = s[set_offset + j];
              }
            }
          }
        }

        return converted;
      }

      return s;
    }
};

int main(){
  std::pair<string, int> cases[]{
    { "PAYPALISHIRING", 3 },
    { "PAYPALISHIRING", 4 },
    { "A", 1 }
  };

  Solution sol;

  for (auto test : cases)
    std::cout << sol.convert(test.first, test.second) << std::endl;
}

