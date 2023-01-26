#include <bits/stdc++.h>
using namespace std;
const long long MXN = 3e5 + 10;
long long n, m, t;
long long A[MXN], P[MXN], cnt[MXN];
vector<long long> ANS;
bool vis[MXN];
void dfs(long long u) {
  t++, vis[u] = 1;
  if (!vis[P[u]]) dfs(P[u]);
}
bool check(long long k) {
  long long p = 1, res = 0;
  k = (n - k + n) % n;
  for (int i = k + 1; i <= n; i++) P[i] = A[p++];
  for (int i = 1; i <= k; i++) P[i] = A[p++];
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      t = 0, dfs(i);
      res += t - 1;
    }
  }
  return (res <= m);
}
void solve() {
  cin >> n >> m, ANS.clear(), cnt[0] = 0;
  for (int i = 1; i <= n; i++) cin >> A[i], cnt[i] = 0;
  for (int i = 1; i <= n; i++) cnt[(i - A[i] + n) % n]++;
  for (int k = 0; k < n; k++) {
    if (cnt[k] >= n / 3 && check(k)) {
      ANS.push_back(k);
    }
  }
  cout << ANS.size() << ' ';
  for (auto X : ANS) cout << X << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) solve();
  return 0;
}
