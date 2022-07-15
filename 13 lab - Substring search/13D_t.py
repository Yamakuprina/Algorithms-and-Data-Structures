
# p =  "abaab"

# def suffix(x):
# 	# x = "aaab"
# 	i = 0
# 	j = len(x)-1

# 	count = 0

# 	while j >= 0:

# 		if p[:i+1]==x[j:]:
# 			count = len(p[:i+1])
	
# 		i+=1
# 		j-=1

# 	return count


# print(suffix("aaab"))
# i+=1
# j-=1
# print(p)
# print(p[:i+1])
# print(x)
# print(x[j:])
# print(count)


N = 2#int(input())
N_arr = [chr(i) for i in range(ord('a'),ord('a')+N)]
pattern = "abaab"#input()

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

# for i in range(1,len(pattern)):
# 	j = prefix[i-1]
# 	while j > 0 and pattern[j] != pattern[i]:
# 		j = prefix[j-1]
# 	if pattern[j] == pattern[i]:
# 		j += 1
# 	prefix[i] = j

d = [[0 for j in range(N)] for i in range(len(pattern)+1)]

# for i in range(len(pattern)):
# 	for j in range(N):
# 		if i > 0 and N_arr[j] != pattern[i]:
# 			d[i][j] = d[prefix[i-1]][j]
# 		if N_arr[j] == pattern[i]:
# 			d[i][j] = i + 1
# 		else:
# 			d[i][j] = i

# for (int i = 0; i < strLen + 1; i++) {
#         for (int j = 0; j < capacity; j++) {
#             if (i > 0 && j + 'a' != str[i]) {
#                 kmp[i][j] = kmp[prefix[i - 1]][j];
#             } else {
#                 kmp[i][j] = i + (j + 'a' == str[i]);
#             }
#         }
#     }
i=0
j=0

for i in range(len(pattern)+1):
	

	#print(prefix)
	for j in range(N):
		#print("NAH")
		if i==len(pattern):
			#print(d[prefix[i]])
			d[i][j] = d[prefix[i]][j]
			break
		if i>0 and N_arr[j] != pattern[i]:
			#print(i)
			#print(j)
			#print(d[prefix[i]][j])
			d[i][j] = d[prefix[i]][j]
			#print("WATAFUCK")
		else:
			if N_arr[j] == pattern[i]:
				d[i][j] = i + 1
			else:
				d[i][j] = i
	#print(d)
print(d)

input()