class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int depth=0;
        int maximum=0; 
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }else if(s[i]== ')'){
               maximum=max(depth ,maximum);
               depth--;
            }
        }
        return maximum;
    }
};