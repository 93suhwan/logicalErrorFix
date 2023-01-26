#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
const ll oo = 1e9;
int n, d, a[maxN];
int avail[maxN], f[maxN], cnt[maxN];
inline void FastInput() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
int dfs(int u) {
  cnt[u]++;
  if (avail[u]) return f[u];
  avail[u] = -1;
  if (!a[u]) return 0;
  int j = (u + d) % n;
  dfs(j);
  f[u] += f[j];
  return f[u];
}
void ReadInput() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[i] = a[i];
    avail[i] = 0;
  }
}
void Solve() {
  for (int i = 0; i < n; i++) {
    if (avail[i]) continue;
    cnt[i] = 0;
    f[i] = dfs(i);
    if (cnt[i] == 2) {
      cout << -1 << '\n';
      return;
    }
  }
  int res = *max_element(f, f + n);
  cout << res << '\n';
}
int main() {
  FastInput();
  int test;
  cin >> test;
  while (test--) {
    ReadInput();
    Solve();
  }
}
