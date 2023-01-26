#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long arr[1010100];
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first != p2.first)
    return p1.first < p2.first;
  else
    return p1.second > p2.second;
}
void solve() {
  long long N;
  cin >> N;
  long long i;
  vector<vector<long long>> v(8192);
  vector<long long> chk(8192, 1000000000000);
  vector<long long> ans(8192);
  for (i = 1; i <= N; i++) cin >> arr[i], v[arr[i]].push_back(i);
  chk[0] = 0;
  v[0].push_back(0);
  for (i = 0; i <= 5000; i++) {
    long long j;
    if (v[i].empty()) continue;
    vector<long long> nw(8192, 1000000000000);
    nw[0] = 0;
    for (j = 0; j < 8192; j++) {
      long long x = i ^ j;
      long long ind =
          upper_bound(v[i].begin(), v[i].end(), chk[x]) - v[i].begin();
      if (ind == v[i].size()) continue;
      ans[j] = 1;
      nw[j] = min(nw[j], v[i][ind]);
    }
    for (j = 0; j < 8192; j++) chk[j] = min(chk[j], nw[j]);
  }
  long long cnt = 0;
  ans[0] = 1;
  for (i = 0; i < 8192; i++) cnt += ans[i];
  cout << cnt << '\n';
  for (i = 0; i < 8192; i++)
    if (ans[i]) cout << i << ' ';
  cout << '\n';
}
void init() {}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long T;
  T = 1;
  while (T--) {
    init();
    solve();
  }
}
