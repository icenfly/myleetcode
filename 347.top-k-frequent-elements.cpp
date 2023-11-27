/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    class cmp{
    public:
        bool operator()(const pair<int, int>& left, const pair<int, int>& right){
            return left.second > right.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res(k);
        unordered_map<int, int> map;
        for(int i : nums){
            map[i] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> queue;
        for(unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++){
            queue.push(*it);
            if(queue.size() > k){
                queue.pop();
            }
        }
        for(int i = k-1; i >= 0; i--){
            res[i] = queue.top().first;
            queue.pop();
        }
        return res;
    }
};
// @lc code=end

