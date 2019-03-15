INF = (10**9)+5

n = int(input())

dp = [0]*3
for day in range(n):
	new_dp = [0]*3 # initialize with 0 of size 3
	act = []*3

	act = list(map(int, input().split()))

	for i in range(3):
		for j in range(3):
			if i != j:
				new_dp[j] = max(new_dp[j], dp[i]+act[j]) # avoiding consecutive activities

	dp = new_dp			

print(max(dp[0], max(dp[1], dp[2])))	

