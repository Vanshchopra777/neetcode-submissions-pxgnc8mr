class Solution {
public:
    bool check_row(vector<char>&nums){
        unordered_set<char>st;
        for(auto ch:nums){
            if(ch == '.') continue;
            // mpp[it]++;
            // if(mpp[it]>1)return false;
            if(st.count(ch)) return false;
            st.insert(ch);
        }
        return true;

    }
    bool check_col(vector<vector<char>>& board,int col){
         unordered_set<char>st;

        for(int i=0;i<9;i++){
             char ch = board[i][col];

            if(ch == '.') continue;
            // mpp[ch]++;
            // if(mpp[ch]>1)return false;
             if(st.count(ch)) return false;
            st.insert(ch);
        }
        return true;

    }
    bool check_cell(vector<vector<char>>& board,int row,int col){
         unordered_set<char>st;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                 char ch = board[i][j];

            if(ch == '.') continue;
            if(st.count(ch)) return false;
            st.insert(ch);

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
