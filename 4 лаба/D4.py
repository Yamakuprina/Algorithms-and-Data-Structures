
stack = []

def insert(x):
	global stack
	stack.append(x)

def extract():
	global stack
	last = stack[-1]
	stack.pop(-1)
	return last

fin = open("postfix.in",  "r")
fout = open("postfix.out", "w")

A =list(fin.readline().split())

for i in A:

	if i in '+-*':
		b = extract()
		a = extract()
		if i =='+':
			result = a+b
		elif i =='-':
			result = a-b
		else:
			result = a*b

		insert(result)
	else:
		insert(int(i))

fout.write(str(stack[0]))

fin.close()
fout.close()