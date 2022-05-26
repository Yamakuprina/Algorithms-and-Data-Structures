import random


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


fin = open("sort.in",  "r")
fout = open("sort.out", "w")

length = int(fin.readline())

A =list(map(int, fin.readline().split()))

quick_sort(A,0,length-1)

for i in range(length): 
	fout.write(str(A[i]))
	fout.write(" ")

fin.close()
fout.close()
