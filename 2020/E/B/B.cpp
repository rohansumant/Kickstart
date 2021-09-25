#include <bits/stdc++.h>
using namespace std;

void solve(int TC) {
  int n,a,b,c;
  cin >> n >> a >> b >> c;
  int a1 = a-c, b1 = b-c;
  bool ok = 1;
  int rem = n - (a1+b1+c);
  if(rem < 0) ok = 0;
  if(!ok) {
    printf("Case #%d: IMPOSSIBLE\n",TC);
    return;
  }
  assert(a1+b1+c+rem == n);
  vector<int> ans;
  for(int i=0;i<a1;i++) ans.push_back(n-1);
  for(;a1 > 0 && rem > 0;rem--) ans.push_back(1);
  for(int i=0;i<c;i++) ans.push_back(n);
  for(;b1 > 0 && rem > 0;rem--) ans.push_back(1);
  for(int i=0;i<b1;i++) ans.push_back(n-1);

  if(rem > 0) {
    if(c > 1) {
      assert(ans.back() == n);
      ans.pop_back();
      while(rem--) ans.push_back(1);
      ans.push_back(n);
    } else {
      printf("Case #%d: IMPOSSIBLE\n",TC);
      return;
    }   
  }
  printf("Case #%d: ",TC);
  for(int i: ans) printf("%d ",i);
  printf("\n");
}
  
int main() {
  int TC; cin >> TC;
  for(int i=1;i<=TC;i++) solve(i);
}
