//dfs with memorization, add memorization to avoid TLE
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
//Memory Usage: 6.4 MB, less than 38.81% of C++ online submissions for Decode Ways.
class Solution {
public:
    vector<int> memo;
    
    int backtrack(string& s, int start){
        if(start == s.size()){
            return 1;
        }else if(memo[start] != -1){
            return memo[start];
        }else{
            int ret = 0;
            if(s[start] != '0'){
                ret += backtrack(s, start+1);
                
                if(start+1 < s.size() &&
                   (s[start] == '1' || (s[start] == '2' && s[start+1] <= '6'))){
                    //if there remains >= 2 chars
                    ret += backtrack(s, start+2);
                }
            }
            
            return memo[start] = ret;
        }
    }
    
    int numDecodings(string s) {
        memo = vector<int>(s.size(), -1);
        return backtrack(s, 0);
    }
};

//bottom-up DP
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
//Memory Usage: 6.4 MB, less than 44.21% of C++ online submissions for Decode Ways.
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n+1, 0);
        
        dp[n] = 1;
        
        for(int i = n-1; i >= 0; --i){
            if(s[i] != '0'){
                dp[i] += dp[i+1];
                
                if(i+1 < n &&
                  (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
                    dp[i] += dp[i+2];
                }
            }
        }
        
        return dp[0];
    }
};
