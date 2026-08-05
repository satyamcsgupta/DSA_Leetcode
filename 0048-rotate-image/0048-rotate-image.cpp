class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int m=nums.size();
        int n=m;
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(nums[i][j],nums[j][i]);
            }
        }
         int j=0;
             int k=n-1;
        for(int i=0;i<m;i++){
              j=0;
              k=n-1;
             while(j<k){
                swap(nums[i][j],nums[i][k]);
                j++;
                k--;
             }
        }
    }
};