class Solution {
public:
void comb(vector<int> &nums, vector<vector<int > > &ans, vector<int> &temp,int k,int n,int index ){
   if(n==0&&temp.size()==k){
 ans.push_back(temp);
 return ;
   }
   if(n<0||temp.size()>k){
    return ;
   }
    if(index==nums.size()){
        return ;
    }
   comb(nums,ans,temp,k,n,index+1);
   temp.push_back(nums[index]);
     comb(nums,ans,temp,k,n-nums[index],index+1);
   temp.pop_back();

    
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int > > ans;
        vector<int> temp;
         
        comb(nums,ans,temp,k,n,0);
        return ans;
    }
};