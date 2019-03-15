INF = (10**9)+5

n, k = map(int, input().split())
height = []*n 

height = list(map(int, input().split()))

dp = [INF]*n # initializing dp with INF with size of n
dp[0] = 0

for i in range(n):
	for j in range(i+1, i+k+1):
		if j < n:
			dp[j] = min(dp[j], dp[i] + abs(height[i]-height[j]))

print(dp[n-1])			
