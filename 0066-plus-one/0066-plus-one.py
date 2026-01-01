class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        # num = 0
        # n = len(digits)
        # for i in range(0,n):
        #     #last_digit = digits[i]%10
        #     num = (num * 10) + digits[i]
        # print(num)#123
        # new_num = num+1#124
        # number = new_num#124
        # increment_list = []
        # while(new_num>0):
        #     digit = new_num%10
        #     increment_list.append(digit)
        #     new_num/=10
        # print(increment_list.sort(reverse=True)) 


        # size = len(digits) 
        # last_element = digits[size-1] + 1 #10
        # if last>9:
        #     last = last_element%10
        #     bef_last = last_element/10
        #     digits[size -1] = last
        #     digits 
        arr_num = 0
        n = len(digits)
        exp = n-1
        for i in range(0,n):
            arr_num += digits[i] * pow(10,exp)
            exp-=1
        result_num = arr_num + 1
        num = result_num
        new_arr = []
        new_ind = 0
        while(num!=0):
            new_arr.append(num%10)
            num/=10
            new_ind  += 1

        rev_ind = new_ind -1
        for i in range(0,new_ind):
            if i<=n-1:
                digits[i] = new_arr[rev_ind]
            else:
                digits.append(new_arr[rev_ind])
            rev_ind-=1
        return digits
        
        


        

            


        