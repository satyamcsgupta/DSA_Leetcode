class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            
          int n=nums.size();
          if(n==1){
            return nums;
          }
          sort(nums.begin(),nums.end());
          int res ;
          int compare=n/3;
          vector<int>ans;
          int count=1;
           
          for(int i=1;i<n;i++){
              if(nums[i]==nums[i-1]){
                count++;
             
              }else{
                   if(count>compare){
                    ans.push_back(nums[i-1]);
                }
                count=1;
              }
               
          }
            if(count>compare){
                    ans.push_back(nums[n-1]);
                }
          return ans;
    }
};