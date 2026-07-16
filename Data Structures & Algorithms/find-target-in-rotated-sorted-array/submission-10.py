class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, r = 0, n-1

        while l <= r:
            m = (l+r)//2
            #print(m, l , r)
            if target == nums[m]:
                return m
            elif l == r:
                return -1

            if nums[l] > nums[r] and nums[m] > nums[r]:
                #first half
                if target < nums[m] and target < nums[l]:
                    l = m + 1
                elif target < nums[m]:
                    r = m - 1
                elif target > nums[m]:
                    l = m + 1
                    
            elif nums[l] > nums[r]:
                #second half
                if target > nums[m] and target <= nums[r]:
                    l = m + 1
                elif target > nums[m]:
                    r = m - 1
                elif target < nums[m]:
                    r = m - 1
        
            elif nums[l] < nums[r]:
                #normal binary search
                if nums[m] < target:
                    l = m + 1
                else:
                    r = m - 1
        
        return -1
        