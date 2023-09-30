/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for(char c : p) need[c] ++;
        int left = 0;
        int right = 0;
        int valid = 0;
        vector<int> res;

        while(right <= s.size() - 1){
            char c = s[right];
            right ++;
            if(need.count(c)){
                window[c] ++;
                if(window[c] == need[c]){
                    valid ++;
                }
            }
            while(right - left >= p.size()){
                if(valid == need.size()){
                    res.push_back(left);
                }
                char d = s[left];
                left ++;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid --;
                    }
                    window[d] --;
                }
            }
        }
        return res;
    }
};
// @lc code=end

