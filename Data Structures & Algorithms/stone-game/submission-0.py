class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        piletotal = sum(piles)
        dp = defaultdict(int)
        def gameplan(turn, l, r):
            if r < l:
                return 0
            if (turn, l ,r) in dp:
                return dp[(turn,l,r)]
            res = 0
            
            if turn:
                res = max(piles[l] + gameplan(False, l+1, r), piles[r] + gameplan(False, l, r-1))
            else:
                res = min(gameplan(True, l+1, r), gameplan(True, l, r-1))
            
            dp[(turn, l, r)] = res
            return res
        
        alice_best = gameplan(True, 0, len(piles)-1)
        bob_best = piletotal - alice_best
        return alice_best > bob_best
        

        