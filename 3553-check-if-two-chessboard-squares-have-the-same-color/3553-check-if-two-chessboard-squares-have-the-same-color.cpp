class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
     auto letterToNumber = [](char letter) {
        return letter - 'a' + 1;
    };

   
    int col1 = letterToNumber(c1[0]);
    int row1 = c1[1] - '0';  

  
    int col2 = letterToNumber(c2[0]);
    int row2 = c2[1] - '0';  

    
    return ((col1 + row1) % 2) == ((col2 + row2) % 2);
    }
};
