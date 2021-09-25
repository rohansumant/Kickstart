#include <bits/stdc++.h>
using namespace std;

//#define debug
#define debug printf

constexpr int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

void solve(int _T) {
  int R, C; cin >> R >> C;
  vector<vector<int>> G(R,vector<int>(C));
  typedef array<int,3> AI3;
  priority_queue<AI3> Q; // max heap
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      cin >> G[i][j];
      if(G[i][j]) {
	Q.push({G[i][j],i,j});
      }
    }
  }

  auto valid = [&](int x,int y) {
    return (min(x,y) >= 0) && x < R && y < C;
  };

  vector<vector<int>> A(R,vector<int>(C));
  while(!Q.empty()) {
    auto [val,x,y] = Q.top(); Q.pop();
    if(!val || A[x][y]) continue;
    A[x][y] = val;
    if(val == 1) continue;
    for(int i=0;i<4;i++) {
      int nx = x + dx[i], ny = y+dy[i];
      if(valid(nx,ny) && !A[nx][ny]) {
	Q.push({val-1,nx,ny});
      }
    }
  }

  long long ans = 0;
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      assert(A[i][j] >= G[i][j]);
      ans += A[i][j] - G[i][j];
      debug("%d ",A[i][j]);
    }
    debug("\n");
  }
  cout << "Case #" << _T << ": " << ans << endl;
}
	

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
  return 0;
}
