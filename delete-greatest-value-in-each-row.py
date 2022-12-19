class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        res = 0
        for t in range(len(grid[0])):
            maxs = []
            for row in grid:
                m = max(row)
                maxs.append(m)
                row.remove(m)
            res += max(maxs)
        return res
