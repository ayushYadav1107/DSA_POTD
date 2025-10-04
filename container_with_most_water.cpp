class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int left = 0 , right = n-1;
        while(left<right){
            int length = right-left; // length of the container
            int breadth = min(height[right],height[left]); // breadth of the container
            int area = length*breadth;
            maxArea = max(area,maxArea);
            if(height[left]<height[right]) left++; // we need to keep track of the lower line because that is the height we can take to calculate area
            else if(height[left]==height[right]){
                left++;
                right--;
            }
            else right--;
        }
        return maxArea;
    }
};