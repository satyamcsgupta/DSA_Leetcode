class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int first =0;
        int second = 0;
        for(int i=0;i<n;i++){
            if(first <nums[i]){
                second = first ;
                first = nums[i];
            }else if(second <nums[i]){
                 second =nums[i];
            }
        }
        return (first -1 )*(second -1);
    }
};