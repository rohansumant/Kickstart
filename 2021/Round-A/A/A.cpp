#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  for(int TC=1;TC<=t;TC++) {
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
    int goodness = 0;
    for(int i=0;i<n/2;i++) {
      goodness += s[i] != s[n-i-1];
    }
    printf("Case #%d: %d\n",TC,abs(goodness-k));
  }
  return 0;
}
