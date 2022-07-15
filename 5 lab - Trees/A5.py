

fin = open("height.in",  "r")
fout = open("height.out", "w")


instructions = fin.read().splitlines()
A=[]

for i in range(len(instructions)):
	instructions[i] = list(map(int, instructions[i].split()))


'''
for i in range(int(instruction[0])):

	if '+' in instruction[i+1]:

		inst = instruction[i+1].split()
		insert(inst[1])

	elif '-' in instruction[i+1]:

		last = extract()
		fout.write(str(last))
		fout.write('\n')
'''
print(instructions)
print(A)

input()
fin.close()
fout.close()