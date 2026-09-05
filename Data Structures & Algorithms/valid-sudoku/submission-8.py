class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        for r in range(len(board)):
            for c in range(len(board[0])):
                val = board[r][c]
                if val == '.':
                    continue
                
                mask = 1 << int(val)

                b = (r // 3) * 3 + (c // 3)
                
                if((rows[r] & mask) or (cols[c] & mask) or (boxes[b] & mask)):
                    return False
                
                rows[r] = rows[r] | mask
                cols[c] = cols[c] | mask
                boxes[b] = boxes[b] | mask

        
        return True