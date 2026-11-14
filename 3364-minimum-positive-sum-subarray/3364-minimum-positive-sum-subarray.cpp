class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int sum =0;
        int minimum = INT_MAX;
        for(int i=0;i<n;i++){
            int j=i;
            int k=1;
            while((k<=l||k<=r)&& j<n){
                sum +=nums[j];
                if(sum > 0 && k>=l&& k<=r){
                    minimum = min(minimum,sum);
                }
                 k++;
                 j++;
            }
            sum = 0;
        }
        if(minimum == INT_MAX ){
            return -1;
        }
        return minimum;
    }
};