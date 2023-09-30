/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for(char c : t){
            need[c] ++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;
        int length = INT_MAX;
        int min_length = t.size();
        int max_length = s.size();
        int max_valid = need.size();
        int ans_left = INT_MAX;
        int ans_length = INT_MAX;

        while(right <= max_length-1){
            char c = s[right];
            right ++;
            if(need.count(c)){
                window[c] ++;
                if(window[c] == need[c]){
                    valid ++;
                }
            }
            while(valid == max_valid){
                int now_length = right - left;
                if(now_length < length){
                    length = now_length;
                    ans_left = left;
                    ans_length = now_length;
                    if(length == min_length){
                        ans = s.substr(left,now_length);
                        return ans;
                    }
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
        return ans_left == INT_MAX ? "" : s.substr(ans_left,ans_length);
    }
};
// @lc code=end

