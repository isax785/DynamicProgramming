def unique_paths(m:int, n:int, DEBUG:bool=False) -> list[list[int]]:
    dp = [[0 for _ in range(n+1)] for __ in range(m+1)]
    dp[0][1] = 1
    for i in range(1, m+1):
        for j in range(1, n+1):
            dp[i][j] = dp[i][j-1] + dp[i-1][j]
    if DEBUG: 
        for row in dp:
            print(row)
    return dp[m][n]

def unique_paths_recursion(m:int, n:int):
    if m == 0 or n == 0: return 0
    if m == 1 and n == 1: return 1
    return unique_paths_recursion(m, n-1) + unique_paths_recursion(m-1, n)

def unique_paths_memo(m:int, n:int, memo:dict={}):
    if memo.get((m,n)): return memo[(m,n)]
    if m == 0 or n == 0: return 0
    if m == 1 and n == 1: return 1
    memo[(m,n)] = unique_paths_recursion(m, n-1) + unique_paths_recursion(m-1, n)
    return memo[(m,n)]


def unique_paths_obstacles(grid:list[list[int]]):
    m, n = len(grid), len(grid[0])
    if m == 0 or n == 0: return 0
    dp = [[0 for _ in range(n+1)] for __ in range(m+1)]
    dp[0][0] = 0 if grid[0][0]==1 else 1
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                dp[i][j] = 0
                continue
            if i - 1 >= 0:
                dp[i][j] += dp[i-1][j] * (1 if grid[i-1][j] != 1 else 0)
            if j - 1 >= 0:
                dp[i][j] += dp[i][j-1] * (1 if grid[i][j-1] != 1 else 0)
    return dp[m-1][n-1] 


def min_path_sum(grid:list[list[int]]) -> int:
    pass
    
def climb_stairs(n:int) -> int:
    s1, s2 = 1, 2
    for i in range(2, n):
        s1 = s1 + s2
        # swap(s1, s2)
        temp = s1
        s1 = s2
        s2 = temp
    return s2 if n>= 2 else s1

    