class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights)-1
        area = 0
        while l < r:
            h_l, h_r = heights[l], heights[r]
            area = max((r-l)*min(h_l, h_r), area)
            if h_l < h_r:
                l+=1
            else:
                r-=1

        return area
        