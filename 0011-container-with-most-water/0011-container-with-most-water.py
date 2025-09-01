class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0; j = len(height) - 1

        maxi = 0
        area = 0
        while(i < j):
            area = min(height[i], height[j]) * (j - i)
            maxi = max(maxi, area)
            if(height[i] <= height[j]): i+=1
            else: j-=1

        return maxi