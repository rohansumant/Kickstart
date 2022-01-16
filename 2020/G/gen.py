from random import randint

tc = 100
print(tc)
for i in range(tc):
    w = randint(1,100)
    n = randint(1,1000)
    print(w,n)
    a = []
    for i in range(w):
        a.append(randint(1,n))
    print(' '.join(map(str,a)))



