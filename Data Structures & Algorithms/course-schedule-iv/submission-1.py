class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        indegree = [0]*numCourses
        #topo = []
        prereq = defaultdict(set)
        adj_map = defaultdict(list)

        for [parent, node] in prerequisites:
            indegree[node]+=1
            adj_map[parent].append(node)
        
        q = deque()
        
        for i, deg in enumerate(indegree):
            if deg == 0:
                q.append(i)
    
        while q:
            node = q.popleft()
            for adj in adj_map[node]:
                indegree[adj]-=1
                prereq[adj].add(node)
                if node in prereq:
                    prereq[adj] |= prereq[node]

                if indegree[adj] == 0:
                    q.append(adj)
        res = []
        
        for [p, n] in queries:
            res.append(p in prereq[n])

        return res

