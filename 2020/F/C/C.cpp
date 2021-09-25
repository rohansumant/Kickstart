#include <bits/stdc++.h>
using namespace std;


//#define debug printf
#define debug(...) 

typedef long long LL;
int _a[] = {0,1,4,9,16,25,36};
int s,ra,pa,rb,pb,c;

inline int my_hash(int x,int y) {
  //assert(x > 0 && x <= s);
  return _a[x-1]+y-1;
}

inline bool valid(int x,int y) {
  if(min(x,y) <= 0 || x > s || y >= 2*x) return false;
  return true;
}

int bitcount(LL x) {
  int ans = 0;
  while(x) {
    ans++;
    x -= x & (-x);
  }
  return ans;
}

int go(int player,
	int ax,int ay,
	int bx,int by,
	LL mask,bool skipped = false) {
  debug("mask: %lld\n",mask);
  if(!mask) return 0;
  //if(!player && (bitcount(mask)+curr <= best)) return;
  int &x = player ? bx : ax;
  int &y = player ? by : ay;
  int mul = player ? 1 : -1; // opposite this time
  pair<int,int> p1;
  if(y&1) {
    p1 = {1,1};
  } else {
    p1 = {-1,-1};
  }
  const pair<int,int> dir[] = {p1,{0,-1},{0,1}};
  int best = player ? INT_MAX : INT_MIN;
  
  bool any = 0;
  for(const pair<int,int> &pr : dir) {
    int dx = pr.first, dy = pr.second;
    x += dx; y += dy;
    debug("%d %d %d\n",x,y,(1LL << my_hash(x,y)));
    if(valid(x,y) && (mask & (1LL << my_hash(x,y)))) {
      //debug("%d %d\n",x,y);
      any |= 1;
      best = max(best,1-go(player^1,ax,ay,bx,by,mask^(1LL << my_hash(x,y))));
    }
    x -= dx; y -= dy;
  }
  if(!any) {
    if(skipped) return 0;
    else return -go(player^1,ax,ay,bx,by,mask,true);
  } else return best;
}

void solve(int TC) {
  cin >> s >> ra >> pa >> rb >> pb >> c;
  LL mask = (1LL << _a[s]) - 1;
  //debug("mask: %lld\n",mask);
  mask ^= 1LL << my_hash(ra,pa);
  //debug("mask: %lld\n",mask);
  mask ^= 1LL << my_hash(rb,pb);
  //debug("mask: %lld\n",mask);
  for(int i=0;i<c;i++) {
    int x,y; cin >> x >> y;
    mask ^= 1LL << my_hash(x,y);
  }
  //debug("mask: %lld\n",mask);
  int ans = go(0,ra,pa,rb,pb,mask);
  printf("Case #%d: %d\n",TC,ans);
}

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
