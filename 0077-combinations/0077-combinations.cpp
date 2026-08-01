class Solution {
public:
   void comb(int n ,int k , vector<vector<int> >&ans , vector<int> &temp , int index){
    if(temp.size()==k){
        ans.push_back( temp);
        return ;
    }
    if(index>n||temp.size()>k){
        return ;
    }


    comb(n,k,ans,temp,index+1);
    temp.push_back(index);
    comb(n,k,ans,temp,index+1);
    temp.pop_back();
   }
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int > >ans ;
         vector<int> temp;
         comb(n,k,ans,temp,1);
         return ans ;
    }
};