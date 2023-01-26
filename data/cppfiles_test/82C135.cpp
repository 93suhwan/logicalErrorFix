#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char& s) {
  string res = "'";
  res += s;
  res += "'";
  return res;
}
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i) res += ", ";
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
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long> pa(n + 1), push_back(n + 1);
  for (long long i = 0; i < n; i++) {
    pa[i + 1] = pa[i];
    push_back[i + 1] = push_back[i];
    if ((s[i] == '+' && i % 2 == 0) || (s[i] == '-' && i % 2 == 1)) {
      pa[i + 1]++;
      push_back[i + 1]--;
    } else {
      pa[i + 1]--;
      push_back[i + 1]++;
    }
  }
  map<pair<long long, long long>, vector<long long>> dpa, dpb;
  for (long long i = 0; i < n; i++) {
    dpa[{pa[i], pa[i + 1]}].push_back(i);
    dpb[{push_back[i], push_back[i + 1]}].push_back(i);
  }
  auto get = [&](long long l, long long r) {
    long long res;
    if (l % 2 == 0) {
      res = pa[r + 1] - pa[l];
    } else {
      res = push_back[r + 1] - push_back[l];
    }
    for (auto x : {-1, 1}) {
      long long need = (res - x) / 2;
      if (l % 2 == 0) {
        need += pa[l];
        pair<long long, long long> key = {need, need + x};
        long long it = lower_bound((dpa[key]).begin(), (dpa[key]).end(), l) -
                       dpa[key].begin();
        if (it != (long long)(dpa[key]).size() && dpa[key][it] <= r) {
          return dpa[key][it];
        }
      } else {
        need += push_back[l];
        pair<long long, long long> key = {need, need + x};
        long long it = lower_bound((dpb[key]).begin(), (dpb[key]).end(), l) -
                       dpb[key].begin();
        if (it != (long long)(dpb[key]).size() && dpb[key][it] <= r) {
          return dpb[key][it];
        }
      }
    }
    assert(false);
    return (long long)228;
  };
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    l--, r--;
    long long ok = 1;
    if (l % 2 == r % 2) {
      ok = 0;
    }
    long long res;
    if (l % 2 == 0) {
      res = pa[r + 1] - pa[l];
    } else {
      res = push_back[r + 1] - push_back[l];
    }
    if (res != 0) {
      ok = 0;
    }
    if (ok) {
      cout << 0 << '\n';
      continue;
    }
    if (l % 2 == r % 2) {
      cout << 1 << '\n';
      cout << get(l, r) + 1 << '\n';
    } else {
      cout << 2 << '\n';
      cout << l + 1 << " " << get(l + 1, r) + 1 << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
}
