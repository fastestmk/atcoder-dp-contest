from collections import defaultdict

INF = (10**5)+5

graph = defaultdict(list)
vis = [0]*INF
dp = [0]*INF

def dfs(s):
    if vis[s]:
        return dp[s]    
    vis[s] = 1
    for i in graph[s]:
        dp[s] = max(dp[s], dfs(i)+1)

    return dp[s]    

if __name__ == "__main__":
                            
    n, m = map(int, input().split())
    for i in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)

    ans = 0
    for i in range(1, n+1):
        ans = max(ans, dfs(i))

    print(ans)  