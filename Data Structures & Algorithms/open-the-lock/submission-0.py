class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        visited = set()
        if '0000' in deadends:
            return -1
        q = deque()
        q.append(('0000', 0))
        visited.add('0000')

        while q:
            comb, step = q.popleft()
            
            if comb == target:
                return step

            for i in range(4):
                for j in [-1,1]:
                    #print(i)
                    newcomb = comb[:i] + str((int(comb[i]) + j) % 10) + comb[i+1:]
                    if newcomb in visited or newcomb in deadends:
                        continue

                    visited.add(newcomb)
                    q.append((newcomb, step+1))


        return -1

        