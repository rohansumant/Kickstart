#include <bits/stdc++.h>
using namespace std;

void solve(int _TC) {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> ans(n);
  for(int i=0;i<n;i++) {
    int len = 0, prev = 'Z'+1;
    for(int j=i;j>=0 && s[j] < prev;j--) {
      len++;
      prev = s[j];
    }
    ans[i] = len;
  }
  printf("Case #%d: ",_TC);
  for(int i: ans) printf("%d ",i);
  printf("\n");
}

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
