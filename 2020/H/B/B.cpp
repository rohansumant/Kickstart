#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a[20];

void pre() {
  a[0] = 1;
  for(int i=1;i<=18;i++) a[i] = a[i-1]*5;
}

vector<char> A = {'1','3','5','7','9'}, B = {'0','2','4','6','8'};

/*
LL gen(const string &x,int ix,int len,bool equal) {
  if(ix == len) return ;
  if(!equal) return 5;
  vector<char> &target_arr = (ix & 1 ? A : B);
  LL ans = 0;
  for(char ch : target_arr) {
    if(ch <= x[ix-1]) {
      ans += gen(x,ix+1,len,ch == x[ix-1]);
    } else break;
  }
  return ans;
}
*/

LL gen(string x) {
  int len = x.size();
  //printf("gen: %s %d\n",x.c_str(),len);
  LL ans = 0;
  bool still_boring = true;
  for(int i=1;still_boring && i<=len;i++) {
    vector<char> &digits = (i & 1 ? A : B);
    still_boring = false;
    for(char ch: digits) {
      if(ch < x[i-1]) {
	ans += a[len-i];
      } else if(ch == x[i-1]) {
	still_boring = true;
      } else {
	break;
      }
    }
    //printf("gen ans: %d %lld\n",i,ans);
  }
  ans += still_boring ? 1:0;
  //printf("final gen ans: %lld\n",ans);
  return ans;
}

LL get(LL x) {
  if(x == 0) return 0;
  
  int len = 0;
  for(LL xx = x; xx; xx /= 10) len++;

  LL ans = 0;
  for(int i=1;i<len;i++) ans += a[i];
  
  string xx = to_string(x);

  //printf("%s\n",xx.c_str());
  //ans += gen(xx,1,len,true);
  LL yy = gen(xx);
  //  printf("gen(%lld): %lld\n",x,yy);
  ans += yy;
  
  /*  for(char ch: A) if(ch <= xx[0]) {
      ans += gen(xx,2,len,ch == xx[0]);
    }
  */
  
  return ans;
}

void solve(int TC) {
  if(TC == 1) pre();
  LL L, R; cin >> L >> R;
  LL ans = get(R) - get(L-1);
  /*for(int i=11;i<=11;i++) {
    printf("%d: %lld\n",i,get(i));
    }*/
  printf("Case #%d: %lld\n",TC,ans);
}
  

int main() {
  int t; cin >> t;
  for(int i=1;i<=t;i++) solve(i);
}
