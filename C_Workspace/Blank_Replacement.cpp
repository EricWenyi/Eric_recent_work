class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        //int Original_Length = length;
        int New_Length = 0;
        int NumberOfBlanks = 0;
        int i = 0;
        
        if(string == NULL)
            return 0;
            
        
        while(string[i] != '\0'){
            if(string[i] == ' ')
                ++ NumberOfBlanks;
            i++;
        }
        
        
        
        New_Length = length  + 2 * NumberOfBlanks;
        
       
        
        
        int originalIndex = length;
        int newIndex = New_Length;
        
        while(newIndex > originalIndex || newIndex >= 0){
            if(string[originalIndex] != ' '){
                string[newIndex --] = string[originalIndex];
            }
            else{
                string[newIndex--] = '0';
                string[newIndex--] = '2';
                string[newIndex--] = '%';
            }
            
            -- originalIndex;
        }
        
        i = 0;
        
        return New_Length;
    }
};  