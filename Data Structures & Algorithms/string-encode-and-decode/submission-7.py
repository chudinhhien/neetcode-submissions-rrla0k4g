class Solution:

    def encode(self, strs: List[str]) -> str:
        part = []
        for s in strs:
            part.append(f"{len(s)}#{s}")
        return "".join(part)

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            j = s.find('#', i)
            length = int(s[i:j])
            res.append(s[j+1:j+length+1])
            i = j + 1 + length
        
        return res
            