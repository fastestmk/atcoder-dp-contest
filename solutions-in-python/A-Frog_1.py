
inf = (10**9)+5

n = int(input())
height = []*n


height = list(map(int, input().split()))
	

dp = [inf]*n
dp[0] = 0

for i in range(n):
	j = i+1
	if j < n:
		dp[j] = min(dp[j], dp[i] + abs(height[i]-height[j]))
	j = i+2
	if j < n:
		dp[j] = min(dp[j], dp[i] + abs(height[i]-height[j]))

print(dp[n-1])		