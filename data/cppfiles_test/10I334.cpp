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
bool comp(const pair<string, vector<long long>> &p1,
          pair<string, vector<long long>> &p2) {
  return p1.second.size() > p2.second.size();
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> res(n, 0);
  unordered_map<string, vector<long long>> hmp;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    hmp[to_string(x)].emplace_back(i);
  }
  vector<pair<string, vector<long long>>> temp;
  for (auto &c : hmp) {
    temp.emplace_back(c.first, c.second);
  }
  sort(begin(temp), end(temp), comp);
  long long colors = 0;
  for (auto &c : temp) {
    long long sz = c.second.size();
    colors += min(k, sz);
  }
  colors = colors / k;
  vector<long long> cntk(k + 1, 0);
  long long sz = k;
  for (auto &c : temp) {
    long long itr = sz;
    for (long long j = 0; j < min((long long)c.second.size(), k); ++j) {
      res[c.second[j]] = itr;
      if (cntk[itr] == k) --sz;
      --itr;
    }
  }
  for (long long i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
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
