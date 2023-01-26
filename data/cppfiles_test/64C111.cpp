#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long d;
  while (b) {
    d = b;
    b = a % b;
    a = d;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long _pow(long long a, long long b) {
  long long d = 1;
  while (b) {
    if (b & 1) d *= a;
    a *= a;
    b >>= 1;
  }
  return d;
}
long long mpow(long long a, long long b, long long m) {
  long long d = 1;
  while (b) {
    if (b & 1) d = (d * (a % m)) % m;
    a = ((a % m) * (a % m)) % m;
    d %= m;
    b >>= 1;
  }
  return d % m;
}
const int N = 2e5 + 10;
const long long mod = 1e9 + 7;
struct dsu {
  vector<int> f;
  dsu(int n) : f(n) { iota(f.begin(), f.end(), 0); }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x > y) swap(x, y);
    f[y] = x;
  }
};
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu t1(n + 1), t2(n + 1);
    for (int i = 0; i < m1; i++) {
      int x, y;
      cin >> x >> y;
      t1.merge(x, y);
    }
    for (int i = 0; i < m2; i++) {
      int x, y;
      cin >> x >> y;
      t2.merge(x, y);
    }
    vector<pair<int, int>> ans;
    vector<int> v1, v2;
    for (int i = 2; i <= n; i++) {
      if (t1.find(i) != 1 && t2.find(i) != 1) {
        ans.push_back({1, i});
        t1.merge(1, i);
        t2.merge(1, i);
      }
      if (t1.find(i) != 1) v1.push_back(i);
      if (t2.find(i) != 1) v2.push_back(i);
    }
    while (!v1.empty() && !v2.empty()) {
      if (t1.find(v1.back()) == 1 && t2.find(v1.back()) == 1) {
        v1.pop_back();
        continue;
      }
      if (t1.find(v2.back()) == 1 && t2.find(v2.back()) == 1) {
        v2.pop_back();
        continue;
      }
      ans.push_back({v1.back(), v2.back()});
      t1.merge(v1.back(), v2.back());
      t2.merge(v1.back(), v2.back());
      v1.pop_back();
      v2.pop_back();
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
      cout << i.first << ' ' << i.second << '\n';
    }
  }
  return 0;
}
