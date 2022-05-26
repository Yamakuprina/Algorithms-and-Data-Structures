
fin = open("search2.in",  "r")
fout = open("search2.out", "w")

pattern = list(fin.readline())
pattern.remove('\n')
pattern = ''.join(map(str, pattern))
text = fin.readline()

def z_func(s):
	z = [0] * len(s)
	left, right = 0, 0
	for i in range(1, len(s)):
		z[i] = max(0, min(z[i - left], right - i))
		while i + z[i] < len(s) and s[z[i]] == s[i + z[i]]:
			z[i] += 1
		if i + z[i] > right:
			left, right = i, i + z[i]
	return z

M = len(pattern)
N = len(text)

answer = []

prep = pattern + '#' + text
z = z_func(prep)
i = M+1
while i < N+2:
	if z[i]==M:
		answer.append(i-M)
	i+=1

fout.write(str(len(answer)))
fout.write("\n")
for i in range(len(answer)): 
	fout.write(str(answer[i]))
	fout.write(" ")

fin.close()
fout.close()