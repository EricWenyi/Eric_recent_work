class Solution {
public:
    string longestPalindrome(string s) {
        int num = s.size()-1;
        int center = 0;//   center/2 indicates the real position of the center
        int i = 0;
        int j = 0;
        int MAX_Length = 1;
        int start = 0;
        int end = 0;

        for(;center <= 2*num; center++){
            cout<<center<<endl;
            
            if(center == 0)
            continue;
            
        	if(center%2 == 0){
        		i = center/2 - 1;
        		j = center/2 + 1;
        	}

        	if (center%2 == 1){
        		i = (center-1) / 2;
        		j = (center+1) / 2;
        	}

        	while (i >= 0 && j <= num){

        		if(s[i] == s[j]){
        			i--;
        			j++;
        		}
        		else{
        			if(MAX_Length < (j-i-1)){
        				start = i+1;
        				end = j-1;
        				MAX_Length = j-i-1;
        			}
        			break;//"break" is a bad guy if you put it in the wrong place
        		}

        		if ((i < 0 || j > num) && MAX_Length < (j-i-1)){
        			start = i+1;
        			end = j-1;
        			MAX_Length = j-i-1;
        		}

        	}
        }
        string results = "";
        int index;
        for (index = start; index <= end; index++){
        	results +=  s[index];
        }
        
        //cout<<i<< "  "<<j<<endl;

        return results;
       // return s.substring(start,end);
    }
};