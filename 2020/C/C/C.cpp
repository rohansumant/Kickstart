#include <bits/stdc++.h>
using namespace std;

int max_subarray(vector<int> &a) {
  int n = a.size();
  vector<int> dp(n);
  dp[0] = a[0];
  int ans = -1e9;
  for(int i=1;i<n;i++) {
    dp[i] = max(dp[i-1]+a[i],a[i]);
    ans = max(ans,dp[i]);
  }
  return ans;
}
  

int main() {
  int tc; cin >> tc;
  
  unordered_set<int> sqrs;
  vector<int> ls;
  for(int i=0;1LL*i*i<=int(1e7);i++) {
    sqrs.insert(i*i);
    ls.push_back(i*i);
  }
  
  for(int itc=1;itc<=tc;itc++) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int MX = max_subarray(a);
    unordered_map<int,int> mp; // {prefix_sum, occurence count}
    long long ans = 0;
    for(int i=0;i<n;i++) {
      //cin >> a[i];
      if(i) a[i] += a[i-1];
      if(sqrs.find(a[i]) != sqrs.end()) ans++;
      for(auto sqr : ls) {
	if(sqr > (MX)) break;
	int rem = a[i] - sqr;
	auto it = mp.find(rem);
	if(it != mp.end()) {
	  ans += it->second;
	}
      }
      mp[a[i]]++;
    }
    printf("Case #%d: %lld\n",itc,ans);
  }
}
