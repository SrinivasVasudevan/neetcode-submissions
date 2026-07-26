class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        prob = [0]*n
        maxHeap = []
        adj_map = defaultdict(list)

        for i, [u, v] in enumerate(edges):
            adj_map[u].append((succProb[i], v))
            adj_map[v].append((succProb[i], u))

        heapq.heappush_max(maxHeap, (1, start_node))

        while maxHeap:
            p, node = heapq.heappop_max(maxHeap)
            print(p, node)
            if p < prob[node]:
                continue
    
            if node == end_node:
                return p
                break

            for adjp, adj in adj_map[node]:
                if adjp * p > prob[adj]:
                    prob[adj] = adjp * p
                    heapq.heappush_max(maxHeap, (adjp * p, adj))
        
                
        return 0



        