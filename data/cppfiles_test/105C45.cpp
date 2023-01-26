#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const double PI = acos(-1.0);
inline long long read() {
  char ch;
  long long x = 0;
  bool f = true;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') f ^= f;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - 48;
  return f ? x : -x;
}
const int N = 2e5 + 7;
int a[N], b[N], r[N], s[N], x[N], y[N], L[N], R[N];
pair<int, int> se[N];
void solve() {
  int n = read(), res = 0;
  for (int i = 1; i <= n; i++)
    a[i] = read(), b[i] = read(), r[i] = read(), s[i] = a[i] + b[i] - r[i];
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) mp[s[i]].push_back(i);
  for (auto S : mp) {
    vector<int> id = S.second;
    int cnt = id.size();
    for (int i = 0, j = id[i]; i < cnt; i++, j = id[i]) {
      L[i] = max(a[j] - r[j], 0);
      R[i] = a[j];
      if (b[j] < r[j]) R[i] -= r[j] - b[j];
    }
    for (int i = 0; i < cnt; i++) se[i] = {R[i], L[i]};
    sort(se, se + cnt);
    int ans = -0x3f3f3f3f;
    vector<int> qu;
    for (int i = 0; i < cnt; i++)
      if (ans < se[i].second) qu.push_back(ans = se[i].first);
    res += qu.size();
    for (int i = 0, j = id[i]; i < cnt; i++, j = id[i])
      x[j] = a[j] - *(upper_bound(qu.begin(), qu.end(), R[i]) - 1),
      y[j] = r[j] - x[j];
  }
  cout << res << "\n";
  for (int i = 1; i <= n; i++) cout << x[i] << " " << y[i] << "\n";
}
int main() {
  int T = 1;
  T = read();
  while (T--) solve();
  return 0;
}
