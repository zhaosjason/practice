cases = input()
i = 0
while i < cases:
	num = input()
	arr = [1,1,2,4]
	j = 4
	while j <= num:
		arr.append(arr[j-1] + arr[j-2] + arr[j-3] + arr[j-4])
		j += 1

	print arr[num]

	i += 1