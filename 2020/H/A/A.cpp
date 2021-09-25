#include <bits/stdc++.h>
using namespace std;

void solve(int TC) {
  long long n,k,s; cin >> n >> k >> s;
  long long ans = k-1 + n+1;
  ans = min(ans,k-1 + k-s + n-s+1);
  printf("Case #%d: %lld\n",TC,ans);
}

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
