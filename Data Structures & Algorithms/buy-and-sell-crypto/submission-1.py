class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr_min = 101
        profit = 0
        for price in prices:
            if price < curr_min:
                curr_min = price
                continue
            profit = max(profit, price - curr_min)

        return profit
            

        