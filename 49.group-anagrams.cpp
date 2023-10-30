/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            string t = s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
// @lc code=end

