#include <bits/stdc++.h>
using namespace std;
void fast(void) __attribute__((constructor));
void fast(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
template <typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T> {
  T v;
  number_iterator(T _v) : v(_v) {}
  operator T &() { return v; }
  T operator*() const { return v; }
};
template <typename T>
struct number_range {
  T b, e;
  number_range(T b, T e) : b(b), e(e) {}
  number_iterator<T> begin() { return b; }
  number_iterator<T> end() { return e; }
};
template <typename T>
number_range<T> range(T e) {
  return number_range<T>(0, e);
}
template <typename T>
number_range<T> range(T b, T e) {
  return number_range<T>(b, e);
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
inline void printV(const vector<long long> &v) {
  for_each(begin(v), end(v), [&](long long x) { cout << x << " "; });
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<long long>> g(n + 1, vector<long long>());
  vector<long long> res(n, 0);
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    g[x].emplace_back(i);
  }
  vector<long long> toColor;
  for (long long i = 1; i <= n; ++i) {
    if ((long long)g[i].size() >= k) {
      for (long long j = 0; j < k; ++j) {
        res[g[i][j]] = j + 1;
      }
    } else {
      for (long long j = 0; j < g[i].size(); ++j) {
        toColor.emplace_back(g[i][j]);
      }
    }
  }
  long long color = k;
  for (long long i = 0; i < toColor.size(); ++i) {
    if (color == 0) color = k;
    res[toColor[i]] = color;
    --color;
  }
  for (auto &c : res) cout << c << " ";
}
signed main(void) {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
