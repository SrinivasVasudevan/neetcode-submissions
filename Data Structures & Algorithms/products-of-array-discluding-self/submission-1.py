class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_product = list(nums)
        postfix_product = list(nums)
        for idx in range(1,len(nums)):
            prefix_product[idx]*=prefix_product[idx-1]
        
        for idx in range(len(nums)-2, -1, -1):
            postfix_product[idx]*=postfix_product[idx+1]

        res = [0]*len(nums)

        for idx in range(len(nums)):
            left, right = 1, 1
            if idx>0:
                left = prefix_product[idx-1]
            
            if idx<len(nums)-1:
                right=postfix_product[idx+1]

            res[idx] = left*right

        return res
            

        