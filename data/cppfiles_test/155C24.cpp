#include <bits/stdc++.h>
using namespace std;
int const mod = 1000000007;
int const maxN = 1e5 + 5;
long long INF = 1e18;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}
long long ExtEuclidean(long long a, long long b, long long& x, long long& y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long x1, y1;
  long long _gcd = ExtEuclidean(b, a % b, x1, y1);
  x = y1, y = x1 - (a / b) * y1;
  return _gcd;
}
class DSU {
 public:
  int *par, *rank;
  DSU(int n) {
    par = new int[n], rank = new int[n];
    for (int i = 0; i < n; i++) par[i] = -1, rank[i] = 1;
  }
  int find(int x) {
    if (par[x] == -1) return x;
    return par[x] = find(par[x]);
  }
  void unite(int a, int b) {
    int p1 = find(a), p2 = find(b);
    if (p1 != p2) {
      if (rank[p1] < rank[p2])
        par[p2] = p1, rank[p1] += rank[p2];
      else
        par[p1] = p2, rank[p2] += rank[p1];
    }
  }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = int(0); i < int(n); ++i) cin >> arr[i];
  string s;
  cin >> s;
  vector<pair<long long, long long>> like, un;
  for (int i = 0; i < ((int)s.size()); i++)
    if (s[i] == '1') like.push_back({arr[i], i});
  for (int i = 0; i < ((int)s.size()); i++)
    if (s[i] == '0') un.push_back({arr[i], i});
  sort(like.begin(), like.end(), greater<pair<long long, long long>>());
  sort(un.begin(), un.end(), greater<pair<long long, long long>>());
  long long k = n;
  vector<long long> v(n);
  for (int i = int(0); i < int(((int)like.size())); ++i) {
    v[like[i].second] = k--;
  }
  for (int i = int(0); i < int(((int)un.size())); ++i) {
    v[un[i].second] = k--;
  }
  for (int i = int(0); i < int(n); ++i) cout << v[i] << " ";
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve();
    cout << '\n';
  }
  return 0;
}
