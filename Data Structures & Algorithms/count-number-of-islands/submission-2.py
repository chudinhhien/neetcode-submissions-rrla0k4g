class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        R, C = len(grid), len(grid[0])

        def is_valid(r:int , c: int) -> bool:
            return 0 <= r < R and 0 <= c < C and grid[r][c] != "0"

        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]

        def dfs(r: int, c: int):
            grid[r][c] = "0"
            for dr, dc in directions:
                if is_valid(r + dr, c + dc):
                    dfs(r + dr, c + dc)
            
        
        cnt = 0
        for r in range(R):
            for c in range(C):
                if grid[r][c] == "1":
                    dfs(r, c)
                    cnt = cnt + 1
        
        return cnt