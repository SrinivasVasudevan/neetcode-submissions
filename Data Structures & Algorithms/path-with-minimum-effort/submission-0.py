class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        minHeap = []
        M, N = len(heights), len(heights[0])
        minEffortDiff = 0
        # dijkstra

        dirs = [(-1,0), (0,-1), (1,0), (0,1)]
        heapq.heappush(minHeap, (0, (0,0)))
        visited = set()

        while minHeap:
            cost, (x, y) = heapq.heappop(minHeap)
            #print((x,y), cost)
            minEffortDiff = max(cost, minEffortDiff)
            visited.add((x, y))
            if x == M-1 and y == N-1:
                return minEffortDiff

            for dir in dirs:
                newX, newY = dir
                newX += x
                newY += y
                if newX >= 0 and newY >=0 and newX < M and newY < N and (newX, newY) not in visited:
                    heapq.heappush(minHeap, (abs(heights[x][y] - heights[newX][newY]), (newX, newY)))


        return -1
                
        