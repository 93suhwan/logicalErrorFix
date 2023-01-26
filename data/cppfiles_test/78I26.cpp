#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
template <typename T>
istream &operator>>(istream &is, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    is >> *a;
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    os << *a << " ";
  }
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
  os << p.first << " " << p.second << '\n';
  return os;
}
long long mul(long long a, long long b, long long md = MOD) {
  return (a % md * b % md) % md;
}
long long add(long long a, long long b, long long md = MOD) {
  long long ans = a + b;
  if (ans >= md) ans -= md;
  return ans;
}
bool valid(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long binPow(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y % 2 == 1) ans = mul(ans, x);
    x = mul(x, x);
    y /= 2;
  }
  return ans;
}
long long modInverse(long long x) { return binPow(x, MOD - 2); }
struct FenwickTree {
  vector<long long> a, b;
  FenwickTree(vector<long long> a) {
    this->a = vector<long long>(1 + ((int)a.size()));
    this->b = vector<long long>(1 + ((int)a.size()));
    for (int i = int(1); i < int(1 + ((int)a.size())); i++) update(i, a[i - 1]);
  }
  int LSBit(int x) { return x & (-x); }
  void update(int x, long long val) {
    long long diff = val - a[x];
    a[x] = val;
    for (int i = x; i < ((int)b.size()); i += LSBit(i)) {
      b[i] += diff;
    }
  }
  long long sum(int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= LSBit(i)) ans += b[i];
    return ans;
  }
  long long rmq(int l, int r) { return sum(r) - sum(l - 1); }
};
vector<vector<int>> G;
void E(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  vector<int> cnt(30);
  for (int i = 0; i < int(n); i++) {
    for (int b = 0; b < int(30); b++) {
      if ((1 << b) & a[i]) cnt[b]++;
    }
  }
  for (int k = int(1); k < int(n + 1); k++) {
    bool oj = true;
    for (int b = 0; b < int(30); b++) {
      if (cnt[b] > 0 && cnt[b] % k) oj = false;
    }
    if (oj) cout << k << " ";
  }
  cout << "\n";
}
int main() {
  (ios_base::sync_with_stdio(false), cin.tie(0));
  solve();
}
