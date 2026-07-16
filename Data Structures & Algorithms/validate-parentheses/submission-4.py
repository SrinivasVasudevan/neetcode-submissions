class Solution:
    def isValid(self, s: str) -> bool:
        st = deque()

        for char in s:
            if char == '[' or char == '(' or char == '{':
                st.append(char)
            elif len(st) == 0:
                return False
            else:
                if char == ']' and st[-1] == '[':
                    st.pop()
                elif char == '}' and st[-1] == '{':
                    st.pop()
                elif char == ')' and st[-1] == '(':
                    st.pop()
                else:
                    return False
            
        return len(st) == 0
        