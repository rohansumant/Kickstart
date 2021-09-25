t = int(input())

def fn(s, n, step, ans):
    if step == 1:
        rng = range(0,n)
    else:
        rng = range(n-1,-1,step)
    prev = -2*n if step == 1 else 2*n
    for i in rng:
        if s[i] == '1':
            ans[i] = 0
            prev = i
        else:
            ans[i] = min(ans[i], abs(i-prev))

for test_case in range(t):
    n = int(input())
    s = input()
    ans = [2*n]*n
    for step in [1,-1]:
        fn(s,n,step,ans)
    print('Case #{}: {}'.format(test_case+1, sum(ans)))
    '''
    print('Case #{}: {}'.format(test_case+1,
            ''.join(map(str,ans))))
    '''
