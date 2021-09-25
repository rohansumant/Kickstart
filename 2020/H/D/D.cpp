#include <bits/stdc++.h>
using namespace std;

void solve(int TC) {
  int n,q; cin >> n >> q;
  vector<unordered_set<int>> G(26);
  for(int i=0;i<n;i++) {
    string s; cin >> s;
    for(char ch: s) G[ch-'a'].insert(i+1);
  }

  auto has = [](unordered_set<int> &S,int x) {
    return S.find(x) != S.end();
  };

  vector<int> res;
  while(q--) {
    int x,y; cin >> x >> y;
    queue<array<int,2>> Q;
    Q.push({x,0});
    vector<bool> vis(n);
    int ans = 200;
    while(!Q.empty()) {
      auto pr = Q.front(); Q.pop();
      if(vis[pr[0]]) continue;
      vis[pr[0]] = 1;
      if(pr[0] == y) {
	ans = min(ans,pr[1]);
	break;
      }
      for(int i=0;i<26;i++) if(has(G[i],pr[0])) {
	  for(int j: G[i]) if(!vis[pr[0]]) {
	      Q.push({j,pr[1]+1});
	    }
	}
    }
    res.push_back(ans == 200 ? -1 : ans);
  }
  printf("Case #%d: ",TC);
  for(int i: res) printf("%d ");
  printf("\n");
}


int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
