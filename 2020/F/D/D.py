from functools import lru_cache
import sys

input = sys.stdin.readline

@lru_cache(maxsize=None)
def rolls_needed(p):
    #print('rn: {}'.format(p))
    assert(p >= 0 and p <= 1)
    ans, q = 0, 1
    for i in range(1,100):
        ans += i*p*q
        q *= (1-p)
    return ans


def solve(TC):
    n,m,k = map(int,input().split())
    assert(n <= 6 and m <= 6)
    arr = []
    for _ in range(k):
        arr.append(int(input()))
    arr.sort(reverse=True)
    #print(arr)
    
    #vis = {}
    def go(a):
        #print(a)
        for i in range(1,k):
            assert(a[i-1] >= a[i])

       # xx = str(a)
       # if xx in vis:
       #     return vis[xx]

        ls, nls = [], []
        counter = [0]*(n+1)
        for i in range(k):
            counter[a[i]] += 1
            if (not i or a[i-1] > a[i]):
                if a[i] < arr[i]:
                    ls.append(i)
                else:
                    nls.append(i)


        face_options = sum([counter[a[i]] for i in ls])
        if counter[0]:
            face_options = m - sum([counter[a[i]] for i in nls])

        ans = rolls_needed(face_options/m)
        #print(a,ans)


        runsum = 0
        for i in ls:
            curr = a[i]
            if curr:
                prob = counter[a[i]]/face_options
                runsum += counter[a[i]]
            else:
                prob = (face_options-runsum)/face_options
            assert(a[i] < arr[i])
            a[i] += 1
            #print('asd',face_options,prob,a)
            ans += prob*go(a)
            a[i] -= 1

        #vis[xx] = ans
        return ans


#        i = start
#        runsum = 0
#        while i < k:
#            curr_val = a[i]
#            j = i+1
#            while j < k and a[j] == a[i]:
#                j += 1
#            count = j-i
#            if curr_val == 0:
#                prob = (face_options - runsum)/face_options
#            else:
#                prob = count/face_options
#                runsum += count
#            a[i] += 1
#            ans += prob*go(a)
#            a[i] -= 1
#            i = j

        #vis[xx] = ans
        return ans

    ans = go([0]*k)
    print('Case #{}: {}'.format(TC,ans))

def main():
    for i in range(1,int(input())+1):
        solve(i)

main()
