class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = 0
        count = 0
        flag = 0
        for i in range(0,len(nums)):
            if nums[i] == 0 and flag == 0:
                count += 1
                flag = 1
            elif flag and nums[i] == 0:
                count += 1
            elif flag and nums[i] != 0:
                ans += (count * (count + 1)) // 2
                count = 0
                flag = 0
        if(flag and count != 0):
            ans += (count * (count + 1)) // 2
        
        return ans