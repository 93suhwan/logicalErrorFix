#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const double pi = acos(-1.0);
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long poww(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) s = (s * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return s % mod;
}
const int N = 1e6 + 11;
long long n, m;
struct DSU {
  vector<int> e;
  DSU(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
void solve() {
  cin >> n >> m;
  DSU z(n + 1);
  vector<pair<int, int> > ans;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (!z.sameSet(a, c)) {
      z.join(a, c);
      ans.push_back({a, c});
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!z.sameSet(1, i)) {
      z.join(1, i);
      ans.push_back({1, i});
    }
  }
  for (auto i : ans) {
    cout << i.first << ' ' << i.second << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(15);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
