#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* head{}, *curr{};

      while (list1 || list2){
        if (!head)
          head = new ListNode(0), curr = head;
        else
          curr->next = new ListNode(0), curr = curr->next;

        int val{};

        if (list1 && list2){
          if (list1->val < list2->val)
            val = list1->val, list1 = list1->next;
          else
            val = list2->val, list2 = list2->next;
        }
        else if (list1)
          val = list1->val, list1 = list1->next;
        else if (list2)
          val = list2->val, list2 = list2->next;

        curr->val = val;
      }

      return head;
    }
};

int main(){
  std::pair<ListNode*, ListNode*> cases[]{
    std::make_pair(new ListNode(1, new ListNode(2, new ListNode(4))), new ListNode(1, new ListNode(3, new ListNode(4)))),
    std::make_pair(nullptr, nullptr),
    std::make_pair(nullptr, new ListNode(0, nullptr))
  };

  Solution sol;

  for (auto test : cases){
    ListNode* curr = sol.mergeTwoLists(test.first, test.second);

    while (curr){
      std::cout << curr->val << " ";
      curr = curr->next;
    }

    endl(std::cout);
  }
}
