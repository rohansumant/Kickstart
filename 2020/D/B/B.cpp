#include <bits/stdc++.h>
using namespace std;

inline int cmp(int a,int b) {
  if(a < b) return -1;
  else if(a == b) return 0;
  return 1;
}

int main() {
  int tc; cin >> tc;
  for(int itc=1;itc<=tc;itc++) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    /*
    if(n <= 4) {
      printf("Case #%d: 0\n",itc);
      continue;
    }
    */
    const int INF = 1e9;
    vector<vector<int>> dp(n,vector<int>(4,INF));
    for(int i=0;i<4;i++) {
      dp[0][i] = 0;
    }
    for(int i=1;i<n;i++) {
      int my = cmp(a[i-1],a[i]);
      for(int prev=0;prev<4;prev++) {
	for(int curr=0;curr<4;curr++) {
	  int alien = cmp(prev,curr), cost = (my == alien ? 0:1);
	  dp[i][curr] = min(dp[i][curr],dp[i-1][prev]+cost);
	}
      }
    }
    int ans = INF;
    for(int i=0;i<4;i++) {
      ans = min(ans,dp[n-1][i]);
    }
    printf("Case #%d: %d\n",itc,ans);
  }
}
    
	
