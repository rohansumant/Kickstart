#include <bits/stdc++.h>
using namespace std;

//#define debug
#define debug printf

constexpr int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

void solve(int _T) {
  int n; cin >> n;
  assert(n <= 4);
  vector<vector<int>> a(n,vector<int>(n)), b(n,vector<int>(n));
  int mask = 0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
      if(a[i][j] == -1) {
	mask |= (1<<(n*i+j));
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> b[i][j];
    }
  }
  vector<int> r(n), c(n);
  for(int i=0;i<n;i++) cin >> r[i];
  for(int i=0;i<n;i++) cin >> c[i];


  auto ok = [&]() {
    vector<int> c(n);
    for(int i=0;i<n;i++) {
      int curr = 0;
      for(int j=0;j<n;j++) if(a[i][j] == -1) {
	  curr |= (1<<j);
	}
      c[i] = curr;
    }
    for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
	int res = c[i] & c[j];
	if(res) {
	  if(res - (res & (-res)) == 0) {
	    return true; // single bit
	  } else {
	    return false;
	  }
	}
      }
    }
    return true;
  };

  int ans;
  if(ok()) {
    ans = 0;
    goto done;
  } else {
    ans = 1e9;
  }
  for(auto xx = mask; xx; xx = mask & (xx-1)) {
    int curr_ans = 0;
    //debug("%d\n",xx);
    for(int i=0;i<n*n;i++) {
      int x = i/n, y = i%n;
      if(!(xx & (1<<(n*x+y)))) continue;
      //printf("%d %d %d\n",x,y,a[x][y]);
      assert(a[x][y] == -1);
      curr_ans += b[x][y];
      a[x][y] = 0;
    }
    if(ok()) ans = min(ans,curr_ans);
    for(int i=0;i<n*n;i++) {
      int x = i/n, y = i%n;
      if(!(xx & (1<<(n*x+y)))) continue;
      a[x][y] = -1;
    }
  }
 done:
  cout << "Case #" << _T << ": " << ans << endl;
}
	

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
  return 0;
}


/*

 */
