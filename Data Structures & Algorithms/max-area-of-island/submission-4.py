class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        R, C = len(grid), len(grid[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def dfs(r: int, c: int) -> int:
            # 1. Đánh dấu ô hiện tại đã thăm ngay lập tức
            grid[r][c] = 0
            area = 1

            # 2. Lan sang 4 hướng
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                # Kiểm tra nằm trong ma trận và là đất liền
                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 1:
                    area += dfs(nr, nc)

            return area

        max_area = 0
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:
                    max_area = max(max_area, dfs(r, c))

        return max_area