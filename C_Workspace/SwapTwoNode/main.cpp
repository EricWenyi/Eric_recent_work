#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        else if(head->next == NULL){
            return head;
        }
        ListNode *p1, *p2;
        p1 = head;
        p2 = head->next;
        head = p2;



        while(p1 != NULL && p2 != NULL){

            p1->next = p2->next;
            p2->next = p1;
            if(p1->next == NULL){
                return head;
            }
            else{
                p1 = p1->next;
                if(p1->next != NULL){
                    p2->next->next = p1->next;
                }
                p2 = p1->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* p = head;

    for(int i = 2; i < 3; i++){
        ListNode *q = new ListNode(i);
        p->next = q;
        p = p->next;
    }


    head = s.swapPairs(head);


    while(head != NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
}
