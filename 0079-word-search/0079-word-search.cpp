class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
  bool valid(int i,int j,int r,int c){
        return i>=0&&j>=0&&i<r&&j<c;
  }
   bool find(vector<vector<char> >&board, string word, int i,int j , int index,int r,int c, vector<vector< bool> > &visited){
             if(index==word.size()){
                return true;
             }

             for(int k=0;k<4;k++){
                if(valid(i+row[k],j+col[k],r,c)&&(board[i+row[k]][j+col[k]]==word[index])&& !visited[i+row[k]][j+col[k]]){
                    visited[i+row[k]][j+col[k]]=1;
                    if( find(board,word,i+row[k],j+col[k],index+1,r,c,visited)){
                         return true;
                    }
                     
                    visited[i+row[k]][j+col[k]]=0;
                }
             }
              
              return false ;

            

   }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        vector<vector< bool> > visited(r,vector<bool>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                   if( find(board,word,i,j,1,r,c,visited)){
                    return  true;
                    
                   }
                   visited[i][j] =0;
                }
            }
        }
        return false ;
    }
};