class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth =0;
        int index =0;
        int n=seq.size();
        vector<int>result(n);
         for (int i=0;i<n;i++){
            if(seq[i] == '('){
               depth++;
               result[i] = (depth%2==0) ?   0:1;
            }else{
                result[i] = (depth%2==0) ?0:1;
                depth--;
            }
         }
         return result;
    }
};