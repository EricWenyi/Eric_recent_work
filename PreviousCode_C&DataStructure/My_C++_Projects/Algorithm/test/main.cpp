#include <iostream>
#include<bits/c++io.h>
#include<vector>

using namespace std;

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

vector<int> printListFromTailToHead(struct ListNode* head) {
            vector<int> results;
            if(head == NULL){
                results.push_back(0);
                return results;
            }


            if(head->next == NULL){
                results.push_back(head->val);
                return results;
            }
            else if(head->next->next == NULL){
                results.push_back(head->next->val);
                results.push_back(head->val);
                return results;
            }


            struct ListNode* before,*now,*after;

            before = head;
            now = head->next;
            after = now->next;
            before->next = NULL;

            while(after != NULL){
                now->next = before;
                before = now;
                now = after;
                after = after->next;
            }
            now->next = before;

            ListNode* p = now;
            while(p!= NULL){
                results.push_back(p->val);
                p = p->next;
            }
            return results;
        }

int main()
{
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(2);
    ListNode* head3 = new ListNode(3);
    ListNode* head4 = new ListNode(4);
    ListNode* head5 = new ListNode(5);

    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;

     ListNode* p = head1;
    cout<<p->next->val<<endl;

    vector<int> number;
    number = printListFromTailToHead(head1);



    for (int i = 0; i < number.size();i++){
        cout<<number[i]<<endl;
    }

    return 0;


}
