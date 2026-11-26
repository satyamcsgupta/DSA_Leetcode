class Solution {
public:
    bool canAliceWin(int n) {
      int count =10;
       bool flag = true ;
       if(n <10){
        return false;
       }
       while( count ){
        if(n >=count ){
            n = n-count;
            flag  = !flag;
        }else{
            return !flag;
        }
        count --;
       }
      return !flag;
    }
};