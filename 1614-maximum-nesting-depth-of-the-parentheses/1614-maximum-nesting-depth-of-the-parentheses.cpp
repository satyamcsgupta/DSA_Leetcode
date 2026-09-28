class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int count =0;
        int max_count =-1;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
             count++;
            }else if(s[i] == ')'){
                count--;
            }
            max_count = max(max_count , count );
        }
        return max_count ;
    }
};