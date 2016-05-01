class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int temp;
        if(stack1.empty() && stack2.empty())
            return 0;
        else if(stack2.empty()){
            while(!stack1.empty()){
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        
        temp = stack2.top();
        stack2.pop();
        return temp;
        
    }

    int top() {
        int temp;
        if(stack1.empty() && stack2.empty())
            return 0;
        else if(stack2.empty()){
            while(!stack1.empty()){
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        
        temp = stack2.top();
        return temp;
    }
};
