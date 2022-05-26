import random

def quick_sort(nums, nums2, fst, lst):
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

print(A)
quick_sort(A, [j for j in range(len(A))], 0, len(A)-1)
print(A)

countrie = A[0][0]
fout.write("=== ")
fout.write(A[0][0])
fout.write(" ===\n")


for i in range(len(A)):

	if A[i][0] == countrie:
		fout.write(A[i][1])
		fout.write("\n")
	else:
		fout.write("=== ")
		fout.write(A[i][0])
		fout.write(" ===\n")
		fout.write(A[i][1])
		fout.write("\n")
		countrie = A[i][0]


input()
fin.close()
fout.close()
