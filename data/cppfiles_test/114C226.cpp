#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const int Inf = 1e9 + 9;
const int Mod = 998244353;
const int N = 2e5 + 9;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long mul(long long a, long long b) { return (1LL * a * b) % Mod; }
long long add(long long a, long long b) {
  a += b;
  if (a >= Mod) a -= Mod;
  if (a < 0) a += Mod;
  return a;
}
long long sub(long long a, long long b) {
  return (a - b) % Mod + ((a >= b) ? 0 : Mod);
}
void solve() {
  int n;
  cin >> n;
  set<int> a;
  int mn = 10000000;
  for (int i = (0); i < (n); i++) {
    int x;
    cin >> x;
    a.insert(x);
    mn = min(x, mn);
  }
  vector<pair<int, int> > ans;
  for (auto it : a) {
    if (it != mn && a.count(it % mn) == 0) {
      ans.push_back({it, mn});
    }
    if (ans.size() == n / 2) break;
  }
  for (auto it : ans) cout << it.first << " " << it.second << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
