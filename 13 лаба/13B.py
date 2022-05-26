
fin = open("search2.in",  "r")
fout = open("search2.out", "w")

pattern = list(fin.readline())
pattern.remove('\n')
text = list(fin.readline())

M = len(pattern)
N = len(text)

Hash_pattern = 0

k=31
m = k**M
mod = 1e3+7

for c in pattern:
	x = (ord(c) - ord('a')+1)
	Hash_pattern = (Hash_pattern*k + x) % mod


Hash = [0 for i in range(N-M+1)]

for c in text[:M]:
	x = (ord(c) - ord('a')+1)
	Hash[0] = (Hash[0]*k + x) % mod


for i in range(N-M):
	Hash[i+1] = (Hash[i]*k - (m*(ord(text[i])-ord('a')+1)) + (ord(text[i+M])-ord('a')+1)) % mod

places = []
count = 0

for i in range(N-M+1):
	if Hash[i]!=Hash_pattern:
		continue
	check = 1
	for j in range(M):
		if text[i+j]!=pattern[j]:
			check = 0
			break
	if check:
		places.append(i+1)
		count+=1

fout.write(str(count))
fout.write("\n")
for i in range(len(places)): 
	fout.write(str(places[i]))
	fout.write(" ")

fout.write("\n")
for i in range(len(Hash)): 
	fout.write(str(Hash[i]))
	fout.write(" ")

fout.write("\n")
fout.write(str(ord('b') - ord('a')))
fin.close()
fout.close()