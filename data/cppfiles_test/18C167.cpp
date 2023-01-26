#include <bits/stdc++.h>
#pragma warning(disable : 4996)
const long long MOD = 998244353;
using namespace std;
void solve() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> f(n);
  vector<vector<int>> vv;
  for (int i = 0; i < n; i++) {
    if (f[i]) continue;
    int curr = i;
    vv.push_back(vector<int>());
    vector<int>& v = vv.back();
    v.push_back(curr);
    f[curr] = 1;
    while (1) {
      curr = (curr + d) % n;
      if (f[curr]) break;
      v.push_back(curr);
      f[curr] = 1;
    }
  }
  int bad = 0;
  int ans = 0;
  for (int i = 0; i < (int)vv.size(); i++) {
    vector<int>& v = vv[i];
    int num = (int)v.size();
    int M = 0;
    int cnt = 0;
    for (int k = 0; k < num * 2; k++) {
      if (a[v[k % num]])
        cnt++;
      else
        cnt = 0;
      M = max(M, cnt);
    }
    if (M >= num) bad = 1;
    ans = max(ans, M);
  }
  if (bad) {
    printf("-1\n");
  } else {
    printf("%d\n", ans);
  }
  return;
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
