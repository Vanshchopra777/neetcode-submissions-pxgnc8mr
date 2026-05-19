class Solution {
public:
    bool check_row(vector<char>&nums){
        unordered_map<char,int>mpp;
        for(auto it:nums){
            if(it == '.') continue;
            mpp[it]++;
            if(mpp[it]>1)return false;
        }
        return true;

    }
    bool check_col(vector<vector<char>>& board,int col){
        unordered_map<char,int>mpp;

        for(int i=0;i<9;i++){
             char ch = board[i][col];

            if(ch == '.') continue;
            mpp[ch]++;
            if(mpp[ch]>1)return false;
        }
        return true;

    }
    bool check_cell(vector<vector<char>>& board,int row,int col){
        unordered_map<char,int>mpp;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                 char ch = board[i][j];

            if(ch == '.') continue;
            mpp[ch]++;
            if(mpp[ch]>1)return false;

            }
        }
        return true;

    }


    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
           if( !check_row(board[i]))return false;
        }
        for(int j=0;j<m;j++){
            if(!check_col(board,j))return false;
        }

        for(int i=0;i<n;i+=3){
            for(int j=0;j<m;j+=3){
                if(!check_cell(board,i,j))return false;
            }
        }

        return true;

        
    }
};
