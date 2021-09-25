#include <bits/stdc++.h>
using namespace std;

void solve(int TC) {
  int n,k;
  cin >> n >> k;
  vector<pair<int,int>> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(),a.end());
  int ans = 0;
  int end = -1;
  for(int j,i=0;i<n;i=j) {
    int begin = max(end,a[i].first); 
    int len = a[i].second - begin;
    int cnt = (len/k) + (len%k ? 1:0);
    end = begin + cnt*k;
    ans += cnt;
    j = i;
    while(j < n && a[j].second <= end) j++;
  }
  printf("Case #%d: %d\n",TC,ans);
}

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
