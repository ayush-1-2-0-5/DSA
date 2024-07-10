class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {};
        int m = n;
        vector<vector<int>> matrix(m, vector<int>(n));
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;
        
        int id = 0;
        
        int counter = 1;
        while(top <= down && left <= right) {
            if(id == 0) {
                for(int i = left; i<=right; i++) {
                    matrix[top][i] = counter++;
                }
                top++;
            }
            
            if(id == 1) {
                for(int i = top; i<=down; i++) {
                    matrix[i][right] = counter++;
                }
                right--;
            }
            
            if(id == 2) {
                for(int i = right; i>=left; i--) {
                    matrix[down][i] = counter++;
                }
                down--;
            }
            
            if(id == 3) {
                for(int i = down; i>=top; i--) {
                    matrix[i][left] = counter++;
                }
                left++;
            }
            
            id = (id+1)%4;
        }
        return matrix;
    }
};