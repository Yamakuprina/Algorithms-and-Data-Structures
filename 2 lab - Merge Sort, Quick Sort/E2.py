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


fin = open("kth.in",  "r")
fout = open("kth.out", "w")

Array = []
Input_nums = list(map(int, fin.read().split()))
N, K, A, B, C = Input_nums[0], Input_nums[1], Input_nums[2], Input_nums[3], Input_nums[4]
Array.append(Input_nums[5])
Array.append(Input_nums[6])

for i in range(2, N):

	Next_num = bytearray(((A*Array[i-2] + B*Array[i-1] + C).to_bytes(32, byteorder='little', signed=True)))
	print(Next_num)
	Array.append(int.from_bytes(Next_num[0:5], byteorder='little', signed=True))


print(Array)






input()
fin.close()
fout.close()
