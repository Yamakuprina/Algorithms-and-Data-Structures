
fin = open("garland.in",  "r")
fout = open("garland.out", "w")

our_input =list(fin.readline().split())

N = int(our_input[0])
A = float(our_input[1])

garland = [0]*N
garland[0] = A

left = 0
right = A

while right-left > 0.0000000001:

    garland[1] = (left + right) / 2
    Above_Ground = True
    
    for i in range(2,N):

        garland[i]=2*garland[i-1]-garland[i-2]+2

        if garland[i]<0:
            Above_Ground = False
            break

    if Above_Ground:
        right = garland[1]
    else:
        left = garland[1]

fout.write(str(round(garland[-1],2)))
fin.close()
fout.close()