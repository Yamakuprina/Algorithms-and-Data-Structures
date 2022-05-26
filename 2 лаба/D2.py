
fin = open("antiqs.in",  "r")
fout = open("antiqs.out", "w")

N = int(fin.readline())
A = [i for i in range(1,N+1)]


for i in range(N):
	A[i], A[i//2] = A[i//2], A[i]
	print(A)
	


for i in range(N): 
	fout.write(str(A[i]))
	fout.write(" ")

print(A)


input()
fin.close()
fout.close()
