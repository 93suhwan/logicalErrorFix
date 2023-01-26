#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
const ll oo = 1e9;
int n, d, a[maxN];
int avail[maxN], f[maxN];
inline void FastInput() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
int dfs(int u) {
  if (avail[u]) return f[u];
  if (!a[u]) return 0;
  avail[u] = -1;
  int j = (u + d) % n;
  dfs(j);
  f[u] += f[j];
  return f[u];
}
map<int, int> mp;
bool CheckCycle(int u) {
  avail[u] = -1;
  if (!a[u]) return 0;
  if (mp[u]) return 1;
  mp[u] = 1;
  int j = (u + d) % n;
  CheckCycle(j);
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
    mp.clear();
    if (CheckCycle(i)) {
      cout << -1 << '\n';
      return;
    }
  }
  fill(avail, avail + n, 0);
  for (int i = 0; i < n; i++) {
    if (avail[i]) continue;
    f[i] = dfs(i);
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
