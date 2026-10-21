class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int ans=0;

        while(left<right){
            int b=min(heights[left],heights[right]);
            int cap=b*(right-left);

            ans=max(cap,ans);

            if(heights[left]>=heights[right]){
                right--;
            } else {
                left++;
            }
        }

        return ans;


        
    }
};
