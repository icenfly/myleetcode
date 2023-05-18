/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1<n2) return findMedianSortedArrays(nums2, nums1);
        int left = 0;
        int right = n2*2;;
        while(left<=right){
            int mid2 = (left+right)/2;
            int mid1 = n1+n2-mid2;
            double l1 = mid1==0 ? INT_MIN : nums1[(mid1-1)/2];
            double l2 = mid2==0 ? INT_MIN : nums2[(mid2-1)/2];
            double r1 = (mid1 == n1 * 2) ? INT_MAX : nums1[(mid1)/2];
            double r2 = (mid2 == n2 * 2) ? INT_MAX : nums2[(mid2)/2];
            if(l1>r2) left = mid2+1;
            else if (l2>r1) right = mid2-1;
            else return (max(l1,l2)+min(r1,r2))/2;
        }
        return -1;
    }
};
// @lc code=end

