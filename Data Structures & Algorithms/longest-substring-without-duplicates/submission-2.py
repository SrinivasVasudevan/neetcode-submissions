class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        location_map = defaultdict(int)
        longest_seq = 0
        last_index = -1
        for idx, char in enumerate(s):
            if char in location_map:
                last_index = max(last_index, location_map[char])
                
            longest_seq = max(longest_seq, idx - last_index)
            location_map[char] = idx

        return longest_seq

        