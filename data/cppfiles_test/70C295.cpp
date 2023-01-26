#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long Linf = 0x7f7f7f7f7f7f7f7f;
const int Inf = 0x3f3f3f3f;
const int MAXN = 1e6;
char t[MAXN];
int n, js;
map<char, int> mp, vis;
bool check(string s, string sx) {
  string tp = s;
  map<char, int> tj;
  for (auto ch : sx) {
    tj[ch] = 1;
    string temp = "";
    for (auto sch : s) {
      if (tj[sch]) continue;
      tp += sch;
      temp += sch;
    }
    s = temp;
  }
  return string(t + 1) == tp;
}
void doit() {
  cin >> (t + 1);
  n = strlen(t + 1);
  mp.clear();
  vis.clear();
  js = 0;
  for (int i = 1; i <= n; i++) {
    js += (mp[t[i]] == 0);
    mp[t[i]]++;
  }
  int now = 0;
  string sx;
  for (int i = n, j = js; i >= 1;) {
    int pos = i;
    while (vis[t[pos]]) pos--;
    sx += t[pos];
    vis[t[pos]] = 1;
    int cnt = mp[t[pos]];
    if (cnt % j) return cout << -1 << '\n', void();
    cnt /= j;
    now += cnt;
    i -= now;
    j--;
  }
  reverse(sx.begin(), sx.end());
  string ans = "";
  for (int i = 1; i <= now; i++) ans += t[i];
  if (!check(ans, sx)) return cout << -1 << '\n', void();
  cout << ans << ' ' << sx << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) doit();
  return 0;
}
