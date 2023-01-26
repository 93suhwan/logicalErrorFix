#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
template <typename A, typename B>
istream& operator>>(istream& s, pair<A, B>& p) {
  s >> p.first >> p.second;
  return s;
}
template <typename A, typename B>
ostream& operator<<(ostream& s, const pair<A, B>& p) {
  s << "(" << p.first << "," << p.second << ")";
  return s;
}
template <typename Iterable,
          typename Begin = decltype(std::begin(std::declval<Iterable>())),
          typename NotString = typename std::enable_if<
              !std::is_same<Iterable, string>::value, void>::type>
istream& operator>>(istream& s, Iterable& it) {
  for (auto& x : it) s >> x;
  return s;
}
template <typename Iterable,
          typename Begin = decltype(std::begin(std::declval<Iterable>())),
          typename NotString = typename std::enable_if<
              !std::is_same<Iterable, string>::value, void>::type>
ostream& operator<<(ostream& s, const Iterable& it) {
  if (&s == &std::cerr) {
    s << "[";
    auto delim = "";
    for (const auto& x : it) {
      s << delim << x;
      delim = ", ";
    }
    s << "]";
  } else {
    auto delim = "";
    for (const auto& x : it) {
      s << delim << x;
      delim = " ";
    }
  }
  return s;
}
template <typename Value = long long>
struct Fenwick {
  vector<Value> ft;
  Fenwick(int N) { ft.assign(N + 1, 0); }
  void add(int p, Value v) {
    for (++p; p < ft.size(); p += p & -p) ft[p] += v;
  }
  Value sum(int b) {
    Value res = 0;
    for (++b; b > 0; b -= b & -b) res += ft[b];
    return res;
  }
  Value sum(int a, int b) { return sum(b) - (a ? sum(a - 1) : 0); }
  Value get(int p) { return sum(p, p); }
  void set(int p, Value v) { add(p, v - get(p)); }
};
struct UFDS {
  vector<int> parent, rank, sz;
  int num_components;
  UFDS(int N) : parent(N, 0), rank(N, 0), sz(N, 1), num_components(N) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
  }
  bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (rank[a] > rank[b]) swap(a, b);
    parent[a] = b;
    sz[b] += sz[a];
    if (rank[a] == rank[b]) rank[b]++;
    num_components--;
    return true;
  }
  bool same(int a, int b) { return find(a) == find(b); }
  int size(int x) { return sz[find(x)]; }
  int components() { return num_components; }
};
template <typename Value>
struct ValueMapper {
  unordered_map<Value, int> mapping;
  vector<Value> mapping_inv;
  template <typename InputIt>
  ValueMapper(InputIt first, InputIt last) {
    for (; first != last; ++first) add(*first);
  }
  ValueMapper() {}
  void add(Value elem) {
    if (mapping.find(elem) != mapping.end()) return;
    mapping[elem] = mapping.size();
    mapping_inv.push_back(elem);
  }
  vector<int> map(const vector<Value>& data) {
    vector<int> res;
    for (auto& x : data) res.push_back(fromvalue(x));
    return res;
  }
  int fromvalue(Value elem) { return mapping.at(elem); }
  Value fromindex(int idx) { return mapping_inv.at(idx); }
  int size() { return mapping.size(); }
};
vector<int> isprime;
vector<int> primes;
void eratosthenes(int N) {
  isprime.assign(N + 1, true);
  isprime[0] = isprime[1] = false;
  for (int p = 2; p <= N; p++)
    if (isprime[p]) {
      primes.push_back(p);
      for (ll k = p * ll{p}; k <= N; k += p) isprime[k] = false;
    }
}
void yesno(bool a) { cout << (a ? "YES\n" : "NO\n"); }
void solve() {
  string x1, x2;
  int p1, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  if (x1 == x2 && p1 == p2)
    cout << '=' << endl;
  else {
    if (x1.size() + p1 != x2.size() + p2) {
      cout << (x1.size() + p1 > x2.size() + p2 ? '>' : '<') << endl;
    } else {
      while (x1.size() < x2.size()) x1 += "0";
      while (x2.size() < x1.size()) x2 += "0";
      if (x1 == x2)
        cout << '=' << endl;
      else
        cout << (x1 > x2 ? '>' : '<') << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }
}
