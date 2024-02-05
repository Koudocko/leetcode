#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
      ListNode* head{}, *curr{};
      bool carry{};

      while (l1 || l2 || carry){
        if (!head)
          head = new ListNode(0), curr = head;
        else
          curr->next = new ListNode(0), curr = curr->next;

        int sum = carry;

        if (l1)
          sum += l1->val, l1 = l1->next;
        if (l2)
          sum += l2->val, l2 = l2->next;

        carry = sum / 10;
        curr->val = sum % 10;
      }

      return head;
    }
};

int main(){
  std::pair<ListNode*, ListNode*> cases[]{
    std::make_pair(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4)))),
    std::make_pair(new ListNode(0, nullptr), new ListNode(0, nullptr)),
    std::make_pair(new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, nullptr))))))), new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, nullptr)))))
  };

  Solution sol;

  for (auto test : cases){
    ListNode* curr = sol.addTwoNumbers(test.first, test.second);

    while (curr){
      std::cout << curr->val << " ";
      curr = curr->next;
    }

    endl(std::cout);
  }
}
