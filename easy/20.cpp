#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using std::string;

class Solution{
public:
    bool isValid(string s){
      std::stack<char> brackets;
      std::unordered_map<char, char> pairs{
        { '(', ')' }, { '[', ']' }, { '{', '}' }
      };

      for (auto bracket : s){
        auto end = pairs.find(bracket);

        if (end == pairs.end()){
          if (brackets.empty() || brackets.top() != bracket)
            return false;
          else
            brackets.pop();
        }
        else{
          brackets.push(end->second);
        }
      }

      return brackets.empty();
    }
};

int main(){
  string cases[]{
    "()",
    "()[]{}",
    "(]"
  };

  Solution sol;

  for (auto test : cases)
    std::cout << sol.isValid(test) << std::endl;
}
