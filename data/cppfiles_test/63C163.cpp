#include <bits/stdc++.h>
using int_t = long long int;
using std::cin;
using std::cout;
using std::endl;
const int_t LARGE = 3e5;
using real_t = double;
const int_t mod = 998244353;
int_t power(int_t base, int_t index) {
  if (index < 0) index = (index % (mod - 1) + mod - 1) % (mod - 1);
  int_t result = 1;
  while (index) {
    if (index & 1) result = result * base % mod;
    index >>= 1;
    base = base * base % mod;
  }
  return result;
}
int_t query(int_t* parent, int_t x) {
  while (parent[x] != x) x = parent[x];
  return x;
}
void merge(int_t* parent, int_t* size, int_t a, int_t b) {
  a = query(parent, a), b = query(parent, b);
  if (size[a] > size[b]) std::swap(a, b);
  size[b] += size[a];
  parent[a] = b;
}
int main() {
  std::ios::sync_with_stdio(false);
  {
    int_t n, m1, m2;
    cin >> n >> m1 >> m2;
    static int_t par1[LARGE], par2[LARGE], size2[LARGE], size1[LARGE];
    for (int_t i = 1; i <= n; i++) {
      par1[i] = par2[i] = i;
      size1[i] = size2[i] = 1;
    }
    for (int_t i = 1; i <= m1; i++) {
      int_t u, v;
      cin >> u >> v;
      merge(par1, size1, u, v);
    }
    for (int_t i = 1; i <= m2; i++) {
      int_t u, v;
      cin >> u >> v;
      merge(par2, size2, u, v);
    }
    struct S {
      int_t u, v;
    };
    std::vector<S> ret;
    for (int_t i = 1; i <= n; i++) {
      for (int_t j = i + 1; j <= n; j++) {
        if (query(par1, i) != query(par1, j) &&
            query(par2, i) != query(par2, j)) {
          ret.push_back(S{i, j});
          merge(par1, size1, i, j);
          merge(par2, size2, i, j);
        }
      }
    }
    cout << ret.size() << "\n";
    for (const auto& v : ret) {
      cout << v.u << " " << v.v << '\n';
    }
  }
  return 0;
}
