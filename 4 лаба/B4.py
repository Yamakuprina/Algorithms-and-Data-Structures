
stack = []

def insert(x):
	global stack
	stack.append(x)

def extract():
	global stack
	last = stack[0]
	stack.pop(0)
	return last


fin = open("queue.in",  "r")
fout = open("queue.out", "w")

instruction = fin.read().splitlines()

for i in range(int(instruction[0])):

	if '+' in instruction[i+1]:

		inst = instruction[i+1].split()
		insert(inst[1])

	elif '-' in instruction[i+1]:

		last = extract()
		fout.write(str(last))
		fout.write('\n')

fin.close()
fout.close()