#include <bits/stdc++.h>
using namespace std;

void solve(int TC) {
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int ans = 2;
  for(int i=0,j;i<n-1;i=j-1) {
    j = i+1;
    int diff = a[j] - a[i];
    while(j < n && (a[j] == a[j-1] + diff)) j++;
    ans = max(ans,j-i);
  }
  printf("Case #%d: %d\n",TC,ans);
}
  
int main() {
  int TC; cin >> TC;
  for(int i=1;i<=TC;i++) solve(i);
}
