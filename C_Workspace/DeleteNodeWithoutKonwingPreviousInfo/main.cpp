#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
 };

class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        int temp = node->next->val;

        node->val = temp;

        node->next = node->next->next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
