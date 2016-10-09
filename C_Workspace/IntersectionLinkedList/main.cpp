#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        stack<ListNode*> A;
        stack<ListNode*> B;
        ListNode* result = NULL;

        while(headA != NULL){
            A.push(headA);
            headA = headA->next;
        }

        while(headB != NULL){
            B.push(headB);
            headB = headB->next;
        }

        while(A.top() == B.top()){
            result = A.top();
            A.pop();
            B.pop();
        }

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
