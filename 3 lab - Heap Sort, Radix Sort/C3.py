
fin = open("radixsort.in",  "r")
fout = open("radixsort.out", "w")

info = list(map(int, fin.readline().split()))

A=[]
for i in range(info[0]):
	A.append(fin.readline().split()[0])

Alphabet=list('abcdefghijklmnopqrstuvwxyz')


for i in range(1,info[2]+1):

	B = [[] for k in range(len(Alphabet))]

	for x in A:
		figure = x[-i]
		B[Alphabet.index(figure)].append(x)

	A = []
	for k in range(len(Alphabet)):
		A = A + B[k]

for i in range(info[0]): 
	fout.write(str(A[i]))
	fout.write('\n')

fin.close()
fout.close()