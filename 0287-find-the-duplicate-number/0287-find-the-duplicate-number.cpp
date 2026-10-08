class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int n=nums.size();
    vector<int> count(n+1,0);
    int ans=0;
    for(int i=0;i<n;i++){
         count[nums[i]]++;
         if(count[nums[i]]>1){
            ans = nums[i];
            break;
         }
    }
    return ans;
    }
};