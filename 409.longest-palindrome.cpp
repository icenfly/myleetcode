/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(int i = 0; i < s.length();i++){
            map[s[i]]++;
        }
        int cnt = 0;
        bool first = true;
        for(auto i: map){
            if(i.second%2==0){
                cnt+=i.second;
            }
            else if(i.second%2==1){
                cnt+=i.second-1;
                if(first){
                    cnt++;
                    first = false;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

