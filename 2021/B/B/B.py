import sys

input = sys.stdin.readline


def print_ans(num,x):
    print('Case #{}: {}'.format(num,x))


def solve(test_case):
    n = int(input())

    a = [i for i in map(int,input().split())]

    if n <= 3:
        print_ans(test_case,n)
        return

    b = [a[i]-a[i-1] for i in range(1,n)]
    c, d = b[:], b[:]
    for i in range(len(c)):
        if i == 0 or b[i] != b[i-1]:
            c[i] = i
        else:
            c[i] = c[i-1]

    for i in range(n-2,-1,-1):
        if i == n-2 or b[i] != b[i+1]:
            d[i] = i
        else:
            d[i] = d[i+1]
        assert(d[i] >= c[i])

    #print(b,c,d)
    def get(ix):
        if ix < 0 or ix >= len(b):
            return int(2e9)
        return b[ix]

    ans = d[0]-c[0]+3
    for i in range(1,n-1):
        ans = max(ans,d[i]-c[i]+3)
        if abs(b[i-1]+b[i])%2 == 0:
            curr = (b[i-1]+b[i])//2
            if curr == get(i-2) and curr == get(i+1):
                ans = max(ans,d[i+1]-c[i-2]+2)
            elif curr == get(i+1):
                ans = max(ans,d[i+1]-(i-1)+2)
            elif curr == get(i-2):
                ans = max(ans,i-c[i-2]+2)
    ans = min(ans,n)
    print_ans(test_case,ans)


def main():
    for i in range(int(input())):
        solve(i+1)


main()
