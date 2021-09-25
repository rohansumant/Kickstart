#include <bits/stdc++.h>
using namespace std;

int R,C;
vector<vector<char>> grid;
typedef pair<int,int> pii;

bool canAdd(char x,vector<pii> &a,vector<bool> &good) {
  for(auto &pr: a) {
    if(pr.first == R-1) continue;
    else {
      char below = grid[pr.first+1][pr.second];
      if(below != x && !good[below-'A']) return false;
    }
  }
  return true;
}
      

int main() {
  int tc; cin >> tc;
  for(int itc = 1; itc <= tc; itc++) {
    cin >> R >> C;
    unordered_map<char,vector<pii>> mp;
    grid.clear();
    grid = vector<vector<char>>(R,vector<char>(C));
    for(int i=0;i<R;i++) {
      for(int j=0;j<C;j++) {
	char x; cin >> x;
	grid[i][j] = x;
	mp[x].push_back({i,j});
      }
    }
    vector<bool> good(26);
    bool done = false;
    string ans;
    while(!mp.empty() && !done) {
      done = true;
      for(auto it = mp.begin(); it != mp.end();) {
	char x = it->first;
	if(canAdd(x,it->second,good)) {
	  done = false;
	  it = mp.erase(it);
	  ans += x;
	  good[x-'A'] = true;
	} else {
	  it++;
	}
      }
    }
    if(!mp.empty()) ans = "-1";
    printf("Case #%d: %s\n",itc,ans.c_str());
  }
}
	
