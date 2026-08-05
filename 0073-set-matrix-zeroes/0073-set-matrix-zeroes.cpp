class Solution {
public:
    void  making(vector<vector<int>>&nums,int i,int j,int r,int c){
               for(int k=0;k<r;k++){
                nums[k][j]=0;
               }
               for(int l=0;l<c;l++){
                nums[i][l]=0;
               }

    }
    void setZeroes(vector<vector<int>>& nums) {
        int r=nums.size();
        int c=nums[0].size();
        vector<int> place;
        int index=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(nums[i][j]==0){
                   
                    place.push_back(i);
                    place.push_back(j);

                }
            }
        }
      int n=place.size();
      int k=0;
       int index_j=0;
       int index_i=0;
        while(k<n){
           index_i=place[k];
           k++;
           index_j=place[k];
           
            k++;
            making(nums,index_i,index_j,r,c);
           
        } 
     
    }
};