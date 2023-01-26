#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void init(vector<T>& v, deque<int> sizes) {
  assert(sizes.size() == 1);
  v = vector<T>(sizes[0]);
}
template <typename T, typename C>
inline void init(vector<T>& v, deque<int> sizes, C content) {
  assert(sizes.size() == 1);
  v = vector<T>(sizes[0], content);
}
template <typename T>
inline void init(vector<vector<T>>& v, deque<int> sizes) {
  v = vector<vector<T>>(sizes[0]);
  sizes.pop_front();
  if (sizes.size() == 0) return;
  for (auto& subv : v) init(subv, sizes);
}
template <typename T, typename C>
inline void init(vector<vector<T>>& v, deque<int> sizes, C content) {
  v = vector<vector<T>>(sizes[0]);
  sizes.pop_front();
  if (sizes.size() == 0) return;
  for (auto& subv : v) init(subv, sizes, content);
}
template <typename T>
void _read(T& t);
template <typename T>
void _read(vector<T>& v);
template <typename T1, typename T2>
void _read(pair<T1, T2>& p);
template <typename T>
void _read(T& t) {
  cin >> t;
}
template <typename T>
void _read(vector<T>& v) {
  for (unsigned _i = 0; _i < v.size(); _i++) _read(v[_i]);
}
template <typename T1, typename T2>
void _read(pair<T1, T2>& p) {
  _read(p.first);
  _read(p.second);
}
void _masterread() {}
template <typename T, typename... V>
void _masterread(T& t, V&... v) {
  _read(t);
  _masterread(v...);
}
stringstream _effout;
template <typename T>
void _print(T t);
template <typename T>
void _print(vector<T>& v);
template <typename T1, typename T2>
void _print(pair<T1, T2>& p);
template <typename T>
void _print(T t) {
  _effout << t;
}
template <typename T>
void _print(vector<T>& v) {
  for (unsigned _i = 0; _i < v.size(); _i++)
    _print(v[_i]), _effout << (_i == v.size() - 1 ? "" : " ");
}
template <typename T1, typename T2>
void _print(pair<T1, T2>& p) {
  _print(p.first);
  _effout << " ";
  _print(p.second);
}
void _masterprint() {}
template <typename T, typename... V>
void _masterprint(T t, V... v) {
  _print(t);
  if (sizeof...(v)) _effout << " ";
  _masterprint(v...);
}
template <typename T>
void _debug(T t);
template <typename T1, typename T2>
void _debug(pair<T1, T2> p);
template <typename T>
void _debug(vector<T> v);
template <typename T>
void _debug(set<T> s);
template <typename T>
void _debug(unordered_set<T> s);
template <typename T>
void _debug(multiset<T> s);
template <typename T>
void _debug(unordered_multiset<T> s);
template <typename T1, typename T2>
void _debug(map<T1, T2> make_pair);
template <typename T1, typename T2>
void _debug(unordered_map<T1, T2> make_pair);
template <typename T1, typename T2>
void _debug(multimap<T1, T2> make_pair);
template <typename T1, typename T2>
void _debug(unordered_multimap<T1, T2> make_pair);
template <typename T>
void _debug(T t) {
  cerr << t;
}
template <typename T1, typename T2>
void _debug(pair<T1, T2> p) {
  cerr << "{";
  _debug(p.first);
  cerr << ", ";
  _debug(p.second);
  cerr << "}";
}
template <typename T>
void _debug(vector<T> v) {
  cerr << "(";
  for (unsigned _i = 0; _i < v.size(); _i++)
    _debug(v[_i]), cerr << (_i == v.size() - 1 ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(set<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(unordered_set<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(multiset<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(unordered_multiset<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(map<T1, T2> make_pair) {
  cerr << "(";
  for (auto e = make_pair.begin(); e != make_pair.end();)
    _debug(*e), cerr << ((++e) == make_pair.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(unordered_map<T1, T2> make_pair) {
  cerr << "(";
  for (auto e = make_pair.begin(); e != make_pair.end();)
    _debug(*e), cerr << ((++e) == make_pair.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(multimap<T1, T2> make_pair) {
  cerr << "(";
  for (auto e = make_pair.begin(); e != make_pair.end();)
    _debug(*e), cerr << ((++e) == make_pair.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(unordered_multimap<T1, T2> make_pair) {
  cerr << "(";
  for (auto e = make_pair.begin(); e != make_pair.end();)
    _debug(*e), cerr << ((++e) == make_pair.end() ? "" : ", ");
  cerr << ")";
}
void _masterdebug() { cerr << "]" << '\n'; }
template <typename T, typename... V>
void _masterdebug(T t, V... v) {
  _debug(t);
  if (sizeof...(v)) cerr << ", ";
  _masterdebug(v...);
}
void prep();
void testcase(signed tc);
signed main() {
  if (!0) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  _masterprint(setprecision(10));
  _masterprint(fixed);
  prep();
  if (0) {
    signed tests;
    _masterread(tests);
    for (signed tc = 1; tc <= tests; tc++) {
      testcase(tc);
    }
  } else {
    testcase(1);
  }
  cout << _effout.str();
}
void prep() {}
long long mod = 998244353;
vector<long long> mobius_transform(int n, vector<long long> f) {
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if ((mask & (1 << i)) != 0) {
        f[mask] -= f[mask ^ (1 << i)];
      }
    }
  }
  return f;
}
void testcase(__attribute__((unused)) signed tc) {
  int n;
  _masterread(n);
  vector<vector<int>> cnt;
  init(cnt, {1 << n, 26});
  for (int i = 0; i < n; i++) {
    string s;
    _masterread(s);
    int idx = 0;
    for (int c = 0; c < 26; c++) {
      while (idx < s.length() && s[idx] - 'a' == c) {
        cnt[1 << i][c]++;
        idx++;
      }
    }
  }
  vector<long long> uniqueforall(1 << n);
  for (int s = (1); s < (1 << n); s++) {
    vector<int> c;
    if (__builtin_popcount(s) == 1) {
      c = cnt[s];
    } else {
      int msb = __builtin_ctz(s);
      c = cnt[s - (1 << msb)];
      for (int j = 0; j < 26; j++) {
        c[j] = min(c[j], cnt[1 << msb][j]);
      }
    }
    uniqueforall[s] = 1;
    for (auto& e : c) {
      uniqueforall[s] *= (e + 1);
      uniqueforall[s] %= mod;
    }
  }
  vector<long long> uniqueforone = mobius_transform(n, uniqueforall);
  long long res = 0;
  for (int i = 0; i < 1 << n; i++) {
    long long ans = uniqueforone[i] % mod;
    ans += mod;
    ans %= mod;
    int k = 0;
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        k++;
        sum += (j + 1);
      }
    }
    if (k % 2 == 0) ans *= -1;
    ans %= mod;
    ans += mod;
    ans %= mod;
    ans *= k;
    ans *= sum;
    res ^= ans;
  }
  (_masterprint(res), _effout << '\n');
}
