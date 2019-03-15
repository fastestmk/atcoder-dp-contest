import sys

n, w = map(int, input().split())
dp = [0]*(w+1)

for i in range(n):
	weight, value = map(int, input().split())

	for weight_cal in range(w-weight, -1, -1):
		dp[weight_cal+weight] = max(dp[weight_cal+weight], dp[weight_cal]+value)

ans = 0
for i in range(w+1):
	ans = max(ans, dp[i])

print(ans)	
