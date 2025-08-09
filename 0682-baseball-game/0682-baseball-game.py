class Solution(object):
    def calPoints(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """

        ans = []
        prev = 100000
        prev2 = 100000

        for i in operations:
            if( i == "C" or i == "D" or i == "+"):
                if(i == "C"):
                    ans.remove(ans[len(ans) - 1])
                elif ( i == "D"):
                    ans.append(ans[len(ans) - 1] * 2)
                else:
                    ans.append(ans[len(ans) - 1] + ans[len(ans) - 2])

            else :
                num = int(i)
                ans.append(num)
        sum = 0
        for i in ans: sum += i

        return sum
        