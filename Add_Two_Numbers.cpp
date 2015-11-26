/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *results=new ListNode(0);
        ListNode *p1,*p2;
        ListNode *N1, *N2;
        int j = 0;

        //results = new ListNode;
        p1 = results;
        p2 = results;

        N1 = l1;
        N2 = l2;
        
        /*写的时候还是要注意一下自己写的规范。
        You really have to think carefully about the side effect when you try ++j or --j
        */

        do
        {
        	
        		p1->val += N1->val + N2->val;
        	
        	//cout<<p1->val<<" "<<endl;

        	if (p1->val >= 10){
        		p1->val = (p1->val)%10;
        		j++;
        	}
        	
        	if(j == 0){
        	    
        		if ((N1->next)==NULL && (N2->next)==NULL){
        		    
        			return results;
        		}
        		else{
        			p1->next = new ListNode(0);
        		    p1 = p1->next;
        		}
        	}

        	if (j == 1){
        		p1->next = new ListNode(1);
        		p1 = p1->next;
        		j--;
        	}
        	
        	
        	//cout<<p1->val<<" "<<endl;
        	
        	if((N1->next) == NULL && (N2->next) == NULL){
        		return results;
        	}

        	if(N1->next == NULL && N2->next != NULL){
        		N1->val = 0;
        		N2 = N2->next;
        		continue;
        	}

        	if(N1->next != NULL && N2->next == NULL){
        		N2->val = 0;
        		N1 = N1->next;
        		continue;
        	}

        	if(N1->next != NULL && N2->next != NULL){
        		N1 = N1->next;
        		N2 = N2->next;
        		continue;
        	}

        	

        } while (true);
        	
        	
    }
};