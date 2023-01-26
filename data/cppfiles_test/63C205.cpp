#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e5 + 5;
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return res;
}
bool isPrime(long long n) {
  static long long i = 2;
  if (n == 0 || n == 1) {
    return false;
  }
  if (n == i) return true;
  if (n % i == 0) {
    return false;
  }
  i++;
  return isPrime(n);
}
class DisjointSet {
 public:
  vector<long long> parent;
  DisjointSet(long long n) : parent(n) {
    for (long long i = 0; i < n; i++) parent[i] = -1;
  }
  void join(long long a, long long b) { parent[find(a)] = find(b); }
  long long find(long long a) {
    if (parent[a] == -1) {
      return a;
    }
    return find(parent[a]);
  }
  bool check(long long a, long long b) { return find(a) == find(b); }
};
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long m1, m2;
  cin >> m1 >> m2;
  DisjointSet a(n);
  DisjointSet b(n);
  for (long long i = 0; i < m1; i++) {
    long long u, v;
    cin >> u >> v;
    a.join(u - 1, v - 1);
  }
  for (long long i = 0; i < m2; i++) {
    long long u, v;
    cin >> u >> v;
    b.join(u - 1, v - 1);
  }
  long long addhere = 0;
  vector<pair<long long, long long>> vv;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (a.check(i, j) || b.check(i, j)) {
        continue;
      }
      addhere += 1;
      a.join(i, j);
      b.join(i, j);
      vv.push_back({i, j});
    }
  }
  cout << addhere << '\n';
  for (auto i : vv) {
    cout << i.first + 1 << " " << i.second + 1 << '\n';
  }
  return 0;
}
