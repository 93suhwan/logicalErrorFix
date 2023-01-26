#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
long long GCD(long long a, long long b) { return (a) ? GCD(b % a, a) : b; }
long long LCM(long long a, long long b) { return a * b / GCD(a, b); }
long long fastpow(long long b, long long p) {
  if (!p) return 1;
  long long ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
long long n, m;
void solve() {
  cin >> n >> m;
  unordered_map<long long, long long> mp;
  long long x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    mp[(i - x + n) % n]++;
  }
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    if (n - mp[i] <= m * 2) ans.push_back(i);
  }
  cout << ans.size() << ' ';
  for (auto xx : ans) cout << xx << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int TT = 1;
  cin >> TT;
  for (int tc = 1; tc <= TT; tc++) {
    solve();
  }
}
