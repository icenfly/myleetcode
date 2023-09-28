/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        int ans = 0;
        queue<string> q;
        unordered_set<string> dead(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        if(dead.find("0000") != dead.end()) return -1;
        q.push("0000");
        visited.insert("0000");
        while(!q.empty()){
            ans++;
            int k = q.size();
            for(int i = 1; i <= k; i++){
                string s = q.front();
                q.pop();
                for(int j = 1; j <= 4; j++){
                    for(int p = 1; p <= 2; p++){
                        string temps = changelock(s,j,p);
                        if(temps == target){
                            return ans;
                        }
                        if(dead.find(temps) == dead.end() && visited.find(temps) == visited.end()){
                            visited.insert(temps);
                            q.push(temps);
                        }
                    }
                }
            }
        }
        return -1;
    }
    string changelock(string s, int bit, int parameter){
        string ans = s;
        if(parameter == 1){
            if(s[bit-1] == '9'){
                ans[bit-1] = '0';
            }
            else{
                ans[bit-1] = char(int(s[bit-1])+1);
            }
        }
        if(parameter == 2){
            if(s[bit-1] == '0'){
                ans[bit-1] = '9';
            }
            else{
                ans[bit-1] = char(int(s[bit-1])-1);
            }
        }
        // check can change
        return ans;
    }
};
// @lc code=end

