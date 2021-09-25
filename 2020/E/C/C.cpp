#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve(int TC) {
  int n; cin >> n;
  vector<int> E(n);
  vector<pair<LL,int>> R(n);
  for(int i=0;i<n;i++) cin >> E[i];
  LL curr_sum = 0;
  for(int i=0;i<n;i++) {
    cin >> R[i].first;
    R[i].second = i;
    curr_sum += 0;
    R[i].first += E[i];
  }
  vector<pair<LL,int>> org = R;
  sort(R.begin(),R.end());
  int ix = 0;
  LL ans = curr_sum;
  int min_del = 0;
  while(ix < n && org[ix].first <= curr_sum) ans += org[ix++].first;
  

  
}

int main() {
  int TC; cin >> TC;
  for(int i=1;i<=TC;i++) solve(i);
}
