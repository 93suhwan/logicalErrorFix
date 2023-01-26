#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
using LL = long long;
using PII = std::pair<int, int>;
constexpr int N(3e5 + 5), M(1e6 + 5);
bool np[N];
std::vector<int> primes;
void sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!np[i]) primes.push_back(i);
    for (int j : primes) {
      if (1LL * i * j > n) break;
      np[i * j] = true;
      if (i % j == 0) break;
    }
  }
}
int id[N];
std::vector<int> get(int x) {
  std::vector<int> res;
  for (int j = 0; j < primes.size(); j++) {
    int i = primes[j];
    if (i > x) break;
    if (x % i) continue;
    do {
      x /= i;
    } while (x % i == 0);
    res.push_back(j);
  }
  if (x > 1) {
    if (!id[x]) id[x] = ++id[0];
    res.push_back(id[x] + primes.size() - 1);
  }
  return res;
}
struct Dsu {
  std::vector<int> f;
  Dsu(int n) : f(n) { std::iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  bool merge(int x, int y) {
    return same(x, y) ? false : f[find(x)] = find(y), true;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  sieve(1000);
  int n, q;
  std::cin >> n >> q;
  Dsu d(n * 4);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    for (int j : get(x)) {
      d.merge(i, j + n + n);
    }
    for (int j : get(x + 1)) {
      d.merge(i + n, j + n + n);
    }
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    if (d.same(x, y)) {
      std::cout << "0\n";
    } else if (d.same(x + n, y) || d.same(x, y + n)) {
      std::cout << "1\n";
    } else {
      std::cout << "2\n";
    }
  }
  return 0;
}
