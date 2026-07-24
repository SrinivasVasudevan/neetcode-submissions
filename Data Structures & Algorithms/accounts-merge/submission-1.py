class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        uindex = 0
        adj_map = defaultdict(set)
        parent = {}
        for account in accounts:
            for node, adj_node in pairwise(account[1:]):
                adj_map[node].add(adj_node)
                adj_map[adj_node].add(node)
                parent[node] = account[0]
                parent[adj_node] = account[0]

            if len(account[1:]) % 2 != 0:
                if account[1:][-1] not in adj_map:
                    parent[account[1:][-1]] = account[0]
                    adj_map[account[1:][-1]] = set()

        visited = set()

        print(adj_map)

        def dfs(node):
            visited.add(node)
            res = []
            for adj_node in adj_map[node]:
                if not adj_node in visited:
                    res += [adj_node] + dfs(adj_node)

            return res

        res = []
        for node in adj_map.keys():
            if not node in visited:
                res.append([parent[node]] + sorted([node] + dfs(node)))
        print(res)
        return res
            

        