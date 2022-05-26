
fin = open("isheap.in",  "r")
fout = open("isheap.out", "w")

length = int(fin.readline())

A =list(map(int, fin.readline().split()))
check = 0

for i in range(length):

	if 2*i+1<=length-1:
		if A[i]>A[2*i+1]:
			check+=1

	if (2*i+2)<=length-1:
		if A[i]>A[2*i+2]:
			check+=1

if check==0:
	fout.write("YES")
else:
	fout.write("NO")

fin.close()
fout.close()
