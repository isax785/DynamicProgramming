def unique_paths(m:int, n:int):
    dp = [[0 for _ in range(n+1)] for __ in range(m+1)]
    dp[0][1] = 1
    for i in range(1, m+1):
        for j in range(1, n+1):
            dp[i][j] = dp[i][j-1] + dp[i-1][j]
    return dp[m][n]