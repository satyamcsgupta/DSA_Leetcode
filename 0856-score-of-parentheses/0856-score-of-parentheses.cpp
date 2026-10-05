class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>ans;
    
        int score = 0;
        for(int i=0;i<s.size() ;i++){
            if(s[i] == '('){
                ans.push(score);
                score =0;
            }else {
                if(s[i-1] == '('){
                    score = ans.top() + 1; 
                }else{
                    score = ans.top() + score*2;
                }
                ans.pop();
            }
            
        }
       
        return score;
    }
};