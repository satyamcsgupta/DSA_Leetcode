class Solution {
public:
void  subset(vector<int>&nums,set<vector<int> > &ans, vector<int> &temp,int index){
   if(index==nums.size()){
    ans.insert(temp);
    return;
   }

   subset(nums,ans,temp,index+1);
   temp.push_back(nums[index]);
   subset(nums,ans,temp,index+1);
   temp.pop_back();


}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         set<vector<int> > ans;
  vector<int> temp;
  sort(nums.begin(),nums.end());
  subset(nums,ans,temp,0);
  vector<vector<int> > result(ans.begin(),ans.end());
  return result;
    }
};