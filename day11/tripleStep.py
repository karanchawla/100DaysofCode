#
def tripleStep(x):
	if x<0:
		return 0
	if x==0:
		return 1
	if x==1:
		return 1
	if x>1:
		return tripleStep(x-1) + tripleStep(x-2) + tripleStep(x-3)


# Using memoization

def optimizedTripleStep(x):
	memo = [-1]*(x+1)
	return tripleHopOptimized(x, memo)

def tripleHopOptimized(x, memo):
	if x<0:
		return 0
	memo[0] = 1
	memo[1] = 1
	memo[2] = memo[1] + memo[0]
	if x>2:
		for i in range(3, x+1):
			memo[i] = memo[i-1] + memo[i-2] + memo[i-3]
	return memo[x]

# print tripleStep(2)
print optimizedTripleStep(24)