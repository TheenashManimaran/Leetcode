class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        mat = []
        xx = x
        yy = y

        for i in range(0,m):
            flag = 0
            temp = []
            for j in range(0,n):

                if(flag == 0 and i == xx and j == yy):
                    temp.append(grid[i][j])
                    flag = 1
                    yy+=1
                elif flag == 1 and i == xx and j == yy:
                    temp.append(grid[i][j])
                    yy+=1
                if yy > k + y - 1:
                    yy = y
                    break
            if len(temp) != 0:
                mat.append(temp)
                xx+=1
            if(xx > k + x - 1): break

        mm = len(mat)
        nn = len(mat[0])
        for i in range(0, mm//2):
            for j in range(0, nn):
                mat[i][j] , mat[mm - i - 1][j] = mat[mm - i - 1][j], mat[i][j]
        
        print(mat)

        xx = x
        yy = y

        matr = 0
        matc = 0
        for i in range(0,m):
            flag = 0
            for j in range(0,n):

                if(flag == 0 and i == xx and j == yy):
                    grid[i][j] = mat[matr][matc]
                    matc+=1
                    flag = 1
                    yy+=1
                elif flag == 1 and i == xx and j == yy:
                    grid[i][j] = mat[matr][matc]
                    matc+=1
                    yy+=1
                if yy > k + y - 1:
                    yy = y
                    matc = 0
                    break
            if flag :
                xx+=1
                matr+=1
            if(xx > k + x - 1): break


        return grid
