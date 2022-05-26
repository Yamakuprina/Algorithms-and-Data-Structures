
fin = open("search1.in",  "r")
fout = open("search1.out", "w")


pattern = fin.readline()
text = fin.readline()

M = len(pattern)
N = len(text)

places = []
count = 0

for i in range(N-M+2):
	if text[i:(i+M-1)] == pattern[0:-1]:
		places.append(i+1)
		count+=1


fout.write(str(count))
fout.write("\n")
for i in range(len(places)): 
	fout.write(str(places[i]))
	fout.write(" ")


fin.close()
fout.close()
