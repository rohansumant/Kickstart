#include <bits/stdc++.h>
using namespace std;

#define debug
//#define debug printf

void solve(int _T) {
  int r,c; cin >> r >> c;
  vector<vector<int>> G(r,vector<int>(c));
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      cin >> G[i][j];
    }
  }
  vector<vector<array<int,4>>> A(r,vector<array<int,4>>(c));
  for(int i=0;i<r;i++) {
    int prev = 0;
    for(int j=0;j<c;j++) {
      if(G[i][j]) {
	A[i][j][0] = prev ? A[i][j-1][0] : j;
      }
      prev = G[i][j];
    }
    prev = 0;
    for(int j=c-1;j>=0;j--) {
      if(G[i][j]) {
	A[i][j][1] = prev ? A[i][j+1][1] : j;
      }
      prev = G[i][j];
    }
  }

  for(int j=0;j<c;j++) {
    int prev = 0;
    for(int i=0;i<r;i++) {
      if(G[i][j]) {
	A[i][j][2] = prev ? A[i-1][j][2] : i;
      }
      prev = G[i][j];
    }
    prev = 0;
    for(int i=r-1;i>=0;i--) {
      if(G[i][j]) {
	A[i][j][3] = prev ? A[i+1][j][3] : i;
      }
      prev = G[i][j];
    }
  }

  int ans = 0;
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(!G[i][j]) continue;
      int left = j - A[i][j][0] + 1;
      int right = A[i][j][1] - j + 1;
      int up = i - A[i][j][2] + 1;
      int down = A[i][j][3] - i + 1;
      for(int xx : {left,right,up,down}) {
	assert(xx > 0);
      }
      // debug("%d %d | %d %d %d %d\n",i,j,
      // 	    left,right,up,down);
      for(int x : {left,right}) {
	for(int y : {up,down}) {
	  if(x > 1 && y > 1) {
	    int xx = x, yy = y;
	    int result = min(xx/2,yy) + min(yy/2,xx) - 2;
	    debug("%d %d | %d\n",i,j,result);
	    assert(result >= 0);
	    ans += result;
	  }
	}
      }
    }
  }

  cout << "Case #" << _T << ": " << ans << endl;
}
	

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
  return 0;
}
