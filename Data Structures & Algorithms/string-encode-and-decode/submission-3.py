class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0: return ""
        ret_val = "#"+";".join(strs)
        return ret_val

    def decode(self, s: str) -> List[str]:
        if s == "": return []
        return s[1:].split(';')
