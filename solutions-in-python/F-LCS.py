dp = [[0]*3005]*3005 # arr = [[0]*cols]*rows 

s = str(input())
t = str(input())

for i in range(1, len(s)+1):
	for j in range(1, len(t)+1):
		if s[i-1] == t[j-1]:
			dp[i][j] = dp[i-1][j-1]+1
		else:
			dp[i][j] = max(dp[i-1][j], dp[i][j-1])

# print(dp[len(s)][len(t)])

i, j = (len(s), len(t))
ans = ""

while i >= 1 and j >= 1:
	if s[i-1] == t[j-1]:
		ans = s[i-1] + ans
		i -= 1
		j -= 1	
		continue
	if dp[i-1][j] > dp[i][j-1]:
		i -= 1
	else:
		j -= 1

print(ans)					

