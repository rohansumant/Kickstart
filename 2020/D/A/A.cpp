#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc; cin >> tc;
  for(int itc = 1; itc <= tc; itc++) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0, max = 0;
    for(int i=0;i<n;i++) {
      if(a[i] > max) {
	if(i == n-1) ans++;
	else if(a[i] > a[i+1]) ans++;
	max = a[i];
      }
    }
    printf("Case #%d: %d\n",itc,ans);
  }
}
