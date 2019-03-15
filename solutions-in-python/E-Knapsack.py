import sys

INF = (10**9)+5

n, w = map(int, input().split())
weight = []*n
value = []*n
for i in range(n):
	wt, val = map(int, input().split())
	weight.append(wt)
	value.append(val)

sum_value = 0
for x in value:
	sum_value += x

dp = [INF]*(sum_value+1)	
dp[0] = 0

for i in range(n):
	for value_cal in range(sum_value-value[i], -1, -1):
		dp[value_cal+value[i]] = min(dp[value_cal+value[i]], dp[value_cal]+weight[i]) 

ans = 0
for i in range(sum_value+1):
	if dp[i] <= w:
		ans = max(ans, i)

print(ans)			