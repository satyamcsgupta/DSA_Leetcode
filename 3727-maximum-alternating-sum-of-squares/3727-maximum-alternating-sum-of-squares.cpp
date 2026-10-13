class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        long long sum =0;
        int i=0;
        for(int i=0;i<n;i++){
            nums[i] = pow(nums[i],2);
        }
        sort(nums.begin() ,nums.end());
        int j =n-1;
       while(i<=j){
          if(i != j){
            sum += abs(nums[j] - nums[i]);

          }else{
            sum += nums[i];
          }
          i++;
          j--;
       }
        return sum;
    }
};