
N = int(input())
N_arr = [chr(i) for i in range(ord('a'),ord('a')+N)]
pattern = input()

prefix = [0]*(len(pattern)+1)
j = 0
i = 1

while i < len(pattern):

	if pattern[j]== pattern[i]:
		prefix[i+1]=j+1
		i+=1
		j+=1
		
	else:
		if j>0:
			j=prefix[j]
			
		else:
			prefix[i+1]=0
			i+=1

d = [[0 for j in range(N)] for i in range(len(pattern)+1)]

for i in range(len(pattern)+1):

	if i==len(pattern):
			d[i] = d[prefix[i]]
			break
	
	for j in range(N):

		if i>0 and N_arr[j] != pattern[i]:
			d[i][j] = d[prefix[i]][j]

		else:
			if N_arr[j] == pattern[i]:
				d[i][j] = i + 1
			else:
				d[i][j] = i

for i in range(len(d)):
	for j in range(len(d[i])):
		print(d[i][j], end=' ')
	print()
#input()