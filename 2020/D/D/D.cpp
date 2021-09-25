#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N+1);
  for(int i=1;i<N;i++) cin >> a[i];
  printf("Case #%d: ",tc);
  while(Q--) {
    int s,k; cin >> s >> k;
    typedef pair<int,int> pii;
    vector<pii> opts;
    if(s == 1) opts = {{1,0}};
    else if(s == N) opts = {{N,-1}};
    else opts = {{s,0},{s,-1}};
    int x;
    for(x=s,k--;k--;) {
      int ix = 0;
      if(opts.size() == 2) {
	if(opts.back() == make_pair(N,0) || opts.back() == make_pair(1,-1)) opts.pop_back();
      }
      if(opts.size() == 2) {
	swap(opts[0],opts[1]);
	if(opts.back() == make_pair(N,0) || opts.back() == make_pair(1,-1)) opts.pop_back();
      }
      if(opts.size() == 2) {
	auto p1 = opts[0], p2 = opts[1];
	if(a[p1.first + p1.second] >
	   a[p2.first + p2.second]) ix = 1;
      }
      auto pr = opts[ix];
      pii npr = {pr.first + (pr.second == 0 ? 1: pr.second), pr.second};
      opts[ix] = npr;
      x = npr.first;
      //printf("---> %d\n",x);
    }
    printf("%d ",x);
  }
  printf("\n");
}
      
      

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
