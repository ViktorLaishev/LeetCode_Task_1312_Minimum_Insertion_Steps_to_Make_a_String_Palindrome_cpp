class Solution { 
public:   
    int minInsertions(string s) {  
        int n = s.size(); 
        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        
        // base cases 
        for (int i = 0; i < n; i++) {  
            dp[i][i] = 0;
            if (i < n-1) {
                dp[i][i+1] = (s[i] == s[i+1]) ? 0 : 1; 
            }
        }
          
        // fill up dp table
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                int j = i+len-1;
                if (s[i] == s[j]) { 
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        
        return dp[0][n-1];
    }
};
