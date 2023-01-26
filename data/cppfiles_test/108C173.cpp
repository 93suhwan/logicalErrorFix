#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (long long i = 0; i < static_cast<long long>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n), b(n);
  vector<long long> aa(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    aa[i] = a[i].first;
    a[i].second = i;
  }
  vector<long long> bb(n);
  for (long long i = 0; i < n; i++) {
    cin >> b[i].first;
    bb[i] = b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  string res = string(n, '0');
  auto relax = [&]() {
    long long cnt = 0, mx_b = 0, mx_a = 0, ptr = 0, ptr_a = 0;
    set<pair<long long, long long>> st_a, st_b;
    for (long long i = 0; i < n; i++) {
      st_a.insert(a[i]);
      st_b.insert(b[i]);
    }
    auto relax = [&]() {
      while (!st_a.empty() && mx_a >= st_a.begin()->first) {
        long long idx = st_a.begin()->second;
        st_a.erase(st_a.begin());
        st_b.erase({bb[idx], idx});
        mx_b = max(mx_b, bb[idx]);
        while (!st_b.empty() && mx_b >= st_b.begin()->first) {
          long long id = st_b.begin()->second;
          st_b.erase(st_b.begin());
          mx_a = max(mx_a, aa[id]);
          st_a.erase({aa[id], id});
        }
      }
    };
    for (long long i = 0; i < n; i++) {
      mx_a = max(mx_a, a[i].first);
      relax();
      if (st_a.empty()) {
        res[a[i].second] = '1';
      }
    }
  };
  relax();
  swap(a, b);
  swap(aa, bb);
  relax();
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  while (tc-- > 0) solve();
  return 0;
}
