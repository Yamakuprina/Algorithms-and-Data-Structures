

def quick_sort(nums, fst, lst):
   if fst >= lst: return
 
   i, j = fst, lst
   pivot = nums[random.randint(fst, lst)]
 
   while i <= j:
       while nums[i] < pivot: i += 1
       while nums[j] > pivot: j -= 1
       if i <= j:
           nums[i], nums[j] = nums[j], nums[i]
           i, j = i + 1, j - 1
   quick_sort(nums, fst, j)
   quick_sort(nums, i, lst)




fin = open("race.in",  "r")
fout = open("race.out", "w")

num = int(fin.readline())

A=[]
for i in range(num):
	A.append(fin.readline().split())


B=[]
B.append(A[0])


for i in range(1, num):

	if A[i][0] in [element for inner_list in B for element in inner_list]:
		B[[B[j][0] for j in range(len(B))].index(A[i][0])].append(A[i][1])
	else:
		B.append(A[i])


quick_sort(B,0,len(B)-1)


"""
for i in range(len(B)):
    for j in range(i + 1, len(B)):
        if B[i][0] > B[j][0]:
            B[i], B[j] = B[j], B[i]

"""


for i in range(len(B)):

	fout.write("=== ")
	fout.write(B[i][0])
	fout.write(" ===\n")

	for j in range(len(B[i])-1):
		fout.write(B[i][j+1])

		if i==len(B)-1 and j==len(B[i])-2:
			continue
		else:
			fout.write("\n")

fin.close()
fout.close()
