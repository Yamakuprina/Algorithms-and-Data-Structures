
fin = open("prefix.in",  "r")
fout = open("prefix.out", "w")

pattern = fin.readline()

prefix = [0]*(len(pattern))
j = 0
i = 1

for i in range(1,len(pattern)):
	j = prefix[i-1]
	while j > 0 and pattern[j] != pattern[i]:
		j = prefix[j-1]
	if pattern[j] == pattern[i]:
		j += 1
	prefix[i] = j

for i in range(len(prefix)): 
	fout.write(str(prefix[i]))
	fout.write(" ")	

fin.close()
fout.close()