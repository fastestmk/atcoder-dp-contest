mod = 10**9+7

h, w = map(int, input().split())
s = [input() for i in range(h)]
paths = [[0 for x in range(w)] for y in range(h)] 
paths[0][0] = 1

for i in range(1, h):
	if s[i][0] == '.':
		paths[i][0] = paths[i-1][0]

for j in range(1, w):
	if s[0][j] == '.':
		paths[0][j] = paths[0][j-1]

for i in range(1, h):
	for j in range(1, w):
		if s[i][j] == '.':
			paths[i][j] = paths[i][j-1]+paths[i-1][j]
			if(paths[i][j] >= mod):
				paths[i][j] -= mod;

print(paths[h-1][w-1])
	