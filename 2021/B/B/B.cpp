
#include <bits/stdc++.h>
using namespace std;

#define dbg printf
//#define dbg

void mx(int &a,int b) {
  a = max(a,b);
}

void solve(int _TC) {
  int n; cin >> n;
  vector<int> a(n);
  for(int &i: a) cin >> i;
  if(n <= 3) {
    printf("Case #%d: %d\n",_TC,n);
    return;
  }

  typedef unordered_map<int,int> mpii;
  vector<array<mpii,2>> dp(n);
  int ans = 3;
  for(int i=1;i<n;i++) {
    int d1 = a[i]-a[i-1];
    dp[i][0][d1] = 2;
    for(auto [d2,val] : dp[i-1][0]) {
      mx(dp[i][(d1==d2 ? 0:1)][d2],dp[i-1][0][d2]+1);
    }
    for(auto [d2,val] : dp[i-1][1]) {
      if(d2 == d1) {
	mx(dp[i][1][d1],dp[i-1][1][d2]+1);
      }
    }
    if(i+1 < n) {
      int d3 = a[i+1]-a[i-1];
      if(d3 % 2 == 0) {
	d3 /= 2;
	if(d1 != d3) {
	  mx(dp[i][1][d3],max(1,dp[i-1][0][d3])+1);
	  dp[i+1][1][d3] = dp[i][1][d3]+1;
	}
      }
    }
    dbg("%d\n",i);
    for(int x : {0,1}) {
      for(auto [d,v] : dp[i][x]) {
	ans = max(ans,v);
	dbg("%d %d %d\n",x,d,v);
      }
    }
    dbg("===\n");
  }
  printf("Case #%d: %d\n",_TC,ans);
}
  
int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}


/*
a b c | c,b->d1 b,a->d2 c,a->d3?

1
9
5 5 4 5 5 5 4 5 6

 */
