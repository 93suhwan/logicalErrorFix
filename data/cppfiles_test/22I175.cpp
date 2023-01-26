#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int n, k;
  cin >> n >> k;
  vector<int> sz(k);
  vector<vector<int>> ind(k);
  for (auto i = 0; i < k; ++i) {
    cin >> sz[i];
    ind[i].resize(sz[i]);
    for (auto &t : ind[i]) {
      cin >> t, --t;
    }
  }
  for (auto START = high_resolution_clock::now();
       duration<double>(high_resolution_clock::now() - START).count() <= 0.9;) {
    long long mask = rngll() & (1LL << n) - 1;
    if (!mask) {
      continue;
    }
    for (const auto &a : ind) {
      for (auto s = 0; s < (int)a.size(); ++s) {
        if (mask >> a[s] & 1) {
          for (auto t = s + 1; t < (int)a.size(); ++t) {
            if (~mask >> a[t] & 1) {
              mask ^= 1LL << a[s] | 1LL << a[t];
              break;
            }
          }
        }
      }
    }
    int t = __builtin_ctzll(mask);
    mask >>= t;
    ++mask;
    if (t + __builtin_ctzll(mask) != n) {
      cout << "REJECTED\n";
      return 0;
    }
  }
  cout << "ACCEPTED\n";
  return 0;
}
