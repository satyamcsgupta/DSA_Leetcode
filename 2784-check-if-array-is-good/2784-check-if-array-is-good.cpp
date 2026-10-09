class Solution {
public:
    bool isGood(vector<int>& nums) {
       int n=nums.size();
       int max_num =0;
       for( int i=0;i<n;i++){
        max_num  =max(max_num ,nums[i]);
       }
       if(n != max_num +1){
        return false;
       }
       vector<int> count(max_num +1 , 0);
       for(int i=0;i<n;i++){
        count[nums[i]]++;
       } 
       for(int i=0;i<n;i++){
        if(nums[i] != max_num ){
            if(count[nums[i]] != 1){
                return false;
            }
        }else{
            if(count[nums[i]] !=2){
                return false;
            }
        }
       }
       return true;
    }
};