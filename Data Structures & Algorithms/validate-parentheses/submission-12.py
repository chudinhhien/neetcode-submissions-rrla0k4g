class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else:
                if len(stack) > 0:
                    tmp = stack[-1]
                    print(tmp)
                    print()
                    if (tmp == '(' and c == ')') or (tmp == '[' and c == ']') or (tmp == '{' and c == '}'):
                        stack.pop()
                    else:
                        return False
                else:
                    return False

        
        print(len(stack))

        if len(stack) > 0: return False    
        
        return True