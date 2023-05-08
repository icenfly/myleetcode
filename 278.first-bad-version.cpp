/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1;
        long long r = n;
        long long mid;
        if(n==1) return 1;
        while(l<=r){
            mid = (l+r)/2;
            if(!isBadVersion(mid-1)&&isBadVersion(mid)){
                return mid;
            }
            else if(!isBadVersion(mid-1)&&!isBadVersion(mid)){
                l = mid+1;
            }
            else if(isBadVersion(mid-1)&&isBadVersion(mid)){
                r = mid-1;
            }
        }
        return mid;
    }
};
// @lc code=end

