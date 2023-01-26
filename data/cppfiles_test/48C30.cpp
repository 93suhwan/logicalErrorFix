#include <bits/stdc++.h>
using namespace std;
template <class T>
using Graph = vector<vector<T>>;
template <class T>
using Maxheap = priority_queue<T>;
template <class T>
using Minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename T1>
inline T max(T a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
inline T min(T a, T1 b) {
  if (b < a) a = b;
  return a;
}
inline int64_t ssum(int64_t n) { return (n * (n + 1)) / 2; };
inline int64_t fastpow(int64_t a, int64_t b, int64_t m = (int64_t)(1e9 + 7)) {
  int64_t res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
void go() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
struct Tree {
  int64_t sz;
  vector<int64_t> bit;
  Tree(int64_t n) {
    sz = n;
    bit.assign(n, 0);
  }
  int64_t sum(int64_t i) {
    int64_t ans = 0;
    while (i >= 0) {
      ans += bit[i];
      i = (i & (i + 1)) - 1;
    }
    return ans;
  }
  void add(int64_t i, int64_t val) {
    while (i < sz) {
      bit[i] += val;
      i |= (i + 1);
    }
  }
};
signed main() {
  go();
  int64_t T = 1;
  cin >> T;
  for (int64_t tt = 1; tt <= T; tt++) {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (int64_t i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (set<int64_t>(a.begin(), a.end()).size() < n) {
      cout << "YES\n";
    } else {
      Tree t(*max_element(a.begin(), a.end()) + 1);
      int64_t S = 0;
      for (int64_t i = n - 1; i >= 0; i--) {
        t.add(a[i], 1);
        S += t.sum(a[i] - 1);
      }
      cout << ((S & 1) ? "NO\n" : "YES\n");
    }
  }
  return 0;
}
