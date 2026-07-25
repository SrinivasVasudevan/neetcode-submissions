class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = defaultdict(int)
        def gameplan(turn, idx, M):
            if idx >= n:
                return 0
            if (turn, idx, M) in dp:
                return dp[(turn, idx, M)]

            curr = 0

            if turn:
                res = 10**6
            else:
                res = 0

            for i in range(idx, min(idx+2*M, n)):
                if not turn:
                    curr += piles[i]
                    res = max(res, curr+gameplan(not turn, i+1, max(i-idx+1, M)))
                else:
                    res = min(res, gameplan(not turn, i+1, max(i-idx+1, M)))
            
            dp[(turn, idx, M)] = res
            return res

        return gameplan(False, 0, 1)