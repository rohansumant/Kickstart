#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    for(int i=n-1; i >= 0; i--) {
      if(a[i] != 1) {
	if(i == n-1) a[i] = 0;
	else a[i] = (a[i]-1 == a[i+1] ? a[i] : 0);
	if(a[i] == k) ans++;
      }
    }
    printf("Case #%d: %d\n",tc,ans);
  }
}
    
