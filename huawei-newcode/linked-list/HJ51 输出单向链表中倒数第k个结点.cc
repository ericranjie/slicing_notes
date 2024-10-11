#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
};

// bug:
int main(int argc, char *argv[]) {
  int num, k;
  vector<int> values;
  ListNode *head = nullptr,
    *dummy = nullptr,
    *pre = nullptr;

  dummy = (ListNode *)malloc(sizeof(ListNode));
  dummy->m_nKey = -1;
  dummy->m_pNext = nullptr;

  cin >> num;
  cin.ignore(256, '\n'); // POE:

  pre = dummy;

  for (int i = 0; i < num; i++) {
    int tmp;
    cin >> tmp;
    cin.ignore(256, '\n'); // POE:
    values.push_back(tmp);
    // ListNode *cur = new ListNode(tmp, nullptr); // POE:
    ListNode *cur = nullptr;
    cur = (ListNode *)malloc(sizeof(ListNode));
    cur->m_nKey = tmp;
    cur->m_pNext = nullptr;

    pre->m_pNext = cur;
    pre = pre->m_pNext;
  }

  // for (int i = 0; i < num; i++) {
  //   cout << values[i] << endl;
  // }
  // ListNode *cur = dummy->m_pNext;
  // while (cur != nullptr) {
  //   cout << cur->m_nKey << endl;
  //   cur = cur->m_pNext;
  // }

  cin >> k;
  cin.ignore(256, '\n'); // POE:

  // cout << "k = " << k << endl;

  ListNode *fast = dummy->m_pNext,
    *slow = dummy->m_pNext;

  while (k > 0) {
    k--;
    fast = fast->m_pNext;
  }

  while (fast && slow) {
    fast = fast->m_pNext;
    slow = slow->m_pNext;
  }

  cout << slow->m_nKey << endl;

  return 0;
}