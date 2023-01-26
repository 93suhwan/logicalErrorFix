#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
int nx[4] = {1, -1, 0, 0}, ny[4] = {0, 0, 1, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> A;
  A.assign(n, 0);
  set<long long> s;
  bool vis[n];
  memset(vis, false, sizeof(vis));
  for (int i = 0; i < n; i++) {
    s.insert(i + 1);
    cin >> A[i];
  }
  sort((A).begin(), (A).end());
  for (int i = 0; i < n; i++) {
    if (s.count(A[i]) != 0) {
      s.erase(A[i]);
      vis[i] = true;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    long long main = *(s.begin());
    if (A[i] != main && A[i] / 2 + (A[i] & 1) <= main) {
      cout << -1 << '\n';
      return;
    } else if (A[i] != main) {
      cnt++;
    }
    s.erase(s.begin());
  }
  cout << cnt << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
}
