class Solution:
    def count_sort(self, val):
        char_map = [0]*26
        for c in val:
            char_map[ord(c)-ord('a')] += 1
        
        key=[]
        for c, v in enumerate(char_map):
            key.append(chr(ord('a')+c)*v)
        return ''.join(key)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        res = []
        for i, ana in enumerate(strs):
            k = self.count_sort(ana)
            mp[''.join(k)].append(ana)
            

        for k, v in mp.items():
            res.append(v)

        return res

        