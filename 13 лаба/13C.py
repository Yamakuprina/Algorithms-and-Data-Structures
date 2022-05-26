
fin = open("prefix.in",  "r")
fout = open("prefix.out", "w")

pattern = fin.readline()

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
			
#print(prefix)	

for i in range(1, len(prefix)): 
	fout.write(str(prefix[i]))
	if i!=len(prefix)-1:
		fout.write(" ")	

#input()
fin.close()
fout.close()