# 20/1/25 monday 8-9pm
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # submitted with time complexity of i don't know but i think it is O(log n) 
        # 20/1/25 monday 11.20pm
        indList = []
        n = len(nums)
        start = end = -1
        i = 0;j = n-1
        while(i<=j):
            if nums[i] != target:
                i+=1
            if nums[j]!= target:
                j-=1
            elif nums[i] == target and nums[j] == target:
                start = i
                end = j
                break
        indList += [start,end]

        return indList

# i couldn't solve this prob with log n but i applied brute O(n) and now i am going to use two pointers.
        # retrn = []
        # flag = 0
        # start = end = -1
        # for i in range(len(nums)):
        #     if flag == 0 and nums[i] == target:
        #         retrn.append(i)
        #         start = i
        #         flag = 1
        #     elif flag == 1 and nums[i] == target:
        #         end = i
        # if start<end:
        #     retrn.append(end)
        # if len(retrn) == 1 :
        #     retrn.append(retrn[0])
        #     return retrn
        # elif not retrn:
        #     return [-1,-1]
        # else:
        #     return retrn
            

        