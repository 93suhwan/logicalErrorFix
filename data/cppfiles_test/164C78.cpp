#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 2e5 + 5;
string a, s;
set<long long> g;
long long c[N], n, k, num[N], tot, L[N], R[N], ok[N];
void dfs(long long u) {
  if (L[u]) dfs(L[u]);
  num[++tot] = u;
  a += s[u];
  if (R[u]) dfs(R[u]);
}
void solve(long long u, long long dp) {
  if (!u || dp > k) return;
  solve(L[u], dp + 1);
  if (ok[L[u]])
    ok[u] = 1;
  else if (c[u])
    ok[u] = 1, k -= dp;
  if (ok[u]) solve(R[u], 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> s;
  s = " " + s;
  for (long long i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
  }
  dfs(1);
  a = " " + a;
  for (long long i = 1; i <= n; i++) {
    long long x = i;
    while (x <= n && a[i] == a[x]) x++;
    if (x > n) break;
    if (a[x] > a[i]) {
      for (long long j = i; j < x; j++) c[num[j]] = 1;
    }
    i = x - 1;
  }
  solve(1, 1);
  for (long long i = 1; i <= n; i++) {
    if (ok[num[i]]) cout << a[i];
    cout << a[i];
  }
  cout << endl;
}
