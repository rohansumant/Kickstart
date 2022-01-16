from itertools import accumulate
from collections import Counter
import sys

input = sys.stdin.readline

def solve(TC):
    w, n = map(int,input().split())
    freq = Counter(map(int,input().split()))
    a = [(k,freq[k]) for k in freq]
    ans = w * (n//2)
    ##print(a)
    for i in range(len(a)):
        curr = 0
        for j in range(len(a)):
            if i == j:
                continue
            dist = abs(a[i][0]-a[j][0])
            dist = min(dist, n - dist)
            curr += dist*a[j][1]
        ans = min(ans, curr)
    print('Case #{}: {}'.format(TC,ans))

def upsolve(TC):
    w, N = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    pre = list(accumulate(a,lambda x,y: x+y))
    #print(a,pre)
    ans = w * (N//2)
    def get(l,r):
        if r < l:
            return 0
        return (pre[r] if l == 0 else pre[r] - pre[l-1])

    for i in range(w):
        curr = 0
        l, r = -1, i
        #print('i: ',i)
        while l+1 < r:
            mid = (l+r)//2
            if a[i]-a[mid] <= N-a[i]+a[mid]:
                r = mid
            else:
                l = mid
        #print('r: ',r)
        curr += (a[i]*(i-r+1) - get(r,i))
        curr += ((N+a[i])*(r) - get(0,r-1))

        l, r = i, w
        while l < r-1:
            mid = (l+r)//2
            if a[mid]-a[i] <= N-a[mid]+a[i]:
                l = mid
            else:
                r = mid
        #print('l: ',l)
        curr += (get(i,l) - a[i]*(l-i+1))
        curr += (-get(l+1,w-1) + (N+a[i])*(w-l-1))
        #print(curr)


        ans = min(ans,curr)

    print('Case #{}: {}'.format(TC,ans))


def main():
    for i in range(1,int(input())+1):
        solve(i)
        #upsolve(i)

main()
