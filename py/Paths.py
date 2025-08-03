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