/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_length = s.size();
        int word_length = words[0].size();
        int word_count = words.size();
        int index = 0;
        int cnt = 0;
        vector<int> ans;
        unordered_map<string,int> ans_map;
        for(int i = 0; i <= word_count - 1; i++){
            ans_map[words[i]] ++;
        }
        while(s_length - index >= word_length * word_count){
            unordered_map<string,int> check_map;
            int j = 0;
            for(; j < word_count ; j++){
                string word = s.substr(index + j * word_length, word_length);
                if(ans_map.find(word) != ans_map.end()){
                    check_map[word] ++;
                    if(check_map[word] > ans_map[word]) break;
                }
                else{
                    break;
                } 
            }
            if(j == word_count) ans.push_back(index);
            index += word_length;
        }
        return ans;
    }
};
// @lc code=end

