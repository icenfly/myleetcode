/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int vis[50110]; 
        int s_used[300];
        int t_used[300];
        memset(vis,0,sizeof(vis));
        memset(s_used,0,sizeof(s_used));
        memset(t_used,0,sizeof(t_used));
        for(int i = 0; i < s.length(); i ++){
            if(vis[i]==1){
                continue;
            }
            else{
                vis[i]=1;
            }
            if(s_used[int(s[i])] == 1||t_used[int(t[i])] == 1){
                return false;
            }
            else{
                s_used[int(s[i])] = 1;
                t_used[int(t[i])] = 1;
            }
            for(int j = i+1; j < s.length(); j ++){
                if(s[j]==s[i]){
                    if(t[j]==t[i]){
                        vis[j]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

