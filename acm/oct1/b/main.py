n, m = raw_input().split()
n = int(n)
m = int(m)

friends = []
relationships = []

i = 0
while i < n:
	friends.append(input())
	i += 1
	
i = 0
while i < m:
	x, y = raw_input().split()
	x = int(x)
	y = int(y)

	a = b = -1
	for j, arr in enumerate(relationships):
		if x in arr:
			a = j
		if y in arr:
			b = j

	if a != b:
		if a != -1 and b != -1:
			relationships[a] = relationships[a] + relationships[b]
			del relationships[b]
		elif a != -1:
			relationships[a].append(y)
		elif b != -1:
			relationships[b].append(x)
	elif a == -1:
		relationships.append([x, y])

	i += 1

for tuple in relationships:
	total = 0
	for friend in tuple:
		total += friends[friend]

	if total != 0:
		print "IMPOSSIBLE"
		exit()
	else:
		for friend in tuple:
			friends[friend] = 0

friends = [int(x) for x in friends]

if sum(friends)  == 0:
	print "POSSIBLE"
else:
	print "IMPOSSIBLE"




