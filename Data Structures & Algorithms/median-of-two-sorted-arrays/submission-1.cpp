class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int m=nums1.size();
        int n=nums2.size();

        int low=0;
        int high=m;

        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=(m+n+1)/2-cut1;

            int maxLeft1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int minRight1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            
            int maxLeft2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int minRight2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            // Check if we found the perfect partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If combined length is even
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } 
                // If combined length is odd
                else {
                    return max(maxLeft1, maxLeft2);
                }
            } 
            // We took too many elements from nums1, move left
            else if (maxLeft1 > minRight2) {
                high = cut1 - 1;
            } 
            // We took too few elements from nums1, move right
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;


        


        
    }
};
