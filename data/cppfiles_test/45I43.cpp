#include <bits/stdc++.h>
using namespace std;
long long mod = 22866613371;
long long p = 1000039, p1 = 911, mod1 = 999999001, INF = 1e9;
const long double PI = acos(-1);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void dfs(vector<bool> &used, vector<vector<int>> &g, int v) {
  if (used[v]) return;
  used[v] = true;
  for (auto i : g[v]) {
    if (!used[i]) {
      dfs(used, g, i);
    }
  }
}
long long binpow(long long a, long long x) {
  if (a == 1 || x == 0) return 1;
  if (x == 1) return a;
  if (x & 1)
    return binpow(a, x - 1) * a % mod1;
  else {
    long long temp = binpow(a, x >> 1);
    return temp * temp % mod1;
  }
}
void solve() {
  long long n, x;
  cin >> n;
  long long cnt = 1;
  bool fl = false, fl1 = true;
  cin >> x;
  fl = x;
  if (x == 1) cnt++;
  for (long long i = 1; i < n; i++) {
    cin >> x;
    if (!fl && x == 0) {
      cout << -1 << '\n';
      fl1 = false;
      break;
    } else if (!fl && x == 1) {
      fl = true;
      cnt++;
    } else if (fl && x == 1) {
      cnt += 5;
    } else {
      fl = false;
    }
  }
  if (fl1) cout << cnt << '\n';
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
