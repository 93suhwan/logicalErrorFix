#include <bits/stdc++.h>
long long MOD = 1e9 + 7;
long long LINF = (long long)4e18;
double EPS = 1e-7;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long binpow(long long a, long long n, long long mod) {
  if (n == 0) return 1ll;
  if (n % 2 == 1)
    return (binpow(a, n - 1, mod) % mod * a) % mod;
  else {
    long long b = binpow(a, n / 2, mod) % mod;
    return (b * b) % mod;
  }
}
void bfs(long long ver, vector<vector<long long>>& g, vector<bool>& us) {
  queue<long long> q;
  q.push(ver);
  us[ver] = 1;
  while (!q.empty()) {
    ver = q.front();
    q.pop();
    for (long long i = 0; i < g[ver].size(); i += 1) {
      long long to = g[ver][i];
      if (!us[to]) {
        us[to] = 1;
        q.push(to);
      }
    }
  }
}
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> bib(n);
  for (long long i = 0; i < n; i += 1) {
    cin >> bib[i];
  }
  if (n % 2 == 0) {
    cout << "YES" << '\n';
    return;
  }
  long long pr = bib[0];
  for (long long i = 1; i < n; i += 1) {
    if (bib[i] <= pr) {
      cout << "YES" << '\n';
      return;
    } else {
      pr = bib[i];
    }
  }
  cout << "NO" << '\n';
}
