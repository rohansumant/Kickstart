#include <bits/stdc++.h>
using namespace std;

void solve(int TC) {
    int n, limit; cin >> n >> limit;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        b[i] = i;
    }
    stable_sort(b.begin(),b.end(),[&](int x,int y) {
       int cnt_x = a[x]/limit + (a[x]%limit ? 1:0);
       int cnt_y = a[y]/limit + (a[y]%limit ? 1:0);
       return cnt_x < cnt_y;
    });
    
    printf("Case #%d: ",TC);
    for(int i: b) {
        printf("%d ",i+1);
    }
    printf("\n");
}

int main() {
    int t = 0;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
