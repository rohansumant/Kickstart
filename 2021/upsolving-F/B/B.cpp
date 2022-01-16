#include <bits/stdc++.h>
#define debug //printf
using namespace std;

void solve(int _tc) {
  int d,n,k;
  cin >> d >> n >> k;
  vector<array<int,4>> a(n);
  vector<int> b(n), c(n);
  for(int i=0;i<n;i++) {
    int h,s,e; cin >> h >> s >> e;
    a[i] = {h,s,e};
    b[i] = c[i] = i;
  }
  sort(b.begin(), b.end(), [&a](int x,int y) {
      return a[x][1] < a[y][1];
      });

  sort(c.begin(), c.end(), [&a](int x,int y) {
      return a[x][2] < a[y][2];
      });

  int curr_sum = 0, ans = 0;
  multiset<int> s1,s2;
  for(int i=0,j=0;i<n;i++) {
    debug("start %d\n",i);
    int curr_ix = b[i];
    s1.insert(a[curr_ix][0]);
    curr_sum += a[curr_ix][0];
    if(s1.size() > k) {
      auto itr = s1.begin();
      curr_sum -= *itr;
      s2.insert(*itr);
      s1.erase(itr);
    }
    while(j < n && a[c[j]][2] < a[curr_ix][1]) {
      int val = a[c[j]][0];
      if(s1.count(val)) {
        s1.erase(s1.find(val));
        curr_sum -= val;
        debug("deleting %d %d\n",val,curr_sum);
      } else if(s2.count(val)) {
        s2.erase(s2.find(val));
      }
      j++;
    }
    while(s1.size() < k && (!s2.empty())) {
      int s2_max = *prev(s2.end());
      s2.erase(s2.find(s2_max));
      curr_sum += s2_max;
      s1.insert(s2_max);
    }
    ans = max(ans, curr_sum);
    debug("end %d\n",i);
  }
  printf("Case #%d: %d\n", _tc, ans);
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL);
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
