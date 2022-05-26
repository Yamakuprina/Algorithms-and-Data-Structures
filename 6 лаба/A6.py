
dictionary = {}

def hash1(x):
	h = x % 32
	return h

def insert(x):
	global dictionary
	dictionary[hash1(x)] = x

def exists(x):
	global dictionary
	if hash1(x) in dictionary:
		return "true"
	elif hash1(x) not in dictionary:
		return "false"

def delete(x):
	global dictionary
	del dictionary[hash1(x)];


fin = open("set.in",  "r")
fout = open("set.out", "w")

instruction = fin.read().splitlines()

for i in range(len(instruction)):

	if 'insert' in instruction[i]:

		inst = instruction[i].split()
		insert(int(inst[1]))

	elif 'exists' in instruction[i]:

		inst = instruction[i].split()
		fout.write(exists(int(inst[1])))
		fout.write("\n")

	elif 'delete' in instruction[i]:

		inst = instruction[i].split()
		delete(int(inst[1]))

fin.close()
fout.close()