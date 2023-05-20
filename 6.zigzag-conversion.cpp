/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows==1) return s;
        if(numRows==2){
            for(int i = 0 ; i <=s.size()-1;i+=2){
                ans = ans +s[i];
            }
            for(int i = 1 ; i <=s.size()-1;i+=2){
                ans = ans +s[i];
            }
            return ans;
        }
        int k = s.size()/(numRows+numRows-2);
        int k1 = s.size()%(numRows+numRows-2);
        if(k1>0) k++;
        k = k*(numRows-1);
        int to[1010];
        memset(to,0,sizeof(to));
        for(int i =1 ; i<= numRows; i++){
            for(int j =1; j<=k;j++){
                if(j%(numRows-1)==1){
                    int ass = ((j-1)/(numRows-1))*(numRows+numRows-2)+i-1;
                    if(ass<=s.size()-1){
                        ans = ans + s[ass];
                    }
                }
                else{
                    int ass = ((j-1)/(numRows-1))*(numRows+numRows-2)+numRows+numRows-i-1;
                    if(ass<=s.size()-1&&i!=1&&i!=numRows&&!to[ass]){
                        ans = ans + s[ass];
                        to[ass] =1;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

