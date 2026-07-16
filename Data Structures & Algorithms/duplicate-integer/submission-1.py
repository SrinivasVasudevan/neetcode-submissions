class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        for num, c in cnt.items():
            if c > 1: return True
        return False
        