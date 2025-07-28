class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = [[1]]
        copy = [1]
        #print(pascal)
        for i in range(1,numRows):
            #print(f"i:{i}")
            temp = []
            ans = 0
            for j in range(0,i+1):
                if j == 0 or j == i:
                    temp.append(1)
                    ##print(f"j:{j}")
                else:
                    #print(f"i-1:{i-1}  j-1:{j-1}  j:{j}")
                    #print(f"{copy[j-1]} : {copy[j]}")
                    #ans = copy[j-1] + copy[j]
                    ans = pascal[i-1][j-1] + pascal[i-1][j]
                    temp.append(ans)
            #copy = temp
            #print(f"copy:{copy}")

            pascal.append(temp)
            #print(pascal)
        return pascal
        