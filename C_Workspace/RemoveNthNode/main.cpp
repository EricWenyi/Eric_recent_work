#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(head == NULL)
            return NULL;

        //set the probe on
        ListNode* probe = head;
        ListNode* r = head;
        for(int i = 0; i < n && probe != NULL; i++){
            probe = probe->next;
        }


        if(probe == NULL)
            return head->next;

        while(probe != NULL){
            probe = probe ->next;
            r = r->next;
        }

        if(r->next == NULL){
            r = head;
            while(r->next != NULL && r->next->next != NULL)
                r = r ->next;
            r -> next = NULL;
        }

        else{
            int temp = r->next->val;
            r->val = temp;
            r->next = r->next->next;
        }

        return head;


    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
