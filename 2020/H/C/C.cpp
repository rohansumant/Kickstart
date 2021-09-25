#include <bits/stdc++.h>
using namespace std;

int n;
vector<array<int,2>> a;
typedef long long LL;

LL dist(int x1,int y1,int x2,int y2) {
  return (0LL + abs(x1-x2) + abs(y1-y2));
}

LL cost(int x,int y) {
  LL ans = 0;
  for(int i=0;i<n;i++) {
    ans += dist(a[i][0],a[i][1],x+i,y);
  }
  return ans;
}

void solve(int TC) {
  cin >> n;
  a.clear(); a.resize(n);
  assert(n <= 10);
  for(int i=0;i<n;i++) cin >> a[i][0] >> a[i][1];
  /*sort(a.begin(),a.end(),[](array<int,2> x, array<int,2> y) {
      return a[x][0] < a[y][0];
      });*/
  sort(a.begin(),a.end());
  LL min_cost = cost(0,0);
  
  for(int i=-500;i<=500;i++) {
    for(int j=-500;j<=500;j++) {
      min_cost = min(min_cost,cost(i,j));
    }
  }
  printf("Case #%d: %lld\n",TC,min_cost);
}
  

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
