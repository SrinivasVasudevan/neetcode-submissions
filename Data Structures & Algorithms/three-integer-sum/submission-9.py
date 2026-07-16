class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        i = 0
        res = []
        n = len(nums)

        while i < n:
            l, r = i+1, n-1
            target = -nums[i]
            while l < r:
                while l > i+1 and l < r and nums[l] == nums[l-1]:
                    l+=1
                while r < n-1 and l < r and nums[r] == nums[r+1]:
                    r-=1

                if l == r: break

                if target == nums[l] + nums[r]:
                    res.append([-target, nums[l], nums[r]])
                    l+=1
                    r-=1
                elif target > nums[l] + nums[r]:
                    l+=1
                else:
                    r-=1

            i+=1
            while i < n and nums[i] == nums[i-1]:
                i+=1

        return res
            

        