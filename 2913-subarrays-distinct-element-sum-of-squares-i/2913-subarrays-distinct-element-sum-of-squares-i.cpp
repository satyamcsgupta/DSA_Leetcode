class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        vector<int>values;
        vector<int>ans(101,0);
        for(int i=0;i<n;i++){

            for(int j=i;j<n;j++){
                 ans[nums[j]]++;
                 for(int k=0;k<101;k++){
                   if(ans[k] >= 1){
                    count++;
                   }
                 }
                 values.push_back(count);
                 count=0;

            }
            fill(ans.begin(), ans.end(), 0);
        }
        int sum =0;
        for(int i=0;i<values.size();i++){
            sum +=(values[i]*values[i]);
        }
        return sum ;
    }
};