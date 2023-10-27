/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int level = 0;
        return dfsmatch(s,p,0,0,level);
    }
    bool dfsmatch(string s, string p, int i, int j, int &level){
        int ssize = s.size();
        int psize = p.size();
        bool first = true;
        int curlevel = level;
        while(i < ssize && (p[j]==s[i] || p[j]=='?')) {++i; ++j;}
        if(j == psize) return i == ssize;
        if(p[j] == '*'){
            while(p[++j] == '*');
            if(j >= psize) return true;
            for(int k = i; k < ssize; k++){
                if(p[j]!= '?' && p[j]!=s[k]) continue;
                if(first){++level; first = false;}
                if(dfsmatch(s,p,k,j,level)) return true;
                if(level > curlevel + 1) return false;
            }
        }
        return false;
    }
};
// @lc code=end

