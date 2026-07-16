class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n-1

        while l < r:
            m = (l+r)//2

            if nums[l] > nums[r] and nums[m] >= nums[l]:
                l = m + 1
            elif nums[l] > nums[r] and nums[m] < nums[l]:
                r = m
            elif nums[l] < nums[r]:
                r = l

        return nums[l]
        