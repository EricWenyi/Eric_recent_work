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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }

        ListNode* probe = head;
        //cout<<probe->val<<endl;
        ListNode* NodeToRemove = head; //Attention: This pointer points to the very node before the Node to be removed
        for(int i = 0; i < n; i++){
            probe = probe->next;
        }


        if(probe == NULL){
            head = head->next;
            return head;
        }

        while(probe->next != NULL){
            probe = probe->next;
            NodeToRemove = NodeToRemove->next;
        }

        ListNode* ToBeDelete = NodeToRemove->next;
        NodeToRemove->next = ToBeDelete->next;
        //delete(ToBeDelete);
        return head;

    }
};


int main()
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(10);
    head->next->next = new ListNode(15);
    head->next->next->next = new ListNode(20);

    Solution s;
    head = s.removeNthFromEnd(head,2);
    while(head != NULL){
        cout<<head->val<<"-->";
        head = head->next;
    }
}
