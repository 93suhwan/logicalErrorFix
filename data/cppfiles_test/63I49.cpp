#include <bits/stdc++.h>
using namespace std;
const int Nmax = 20;
int n;
string s[20];
int sum[20], minl[20];
int f[1 << 20];
int g[20][800010];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) {
    minl[i] = 1e9;
    for (auto c : s[i]) {
      sum[i] += (c == '(' ? 1 : -1);
      minl[i] = min(minl[i], sum[i]);
      if (sum[i] > minl[i]) continue;
      ++g[i][sum[i] + s[i].size()];
    }
  }
  memset(f, -1, sizeof(f));
  f[0] = 0;
  int ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (f[mask] < 0) continue;
    int now = 0;
    for (int i = 0; i < n; ++i)
      if (mask >> i & 1) now += sum[i];
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) continue;
      int bonus = g[i][-now + s[i].size()];
      ans = max(ans, f[mask] + bonus);
      if (now + minl[i] < 0) continue;
      f[mask | (1 << i)] = max(f[mask | (1 << i)], f[mask] + bonus);
    }
  }
  cout << ans << '\n';
}
