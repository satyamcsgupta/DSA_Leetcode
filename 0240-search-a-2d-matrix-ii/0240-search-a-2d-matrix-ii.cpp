class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m= nums.size();
        int n=nums[0].size();
       
        for(int i=0;i<m;i++){
           int low=0;
        int high =n-1;
          while(low<=high){
            int mid=low+(high - low)/2;
            if(nums[i][mid]==target){
                return true;
            }else if(nums[i][mid] < target){
                 low=mid+1;
            }else{
                high = mid-1 ;
            }
          }
            
        }
        return false ;
    }
};