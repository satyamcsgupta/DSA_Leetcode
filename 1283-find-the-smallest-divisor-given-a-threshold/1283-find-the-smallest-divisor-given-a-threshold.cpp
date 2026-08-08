class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      int low=1;
      int high =-1;
      for(int i=0;i<n;i++){
          
          high =max(high ,nums[i]);
      }
       int ans=0;
      while(low <= high){
        long long  sum=0;
        int mid=low+(high - low)/2;
        for(int i=0;i<n;i++){
           sum +=(nums[i] + mid -1)/mid;
           
        }
         if(sum <= threshold){
            ans=mid;
            high=mid-1;
         }else{
            low=mid+1;
         }
      }
      return ans;
    }
};